#pragma once

#include "REL/Common.h"
#include <REL/Version.h>

namespace REL::F4
{
	// Forward declarations
	Runtime     detect_runtime() noexcept;
	std::size_t get_runtime_index() noexcept;

	// Implementation functions
	[[nodiscard]] bool    IsVR() noexcept;
	[[nodiscard]] bool    IsNG() noexcept;
	[[nodiscard]] bool    IsF4() noexcept;
	[[nodiscard]] Runtime GetRuntime() noexcept;
}