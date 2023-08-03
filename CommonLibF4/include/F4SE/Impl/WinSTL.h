#pragma once

namespace F4SE::WinSTL
{
	inline std::string GetEnvironmentVariable(
		std::string_view a_name,
		std::size_t a_maxSize = 1024u)
	{
		if (a_name.empty() || !a_maxSize)
			return {};

		std::string buffer(a_maxSize + 1, 0);
		const auto result = WinAPI::GetEnvironmentVariable(
			a_name.data(),
			buffer.data(),
			static_cast<std::uint32_t>(a_maxSize));

		return { buffer.c_str() };
	}

	inline std::wstring GetEnvironmentVariable(
		std::wstring_view a_name,
		std::size_t a_maxSize = 1024u)
	{
		if (a_name.empty() || !a_maxSize)
			return {};

		std::wstring buffer(a_maxSize + 1, 0);
		const auto result = WinAPI::GetEnvironmentVariable(
			a_name.data(),
			buffer.data(),
			static_cast<std::uint32_t>(a_maxSize));

		return { buffer.c_str() };
	}
}
