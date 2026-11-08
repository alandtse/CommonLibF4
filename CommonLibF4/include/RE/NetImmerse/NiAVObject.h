#pragma once

#include "RE/NetImmerse/NiBound.h"
#include "RE/NetImmerse/NiFlags.h"
#include "RE/NetImmerse/NiObjectNET.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTransform.h"

namespace RE
{
	class NiAlphaProperty;
	class NiCollisionObject;
	class NiCullingProcess;
	class NiNode;
	class NiUpdateData;
	class PerformOpFunc;

	class __declspec(novtable) NiAVObject :
		public NiObjectNET  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::NiAVObject };
		static constexpr auto VTABLE{ VTABLE::NiAVObject };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiAVObject };

		NiAVObject();
		virtual ~NiAVObject();  // NOLINT(modernize-use-override) 00

		// add
		void UpdateControllers(NiUpdateData& a_data)  // 28
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateControllers)>(0x28, 0x2B, this, a_data);
		}

		void PerformOp(PerformOpFunc& a_operation)  // 29
		{
			REL::RelocateVirtual<decltype(&NiAVObject::PerformOp)>(0x29, 0x2C, this, a_operation);
		}

		void AttachProperty(NiAlphaProperty* a_prop)  // 2A
		{
			REL::RelocateVirtual<decltype(&NiAVObject::AttachProperty)>(0x2A, 0x2D, this, a_prop);
		}

		void SetMaterialNeedsUpdate(bool a_needsUpdate)  // 2B
		{
			REL::RelocateVirtual<decltype(&NiAVObject::SetMaterialNeedsUpdate)>(0x2B, 0x2E, this, a_needsUpdate);
		}

		void SetDefaultMaterialNeedsUpdateFlag(bool a_flag)  // 2C
		{
			REL::RelocateVirtual<decltype(&NiAVObject::SetDefaultMaterialNeedsUpdateFlag)>(0x2C, 0x2F, this, a_flag);
		}

		void SetAppCulled(bool a_appCulled)  // 2D
		{
			REL::RelocateVirtual<decltype(&NiAVObject::SetAppCulled)>(0x2D, 0x30, this, a_appCulled);
		}

		NiAVObject* GetObjectByName(const BSFixedString& a_name)  // 2E
		{
			return REL::RelocateVirtual<decltype(&NiAVObject::GetObjectByName)>(0x2E, 0x31, this, a_name);
		}

		void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid)  // 2F
		{
			REL::RelocateVirtual<decltype(&NiAVObject::SetSelectiveUpdateFlags)>(0x2F, 0x32, this, a_selectiveUpdate, a_selectiveUpdateTransforms, a_rigid);
		}

		void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags)  // 30
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateDownwardPass)>(0x30, 0x33, this, a_data, a_flags);
		}

		void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags)  // 31
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateSelectedDownwardPass)>(0x31, 0x34, this, a_data, a_flags);
		}

		void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_flags)  // 32
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateRigidDownwardPass)>(0x32, 0x35, this, a_data, a_flags);
		}

		void UpdateWorldBound()  // 33
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateWorldBound)>(0x33, 0x36, this);
		}

		void UpdateWorldData(NiUpdateData* a_data)  // 34
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateWorldData)>(0x34, 0x37, this, a_data);
		}

		void UpdateTransformAndBounds(NiUpdateData& a_data)  // 35
		{
			REL::RelocateVirtual<decltype(&NiAVObject::UpdateTransformAndBounds)>(0x35, 0x38, this, a_data);
		}

		void UpdateTransforms(NiUpdateData& a_data)  // 36
		{
			if (REL::Module::IsVR())
				REL::RelocateVirtual<decltype(&NiAVObject::UpdateTransforms)>(0x36, 0x39, this, a_data);
			else
				UpdateWorldData(std::addressof(a_data));
		}

		void PreAttachUpdate(NiNode* a_eventualParent, NiUpdateData& a_data)  // 37
		{
			REL::RelocateVirtual<decltype(&NiAVObject::PreAttachUpdate)>(0x37, 0x3A, this, a_eventualParent, a_data);
		}

		void PostAttachUpdate()  // 38
		{
			REL::RelocateVirtual<decltype(&NiAVObject::PostAttachUpdate)>(0x38, 0x3B, this);
		}

		void OnVisible(NiCullingProcess& a_culler)  // 39
		{
			REL::RelocateVirtual<decltype(&NiAVObject::OnVisible)>(0x39, 0x3C, this, a_culler);
		}

		F4_HEAP_REDEFINE_ALIGNED_NEW(NiAVObject);

		[[nodiscard]] bool          GetAppCulled() const noexcept { return flags.flags & 1; }
		[[nodiscard]] std::uint64_t GetFlags() const noexcept { return flags.flags; }
		[[nodiscard]] bool          ShadowCaster() const noexcept { return ~(flags.flags >> 40) & 1; }
		void                        CullGeometry(bool a_cull);
		void                        CullNode(bool a_cull);
		void                        Update(NiUpdateData& a_data);

		// members
		NiNode*                             parent{ nullptr };          // 027
		NiTransform                         local;                      // 030
		NiTransform                         world;                      // 070
		NiBound                             worldBound;                 // 0B0
		NiTransform                         previousWorld;              // 0C0
		NiPointer<NiCollisionObject>        collisionObject;            // 100
		NiTFlags<std::uint64_t, NiAVObject> flags;                      // 108
		std::uintptr_t                      userData{ 0 };              // 110
		float                               fadeAmount{ 1.0F };         // 118
		std::int8_t                         multType{ 0 };              // 11C
		std::int8_t                         meshLODFadingLevel{ 0 };    // 11D
		std::int8_t                         currentMeshLODLevel{ 0 };   // 11E
		std::int8_t                         previousMeshLODLevel{ 0 };  // 11F
	};
	static_assert(sizeof(NiAVObject) == 0x120);
}
