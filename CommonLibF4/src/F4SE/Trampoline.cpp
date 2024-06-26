#include "F4SE/Trampoline.h"

#include "F4SE/Logger.h"

#ifdef F4SE_SUPPORT_XBYAK
#	include <xbyak/xbyak.h>
#endif
#undef max

namespace F4SE
{
#ifdef F4SE_SUPPORT_XBYAK
	void* Trampoline::allocate(const Xbyak::CodeGenerator& a_code)
	{
		auto result = do_allocate(a_code.getSize());
		log_stats();
		std::memcpy(result, a_code.getCode(), a_code.getSize());
		return result;
	}
#endif

	// https://stackoverflow.com/a/54732489
	void* Trampoline::do_create(std::size_t a_size, std::uintptr_t a_address)
	{
		constexpr std::size_t gigabyte = static_cast<std::size_t>(1) << 30;
		constexpr std::size_t minRange = gigabyte * 2;
		constexpr std::uintptr_t maxAddr = std::numeric_limits<std::uintptr_t>::max();

		WinAPI::SYSTEM_INFO si;
		WinAPI::GetSystemInfo(&si);
		std::uint32_t granularity = si.dwAllocationGranularity;

		std::uintptr_t min = a_address >= minRange ? detail::roundup(a_address - minRange, granularity) : 0;
		const std::uintptr_t max = a_address < (maxAddr - minRange) ? detail::rounddown(a_address + minRange, granularity) : maxAddr;
		std::uintptr_t addr;

		WinAPI::MEMORY_BASIC_INFORMATION mbi;
		do {
			if (!WinAPI::VirtualQuery(reinterpret_cast<void*>(min), std::addressof(mbi), sizeof(mbi))) {
				log::error(FMT_STRING("VirtualQuery failed with code: 0x{:08X}"), WinAPI::GetLastError());
				return nullptr;
			}

			auto baseAddr = reinterpret_cast<std::uintptr_t>(mbi.baseAddress);
			min = baseAddr + mbi.regionSize;

			if (mbi.state == MEM_FREE) {
				addr = detail::roundup(baseAddr, granularity);

				// if rounding didn't advance us into the next region and the region is the required size
				if (addr < min && (min - addr) >= a_size) {
					auto mem = WinAPI::VirtualAlloc(reinterpret_cast<void*>(addr), a_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
					if (mem) {
						return mem;
					} else {
						log::warn(FMT_STRING("VirtualAlloc failed with code: 0x{:08X}"), WinAPI::GetLastError());
					}
				}
			}
		} while (min < max);

		return nullptr;
	}

	void Trampoline::log_stats() const
	{
		auto pct = (static_cast<double>(_size) / static_cast<double>(_capacity)) * 100.0;
		log::debug(
			FMT_STRING("{} => {}B / {}B ({:05.2f}%)"),
			_name,
			_size,
			_capacity,
			pct);
	}
}
