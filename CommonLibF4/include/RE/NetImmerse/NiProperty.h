#pragma once

#include "RE/NetImmerse/NiObjectNET.h"

namespace RE
{
	class NiUpdateData;

	class __declspec(novtable) NiProperty :
		public NiObjectNET  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiProperty };
		static constexpr auto VTABLE{ VTABLE::NiProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiProperty };

		// add
		std::int32_t Type()  // 28
		{
			return REL::RelocateVirtual<decltype(&NiProperty::Type)>(0x28, 0x2A, this);
		}

		void Update(NiUpdateData& a_updateData)  // 29
		{
			REL::RelocateVirtual<decltype(&NiProperty::Update)>(0x29, 0x2B, this, a_updateData);
		}
	};
	static_assert(sizeof(NiProperty) == 0x28);
}
