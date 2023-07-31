#include "REL/Relocation.h"

namespace REL
{
	namespace detail
	{
		bool memory_map::open(stl::zwstring a_name, std::size_t a_size)
		{
			close();

			_mapping = WinAPI::OpenFileMapping(
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				false,
				a_name.data());
			if (!_mapping) {
				close();
				return false;
			}

			_view = WinAPI::MapViewOfFile(
				_mapping,
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				0,
				0,
				a_size);
			if (!_view) {
				close();
				return false;
			}

			return true;
		}

		bool memory_map::create(stl::zwstring a_name, std::size_t a_size)
		{
			close();

			WinAPI::ULARGE_INTEGER bytes;
			bytes.quadPart = a_size;

			_mapping = WinAPI::OpenFileMapping(
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				false,
				a_name.data());
			if (!_mapping) {
				_mapping = WinAPI::CreateFileMapping(
					WinAPI::INVALID_HANDLE_VALUE,
					nullptr,
					WinAPI::PAGE_READWRITE,
					bytes.highPart,
					bytes.lowPart,
					a_name.data());
				if (!_mapping) {
					return false;
				}
			}

			_view = WinAPI::MapViewOfFile(
				_mapping,
				WinAPI::FILE_MAP_READ | WinAPI::FILE_MAP_WRITE,
				0,
				0,
				bytes.quadPart);
			if (!_view) {
				return false;
			}

			return true;
		}

		void memory_map::close()
		{
			if (_view) {
				WinAPI::UnmapViewOfFile(static_cast<const void*>(_view));
				_view = nullptr;
			}

			if (_mapping) {
				WinAPI::CloseHandle(_mapping);
				_mapping = nullptr;
			}
		}
	}

	Module Module::_instance;

	void Module::load_segments()
	{
		auto dosHeader = reinterpret_cast<const WinAPI::IMAGE_DOS_HEADER*>(_base);
		auto ntHeader = stl::adjust_pointer<WinAPI::IMAGE_NT_HEADERS64>(dosHeader, dosHeader->lfanew);
		const auto* sections = WinAPI::IMAGE_FIRST_SECTION(ntHeader);
		const auto size = std::min<std::size_t>(ntHeader->fileHeader.numberOfSections, _segments.size());
		for (std::size_t i = 0; i < size; ++i) {
			const auto& section = sections[i];
			const auto it = std::find_if(
				SEGMENTS.begin(),
				SEGMENTS.end(),
				[&](auto&& a_elem) {
					constexpr auto size = std::extent_v<decltype(section.name)>;
					const auto len = (std::min)(a_elem.first.size(), size);
					return std::memcmp(a_elem.first.data(), section.name, len) == 0 &&
				           (section.characteristics & a_elem.second) == a_elem.second;
				});
			if (it != SEGMENTS.end()) {
				const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
				_segments[idx] = Segment{ _base, _base + section.virtualAddress, section.misc.virtualSize };
			}
		}
	}

	void Module::clear()
	{
		if (_injectedModule) {
			WinAPI::FreeLibrary(_injectedModule);
			_injectedModule = nullptr;
		}
		_base = 0;
		_filename.clear();
		_filePath.clear();
		_runtime = Runtime::F4;
		_version = { 0, 0, 0, 0 };
		for (auto& segment : _segments) {
			segment = {};
		}
		IDDatabase::_instance.clear();
		IDDatabase::_initialized = false;
	}

	IDDatabase IDDatabase::_instance;
}
