#pragma once

#include "RE/NetImmerse/NiProperty.h"

namespace RE
{
	class __declspec(novtable) NiShadeProperty :
		public NiProperty  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiShadeProperty };
		static constexpr auto VTABLE{ VTABLE::NiShadeProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiShadeProperty };

		// add
		bool SetupGeometry(BSGeometry* a_geometry)  // 2A
		{
			return REL::RelocateVirtual<decltype(&NiShadeProperty::SetupGeometry)>(0x2A, 0x2C, this, a_geometry);
		}
	};
	static_assert(sizeof(NiShadeProperty) == 0x28);
}
