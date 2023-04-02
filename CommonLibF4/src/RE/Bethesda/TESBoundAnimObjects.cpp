#include "RE/Bethesda/TESBoundAnimObjects.h"

#include "RE/Bethesda/PlayerCharacter.h"
#include "RE/Bethesda/TESRace.h"

namespace RE
{
	bool TESNPC::ContainsKeyword(std::string_view a_editorID) const
	{
		if (ContainsKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetFormRace(); npcRace && npcRace->ContainsKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	bool TESNPC::HasApplicableKeywordString(std::string_view a_editorID) const
	{
		if (HasKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetFormRace(); npcRace && npcRace->HasKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	bool TESNPC::UsingAlternateHeadPartList() const
	{
		if (const auto player = PlayerCharacter::GetSingleton(); IsPlayer() && player) {
			const auto& map = GetAlternateHeadPartListMap();
			return player->charGenRace && player->charGenRace != formRace && map.contains(player->GetNPC());
		} else {
			return originalRace && originalRace != formRace;
		}
	}
}
