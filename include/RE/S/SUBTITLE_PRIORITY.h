#pragma once

namespace RE
{
	enum class SUBTITLE_PRIORITY : std::int32_t
	{
		kLow = 0x0,
		kNormal = 0x1,
		kHigh = 0x2,
		kForce = 0x3,
		kTotal = 0x4
	};
}
