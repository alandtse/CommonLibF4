#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/ImageSpaceData.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class TESImageSpaceModifier;
	class TESImageSpaceModifierForm;

	class ImageSpaceModifierFinder
	{
	public:
		// members
		TESImageSpaceModifierForm* modifier;        // 00
		const BSFixedString&       modifierToFind;  // 08
	};
	static_assert(sizeof(ImageSpaceModifierFinder) == 0x10);

	class ImageSpaceModifierInstance :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstance };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstance };

		virtual ~ImageSpaceModifierInstance();  // 00

		// add
		bool IsExpired()  // 28
		{
			return REL::RelocateVirtual<decltype(&ImageSpaceModifierInstance::IsExpired)>(0x28, 0x2A, this);
		}

		void Apply()  // 29
		{
			REL::RelocateVirtual<decltype(&ImageSpaceModifierInstance::Apply)>(0x29, 0x2B, this);
		}

		void PrintInfo(char* a_buffer)  // 2A
		{
			REL::RelocateVirtual<decltype(&ImageSpaceModifierInstance::PrintInfo)>(0x2A, 0x2C, this, a_buffer);
		}

		ImageSpaceModifierInstanceForm* IsForm()  // 2B
		{
			return REL::RelocateVirtual<decltype(&ImageSpaceModifierInstance::IsForm)>(0x2B, 0x2D, this);
		}

		// members
		float                 strength;  // 10
		NiPointer<NiAVObject> target;    // 18
		float                 age;       // 20
		std::uint32_t         flags;     // 24
	};
	static_assert(sizeof(ImageSpaceModifierInstance) == 0x28);

	class ImageSpaceModifierInstanceForm :
		public ImageSpaceModifierInstance
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceForm };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceForm };

		virtual ~ImageSpaceModifierInstanceForm();  // 00

		static ImageSpaceModifierInstanceForm* Trigger(TESImageSpaceModifier* a_mod, float a_strength, NiAVObject* a_target)
		{
			using func_t = ImageSpaceModifierInstanceForm* (*)(TESImageSpaceModifier*, float, NiAVObject*);
			static REL::Relocation<func_t> func{ REL::ID(179769) };
			return func(a_mod, a_strength, a_target);
		}

		static ImageSpaceModifierInstanceForm* Trigger(const BSFixedString& a_name)
		{
			using func_t = ImageSpaceModifierInstanceForm* (*)(const BSFixedString&);
			static REL::Relocation<func_t> func{ REL::ID(1216312) };
			return func(a_name);
		}

		static void Stop(TESImageSpaceModifier* a_mod)
		{
			using func_t = void (*)(TESImageSpaceModifier*);
			static REL::Relocation<func_t> func{ REL::ID(217873) };
			return func(a_mod);
		}

		static void Stop(const BSFixedString& a_name)
		{
			using func_t = void (*)(const BSFixedString&);
			static REL::Relocation<func_t> func{ REL::ID(549773) };
			return func(a_name);
		}

		// members
		TESImageSpaceModifier* imageSpaceMod;      // 28
		TESImageSpaceModifier* lastImageSpaceMod;  // 30
		float                  lastStrength;       // 38
		NiPointer<NiAVObject>  lastTarget;         // 40
		float                  transitionTime;     // 48
	};
	static_assert(sizeof(ImageSpaceModifierInstanceForm) == 0x50);

	class ImageSpaceModifierInstanceTemp :
		public ImageSpaceModifierInstance  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceTemp };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceTemp };

		virtual ~ImageSpaceModifierInstanceTemp();  // 00

		// members
		float duration;  // 28
	};
	static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30);

	class ImageSpaceModifierInstanceDOF :
		public ImageSpaceModifierInstanceTemp  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceDOF };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceDOF };

		virtual ~ImageSpaceModifierInstanceDOF();  // 00

		// members
		ImageSpaceModData data;  // 30
	};
	static_assert(sizeof(ImageSpaceModifierInstanceDOF) == 0x80);

	class ImageSpaceModifierInstanceRB :
		public ImageSpaceModifierInstanceTemp
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceRB };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceRB };

		virtual ~ImageSpaceModifierInstanceRB();  // 00

		// members
		ImageSpaceModData data;  // 30
	};
	static_assert(sizeof(ImageSpaceModifierInstanceRB) == 0x80);
}
