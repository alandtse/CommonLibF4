#include "REL/F4/Config.h"
#include "REL/F4/Module.h"
#include <REL/Module.h>

#include <array>
#include <filesystem>

namespace REL
{
	namespace F4
	{
		// F4-specific executable detection
		static constexpr std::array<std::wstring_view, 2> RUNTIMES{
			L"Fallout4VR.exe",
			L"Fallout4.exe"
		};

		// Cached runtime detection
		static Runtime g_runtime = Runtime::Unknown;

		Runtime detect_runtime() noexcept
		{
			if (g_runtime != Runtime::Unknown) {
				return g_runtime;
			}

			try {
				// Check for VR first
				if (std::filesystem::exists("Fallout4VR.exe")) {
					g_runtime = Runtime::VR;
					return g_runtime;
				}

				// Check for standard F4
				if (std::filesystem::exists("Fallout4.exe")) {
					// Get module version to distinguish F4 vs NG vs AE
					const auto module = Module::GetSingleton();
					if (module) {
						const auto version = module->version();
						// AE is version 1.11.137 and above
						if (version.major() == 1 && version.minor() == 11 && version.patch() >= 137) {
							g_runtime = Runtime::AE;
						}
						// NG is version 1.10.980 and above (but below AE)
						else if (version.major() == 1 && version.minor() == 10 && version.patch() >= 980) {
							g_runtime = Runtime::NG;
						} else {
							g_runtime = Runtime::F4;
						}
						return g_runtime;
					}
				}

// Fallback based on enabled features
#if defined(ENABLE_FALLOUT_AE)
				g_runtime = Runtime::AE;
#elif defined(ENABLE_FALLOUT_VR)
				g_runtime = Runtime::VR;
#elif defined(ENABLE_FALLOUT_NG)
				g_runtime = Runtime::NG;
#elif defined(ENABLE_FALLOUT_F4)
				g_runtime = Runtime::F4;
#else
				g_runtime = Runtime::Unknown;
#endif

			} catch (...) {
// Exception during detection - use build defaults
#if defined(ENABLE_FALLOUT_AE)
				g_runtime = Runtime::AE;
#elif defined(ENABLE_FALLOUT_VR)
				g_runtime = Runtime::VR;
#elif defined(ENABLE_FALLOUT_NG)
				g_runtime = Runtime::NG;
#else
				g_runtime = Runtime::F4;
#endif
			}

			return g_runtime;
		}

		Runtime GetRuntime() noexcept
		{
			return detect_runtime();
		}

		bool IsNG() noexcept
		{
			return detect_runtime() == Runtime::NG;
		}

		bool IsF4() noexcept
		{
			return detect_runtime() == Runtime::F4;
		}

		bool IsVR() noexcept
		{
			return detect_runtime() == Runtime::VR;
		}

		bool IsAE() noexcept
		{
			return detect_runtime() == Runtime::AE;
		}
	}

	std::size_t get_runtime_index() noexcept
	{
#ifdef REL_CURRENT_RUNTIME
		// Single runtime build - use compile-time constant
		return REL_CURRENT_RUNTIME;
#else
		// Multi-runtime build - detect at runtime
		static std::size_t cached_index = []() -> std::size_t {
			const auto runtime = F4::GetRuntime();

#	if defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR) && defined(ENABLE_FALLOUT_AE)
			// Four runtime build (full support)
			switch (runtime) {
				case F4::Runtime::F4:
					return F4::RuntimeIndex4::PRE_NG_4;
				case F4::Runtime::NG:
					return F4::RuntimeIndex4::NG_4;
				case F4::Runtime::VR:
					return F4::RuntimeIndex4::VR_4;
				case F4::Runtime::AE:
					return F4::RuntimeIndex4::AE_4;
				default:
					return F4::RuntimeIndex4::PRE_NG_4;
			}
#	elif defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR)
			// Three runtime build
			switch (runtime) {
				case F4::Runtime::F4:
					return F4::RuntimeIndex3::PRE_NG;
				case F4::Runtime::NG:
					return F4::RuntimeIndex3::NG_3;
				case F4::Runtime::VR:
					return F4::RuntimeIndex3::VR;
				default:
					return F4::RuntimeIndex3::PRE_NG;
			}
#	elif defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG)
			// Two runtime build (traditional)
			switch (runtime) {
				case F4::Runtime::NG:
					return F4::RuntimeIndex::NG;
				default:
					return F4::RuntimeIndex::PRE_NG_VR;  // F4 and VR share
			}
#	elif defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_VR)
			// F4 + VR build
			switch (runtime) {
				case F4::Runtime::VR:
					return 1;
				default:
					return 0;
			}
#	elif defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR)
			// NG + VR build
			switch (runtime) {
				case F4::Runtime::VR:
					return 1;
				default:
					return 0;
			}
#	elif defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_AE)
			// F4 + AE build
			switch (runtime) {
				case F4::Runtime::AE:
					return 1;
				default:
					return 0;
			}
#	elif defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_AE)
			// NG + AE build
			switch (runtime) {
				case F4::Runtime::AE:
					return 1;
				default:
					return 0;
			}
#	elif defined(ENABLE_FALLOUT_VR) && defined(ENABLE_FALLOUT_AE)
			// VR + AE build
			switch (runtime) {
				case F4::Runtime::AE:
					return 1;
				default:
					return 0;
			}
#	else
			// Single runtime build - shouldn't reach here due to REL_CURRENT_RUNTIME
			return 0;
#	endif
		}();

		return cached_index;
#endif
	}
}