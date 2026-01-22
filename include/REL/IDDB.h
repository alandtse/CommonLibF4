#pragma once

#include <REL/IDDB.h>
#include <REL/Version.h>
#include <string>

// F4-specific IDDB extensions
namespace REL::F4
{
	// F4-specific database path resolution
	[[nodiscard]] std::string get_database_path();

	// Wrapper around shared IDDB::offset for F4-specific usage
	[[nodiscard]] inline std::size_t id2offset(std::uint64_t a_id) noexcept
	{
		return static_cast<std::size_t>(REL::detail::get_id_offset(a_id));
	}

#ifdef ENABLE_FALLOUT_VR
	// VR Address Library version checking (F4 VR specific)
	[[nodiscard]] bool                IsVRAddressLibraryAtLeastVersion(const char* a_minVersion, bool a_reportAndFail = true);
	[[nodiscard]] const REL::Version& GetVRAddressLibraryVersion();
	void                              SetVRAddressLibraryVersion(const REL::Version& a_version);
#endif
}