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

		explicit NiNode(std::uint32_t a_numChildren)
		{
			stl::emplace_vtable(this);
			GetRuntimeData().children = NiTObjectArray<NiPointer<NiAVObject>>(a_numChildren);
			static REL::Relocation<std::uintptr_t> childrenVTable{ REL::ID(390064) };
			reinterpret_cast<std::uintptr_t&>(GetRuntimeData().children) = childrenVTable.address();
		}

		// add
		void AttachChild(NiAVObject* a_child, bool a_firstAvail)  // 3A
		{
			REL::RelocateVirtual<decltype(&NiNode::AttachChild)>(0x3A, 0x3D, this, a_child, a_firstAvail);
		}

		void InsertChildAt(std::uint32_t a_idx, NiAVObject* a_child)  // 3B
		{
			REL::RelocateVirtual<decltype(&NiNode::InsertChildAt)>(0x3B, 0x3E, this, a_idx, a_child);
		}

		void DetachChild(NiAVObject* a_child)  // 3D
		{
			using DetachChild = void (NiNode::*)(NiAVObject*);
			REL::RelocateVirtual<DetachChild>(0x3C, 0x40, this, a_child);
		}

		void DetachChild(NiAVObject* a_child, NiPointer<NiAVObject>& a_avObject)  // 3C
		{
			using DetachChild = void (NiNode::*)(NiAVObject*, NiPointer<NiAVObject>&);
			REL::RelocateVirtual<DetachChild>(0x3D, 0x3F, this, a_child, a_avObject);
		}

		void DetachChildAt(std::uint32_t a_idx)  // 3F
		{
			using DetachChildAt = void (NiNode::*)(std::uint32_t);
			REL::RelocateVirtual<DetachChildAt>(0x3E, 0x42, this, a_idx);
		}

		void DetachChildAt(std::uint32_t a_idx, NiPointer<NiAVObject>& a_avObject)  // 3E
		{
			using DetachChildAt = void (NiNode::*)(std::uint32_t, NiPointer<NiAVObject>&);
			REL::RelocateVirtual<DetachChildAt>(0x3F, 0x41, this, a_idx, a_avObject);
		}

		void SetAt(std::uint32_t a_idx, NiAVObject* a_child)  // 41
		{
			using SetAt = void (NiNode::*)(std::uint32_t, NiAVObject*);
			REL::RelocateVirtual<SetAt>(0x40, 0x44, this, a_idx, a_child);
		}

		void SetAt(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_avObject)  // 40
		{
			using SetAt = void (NiNode::*)(std::uint32_t, NiAVObject*, NiPointer<NiAVObject>&);
			REL::RelocateVirtual<SetAt>(0x41, 0x43, this, a_idx, a_child, a_avObject);
		}

		void UpdateUpwardPass(NiUpdateData& a_data)  // 42
		{
			REL::RelocateVirtual<decltype(&NiNode::UpdateUpwardPass)>(0x42, 0x45, this, a_data);
		}

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
