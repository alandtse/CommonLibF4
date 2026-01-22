#pragma once

// Include F4-specific configuration before commonlib-shared library use to set values
#include "REL/F4/Config.h"

#include <REL/REL.h>
#include <REX/REX.h>

// Include F4-specific extensions after shared library
#include "REL/F4/Module.h"
#include "REL/F4/Runtime.h"
#include "REL/IDDB.h"

namespace F4SE
{
	using namespace std::literals;
}

namespace RE
{
	using namespace std::literals;
}

namespace Scaleform
{
	using namespace std::literals;
}

#include "RE/IDs.h"
#include "RE/IDs_NiRTTI.h"
#include "RE/IDs_RTTI.h"
#include "RE/IDs_VTABLE.h"

#include "RE/B/BSCoreTypes.h"
