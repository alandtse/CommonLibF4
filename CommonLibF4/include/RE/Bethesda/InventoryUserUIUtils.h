#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Scaleform/GFx/GFx_Player.h"

namespace RE
{
	class EffectItem;
	class MagicItem;

	class HUDModeType;

	namespace InventoryUserUIUtils
	{
		namespace detail
		{
			inline void AddItemCardInfoEntry(
				Scaleform::GFx::Value& a_array,
				Scaleform::GFx::Value& a_newEntry,
				const BSFixedStringCS& a_textID,
				Scaleform::GFx::Value& a_value,
				float a_difference = 0.0F,
				float a_totalDamage = FLT_MAX,
				float a_compareDamage = FLT_MAX)
			{
				using func_t = decltype(&detail::AddItemCardInfoEntry);
				REL::Relocation<func_t> func{ REL::ID(489521) };
				return func(a_array, a_newEntry, a_textID, a_value, a_difference, a_totalDamage, a_compareDamage);
			}
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, Scaleform::GFx::Value& a_entry, const char* a_name, Scaleform::GFx::Value a_value, float a_difference, float a_totalValue = FLT_MAX, float a_comparisonValue = FLT_MAX)
		{
			detail::AddItemCardInfoEntry(a_array, a_entry, a_name, a_value, a_difference, a_totalValue, a_comparisonValue);
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, Scaleform::GFx::Value& a_entry, const char* a_name = "", Scaleform::GFx::Value a_value = 0)
		{
			detail::AddItemCardInfoEntry(a_array, a_entry, a_name, a_value);
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, const char* a_name, Scaleform::GFx::Value a_value)
		{
			Scaleform::GFx::Value entry;
			detail::AddItemCardInfoEntry(a_array, entry, a_name, a_value);
		}
	}

	namespace StatsMenuUtils
	{
		inline void GetEffectDisplayInfo(MagicItem* a_item, EffectItem* a_effect, float& a_magnitude, float& a_duration)
		{
			using func_t = decltype(&StatsMenuUtils::GetEffectDisplayInfo);
			REL::Relocation<func_t> func{ REL::ID(294691) };
			return func(a_item, a_effect, a_magnitude, a_duration);
		}
	}

	namespace UIUtils
	{
		using ComparisonItems = BSScrapArray<BSTTuple<const BGSInventoryItem*, std::uint32_t>>;

		inline void GetComparisonItems(const TESBoundObject* a_object, ComparisonItems& a_comparisonItems)
		{
			using func_t = decltype(&GetComparisonItems);
			REL::Relocation<func_t> func{ REL::ID(593818) };
			return func(a_object, a_comparisonItems);
		}

		inline void PlayMenuSound(const char* a_soundName)
		{
			using func_t = decltype(&PlayMenuSound);
			REL::Relocation<func_t> func{ REL::ID(1227993) };
			return func(a_soundName);
		}
	}
}
