#pragma once

#include "RE/Bethesda/TESForms.h"

namespace RE
{
	class ActiveEffect;
	class EffectItem;
	class MagicItem;
	class MagicTarget;
	class TESForm;
	class TESObjectREFR;

	class ActiveEffectReferenceEffectController
	{
	public:
		virtual ~ActiveEffectReferenceEffectController();

		//	void			** _vtbl;	// 00
		ActiveEffect* effect;  // 08
							   // possibly more
	};

	class __declspec(novtable) ActiveEffect :
		public BSIntrusiveRefCounted
	{
	public:
		static constexpr auto RTTI{ RTTI::ActiveEffect };
		static constexpr auto VTABLE{ VTABLE::ActiveEffect };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kActiveEffect };

		bool CheckDisplacementSpellOnTarget()
		{
			using func_t = decltype(&ActiveEffect::CheckDisplacementSpellOnTarget);
			REL::Relocation<func_t> func{ REL::ID(1415178) };
			return func(this);
		}

		enum class Flags : std::uint32_t
		{
			kNone = 0,
			kNoHitShader = 1U << 1,
			kNoHitEffectArt = 1U << 2,
			kNoInitialFlare = 1U << 4,
			kApplyingHitEffects = 1U << 5,
			kApplyingSounds = 1U << 6,
			kHasConditions = 1U << 7,
			kRecover = 1U << 9,
			kDualCasted = 1U << 12,
			kInactive = 1U << 15,
			kAppliedEffects = 1U << 16,
			kRemovedEffects = 1U << 17,
			kDispelled = 1U << 18,
			kWornOff = 1U << 31
		};

		enum class ConditionStatus : std::uint32_t
		{
			kNotAvailable = static_cast<std::underlying_type_t<ConditionStatus>>(-1),
			kFalse = 0,
			kTrue = 1
		};

		virtual ~ActiveEffect();

		//	void					** _vtbl;		// 00
		ActiveEffectReferenceEffectController controller;
		std::int32_t unk20;
		float unk24;
		float unk28;
		float unk2C;
		std::int32_t unk30;
		std::int8_t unk34;
		std::int8_t pad35[3];
		ObjectRefHandle target;
		std::int32_t unk3C;
		void* niNode;
		MagicItem* item;
		EffectItem* effect;  // 50
		MagicTarget* magicTarget;
		TESForm* sourceItem;
		std::int64_t unk68;
		std::int64_t unk70;
		float elapsed;
		float duration;
		float magnitude;
		stl::enumeration<Flags, std::uint32_t> flags;
		stl::enumeration<ConditionStatus, std::uint32_t> conditionStatus;
		std::uint32_t uniqueID;
		std::int32_t unk90;
		std::int32_t pad94;
		std::int32_t actorValue;
		std::int32_t unk9C;
		std::int64_t unkA0;
	};
}
