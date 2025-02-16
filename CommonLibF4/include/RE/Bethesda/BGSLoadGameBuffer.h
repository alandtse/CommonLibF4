#pragma once

namespace RE
{
	class __declspec(novtable) BGSLoadGameBuffer
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSLoadGameBuffer };
		static constexpr auto VTABLE{ VTABLE::BGSLoadGameBuffer };

		virtual ~BGSLoadGameBuffer();

		// add
		virtual std::uint8_t GetVersion(void);  // 01

		void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size)
		{
			using func_t = decltype(&BGSLoadGameBuffer::LoadDataEndian);
			static REL::Relocation<func_t> func{ REL::ID(1451631) };
			return func(this, a_data, a_offset, a_size);
		}

		// members
		void*         buffer;          // 08
		std::uint64_t unk10;           // 10
		std::uint32_t unk18;           // 18
		std::uint32_t unk1C;           // 1C
		std::uint32_t unk20;           // 20
		std::uint32_t bufferPosition;  // 24
	};
	static_assert(sizeof(BGSLoadGameBuffer) == 0x28);
}
