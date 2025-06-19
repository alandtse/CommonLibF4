#pragma once

namespace RE
{
	class NiBinaryStream;

	class BSStreamParserData
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BSStreamParserData };
		inline static constexpr auto VTABLE{ VTABLE::BSStreamParserData };

		virtual ~BSStreamParserData() = default;  // 00

		virtual bool            Begin() = 0;      // 01
		virtual void            End() = 0;        // 02
		virtual NiBinaryStream* GetStream() = 0;  // 03
	};
}
