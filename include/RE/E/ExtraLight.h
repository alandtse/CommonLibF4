#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/R/REFR_LIGHT.h"

namespace RE
{
	class __declspec(novtable) ExtraLight :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLight };
		static constexpr auto VTABLE{ VTABLE::ExtraLight };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLight };

		// members
		REFR_LIGHT lightdata;  // 18
	};
	static_assert(sizeof(ExtraLight) == 0x30);
}
