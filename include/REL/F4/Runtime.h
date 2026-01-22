#pragma once

#include <REL/Version.h>

namespace REL::F4
{
	// F4 runtime variants
	enum class Runtime
	{
		Unknown,  // Unknown runtime
		F4,       // Pre-NG Fallout 4 (1.10.163)
		NG,       // Next-Gen Fallout 4 (1.10.984+)
		VR,       // Fallout 4 VR (1.2.x)
		AE        // Anniversary Edition (1.11.137+)
	};

	// Forward declarations
	Runtime     detect_runtime() noexcept;
	std::size_t get_runtime_index() noexcept;

	// Implementation functions
	[[nodiscard]] bool    IsVR() noexcept;
	[[nodiscard]] bool    IsNG() noexcept;
	[[nodiscard]] bool    IsF4() noexcept;
	[[nodiscard]] bool    IsAE() noexcept;
	[[nodiscard]] Runtime GetRuntime() noexcept;
}