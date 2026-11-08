#pragma once

#if defined(ENABLE_FALLOUT_VR) && (defined(ENABLE_FALLOUT_NG) || defined(ENABLE_FALLOUT_F4))
/**
 * Defined to indicate that this build supports both VR and non-VR runtimes.
 */
#	define FALLOUT_CROSS_VR
#endif

#if !defined(ENABLE_FALLOUT_NG) || (!defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_VR))
/**
 * A macro which defines a modifier for expressions that vary by FALLOUT Address Library IDs.
 *
 * <p>
 * Currently defined as <code>constexpr</code> since this build only targets one family of Address Library.
 * </p>
 */
#	define FALLOUT_ADDR constexpr
#else
/**
 * A macro which defines a modifier for expressions that vary by FALLOUT address library IDs.
 *
 * <p>
 * Currently defined as <code>inline</code> to support multiple Address Library ID families dynamically.
 * </p>
 */
#	define FALLOUT_ADDR inline
#endif

#if (!defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_VR)) || (!defined(ENABLE_FALLOUT_F4) && !defined(ENABLE_FALLOUT_VR)) || (!defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_F4))
/**
 * A macro which defines a modifier for expressions that vary by the specific FALLOUT runtime.
 *
 * <p>
 * Currently defined as <code>constexpr</code> since this build is for only a single runtime.
 * </p>
 */
#	define FALLOUT_REL constexpr

/**
 * A macro which defines a modifier for expressions which may be <code>constexpr</code> when using selective targeting.
 *
 * <p>
 * Currently defined as <code>constexpr</code> since this build is for only a single runtime.
 * </p>
 */
#	define FALLOUT_REL_CONSTEXPR constexpr
#else
/**
 * A macro which defines a modifier for expressions that vary by the specific FALLOUT runtime.
 *
 * <p>
 * Currently defined as <code>inline</code> to support multiple runtimes dynamically.
 * </p>
 */
#	define FALLOUT_REL inline

/**
 * A macro which defines a modifier for expressions which may be <code>constexpr</code> when using selective targeting.
 *
 * <p>
 * Currently defined as empty to support multiple runtimes.
 * </p>
 */
#	define FALLOUT_REL_CONSTEXPR
#endif

#ifndef FALLOUT_CROSS_VR
/**
 * A macro which defines a modifier for expressions that vary between FALLOUT SE/AE and FALLOUT VR.
 *
 * <p>
 * Currently defined as <code>constexpr</code> since this build is only for VR or non-VR.
 * </p>
 */
#	define FALLOUT_REL_VR constexpr

/**
 * A macro which defines a modifier for expressions which may be <code>constexpr</code> when using selectively VR or non-VR.
 *
 * <p>
 * Currently defined as <code>constexpr</code> since this build is only for VR or non-VR.
 * </p>
 */
#	define FALLOUT_REL_VR_CONSTEXPR constexpr

/**
 * A macro which defines a modifier for functions which may be <code>virtual</code> when using selectively VR or non-VR.
 *
 * <p>
 * Currently defined as <code>virtual</code> since this build is only for VR or non-VR.
 * </p>
 */
#	define FALLOUT_REL_VR_VIRTUAL virtual
#else
/**
 * A macro which defines a modifier for expressions that vary between FALLOUT SE/AE and FALLOUT VR.
 *
 * <p>
 * Currently defined as <code>inline</code> since this build is for both VR and non-VR.
 * </p>
 */
#	define FALLOUT_REL_VR inline

/**
 * A macro which defines a modifier for expressions which may be <code>constexpr</code> when using selectively VR or non-VR.
 *
 * <p>
 * Currently defined as empty since this build is for both VR and non-VR.
 * </p>
 */
#	define FALLOUT_REL_VR_CONSTEXPR

/**
 * A macro which defines a modifier for functions which may be <code>virtual</code> when using selectively VR or non-VR.
 *
 * <p>
 * Currently defined as empty since this build is for both VR and non-VR.
 * </p>
 */
#	define FALLOUT_REL_VR_VIRTUAL
#endif
