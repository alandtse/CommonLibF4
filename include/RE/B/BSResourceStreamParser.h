#pragma once

#include "RE/B/BSResourceNiBinaryStream.h"
#include "RE/B/BSStreamParserData.h"

namespace RE
{
	class BSResourceStreamParser :
		public BSResourceNiBinaryStream,
		public BSStreamParserData
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BSResourceStreamParser };
		inline static constexpr auto VTABLE{ VTABLE::BSResourceStreamParser };

		BSResourceStreamParser(const char* a_file) :
			BSResourceNiBinaryStream(a_file, false, nullptr, false)
		{}

		virtual ~BSResourceStreamParser() = default;  // 00

		// override (BSStreamParserData)
		virtual bool            Begin() override { return BSResourceNiBinaryStream::operator bool(); }  // 1:01
		virtual void            End() override {}                                                       // 1:02
		virtual NiBinaryStream* GetStream() override { return this; }                                   // 1:03
	};
}
