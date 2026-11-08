#pragma once

namespace RE
{
	class Actor;
	template <class T>
	class NiPointer;
	class TESObjectREFR;

	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
}
