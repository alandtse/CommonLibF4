#pragma once

#include <cstddef>  // For std::size_t

// F4-specific RelocationID configuration
// This must be included before any REL headers
//
// CommonLibF4-NG Runtime Configuration System
// ==========================================
//
// This file configures the multi-runtime RelocationID system for Fallout 4.
// It determines REL_DEFAULT_RUNTIME_COUNT based on enabled runtime defines:
//
// Single Runtime (REL_DEFAULT_RUNTIME_COUNT = 1):
//   - ENABLE_FALLOUT_F4 only: Pre-NG F4 v1.10.163
//   - ENABLE_FALLOUT_NG only: Next-Gen F4 v1.10.984+
//   - ENABLE_FALLOUT_VR only: VR F4 v1.2.x
//
// Dual Runtime (REL_DEFAULT_RUNTIME_COUNT = 2):
//   - F4 + NG: Traditional flat build (no VR)
//   - F4 + VR: Legacy support combination
//   - NG + VR: Modern support combination
//
// Triple Runtime (REL_DEFAULT_RUNTIME_COUNT = 3):
//   - F4 + NG + VR: Full compatibility (default)
//
// The shared commonlib-shared library uses these counts to instantiate
// appropriate RelocationID template specializations with smart fallback logic.
// Define REL_DEFAULT_RUNTIME_COUNT before shared library to avoid conflicts
#ifndef REL_DEFAULT_RUNTIME_COUNT

// Count enabled runtimes directly in preprocessor conditionals
#	if !defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_VR)
#		error "At least one Fallout runtime must be enabled (ENABLE_FALLOUT_F4, ENABLE_FALLOUT_NG, or ENABLE_FALLOUT_VR)"
#	elif (defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_VR)) || \
		(!defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_VR)) ||   \
		(!defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR))
// Single runtime build - optimize for specific version
#		define REL_DEFAULT_RUNTIME_COUNT 1
#		ifdef ENABLE_FALLOUT_F4
#			define REL_CURRENT_RUNTIME 0  // Pre-NG runtime index
#		elif defined(ENABLE_FALLOUT_NG)
#			define REL_CURRENT_RUNTIME 1  // NG runtime index
#		elif defined(ENABLE_FALLOUT_VR)
#			define REL_CURRENT_RUNTIME 0  // VR shares Pre-NG IDs (traditional)
#		endif
#	elif (defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_VR)) || \
		(defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR)) ||   \
		(!defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR))
// Two runtimes enabled - use 2-runtime system
#		define REL_DEFAULT_RUNTIME_COUNT 2
// Runtime determined at load time
#	else
// All three runtimes enabled - use 3-runtime system with VR fallback to Pre-NG
#		define REL_DEFAULT_RUNTIME_COUNT 3
// Runtime determined at load time
#	endif

#endif  // REL_DEFAULT_RUNTIME_COUNT

// Runtime count macro for C++ code (safe to use in expressions, not preprocessor conditionals)
#define F4_RUNTIME_COUNT                       \
	(defined(ENABLE_FALLOUT_F4) ? 1 : 0) +     \
		(defined(ENABLE_FALLOUT_NG) ? 1 : 0) + \
		(defined(ENABLE_FALLOUT_VR) ? 1 : 0)

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