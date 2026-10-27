#pragma once

#include "RE/NetImmerse/NiObject.h"

namespace RE
{
	class NiUpdateData;

	class __declspec(novtable) NiCollisionObject :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiCollisionObject };
		static constexpr auto VTABLE{ VTABLE::NiCollisionObject };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiCollisionObject };

		// add
		void SetSceneGraphObject(NiAVObject* a_sceneObject)  // 28
		{
			REL::RelocateVirtual<decltype(&NiCollisionObject::SetSceneGraphObject)>(0x28, 0x2A, this, a_sceneObject);
		}

		void UpdateWorldData(NiUpdateData& a_updateData)  // 29
		{
			REL::RelocateVirtual<decltype(&NiCollisionObject::UpdateWorldData)>(0x29, 0x2B, this, a_updateData);
		}

		void Initialize(void* a_data)  // 2A
		{
			REL::RelocateVirtual<decltype(&NiCollisionObject::Initialize)>(0x2A, 0x2C, this, a_data);
		}

		void Convert(std::uint32_t a_version, void* a_data)  // 2B
		{
			REL::RelocateVirtual<decltype(&NiCollisionObject::Convert)>(0x2B, 0x2D, this, a_version, a_data);
		}

		// members
		NiAVObject* sceneObject;  // 10
	};
	static_assert(sizeof(NiCollisionObject) == 0x18);
}
