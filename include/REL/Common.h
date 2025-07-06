#pragma once

// F4-specific runtime configuration macros
// Based on original implementation but adapted for new RelocationID system

// Check if VR support crosses with other runtimes
#if defined(ENABLE_FALLOUT_VR) && (defined(ENABLE_FALLOUT_F4) || defined(ENABLE_FALLOUT_NG))
#	define FALLOUT_CROSS_VR
#endif

// Conditional compilation helpers
#if defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR)
// All three runtimes enabled - runtime selection needed
#	define FALLOUT_ADDR inline
#	define FALLOUT_REL inline
#	define FALLOUT_REL_VR inline
#elif (defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG)) || \
	(defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_VR)) ||   \
	(defined(ENABLE_FALLOUT_NG) && defined(ENABLE_FALLOUT_VR))
// Two runtimes enabled - runtime selection needed
#	define FALLOUT_ADDR inline
#	define FALLOUT_REL inline
#	ifdef FALLOUT_CROSS_VR
#		define FALLOUT_REL_VR inline
#	else
#		define FALLOUT_REL_VR constexpr
#	endif
#else
// Single runtime enabled - compile-time optimization
#	define FALLOUT_ADDR constexpr
#	define FALLOUT_REL constexpr
#	define FALLOUT_REL_VR constexpr
#endif

// Runtime type enumeration (F4-specific)
namespace REL::F4
{
	enum class Runtime : std::uint8_t
	{
		Unknown = 0,
		NG = 1 << 0,  // Next Gen Update (≥ v1.10.980)
		F4 = 1 << 1,  // Pre-NG (≤ v1.10.163)
		VR = 1 << 2   // Fallout VR (v1.2.x)
	};

	// Runtime convenience functions
	[[nodiscard]] Runtime GetRuntime() noexcept;
	[[nodiscard]] bool    IsNG() noexcept;
	[[nodiscard]] bool    IsF4() noexcept;
	[[nodiscard]] bool    IsVR() noexcept;

	// Runtime index function for shared library
	[[nodiscard]] std::size_t get_runtime_index() noexcept;
}

// Extend REL::Module with F4-specific runtime detection for downstream compatibility
namespace REL
{
	class Module;

	// F4-specific Module extensions for CommonLibSSE-NG compatibility
	// These forward to F4-specific implementations
	namespace ModuleExtensions
	{
		// Primary runtime detection functions
		[[nodiscard]] inline bool IsVR() noexcept { return F4::IsVR(); }
		[[nodiscard]] inline bool IsNG() noexcept { return F4::IsNG(); }
		[[nodiscard]] inline bool IsF4() noexcept { return F4::IsF4(); }

		// SSE compatibility aliases
		[[nodiscard]] inline bool IsAE() noexcept { return F4::IsNG(); }  // AE equivalent to NG
		[[nodiscard]] inline bool IsSE() noexcept { return F4::IsF4(); }  // SE equivalent to Pre-NG
	}
}

// Make Module runtime detection available as if they were Module member functions
// This provides downstream compatibility with CommonLibSSE-NG patterns
namespace REL
{
	// Standalone functions that can be called as REL::IsVR(), etc.
	using ModuleExtensions::IsAE;
	using ModuleExtensions::IsF4;
	using ModuleExtensions::IsNG;
	using ModuleExtensions::IsSE;
	using ModuleExtensions::IsVR;
}