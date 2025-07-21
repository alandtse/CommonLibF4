#pragma once

#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/TESFile.h"
#include "RE/Bethesda/TESForms.h"
#include "RE/NetImmerse/NiTArray.h"
#include "RE/NetImmerse/NiTList.h"

namespace RE
{
	class TESRegionDataManager;

	struct BGSHotloadCompletedEvent;
	struct TESObjectList;
	struct TESRegionList;

	class __declspec(novtable) NEW_REFR_DATA
	{
	public:
		static constexpr auto RTTI{ RTTI::NEW_REFR_DATA };
		static constexpr auto VTABLE{ VTABLE::NEW_REFR_DATA };

		NEW_REFR_DATA()
		{
			stl::emplace_vtable(this);
		}

		virtual void HandlePre3D(TESObjectREFR*) { return; }

		// members
		NiPoint3                       location;                        // 08
		NiPoint3                       direction;                       // 14
		TESBoundObject*                object{ nullptr };               // 20
		TESObjectCELL*                 interior{ nullptr };             // 28
		TESWorldSpace*                 world{ nullptr };                // 30
		TESObjectREFR*                 reference{ nullptr };            // 38
		BGSPrimitive*                  addPrimitive{ nullptr };         // 40
		void*                          additionalData{ nullptr };       // 48
		BSTSmartPointer<ExtraDataList> extra{ nullptr };                // 50
		INSTANCE_FILTER*               instanceFilter{ nullptr };       // 58
		BGSObjectInstanceExtra*        modExtra{ nullptr };             // 60
		std::uint16_t                  maxLevel{ 0 };                   // 68
		bool                           forcePersist{ false };           // 6A
		bool                           clearStillLoadingFlag{ false };  // 6B
		bool                           initializeScripts{ true };       // 6C
		bool                           initiallyDisabled{ false };      // 6D
	};
	static_assert(sizeof(NEW_REFR_DATA) == 0x70);

	struct TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;       // 00
		BSTArray<TESFile*> smallFiles;  // 18
	};
	static_assert(sizeof(TESFileCollection) == 0x30);

	class TESDataHandler :
		public BSTEventSource<BGSHotloadCompletedEvent>,  // 0000
		public BSTSingletonSDM<TESDataHandler>            // 0058
	{
	public:
		struct RUNTIME_DATA
		{
#define RUNTIME_DATA_CONTENT                                  \
	BSTArray<std::uint32_t> releasedFormIDArray;   /* 0FF0 */ \
	bool                    masterSave;            /* 1008 */ \
	bool                    blockSave;             /* 1009 */ \
	bool                    saveLoadGame;          /* 100A */ \
	bool                    autoSaving;            /* 100B */ \
	bool                    exportingPlugin;       /* 100C */ \
	bool                    clearingData;          /* 100D */ \
	bool                    hasDesiredFiles;       /* 100E */ \
	bool                    checkingModels;        /* 100F */ \
	bool                    loadingFiles;          /* 1010 */ \
	bool                    dontRemoveIDs;         /* 1011 */ \
	char                    gameSettingsLoadState; /* 1012*/
            RUNTIME_DATA_CONTENT
		};

		struct VR_MOD_DATA
		{
#define VR_MOD_DATA_CONTENT                    \
	std::uint32_t loadedModCount;   /* 0FC0 */ \
	std::uint32_t pad14;            /* 0FC4 */ \
	TESFile*      loadedMods[0xFF]; /* 0FC8 */
            VR_MOD_DATA_CONTENT
		};

		inline static RE::TESFileCollection* VRcompiledFileCollection = nullptr;  // used by FalloutVRESL to store pointer to VR version

		[[nodiscard]] static TESDataHandler* GetSingleton(bool a_VRESL = true)
		{
			static REL::Relocation<TESDataHandler**> singleton{ REL::RelocationID(711558, 2688883) };
			if (REL::Module::IsVR() && a_VRESL && !VRcompiledFileCollection) {
				const auto VRhandle = REX::W32::GetModuleHandleW(L"falloutvresl");
				if (VRhandle != NULL) {
					const auto GetCompiledFileCollection = reinterpret_cast<const RE::TESFileCollection* (*)()>(REX::W32::GetProcAddress(VRhandle, "GetCompiledFileCollectionExtern"));
					if (GetCompiledFileCollection != nullptr) {
						TESDataHandler::VRcompiledFileCollection = const_cast<RE::TESFileCollection*>(GetCompiledFileCollection());
					}
				}
			}
			return *singleton;
		}

		[[nodiscard]] bool AddFormToDataHandler(TESForm* a_form)
		{
			using func_t = decltype(&TESDataHandler::AddFormToDataHandler);
			static REL::Relocation<func_t> func{ REL::RelocationID(350112, 2192271) };
			return func(this, a_form);
		}

		[[nodiscard]] bool CheckModsLoaded(bool a_everModded)
		{
			using func_t = decltype(&TESDataHandler::CheckModsLoaded);
			static REL::Relocation<func_t> func{ REL::RelocationID(1432894, 2192323) };
			return func(this, a_everModded);
		}

		[[nodiscard]] ObjectRefHandle CreateReferenceAtLocation(NEW_REFR_DATA& a_data)
		{
			using func_t = decltype(&TESDataHandler::CreateReferenceAtLocation);
			static REL::Relocation<func_t> func{ REL::RelocationID(500304, 500304) };
			return func(this, a_data);
		}

		template <class T>
		[[nodiscard]] BSTArray<T*>& GetFormArray() noexcept  //
			requires(std::derived_from<T, TESForm> &&
					 !std::is_pointer_v<T> &&
					 !std::is_reference_v<T>)
		{
			assert(T::FORM_ID < ENUM_FORM_ID::kTotal);
			return reinterpret_cast<BSTArray<T*>&>(formArrays[std::to_underlying(T::FORM_ID)]);
		}

		TESFormID LookupFormID(TESFormID a_rawFormID, std::string_view a_modName)
		{
			auto file = LookupModByName(a_modName);
			if (!file || file->compileIndex == 0xFF) {
				return 0;
			}

			if (REL::Module::IsVR() && !VRcompiledFileCollection) {
				// Use FalloutVR lookup logic, ignore light plugin index which doesn't exist in VR
				return (a_rawFormID & 0xFFFFFF) | (file->compileIndex << 24);
			} else {
				TESFormID formID = file->compileIndex << 24;
				formID += file->smallFileCompileIndex << 12;
				formID += a_rawFormID;
				return formID;
			}
		}

		TESForm* LookupForm(TESFormID a_rawFormID, std::string_view a_modName)
		{
			auto file = LookupLoadedFile(a_modName);
			if (!file.first) {
				return nullptr;
			}

			uint32_t formID = 0;
			if (file.second) {
				formID = file.first->compileIndex << 24;
				formID += (a_rawFormID & 0x00FFFFFF);
			} else {
				formID = 0xFE000000;
				formID += file.first->smallFileCompileIndex << 12;
				formID += (a_rawFormID & 0x00000FFF);
			}

			return TESForm::GetFormByID(formID);
		}

		template <class T>
		T* LookupForm(TESFormID a_rawFormID, std::string_view a_modName)
		{
			auto form = LookupForm(a_rawFormID, a_modName);
			if (!form) {
				return nullptr;
			}

			return form->Is(T::FORM_ID) ? form->As<T>() : nullptr;
		}

		const std::pair<TESFile*, bool> LookupLoadedFile(std::string_view a_fileName)
		{
			if (auto fullFile = LookupLoadedModByName(a_fileName))
				return { const_cast<TESFile*>(fullFile), true };
			if (auto smallFile = LookupLoadedLightModByName(a_fileName))
				return { const_cast<TESFile*>(smallFile), false };
			return { nullptr, false };
		}

		const TESFile* LookupModByName(std::string_view a_modName)
		{
			for (auto& file : files) {
				if (a_modName.size() == strlen(file->filename) &&
					_strnicmp(file->filename, a_modName.data(), a_modName.size()) == 0) {
					return file;
				}
			}
			return nullptr;
		}

		std::optional<std::uint8_t> GetModIndex(std::string_view a_modName)
		{
			auto mod = LookupModByName(a_modName);
			return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
		}

		const TESFile* LookupLoadedModByName(std::string_view a_modName)
		{
			auto pCompiledFileCollection = GetCompiledFileCollection();
			if (pCompiledFileCollection) {
				for (auto& file : pCompiledFileCollection->files) {
					if (a_modName.size() == strlen(file->filename) &&
						_strnicmp(file->filename, a_modName.data(), a_modName.size()) == 0) {
						return file;
					}
				}
			} else if (auto pLoadedMods = GetVRModData()) {  // In VR so only have files loadedMods
				for (uint32_t i = 0; i < pLoadedMods->loadedModCount; i++) {
					auto& file = pLoadedMods->loadedMods[i];
					if (a_modName.size() == strlen(file->filename) &&
						_strnicmp(file->filename, a_modName.data(), a_modName.size()) == 0) {
						return file;
					}
				}
			}
			return nullptr;
		}

		const TESFile* LookupLoadedModByIndex(std::uint8_t a_index)
		{
			auto pCompiledFileCollection = GetCompiledFileCollection();
			if (pCompiledFileCollection) {
				for (auto& file : pCompiledFileCollection->files) {
					if (file->compileIndex == a_index) {
						return file;
					}
				}
			} else if (auto pLoadedMods = GetVRModData()) {  // In VR so only have files loadedMods
				for (uint32_t i = 0; i < pLoadedMods->loadedModCount; i++) {
					auto& file = pLoadedMods->loadedMods[i];
					if (file->compileIndex == a_index) {
						return file;
					}
				}
			}
			return nullptr;
		}

		std::optional<std::uint8_t> GetLoadedModIndex(std::string_view a_modName)
		{
			auto mod = LookupLoadedModByName(a_modName);
			return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
		}

		const TESFile* LookupLoadedLightModByName(std::string_view a_modName)
		{
			auto pCompiledFileCollection = GetCompiledFileCollection();
			if (pCompiledFileCollection) {
				for (auto& smallFile : pCompiledFileCollection->smallFiles) {
					if (a_modName.size() == strlen(smallFile->filename) &&
						_strnicmp(smallFile->filename, a_modName.data(), a_modName.size()) == 0) {
						return smallFile;
					}
				}
			}
			return nullptr;
		}

		const TESFile* LookupLoadedLightModByIndex(std::uint16_t a_index)
		{
			auto pCompiledFileCollection = GetCompiledFileCollection();
			if (pCompiledFileCollection) {
				for (auto& smallFile : pCompiledFileCollection->smallFiles) {
					if (smallFile->smallFileCompileIndex == a_index) {
						return smallFile;
					}
				}
			}
			return nullptr;
		}

		std::optional<std::uint16_t> GetLoadedLightModIndex(std::string_view a_modName)
		{
			auto mod = LookupLoadedLightModByName(a_modName);
			return mod ? std::make_optional(mod->smallFileCompileIndex) : std::nullopt;
		}

		bool IsFormIDInUse(std::uint32_t a_formID)
		{
			using func_t = decltype(&TESDataHandler::IsFormIDInUse);
			static REL::Relocation<func_t> func{ REL::RelocationID(1448838, 2192351) };
			return func(this, a_formID);
		}

		[[nodiscard]] inline RUNTIME_DATA& GetRuntimeData() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x0FF0, 0x0FF0);
		}

		[[nodiscard]] inline const RUNTIME_DATA& GetRuntimeData() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x0FF0, 0x0FF0);
		}

		[[nodiscard]] inline VR_MOD_DATA* GetVRModData() noexcept
		{
			if FALLOUT_REL_CONSTEXPR (REL::Module::IsVR()) {
				return &REL::RelocateMember<VR_MOD_DATA>(this, 0, 0xFC0);
			}
			return nullptr;
		}

		[[nodiscard]] inline const VR_MOD_DATA* GetVRModData() const noexcept
		{
			if FALLOUT_REL_CONSTEXPR (REL::Module::IsVR()) {
				return &REL::RelocateMember<VR_MOD_DATA>(this, 0, 0xFC0);
			}
			return nullptr;
		}
		[[nodiscard]] inline TESFileCollection* GetCompiledFileCollection() noexcept
		{
			if FALLOUT_REL_CONSTEXPR (REL::Module::IsVR()) {
				return VRcompiledFileCollection;
			} else {
				return &REL::RelocateMember<TESFileCollection>(this, 0xFC0, 0);
			}
		}

		[[nodiscard]] inline const TESFileCollection* GetCompiledFileCollection() const noexcept
		{
			if FALLOUT_REL_CONSTEXPR (REL::Module::IsVR()) {
				return VRcompiledFileCollection;
			} else {
				return REL::RelocateMember<TESFileCollection*>(this, 0xFC0, 0);
			}
		}

		[[nodiscard]] inline TESRegionDataManager* GetRegionDataManager() noexcept
		{
			return REL::RelocateMember<TESRegionDataManager*>(this, 0x1018, 0x17E8);
		}

		[[nodiscard]] inline const TESRegionDataManager* GetRegionDataManager() const noexcept
		{
			return REL::RelocateMember<TESRegionDataManager*>(this, 0x1018, 0x17E8);
		}

		// members
		TESObjectList*                    objectList;                                            // 0060
		BSTArray<TESForm*>                formArrays[std::to_underlying(ENUM_FORM_ID::kTotal)];  // 0068
		TESRegionList*                    regionList;                                            // 0F50
		NiTPrimitiveArray<TESObjectCELL*> interiorCells;                                         // 0F58
		NiTPrimitiveArray<BGSAddonNode*>  addonNodes;                                            // 0F70
		NiTList<TESForm*>                 badForms;                                              // 0F88
		std::uint32_t                     nextID;                                                // 0FA0
		TESFile*                          activeFile;                                            // 0FA8
		BSSimpleList<TESFile*>            files;                                                 // 0FB0
#if !defined(ENABLE_FALLOUT_VR)
		TESFileCollection compiledFileCollection;  // 0FC0
		RUNTIME_DATA_CONTENT
		TESRegionDataManager* regionDataManager;  // 1018, VR 17E8
#elif !defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_F4)
		VR_MOD_DATA_CONTENT
		RUNTIME_DATA_CONTENT
		TESRegionDataManager* regionDataManager;  // 1018, VR 17E8
#endif
	};
#if !defined(ENABLE_FALLOUT_VR)
	static_assert(sizeof(TESDataHandler) == 0x1020);
	static_assert(offsetof(TESDataHandler, regionDataManager) == 0x1018);
	static_assert(offsetof(TESDataHandler, compiledFileCollection) == 0xFC0);
#elif !defined(ENABLE_FALLOUT_NG) && !defined(ENABLE_FALLOUT_F4)
	static_assert(sizeof(TESDataHandler) == 0x17F0);
	static_assert(offsetof(TESDataHandler, regionDataManager) == 0x17E8);
	static_assert(offsetof(TESDataHandler, loadedModCount) == 0xFC0);
	static_assert(offsetof(TESDataHandler, loadedMods) == 0xFC8);
#else
	static_assert(sizeof(TESDataHandler) == 0xFC0);
#endif
}
#undef RUNTIME_DATA_CONTENT
#undef VR_MOD_DATA_CONTENT
