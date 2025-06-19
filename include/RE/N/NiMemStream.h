#pragma once

#include "RE/N/NiBinaryStream.h"

namespace RE
{
	class __declspec(novtable) NiMemStream :
		public NiBinaryStream  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiMemStream };
		static constexpr auto VTABLE{ VTABLE::NiMemStream };

		enum class OpenMode
		{
			kReadOnly = 0x0,
			kWriteOnly = 0x1,
			kAppendOnly = 0x2,
			kReadWrite = 0x3
		};

		// members
		void*       buffer;           // 10
		std::size_t pos;              // 18
		std::size_t bufferAllocSize;  // 20
		std::size_t currentFilePos;   // 28
		bool        good;             // 30
	};
	static_assert(sizeof(NiMemStream) == 0x38);
}
