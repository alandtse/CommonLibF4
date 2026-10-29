#pragma once

#include "RE/NetImmerse/NiFlags.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class NiObjectNET;
	class NiUpdateData;

	class __declspec(novtable) NiTimeController :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiTimeController };
		static constexpr auto VTABLE{ VTABLE::NiTimeController };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiTimeController };

		// add
		void Start(float a_time)  // 28
		{
			REL::RelocateVirtual<decltype(&NiTimeController::Start)>(0x28, 0x2A, this, a_time);
		}

		void Stop()  // 29
		{
			REL::RelocateVirtual<decltype(&NiTimeController::Stop)>(0x29, 0x2B, this);
		}

		void Update(NiUpdateData& a_updateData)  // 2A
		{
			REL::RelocateVirtual<decltype(&NiTimeController::Update)>(0x2A, 0x2C, this, a_updateData);
		}

		void SetTarget(NiObjectNET* a_target)  // 2B
		{
			REL::RelocateVirtual<decltype(&NiTimeController::SetTarget)>(0x2B, 0x2D, this, a_target);
		}

		bool IsTransformController() const  // 2C
		{
			return REL::RelocateVirtual<decltype(&NiTimeController::IsTransformController)>(0x2C, 0x2E, this);
		}

		bool IsVertexController() const  // 2D
		{
			return REL::RelocateVirtual<decltype(&NiTimeController::IsVertexController)>(0x2D, 0x2F, this);
		}

		float ComputeScaledTime(float a_time)  // 2E
		{
			return REL::RelocateVirtual<decltype(&NiTimeController::ComputeScaledTime)>(0x2E, 0x30, this, a_time);
		}

		void OnPreDisplay()  // 2F
		{
			REL::RelocateVirtual<decltype(&NiTimeController::OnPreDisplay)>(0x2F, 0x31, this);
		}

		bool IsStreamable() const  // 30
		{
			return REL::RelocateVirtual<decltype(&NiTimeController::IsStreamable)>(0x30, 0x32, this);
		}

		bool TargetIsRequiredType() const  // 31
		{
			return REL::RelocateVirtual<decltype(&NiTimeController::TargetIsRequiredType)>(0x31, 0x33, this);
		}

		// members
		NiTFlags<std::uint16_t, NiTimeController> flags;             // 10
		float                                     frequency;         // 14
		float                                     phase;             // 18
		float                                     loKeyTime;         // 1C
		float                                     hiKeyTime;         // 20
		float                                     startTime;         // 24
		float                                     lastTime;          // 28
		float                                     weightedLastTime;  // 2C
		float                                     scaledTime;        // 30
		NiObjectNET*                              target;            // 38
		NiPointer<NiTimeController>               next;              // 40
	};
	static_assert(sizeof(NiTimeController) == 0x48);
}
