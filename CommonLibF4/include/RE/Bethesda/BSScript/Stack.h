#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IMemoryPagePolicy.h"
#include "RE/Bethesda/BSScript/IProfilePolicy.h"
#include "RE/Bethesda/BSScript/IStackCallbackFunctor.h"
#include "RE/Bethesda/BSScript/Object.h"
#include "RE/Bethesda/BSScript/StackFrame.h"
#include "RE/Bethesda/BSScript/Variable.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class IProfilePolicy;
		class IStackCallbackFunctor;
		class MemoryPage;  // stub
		class Object;
		class StackFrame;
		class Variable;

		struct IMemoryPagePolicy;

		namespace Internal
		{
			class CodeTasklet;
		}

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class Stack :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			enum class StackType;

			enum class FreezeState
			{
				kUnfrozen,
				kFreezing,
				kFrozen
			};

			enum class State
			{
				kRunning,
				kFinished,
				kWaitingOnMemory,
				kWaitingOnLatentFunction,
				kWaitingInOtherStackForCall,
				kWaitingInOtherStackForReturn,
				kWaitingInOtherStackForReturnNoPop,
				kRetryReturnNoPop,
				kRetryCall
			};

			struct MemoryPageData
			{
			public:
				// members
				BSTAutoPointer<MemoryPage> page;       // 00
				std::uint32_t availableMemoryInBytes;  // 08
			};
			static_assert(sizeof(MemoryPageData) == 0x10);

			[[nodiscard]] std::uint32_t GetPageForFrame(const StackFrame* a_frame) const
			{
				using func_t = decltype(&Stack::GetPageForFrame);
				REL::Relocation<func_t> func{ REL::ID(1429302) };
				return func(this, a_frame);
			}

			[[nodiscard]] Variable& GetStackFrameVariable(const StackFrame* a_frame, std::uint32_t a_index, std::uint32_t a_pageHint)
			{
				using func_t = decltype(&Stack::GetStackFrameVariable);
				REL::Relocation<func_t> func{ REL::ID(897539) };
				return func(this, a_frame, a_index, a_pageHint);
			}

			// members
			IMemoryPagePolicy* policy;                                // 08
			IProfilePolicy* profilePolicy;                            // 10
			BSTSmallArray<MemoryPageData, 3> pages;                   // 18
			std::uint32_t frames;                                     // 58
			StackFrame* top;                                          // 60
			stl::enumeration<State, std::int32_t> state;              // 68
			stl::enumeration<FreezeState, std::int32_t> freezeState;  // 6C
			Variable returnValue;                                     // 70
			std::uint32_t stackID;                                    // 80
			stl::enumeration<StackType, std::int32_t> stackType;      // 84
			BSTSmartPointer<Internal::CodeTasklet> owningTasklet;     // 88
			BSTSmartPointer<IStackCallbackFunctor> callback;          // 90
			BSTSmartPointer<Object> objToUnbind;                      // 98
			BSTSmartPointer<Stack> nextStack;                         // A0
		};
		static_assert(sizeof(Stack) == 0xA8);
	}
}
