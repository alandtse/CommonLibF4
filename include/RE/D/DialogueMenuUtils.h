#pragma once

namespace RE
{
	namespace DialogueMenuUtils
	{
		inline void OpenMenu()
		{
			using func_t = decltype(&DialogueMenuUtils::OpenMenu);
			static REL::Relocation<func_t> func{ ID::DialogueMenuUtils::OpenMenu };
			return func();
		}

		inline void CloseMenu()
		{
			using func_t = decltype(&DialogueMenuUtils::CloseMenu);
			static REL::Relocation<func_t> func{ ID::DialogueMenuUtils::CloseMenu };
			return func();
		}

		inline void ShowSpeechChallengeAnim()
		{
			using func_t = decltype(&DialogueMenuUtils::ShowSpeechChallengeAnim);
			static REL::Relocation<func_t> func{ ID::DialogueMenuUtils::ShowSpeechChallengeAnim };
			return func();
		}
	}
}
