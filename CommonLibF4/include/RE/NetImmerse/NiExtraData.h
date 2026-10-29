#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/NetImmerse/NiObject.h"

namespace RE
{
	class __declspec(novtable) NiExtraData :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiExtraData };
		static constexpr auto VTABLE{ VTABLE::NiExtraData };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiExtraData };

		// add
		bool KeepForExport() const  // 28
		{
			return REL::RelocateVirtual<decltype(&NiExtraData::KeepForExport)>(0x28, 0x2A, this);
		}

		bool KeepForExporterOnly() const  // 29
		{
			return REL::RelocateVirtual<decltype(&NiExtraData::KeepForExporterOnly)>(0x29, 0x2B, this);
		}

		bool IsStreamable() const  // 2A
		{
			return REL::RelocateVirtual<decltype(&NiExtraData::IsStreamable)>(0x2A, 0x2C, this);
		}

		bool IsCloneable() const  // 2B
		{
			return REL::RelocateVirtual<decltype(&NiExtraData::IsCloneable)>(0x2B, 0x2D, this);
		}

		// members
		BSFixedString name;  // 10
	};
	static_assert(sizeof(NiExtraData) == 0x18);
}
