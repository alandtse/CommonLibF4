#pragma once

#include "RE/Bethesda/BSResource/BSResourceEnums.h"
#include "RE/Bethesda/BSResource/LooseFileStreamBase.h"
#include "RE/Bethesda/BSResource/StreamBase.h"
#include "RE/Bethesda/BSSystemFile.h"

#include "RE/Bethesda/BSResource/Stream.h"

namespace RE::BSResource
{
	class Location;

	[[nodiscard]] ErrorCode GetOrCreateStream(const char* a_fileName, BSTSmartPointer<Stream>& a_result, bool a_writable = false, Location* a_optionalStart = nullptr);
}
