#include "REL/IDDB.h"
#include "REL/Common.h"
#include "REL/Module.h"

#include <filesystem>
#include <format>

namespace REL::F4
{
#ifdef ENABLE_FALLOUT_VR
	// F4-specific VR Address Library version tracking
	static REL::Version s_vrAddressLibraryVersion{};

	bool IsVRAddressLibraryAtLeastVersion(const char* a_minVersion, bool a_reportAndFail)
	{
		const auto minimalVersion = REL::ParseVersionString(a_minVersion);
		if (!minimalVersion) {
			throw std::runtime_error(std::format("Invalid version string: {}", a_minVersion));
		}

		if (*minimalVersion <= s_vrAddressLibraryVersion) {
			return true;
		}

		if (a_reportAndFail) {
			throw std::runtime_error(std::format(
				"VR Address Library version {} is older than required {}",
				s_vrAddressLibraryVersion.string(),
				minimalVersion->string()));
		}

		return false;
	}

	const REL::Version& GetVRAddressLibraryVersion()
	{
		return s_vrAddressLibraryVersion;
	}

	void SetVRAddressLibraryVersion(const REL::Version& a_version)
	{
		s_vrAddressLibraryVersion = a_version;
	}
#endif

	std::string get_database_path()
	{
		const auto module = REL::Module::GetSingleton();
		if (!module) {
			throw std::runtime_error("Module not initialized");
		}

		const auto version = module->version();
		const auto runtime = F4::GetRuntime();

		// F4-specific path logic: VR uses CSV, others use binary
		const char* extension = (runtime == Runtime::VR) ? "csv" : "bin";

		// Format: Data/F4SE/Plugins/version-1.10.163.csv or version-1.10.980.bin
		return std::format("Data/F4SE/Plugins/version-{}.{}",
			version.string("-"),
			extension);
	}
}