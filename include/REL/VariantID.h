#pragma once

#include "REL/Common.h"
#include "REL/IDDB.h"
#include "REL/Module.h"

// Include the shared VariantID implementation
#include <REL/VariantID.h>

namespace REL::F4
{
	// Thin wrapper around shared VariantID with F4-specific features
	//
	// Backward compatibility: All existing F4::VariantID usage continues to work
	// New capabilities: Template-based with smart fallback from shared implementation
	// F4-specific: Direct offset support for VR, F4 runtime detection
	//
	// Usage examples:
	//   // Traditional 2-runtime (Pre-NG+VR share, NG separate)
	//   F4::VariantID2 MyFunc{ 187096, 2230121 };
	//
	//   // 3-runtime with explicit VR support
	//   F4::VariantID3 MyFunc{ 187096, 2230121, 0x12345678 };  // VR uses direct offset
	//
	//   // VR falls back to Pre-NG (zero value)
	//   F4::VariantID3 MyFunc{ 187096, 2230121, 0 };
	template <std::size_t N>
	class VariantID : public REL::VariantID<N>
	{
	public:
		using Base = REL::VariantID<N>;

		// Inherit all constructors from base
		using Base::VariantID;

		// F4-specific: Get address with runtime detection
		[[nodiscard]] std::uintptr_t address() const
		{
			const auto mod = Module::GetSingleton();
			return mod->base() + offset();
		}

		// F4-specific: Get offset with direct offset support for VR
		[[nodiscard]] std::size_t offset() const
		{
			const auto runtime = F4::GetRuntime();
			const auto runtime_index = static_cast<std::size_t>(runtime);
			const auto id_or_offset = this->get(runtime_index);

			switch (runtime) {
				case Runtime::NG:
				case Runtime::F4:
					// Use Address Library for F4/NG
					if (id_or_offset != 0) {
						return IDDB::id2offset(id_or_offset);
					}
					break;

				case Runtime::VR:
					// VR can use direct offset or fall back to Address Library
					if (id_or_offset != 0) {
						// Check if this looks like a direct offset (large number)
						if (id_or_offset > 0x10000) {
							return static_cast<std::size_t>(id_or_offset);
						} else {
							// Treat as ID and look up
							return IDDB::id2offset(id_or_offset);
						}
					}
					break;

				default:
					break;
			}

			// Fallback to F4 ID
			const auto f4_id = this->get(0);  // First runtime (Pre-NG)
			if (f4_id != 0) {
				return IDDB::id2offset(f4_id);
			}

			return 0;
		}

		// F4-specific: Get ID with runtime detection
		[[nodiscard]] std::uint64_t id() const noexcept
		{
			const auto runtime = F4::GetRuntime();
			const auto runtime_index = static_cast<std::size_t>(runtime);
			return this->get(runtime_index);
		}

		// Expose shared API methods for consistency
		using Base::get;
		using Base::raw;

		// Additional convenience methods for F4-specific usage

		// Get ID for specific runtime with F4 runtime mapping
		[[nodiscard]] std::uint64_t get_for_runtime(Runtime a_runtime) const noexcept
		{
			const auto runtime_index = static_cast<std::size_t>(a_runtime);
			return this->get(runtime_index);
		}

		// Check if a specific runtime has an explicit ID (not using fallback)
		[[nodiscard]] constexpr bool has_explicit_id(Runtime a_runtime) const noexcept
		{
			const auto runtime_index = static_cast<std::size_t>(a_runtime);
			return this->raw(runtime_index) != 0;
		}

		// Get raw ID for specific runtime (before fallback resolution)
		[[nodiscard]] constexpr std::uint64_t raw_id(Runtime a_runtime) const noexcept
		{
			const auto runtime_index = static_cast<std::size_t>(a_runtime);
			return this->raw(runtime_index);
		}

		// F4-specific: Get offset for specific runtime
		[[nodiscard]] std::size_t offset_for_runtime(Runtime a_runtime) const
		{
			const auto id_or_offset = this->get_for_runtime(a_runtime);

			switch (a_runtime) {
				case Runtime::NG:
				case Runtime::F4:
					// Use Address Library for F4/NG
					if (id_or_offset != 0) {
						return IDDB::id2offset(id_or_offset);
					}
					break;

				case Runtime::VR:
					// VR can use direct offset or fall back to Address Library
					if (id_or_offset != 0) {
						// Check if this looks like a direct offset (large number)
						if (id_or_offset > 0x10000) {
							return static_cast<std::size_t>(id_or_offset);
						} else {
							// Treat as ID and look up
							return IDDB::id2offset(id_or_offset);
						}
					}
					break;

				default:
					break;
			}

			return 0;
		}
	};

	// Convenience aliases for common F4 patterns
	using VariantID2 = VariantID<2>;  // Pre-NG+VR, NG
	using VariantID3 = VariantID<3>;  // Pre-NG, NG, VR (explicit)
}