#pragma once

#include "RE/N/NiPointer.h"

namespace RE
{
	class BSLight;
	class NiLight;

	class REFR_LIGHT
	{
	public:
		// members
		NiPointer<NiLight> light;       // 00
		NiPointer<BSLight> BSLight;     // 08
		float              wantDimmer;  // 10
	};
	static_assert(sizeof(REFR_LIGHT) == 0x18);
}
