#pragma once

// F4-specific Module extensions
// This header extends the shared REL::Module with F4-specific functionality
//
// CommonLibF4-NG Module Runtime Detection API
// ==========================================
//
// Provides F4-specific runtime detection functions that maintain API compatibility
// with downstream libraries expecting CommonLibSSE-NG patterns.
//
// Functions provided:
//   - REL::IsVR(): Returns true if current runtime is Fallout 4 VR
//   - REL::IsNG(): Returns true if current runtime is Next-Gen Update
//   - REL::IsF4(): Returns true if current runtime is Pre-NG F4
//   - REL::GetRuntime(): Returns F4::Runtime enum value
//
// Compatibility aliases:
//   - REL::IsAE(): Alias for IsNG() (Anniversary Edition → Next-Gen equivalent)
//   - REL::IsSE(): Alias for IsF4() (Special Edition → Pre-NG equivalent)
//
// All functions forward to F4-specific implementations in REL::F4 namespace
// while keeping game-specific logic separate from the shared library.

#include "REL/Common.h"  // For F4 runtime functions
#include <REL/Module.h>  // Include shared Module
namespace REL
{
	/**
     * Returns whether the current FALLOUT runtime is a FALLOUT VR release.
     */
	[[nodiscard]] inline bool IsVR() noexcept
	{
		return F4::IsVR();
	}

	/**
     * Returns whether the current FALLOUT runtime is a post-Nextgen Update Fallout release.
     */
	[[nodiscard]] inline bool IsNG() noexcept
	{
		return F4::IsNG();
	}

	/**
     * Returns whether the current FALLOUT runtime is a pre-Nextgen Update Fallout release.
     */
	[[nodiscard]] inline bool IsF4() noexcept
	{
		return F4::IsF4();
	}

	/**
     * Get the type of runtime the currently-loaded FALLOUT module is.
     */
	[[nodiscard]] inline F4::Runtime GetRuntime() noexcept
	{
		return F4::GetRuntime();
	}

	// SSE compatibility aliases for cross-game library support
	[[nodiscard]] inline bool IsAE() noexcept { return IsNG(); }  // AE equivalent to NG
	[[nodiscard]] inline bool IsSE() noexcept { return IsF4(); }  // SE equivalent to Pre-NG
}