#pragma once

#include "RE/NetImmerse/NiRefObject.h"

namespace RE
{
	class bhkBlendCollisionObject;
	class bhkLimitedHingeConstraint;
	class bhkNiCollisionObject;
	class bhkNPCollisionObject;
	class bhkRigidBody;
	class BSDynamicTriShape;
	class BSFadeNode;
	class BSGeometry;
	class BSLines;
	class BSMultiBoundNode;
	class BSSegmentedTriShape;
	class BSSubIndexTriShape;
	class BSTriShape;
	class NiCloningProcess;
	class NiControllerManager;
	class NiGeometry;
	class NiLight;
	class NiNode;
	class NiObjectGroup;
	class NiParticles;
	class NiParticleSystem;
	class NiStream;
	class NiSwitchNode;
	class NiTriBasedGeom;
	class NiTriShape;
	class NiTriStrips;

	struct NiRTTI;

	class __declspec(novtable) NiObject :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiObject };
		static constexpr auto VTABLE{ VTABLE::NiObject };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiObject };

		NiObject() { stl::emplace_vtable(this); }
		virtual ~NiObject() = default;  // NOLINT(modernize-use-override) 00

		// add
		virtual const NiRTTI*        GetRTTI() const;                           // 02
		virtual NiNode*              IsNode() { return nullptr; }               // 04
		virtual const NiNode*        IsNode() const { return nullptr; }         // 03
		virtual NiSwitchNode*        IsSwitchNode() { return nullptr; }         // 05
		virtual BSFadeNode*          IsFadeNode() { return nullptr; }           // 06
		virtual BSMultiBoundNode*    IsMultiBoundNode() { return nullptr; }     // 07
		virtual BSGeometry*          IsGeometry() { return nullptr; }           // 08
		virtual NiTriStrips*         IsTriStrips() { return nullptr; }          // 09
		virtual BSTriShape*          IsTriShape() { return nullptr; }           // 0A
		virtual BSDynamicTriShape*   IsDynamicTriShape() { return nullptr; }    // 0B
		virtual BSSegmentedTriShape* IsSegmentedTriShape() { return nullptr; }  // 0C
		virtual BSSubIndexTriShape*  IsSubIndexTriShape() { return nullptr; }   // 0D
		virtual NiGeometry*          IsNiGeometry() { return nullptr; }         // 0E
		virtual NiTriBasedGeom*      IsNiTriBasedGeom() { return nullptr; }     // 0F
		virtual NiTriShape*          IsNiTriShape() { return nullptr; }         // 10
		virtual NiParticles*         IsParticlesGeom() { return nullptr; }      // 11
		virtual NiParticleSystem*    IsParticleSystem() { return nullptr; }     // 12
		virtual BSLines*             IsLinesGeom() { return nullptr; }          // 13
		virtual NiLight*             IsLight() { return nullptr; }              // 14

		bhkNiCollisionObject* IsBhkNiCollisionObject()  // 15
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsBhkNiCollisionObject)>(0x15, 0x17, this);
		}

		bhkBlendCollisionObject* IsBhkBlendCollisionObject()  // 16
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsBhkBlendCollisionObject)>(0x16, 0x18, this);
		}

		bhkRigidBody* IsBhkRigidBody()  // 17
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsBhkRigidBody)>(0x17, 0x19, this);
		}

		bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint()  // 18
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsBhkLimitedHingeConstraint)>(0x18, 0x1A, this);
		}

		bhkNPCollisionObject* IsbhkNPCollisionObject()  // 19
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsbhkNPCollisionObject)>(0x19, 0x1B, this);
		}

		NiObject* CreateClone(NiCloningProcess& a_cloneData)  // 1A
		{
			return REL::RelocateVirtual<decltype(&NiObject::CreateClone)>(0x1A, 0x1C, this, a_cloneData);
		}

		void LoadBinary(NiStream& a_stream)  // 1B
		{
			REL::RelocateVirtual<decltype(&NiObject::LoadBinary)>(0x1B, 0x1D, this, a_stream);
		}

		void LinkObject(NiStream& a_stream)  // 1C
		{
			REL::RelocateVirtual<decltype(&NiObject::LinkObject)>(0x1C, 0x1E, this, a_stream);
		}

		bool RegisterStreamables(NiStream& a_stream)  // 1D
		{
			return REL::RelocateVirtual<decltype(&NiObject::RegisterStreamables)>(0x1D, 0x1F, this, a_stream);
		}

		void SaveBinary(NiStream& a_stream)  // 1E
		{
			REL::RelocateVirtual<decltype(&NiObject::SaveBinary)>(0x1E, 0x20, this, a_stream);
		}

		bool IsEqual(NiObject* a_object)  // 1F
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsEqual)>(0x1F, 0x21, this, a_object);
		}

		void ProcessClone(NiCloningProcess& a_cloning)  // 20
		{
			REL::RelocateVirtual<decltype(&NiObject::ProcessClone)>(0x20, 0x22, this, a_cloning);
		}

		void PostLinkObject(NiStream& a_stream)  // 21
		{
			REL::RelocateVirtual<decltype(&NiObject::PostLinkObject)>(0x21, 0x23, this, a_stream);
		}

		bool StreamCanSkip()  // 22
		{
			return REL::RelocateVirtual<decltype(&NiObject::StreamCanSkip)>(0x22, 0x24, this);
		}

		const NiRTTI* GetStreamableRTTI()  // 23
		{
			return REL::RelocateVirtual<decltype(&NiObject::GetStreamableRTTI)>(0x23, 0x25, this);
		}

		std::uint32_t GetBlockAllocationSize() const  // 24
		{
			return REL::RelocateVirtual<decltype(&NiObject::GetBlockAllocationSize)>(0x24, 0x26, this);
		}

		NiObjectGroup* GetGroup() const  // 25
		{
			return REL::RelocateVirtual<decltype(&NiObject::GetGroup)>(0x25, 0x27, this);
		}

		void SetGroup(NiObjectGroup* a_group)  // 26
		{
			REL::RelocateVirtual<decltype(&NiObject::SetGroup)>(0x26, 0x28, this, a_group);
		}

		NiControllerManager* IsNiControllerManager()  // 27
		{
			return REL::RelocateVirtual<decltype(&NiObject::IsNiControllerManager)>(0x27, 0x29, this);
		}

		F4_HEAP_REDEFINE_NEW(NiObject);
	};
	static_assert(sizeof(NiObject) == 0x10);
}
