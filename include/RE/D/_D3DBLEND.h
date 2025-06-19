#pragma once

namespace RE
{
	enum class _D3DBLEND
	{
		kZero = 0x1,
		kOne = 0x2,
		kSrcColor = 0x3,
		kInvSrcColor = 0x4,
		kSrcAlpha = 0x5,
		kInvSrcAlpha = 0x6,
		kDestAlpha = 0x7,
		kInvDestAlpha = 0x8,
		kDestColor = 0x9,
		kInvDestColor = 0xA,
		kSrcAlphaSat = 0xB,
		kBothSrcAlpha = 0xC,
		kBothInvSrcAlpha = 0xD,
		kBlendFactor = 0xE,
		kInvBlendFactor = 0xF,
		kSrcColor2 = 0x10,
		kInvSrcColor2 = 0x11,
		kForce_DWORD = 0x7FFFFFFF
	};
}
