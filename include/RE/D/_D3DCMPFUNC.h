#pragma once

namespace RE
{
	enum class _D3DCMPFUNC
	{
		kNever = 0x1,
		kLess = 0x2,
		kEqual = 0x3,
		kLessEqual = 0x4,
		kGreater = 0x5,
		kNotEqual = 0x6,
		kGreaterEqual = 0x7,
		kAlways = 0x8,
		kForce_DWORD = 0x7FFFFFFF
	};
}
