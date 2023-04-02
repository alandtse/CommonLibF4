#include "RE/Bethesda/TESObjectREFRs.h"

#include "RE/NetImmerse/NiAVObject.h"

namespace RE
{
	BIPOBJECT::~BIPOBJECT()
	{
		Dtor();
		stl::memzero(this);
	}

	TESObjectREFR* TESObjectREFR::FindReferenceFor3D(NiAVObject* a_object3D)
	{
		using func_t = decltype(&TESObjectREFR::FindReferenceFor3D);
		REL::Relocation<func_t> func{ REL::ID(766937) };
		return func(a_object3D);
	}

}
