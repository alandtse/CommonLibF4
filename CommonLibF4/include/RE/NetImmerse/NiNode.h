#pragma once

#include "RE/Bethesda/Atomic.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTArray.h"

namespace RE
{
	class __declspec(novtable) NiNode :
		public NiAVObject  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::NiNode };
		static constexpr auto VTABLE{ VTABLE::NiNode };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiNode };

		// NOLINTNEXTLINE(modernize-use-equals-default)
		NiNode() :
			NiNode(0)
		{}

		explicit NiNode(std::uint32_t a_numChildren) :
			children(a_numChildren)
		{
			stl::emplace_vtable(this);
			static REL::Relocation<std::uintptr_t> childrenVTable{ REL::ID(390064) };
			reinterpret_cast<std::uintptr_t&>(children) = childrenVTable.address();
		}

		// add
		virtual void AttachChild(NiAVObject* a_child, bool a_firstAvail);                                 // 3A
		virtual void InsertChildAt(std::uint32_t a_idx, NiAVObject* a_child);                             // 3B
		virtual void DetachChild(NiAVObject* a_child);                                                    // 3D
		virtual void DetachChild(NiAVObject* a_child, NiPointer<NiAVObject>& a_avObject);                 // 3C
		virtual void DetachChildAt(std::uint32_t a_idx);                                                  // 3F
		virtual void DetachChildAt(std::uint32_t a_idx, NiPointer<NiAVObject>& a_avObject);               // 3E
		virtual void SetAt(std::uint32_t a_idx, NiAVObject* a_child);                                     // 41
		virtual void SetAt(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_avObject);  // 40
		virtual void UpdateUpwardPass(NiUpdateData& a_data);                                              // 42

		F4_HEAP_REDEFINE_ALIGNED_NEW(NiNode);

		struct RUNTIME_DATA
		{
#define RUNTIME_DATA_CONTENT                                                 \
	NiTObjectArray<NiPointer<NiAVObject>> children;                  /*120*/ \
	BSTAtomicValue<std::uint32_t>         dirtyState;                /*138*/ \
	float                                 meshLODFadeAmount{ 0.0F }; /*13C*/
            RUNTIME_DATA_CONTENT
		};
		static_assert(sizeof(RUNTIME_DATA) == 0x20);

		[[nodiscard]] inline RUNTIME_DATA& GetRuntimeData() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x120, 0x160);
		}

		[[nodiscard]] inline const RUNTIME_DATA& GetRuntimeData() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x120, 0x160);
		}

		// members
#if !defined(ENABLE_FALLOUT_VR)
		RUNTIME_DATA_CONTENT
#elif (!defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_F4))
		std::uint32_t pad120[0x10];  // 120
		RUNTIME_DATA_CONTENT
#endif
	};
#if !defined(ENABLE_FALLOUT_VR)
	static_assert(sizeof(NiNode) == 0x140);
#elif (!defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_F4))
	static_assert(sizeof(NiNode) == 0x180);
#endif
}
#undef RUNTIME_DATA_CONTENT
