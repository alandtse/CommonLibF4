#pragma once

#include "REL/Common.h"

namespace REL::F4
{
	// F4-specific runtime selection utilities with compile-time optimization

	// Two-value relocate: F4/VR vs NG
	template <class T>
	[[nodiscard]] FALLOUT_REL T Relocate(T&& a_f4AndVR, T&& a_ng) noexcept
	{
#ifndef ENABLE_FALLOUT_NG
		return a_f4AndVR;
#elif !defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_VR)
		return a_ng;
#else
		return IsNG() ? a_ng : a_f4AndVR;
#endif
	}

	// Three-value relocate: F4, NG, VR
	template <class T>
	[[nodiscard]] FALLOUT_REL T Relocate(T a_f4, T a_ng, T a_vr) noexcept
	{
#if defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR)
		switch (GetRuntime()) {
			case Runtime::NG:
				return a_ng;
			case Runtime::VR:
				return a_vr;
			default:
				return a_f4;
		}
#elif defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG)
		return IsNG() ? a_ng : a_f4;
#elif defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_VR)
		return IsVR() ? a_vr : a_f4;
#elif defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR)
		return IsVR() ? a_vr : a_ng;
#elif defined(ENABLE_FALLOUT_NG)
		return a_ng;
#elif defined(ENABLE_FALLOUT_VR)
		return a_vr;
#else
		return a_f4;
#endif
	}

	// VR-specific relocate: VR vs non-VR
	template <class T>
	[[nodiscard]] FALLOUT_REL_VR T RelocateVR(T&& a_nonVR, T&& a_vr) noexcept
	{
#ifndef ENABLE_FALLOUT_VR
		return a_nonVR;
#elif !defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_NG)
		return a_vr;
#else
		return IsVR() ? a_vr : a_nonVR;
#endif
	}
}