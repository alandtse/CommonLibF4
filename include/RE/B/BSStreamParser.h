#pragma once

namespace RE
{
	class BSStreamParserData;

	template <class T>
	class BSStreamParser
	{
	public:
		BSStreamParser(BSStreamParserData* a_data) :
			data(a_data)
		{
			if (const auto stream = a_data->GetStream()) {
				NiBinaryStream::BufferInfo info;
				stream->GetBufferInfo(info);
				streamSizeInBytes = info.fileSize;
			}
		}

		// members
		T                   readBuffer[256]{};
		T*                  readPosition{ 0 };
		BSStreamParserData* data;
		std::uint64_t       streamSizeInBytes{ 0 };
	};
	static_assert(sizeof(BSStreamParser<char>) == 0x118);
	static_assert(sizeof(BSStreamParser<wchar_t>) == 0x218);
}
