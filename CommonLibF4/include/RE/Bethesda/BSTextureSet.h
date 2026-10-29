#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSShaderProperty.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class NiTexture;

	class __declspec(novtable) BSTextureSet :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTextureSet };
		static constexpr auto VTABLE{ VTABLE::BSTextureSet };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTextureSet };

		// add
		const BSFixedString* GetTextureFilenameFS(BSShaderProperty::TextureTypeEnum a_type)  // 28
		{
			return REL::RelocateVirtual<decltype(&BSTextureSet::GetTextureFilenameFS)>(0x28, 0x2A, this, a_type);
		}

		const char* GetTextureFilename(BSShaderProperty::TextureTypeEnum a_type)  // 29
		{
			return REL::RelocateVirtual<decltype(&BSTextureSet::GetTextureFilename)>(0x29, 0x2B, this, a_type);
		}

		void GetTexture(const void* a_prefetchedHandle, BSShaderProperty::TextureTypeEnum a_type, NiPointer<NiTexture>* a_texture, bool a_srgb)  // 2A
		{
			using GetTexture = void (BSTextureSet::*)(const void*, BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture>*, bool);
			REL::RelocateVirtual<GetTexture>(0x2A, 0x2C, this, a_prefetchedHandle, a_type, a_texture, a_srgb);
		}

		void GetTexture(BSShaderProperty::TextureTypeEnum a_type, NiPointer<NiTexture>* a_texture, bool a_srgb)  // 2B
		{
			using GetTexture = void (BSTextureSet::*)(BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture>*, bool);
			REL::RelocateVirtual<GetTexture>(0x2B, 0x2D, this, a_type, a_texture, a_srgb);
		}

		void SetTextureFilename(BSShaderProperty::TextureTypeEnum a_type, const char* a_filename)  // 2C
		{
			REL::RelocateVirtual<decltype(&BSTextureSet::SetTextureFilename)>(0x2C, 0x2E, this, a_type, a_filename);
		}
	};
	static_assert(sizeof(BSTextureSet) == 0x10);

	class __declspec(novtable) BSShaderTextureSet :
		public BSTextureSet  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderTextureSet };
		static constexpr auto VTABLE{ VTABLE::BSShaderTextureSet };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSShaderTextureSet };

		static BSShaderTextureSet* CreateObject()
		{
			using func_t = decltype(&BSShaderTextureSet::CreateObject);
			static REL::Relocation<func_t> func{ REL::RelocationID(993063, 2316324) };
			return func();
		}

		// members
		BSFixedString textureNames[10];  // 10
	};
	static_assert(sizeof(BSShaderTextureSet) == 0x60);
}
