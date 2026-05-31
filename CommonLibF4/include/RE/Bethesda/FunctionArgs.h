/*
MIT License

Copyright (c) 2022 shad0wshayd3

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#include <RE/msvc/functional.h>

namespace Papyrus
{
	template <class F>
	using BSTThreadScrapFunctionOG = RE::msvc::function<F>;  // Used by OG/VR for DispatchMethod calls

	namespace detail
	{
		class FunctionArgsBase
		{
		public:
			FunctionArgsBase() = delete;

			FunctionArgsBase(RE::BSScript::IVirtualMachine* a_vm) :
				args(nullptr), vm(a_vm) {}

			/*
            bool operator()(RE::BSScrapArray<RE::BSScript::Variable>& a_args)
            {
                args->GetArrayCopy(a_args, *vm);
                return true;
            }
            */

		protected:
			// members
			RE::BSScript::ArrayWrapper<RE::BSScript::Variable>* args;  // 00
			RE::BSScript::IVirtualMachine*                      vm;    // 08
		};

		static_assert(sizeof(FunctionArgsBase) == 0x10);

		inline BSTThreadScrapFunctionOG<bool(RE::BSScrapArray<RE::BSScript::Variable>&)> CreateThreadScrapFunction(
			FunctionArgsBase& a_args)
		{
			using func_t = decltype(&detail::CreateThreadScrapFunction);
			REL::Relocation<func_t> func{ REL::ID(69733) };
			return func(a_args);
		}
	}

	template <class... Args>
	class FunctionArgs : public detail::FunctionArgsBase
	{
		RE::BSScrapArray<RE::BSScript::Variable> scrap;

	public:
		FunctionArgs() = delete;
		FunctionArgs(const FunctionArgs&) = delete;
		FunctionArgs& operator=(const FunctionArgs&) = delete;
		FunctionArgs(FunctionArgs&&) = delete;
		FunctionArgs& operator=(FunctionArgs&&) = delete;

		FunctionArgs(RE::BSScript::IVirtualMachine* a_vm, Args... a_args) :
			FunctionArgsBase(a_vm)
		{
			scrap = RE::BSScript::detail::PackVariables(a_args...);
			args = new RE::BSScript::ArrayWrapper<RE::BSScript::Variable>(scrap, *vm);
		}

		BSTThreadScrapFunctionOG<bool(RE::BSScrapArray<RE::BSScript::Variable>&)> get()
		{
			return detail::CreateThreadScrapFunction(*this);
		}

		~FunctionArgs()
		{
			if (args != nullptr)
				delete args;
		}
	};

	static_assert(sizeof(FunctionArgs<std::monostate>) == 0x30);
}
