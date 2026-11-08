#pragma once

#include "RE/NetImmerse/NiObject.h"

namespace RE
{
	struct hknpWorldCinfo;

	class bhkWorld :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::bhkWorld };
		static constexpr auto VTABLE{ VTABLE::bhkWorld };
		static constexpr auto Ni_RTTI{ Ni_RTTI::bhkWorld };

		// add
		bool Update(std::uint32_t a_updateFlags)  // 28
		{
			return REL::RelocateVirtual<decltype(&bhkWorld::Update)>(0x28, 0x2A, this, a_updateFlags);
		}

		void Init(const hknpWorldCinfo& a_info)  // 29
		{
			REL::RelocateVirtual<decltype(&bhkWorld::Init)>(0x29, 0x2B, this, a_info);
		}

		static bool RemoveObjects(NiAVObject* a_object, bool a_recurse, bool a_force)
		{
			using func_t = decltype(&RemoveObjects);
			static REL::Relocation<func_t> func{ REL::RelocationID(1514984, 2277721) };
			return func(a_object, a_recurse, a_force);
		}

		// members
		std::byte pad[0x180 - 0x10];  // 0x10 - TODO
	};
	static_assert(sizeof(bhkWorld) == 0x180);
}
