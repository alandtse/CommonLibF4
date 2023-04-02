#pragma once

namespace RE
{
	namespace BSResource
	{
		enum class ErrorCode : std::uint32_t
		{
			kNone = 0,
			kNotExist = 1,
			kInvalidPath = 2,
			kFileError = 3,
			kInvalidType = 4,
			kMemoryError = 5,
			kBusy = 6,
			kInvalidParam = 7,
			kUnsupported = 8
		};

		enum class SeekMode
		{
			kSet = 0,
			kCurrent = 1,
			kEnd = 2
		};

		struct FileID
		{
		public:
			// members
			std::uint32_t file;  // 0
			std::uint32_t ext;   // 4
		};
		static_assert(sizeof(FileID) == 0x8);

		struct ID :
			public FileID  // 0
		{
		public:
			// members
			std::uint32_t dir;  // 8
		};
		static_assert(sizeof(ID) == 0xC);

	}
}