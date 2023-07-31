#include "F4SE/Logger.h"

namespace F4SE::log
{
	std::optional<std::filesystem::path> log_directory()
	{
		wchar_t* buffer{ nullptr };
		const auto result = WinAPI::SHGetKnownFolderPath(WinAPI::FOLDERID_Documents, WinAPI::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
		std::unique_ptr<wchar_t[], decltype(&WinAPI::CoTaskMemFree)> knownPath(buffer, WinAPI::CoTaskMemFree);
		if (!knownPath || result != 0) {
			error("failed to get known folder path"sv);
			return std::nullopt;
		}

		std::filesystem::path path = knownPath.get();
		path /= REL::Module::IsF4() ? "My Games/Fallout4/F4SE"sv : "My Games/Fallout4VR/F4SE"sv;
		return path;
	}
}
