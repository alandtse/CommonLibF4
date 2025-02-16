#pragma once

namespace RE
{
	class Actor;
	class TESForm;
	class TESObjectREFR;

	class __declspec(novtable) BGSSaveGameBuffer
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSaveGameBuffer };
		static constexpr auto VTABLE{ VTABLE::BGSSaveGameBuffer };

		virtual ~BGSSaveGameBuffer();

		// add
		virtual TESForm*       GetForm();       // 01 - { return nullptr; }
		virtual TESObjectREFR* GetReference();  // 02 - { return nullptr; }
		virtual Actor*         GetActor();      // 03 - { return nullptr; }

		void SaveDataEndian(const void* a_data, std::uint32_t a_size)
		{
			using func_t = decltype(&BGSSaveGameBuffer::SaveDataEndian);
			static REL::Relocation<func_t> func{ REL::ID(594281) };
			return func(this, a_data, a_size);
		}

		// members
		void*         buffer;          // 08
		std::uint32_t size;            // 10
		std::uint32_t bufferPosition;  // 14
	};
	static_assert(sizeof(BGSSaveGameBuffer) == 0x18);
}
