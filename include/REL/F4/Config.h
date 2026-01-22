#pragma once

#include <cstddef>

// F4-specific RelocationID configuration
// This must be included before any REL headers from commonlib-shared
//
// REL_DEFAULT_RUNTIME_COUNT is now defined by XMake build system
// based on enabled runtime configurations
//
// Supported configurations:
//   - Single Runtime (REL_DEFAULT_RUNTIME_COUNT = 1): F4, NG, VR, or AE only
//   - Dual Runtime (REL_DEFAULT_RUNTIME_COUNT = 2): F4+NG, F4+VR, F4+AE, NG+AE, VR+AE, etc.
//   - Triple Runtime (REL_DEFAULT_RUNTIME_COUNT = 3): F4+NG+VR, F4+NG+AE, etc.
//   - Quad Runtime (REL_DEFAULT_RUNTIME_COUNT = 4): F4+NG+VR+AE (full support)

// Validate that REL_DEFAULT_RUNTIME_COUNT is properly defined by build system
#ifndef REL_DEFAULT_RUNTIME_COUNT
#	error "REL_DEFAULT_RUNTIME_COUNT must be defined by the build system (XMake)"
#endif

// Validate that at least one runtime is enabled
#if !defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_VR) && !defined(ENABLE_FALLOUT_AE)
#	error "At least one Fallout runtime must be enabled (ENABLE_FALLOUT_F4, ENABLE_FALLOUT_NG, ENABLE_FALLOUT_VR, or ENABLE_FALLOUT_AE)"
#endif

// Runtime count macro for C++ code (safe to use in expressions, not preprocessor conditionals)
#define F4_RUNTIME_COUNT                       \
	(defined(ENABLE_FALLOUT_F4) ? 1 : 0) +     \
		(defined(ENABLE_FALLOUT_NG) ? 1 : 0) + \
		(defined(ENABLE_FALLOUT_VR) ? 1 : 0) + \
		(defined(ENABLE_FALLOUT_AE) ? 1 : 0)

// F4-specific runtime indices
namespace REL::F4
{
	enum RuntimeIndex : std::size_t
	{
		PRE_NG_VR = 0,  // Pre-NG and VR share same IDs (historical)
		NG = 1          // Next-Gen has separate IDs
	};

	// Alternative 3-runtime mode for explicit VR support
	enum RuntimeIndex3 : std::size_t
	{
		PRE_NG = 0,  // Pre-NG only
		NG_3 = 1,    // Next-Gen
		VR = 2       // VR explicit (when different from Pre-NG)
	};

	// 4-runtime mode for full support (F4, NG, VR, AE)
	enum RuntimeIndex4 : std::size_t
	{
		PRE_NG_4 = 0,  // Pre-NG Fallout 4 (1.10.163)
		NG_4 = 1,      // Next-Gen (1.10.984+)
		VR_4 = 2,      // VR (1.2.x)
		AE_4 = 3       // Anniversary Edition (1.11.137+)
	};
}

// Forward declare the runtime detection function that REL::RelocationID will use
namespace REL
{
	// Implementation in F4SE or a dedicated source file
	[[nodiscard]] std::size_t get_runtime_index() noexcept;
}

// F4-specific fallback configuration for RelocationID
// This tells the system how to handle VR fallbacks
#define REL_F4_VR_FALLBACK_TO_PRE_NG 1

// F4-specific runtime mapping for fallback logic
namespace REL::F4::Fallback
{
	// Map VR runtime index to Pre-NG for fallback purposes
	constexpr std::size_t VR_FALLBACK_INDEX = 0;  // VR falls back to Pre-NG (index 0)

	// Function to get the fallback index for a given runtime
	constexpr std::size_t get_fallback_index(std::size_t a_runtime_index) noexcept
	{
#ifdef ENABLE_FALLOUT_VR
		// If VR is enabled and this is the VR runtime, fall back to Pre-NG
		if (a_runtime_index == 2) {  // VR index in 3-runtime mode
			return VR_FALLBACK_INDEX;
		}
#endif
		return a_runtime_index;  // No fallback for other runtimes
	}
}