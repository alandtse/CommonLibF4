#pragma once

// F4-specific Module singleton implementation
// This header provides a F4-specific Module singleton that delegates to the shared library Module

#include "REX/REX/Singleton.h"
#include <REL/Module.h>  // Include shared Module

namespace REL
{
	namespace F4
	{
		// F4-specific Module singleton that delegates to the shared library Module
		class Module : public REX::Singleton<Module>
		{
		public:
			Module() = default;

			[[nodiscard]] constexpr std::uintptr_t base() const noexcept
			{
				return REL::Module::GetSingleton()->base();
			}

			[[nodiscard]] std::wstring_view filename() const noexcept
			{
				return REL::Module::GetSingleton()->filename();
			}

			[[nodiscard]] constexpr Segment segment(Segment::Name a_segment) const noexcept
			{
				return REL::Module::GetSingleton()->segment(a_segment);
			}

			[[nodiscard]] constexpr Version version() const noexcept
			{
				return REL::Module::GetSingleton()->version();
			}

			constexpr void version(Version a_version) noexcept
			{
				REL::Module::GetSingleton()->version(a_version);
			}

			[[nodiscard]] void* pointer() const noexcept
			{
				return REL::Module::GetSingleton()->pointer();
			}

			template <class T>
			[[nodiscard]] T* pointer() const noexcept
			{
				return REL::Module::GetSingleton()->template pointer<T>();
			}
		};
	}
}