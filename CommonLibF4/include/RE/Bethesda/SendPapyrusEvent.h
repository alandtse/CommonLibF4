#pragma once
#include <F4SE/API.h>
#include <F4SE/interfaces.h>
#include <RE/Bethesda/BSScriptUtil.h>
#include <RE/Bethesda/FunctionArgs.h>
#include <RE/msvc/functional.h>

/*
Functions for calling Papyrus functions from C++
NG changed the parameters for the DispatchMethodCall function,
so we need to call the function differently for OG/VR and NG

Usage: in Papyrus, use 'RegisterForExternalEvent'
in C++, call 'SendPapyrusExternalEvent'
*/

namespace Papyrus
{
	namespace detail
	{

		template <class F>
		using BSTThreadScrapFunction = std::function<F>;  // Used by NG for DispatchMethod calls

		template <class F>
		using BSTThreadScrapFunctionOG = RE::msvc::function<F>;  // Used by OG for same

		// Get function address from VirtualMachine Vtable
		inline size_t GetVtableFunctionAddr(int entry)
		{
			auto    VMvtbl = RE::BSScript::Internal::VirtualMachine::VTABLE;
			REL::ID VMvtblID = VMvtbl[0];

			void** pt = (void**)VMvtblID.address();
			return (size_t)pt[entry];
		}

		// NG can use the current IVirtualMachine::DispatchMethodCall as is.
		// OG/VR, we need to call the function with different args.

		inline bool DispatchMethodCallOG(
			RE::BSScript::IVirtualMachine*                                                   vm,
			std::uint64_t                                                                    a_objHandle,
			const RE::BSFixedString&                                                         a_objName,
			const RE::BSFixedString&                                                         a_funcName,
			const BSTThreadScrapFunctionOG<bool(RE::BSScrapArray<RE::BSScript::Variable>&)>& a_arguments,
			const RE::BSTSmartPointer<RE::BSScript::IStackCallbackFunctor>&                  a_callback)
		{
			// Get function address out of the Vtable
			using func_t = decltype(&DispatchMethodCallOG);
			REL::Relocation<func_t> func{ GetVtableFunctionAddr(46) };

			return func(vm, a_objHandle, a_objName, a_funcName, a_arguments, a_callback);
		}

		// OG/VR version of DispatchStatic call

		inline bool DispatchStaticCallOG(
			RE::BSScript::IVirtualMachine*                                                   vm,
			const RE::BSFixedString&                                                         a_objName,
			const RE::BSFixedString&                                                         a_funcName,
			const BSTThreadScrapFunctionOG<bool(RE::BSScrapArray<RE::BSScript::Variable>&)>& a_arguments,
			const RE::BSTSmartPointer<RE::BSScript::IStackCallbackFunctor>&                  a_callback)
		{
			// Get function address out of the Vtable
			using func_t = decltype(&DispatchStaticCallOG);
			REL::Relocation<func_t> func{ GetVtableFunctionAddr(44) };

			return func(vm, a_objName, a_funcName, a_arguments, a_callback);
		}

		// Generic DispatchStaticCall used to call global Papyrus functions

		template <class... Args>
		bool DispatchStaticCall(
			RE::BSScript::IVirtualMachine*                                  vm,          // VM pointer
			const RE::BSFixedString&                                        a_objName,   // Papyrus script name
			const RE::BSFixedString&                                        a_funcName,  // Papyrus function name
			const RE::BSTSmartPointer<RE::BSScript::IStackCallbackFunctor>& a_callback,
			Args... a_args)
		{  // Args, must match Papyrus declaration

			if (REL::Module::IsNG()) {
				return vm->DispatchStaticCall(
					a_objName,
					a_funcName,
					[&](RE::BSScrapArray<RE::BSScript::Variable>& a_out) {
						a_out = RE::BSScript::detail::PackVariables(a_args...);
						return true;
					},
					a_callback);
			} else {
				FunctionArgs l_args(vm, a_args...);
				return DispatchStaticCallOG(vm, a_objName, a_funcName, l_args.get(), a_callback);
			}
		}

		// Generic DispatchMethodCall used to call Papyrus function on a specific script instance

		template <class... Args>
		bool DispatchMethodCall(
			RE::BSScript::IVirtualMachine*                                  vm,           // VM pointer
			std::uint64_t                                                   a_objHandle,  // Handle to script instance
			const RE::BSFixedString&                                        a_objName,    // Papyrus Script name
			const RE::BSFixedString&                                        a_funcName,   // Papyrus function name
			const RE::BSTSmartPointer<RE::BSScript::IStackCallbackFunctor>& a_callback,
			Args... a_args)  // Args, must match Papyrus declaration
		{
			if (REL::Module::IsNG()) {
				return vm->DispatchMethodCall(
					a_objHandle,
					a_objName,
					a_funcName,
					[&](RE::BSScrapArray<RE::BSScript::Variable>& a_out) {
						a_out = RE::BSScript::detail::PackVariables(a_args...);
						return true;
					},
					a_callback);
			} else {
				FunctionArgs l_args(vm, a_args...);
				return DispatchMethodCallOG(vm, a_objHandle, a_objName, a_funcName, l_args.get(), a_callback);
			}
		}

		// Call all the Papyrus functions registered with a_eventName
		// Call RegisterForExternalEvent to register Papyrus functions to be called.

		template <class... Args>
		void SendPapyrusExternalEvent(std::string a_eventName, Args... a_args)
		{
			auto const papyrus = F4SE::GetPapyrusInterface();
			auto*      vm = RE::GameVM::GetSingleton()->GetVM().get();

			if (REL::Module::IsNG()) {
				struct PapyrusEventData
				{
					RE::BSScript::IVirtualMachine*           vm;
					RE::BSScrapArray<RE::BSScript::Variable> argsPacked;
				};
				PapyrusEventData evntData;

				evntData.argsPacked = RE::BSScript::detail::PackVariables(a_args...);
				evntData.vm = vm;

				papyrus->GetExternalEventRegistrations(
					a_eventName, &evntData,
					[](uint64_t handle, const char* scriptName, const char* callbackName, void* dataPtr) {
						PapyrusEventData* d = static_cast<PapyrusEventData*>(dataPtr);
						d->vm->DispatchMethodCall(
							handle, scriptName, callbackName,
							[&](RE::BSScrapArray<RE::BSScript::Variable>& a_out) {
								a_out = d->argsPacked;
								return true;
							},
							nullptr);
					});
			} else {
				struct PapyrusEventData
				{
					RE::BSScript::IVirtualMachine*                                            vm;
					BSTThreadScrapFunctionOG<bool(RE::BSScrapArray<RE::BSScript::Variable>&)> scrapFunc;
				};

				PapyrusEventData evntData;
				FunctionArgs     l_args(vm, a_args...);

				evntData.scrapFunc = l_args.get();
				evntData.vm = vm;

				papyrus->GetExternalEventRegistrations(
					a_eventName, &evntData,
					[](uint64_t handle, const char* scriptName, const char* callbackName, void* dataPtr) {
						PapyrusEventData* d = static_cast<PapyrusEventData*>(dataPtr);
						DispatchMethodCallOG(d->vm, handle, scriptName, callbackName, d->scrapFunc, nullptr);
					});
			}
		}
	}
}
