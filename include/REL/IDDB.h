#pragma once

#include "REL/Common.h"
#include <REL/IDDB.h>
#include <string>

// F4-specific IDDB extensions
namespace REL::F4
{
	// F4-specific database path resolution
	[[nodiscard]] std::string get_database_path();

	// Wrapper around shared IDDB::offset for F4-specific usage
	[[nodiscard]] inline std::size_t id2offset(std::uint64_t a_id) noexcept
	{
		const auto iddb = REL::IDDB::GetSingleton();
		return iddb ? static_cast<std::size_t>(iddb->offset(a_id)) : 0;
	}

#ifdef ENABLE_FALLOUT_VR
	// VR Address Library version checking (F4 VR specific)
	[[nodiscard]] bool                IsVRAddressLibraryAtLeastVersion(const char* a_minVersion, bool a_reportAndFail = true);
	[[nodiscard]] const REL::Version& GetVRAddressLibraryVersion();
	void                              SetVRAddressLibraryVersion(const REL::Version& a_version);
#endif
}