#pragma once

// F4-specific REL system
// Include this header to get full F4 REL functionality

// Must include Config.h first to set up RelocationID configuration
#include "REL/Config.h"

// Core REL functionality (from commonlib-shared)
// These are already included via PCH.h -> REL/REL.h from commonlib-shared

// F4-specific REL extensions
#include "REL/Common.h"
#include "REL/IDDB.h"
#include "REL/Module.h"  // F4-specific Module extensions with IsVR(), etc.
#include "REL/Relocate.h"
#include "REL/VariantID.h"