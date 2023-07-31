#pragma once

#ifdef _INC_WINAPIFAMILY
#	error Windows API detected. Please move any Windows API includes after CommonLibF4, or remove them.
#else

namespace F4SE::WinAPI
{
	// general constants
	inline const auto INVALID_HANDLE_VALUE{ reinterpret_cast<void*>(static_cast<std::intptr_t>(-1)) };
	inline constexpr auto MAX_PATH{ 260u };

	// standard access
	inline constexpr auto STANDARD_RIGHTS_REQUIRED{ 0x000F0000 };
	inline constexpr auto STANDARD_RIGHTS_ALL{ 0x001F0000 };

	// code page identifiers
	inline constexpr auto CP_UTF8{ 65001u };

	// pe image header
	inline constexpr auto IMAGE_DOS_SIGNATURE{ 0x5A4Du };
	inline constexpr auto IMAGE_NT_SIGNATURE{ 0x00004550u };
	inline constexpr auto IMAGE_NT_OPTIONAL_HDR32_MAGIC{ 0x10Bu };
	inline constexpr auto IMAGE_NT_OPTIONAL_HDR64_MAGIC{ 0x20Bu };

	// pe image directory entries
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_EXPORT{ 0u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_IMPORT{ 1u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_RESOURCE{ 2u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_EXCEPTION{ 3u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_SECURITY{ 4u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_BASERELOC{ 5u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_DEBUG{ 6u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_ARCHITECTURE{ 7u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_GLOBALPTR{ 8u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_TLS{ 9u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG{ 10u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT{ 11u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_IAT{ 12u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT{ 13u };
	inline constexpr auto IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR{ 14u };
	inline constexpr auto IMAGE_NUMBEROF_DIRECTORY_ENTRIES{ 16u };

	// pe image ordinal
	inline constexpr auto IMAGE_ORDINAL_FLAG32{ 0x80000000u };
	inline constexpr auto IMAGE_ORDINAL_FLAG64{ 0x8000000000000000ull };

	// pe image section header characteristics
	inline constexpr auto IMAGE_SCN_MEM_SHARED{ 0x10000000u };
	inline constexpr auto IMAGE_SCN_MEM_EXECUTE{ 0x20000000u };
	inline constexpr auto IMAGE_SCN_MEM_READ{ 0x40000000u };
	inline constexpr auto IMAGE_SCN_MEM_WRITE{ 0x80000000u };
	inline constexpr auto IMAGE_SIZEOF_SECTION_HEADER{ 40u };
	inline constexpr auto IMAGE_SIZEOF_SHORT_NAME{ 8u };

	// memory allocation types
	inline constexpr auto MEM_COMMIT{ 0x00001000u };
	inline constexpr auto MEM_RESERVE{ 0x00002000u };
	inline constexpr auto MEM_DECOMMIT{ 0x00004000u };
	inline constexpr auto MEM_RELEASE{ 0x00008000u };
	inline constexpr auto MEM_FREE{ 0x00010000u };
	inline constexpr auto MEM_RESET{ 0x00080000u };
	inline constexpr auto MEM_RESET_UNDO{ 0x01000000u };

	// memory page protection attributes
	inline constexpr auto PAGE_NOACCESS{ 0x00000001u };
	inline constexpr auto PAGE_READONLY{ 0x00000002u };
	inline constexpr auto PAGE_READWRITE{ 0x00000004u };
	inline constexpr auto PAGE_WRITECOPY{ 0x00000008u };
	inline constexpr auto PAGE_EXECUTE{ 0x00000010u };
	inline constexpr auto PAGE_EXECUTE_READ{ 0x00000020u };
	inline constexpr auto PAGE_EXECUTE_READWRITE{ 0x00000040u };

	// memory section
	inline constexpr auto SECTION_QUERY{ 0x00000001 };
	inline constexpr auto SECTION_MAP_WRITE{ 0x00000002 };
	inline constexpr auto SECTION_MAP_READ{ 0x00000004 };
	inline constexpr auto SECTION_MAP_EXECUTE{ 0x00000008 };
	inline constexpr auto SECTION_EXTEND_SIZE{ 0x00000010 };
	inline constexpr auto SECTION_MAP_EXECUTE_EXPLICIT{ 0x00000020 };
	inline constexpr auto SECTION_ALL_ACCESS{
		STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_SIZE
	};

	// file attributes
	inline constexpr auto FILE_ATTRIBUTE_READONLY{ 0x00000001u };
	inline constexpr auto FILE_ATTRIBUTE_HIDDEN{ 0x00000002u };
	inline constexpr auto FILE_ATTRIBUTE_SYSTEM{ 0x00000004u };
	inline constexpr auto FILE_ATTRIBUTE_DIRECTORY{ 0x00000010u };
	inline constexpr auto FILE_ATTRIBUTE_ARCHIVE{ 0x00000020u };

	// file mapping flags
	inline constexpr auto FILE_MAP_ALL_ACCESS{ SECTION_ALL_ACCESS };
	inline constexpr auto FILE_MAP_COPY{ 0x00000001u };
	inline constexpr auto FILE_MAP_WRITE{ 0x00000002u };
	inline constexpr auto FILE_MAP_READ{ 0x00000004u };
	inline constexpr auto FILE_MAP_EXECUTE{ 0x00000020u };
	inline constexpr auto FILE_MAP_LARGE_PAGES{ 0x20000000u };
	inline constexpr auto FILE_MAP_TARGETS_INVALID{ 0x40000000u };
	inline constexpr auto FILE_MAP_RESERVE{ 0x80000000u };

	// known folder flags
	inline constexpr auto KF_FLAG_DEFAULT{ 0x00000000u };
	inline constexpr auto KF_FLAG_FORCE_APP_DATA_REDIRECTION{ 0x00080000u };
	inline constexpr auto KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET{ 0x00040000u };
	inline constexpr auto KF_FLAG_FORCE_PACKAGE_REDIRECTION{ 0x00020000u };
	inline constexpr auto KF_FLAG_NO_PACKAGE_REDIRECTION{ 0x00010000u };
	inline constexpr auto KF_FLAG_FORCE_APPCONTAINER_REDIRECTION{ 0x00020000u };
	inline constexpr auto KF_FLAG_NO_APPCONTAINER_REDIRECTION{ 0x00010000u };
	inline constexpr auto KF_FLAG_CREATE{ 0x00008000u };
	inline constexpr auto KF_FLAG_DONT_VERIFY{ 0x00004000u };
	inline constexpr auto KF_FLAG_DONT_UNEXPAND{ 0x00002000u };
	inline constexpr auto KF_FLAG_NO_ALIAS{ 0x00001000u };
	inline constexpr auto KF_FLAG_INIT{ 0x00000800u };
	inline constexpr auto KF_FLAG_DEFAULT_PATH{ 0x00000400u };
	inline constexpr auto KF_FLAG_NOT_PARENT_RELATIVE{ 0x00000200u };
	inline constexpr auto KF_FLAG_SIMPLE_IDLIST{ 0x00000100u };
	inline constexpr auto KF_FLAG_ALIAS_ONLY{ 0x80000000u };

	// string normalization forms
	inline constexpr auto NORM_FORM_OTHER{ 0x0 };
	inline constexpr auto NORM_FORM_C{ 0x1 };
	inline constexpr auto NORM_FORM_D{ 0x2 };
	inline constexpr auto NORM_FORM_KC{ 0x5 };
	inline constexpr auto NORM_FORM_KD{ 0x6 };

	// locale map flags
	inline constexpr auto LCMAP_LOWERCASE{ 0x00000100u };
	inline constexpr auto LCMAP_UPPERCASE{ 0x00000200u };
	inline constexpr auto LCMAP_TITLECASE{ 0x00000300u };
	inline constexpr auto LCMAP_SORTKEY{ 0x00000400u };
	inline constexpr auto LCMAP_BYTEREV{ 0x00000800u };
	inline constexpr auto LCMAP_HIRAGANA{ 0x00100000u };
	inline constexpr auto LCMAP_KATAKANA{ 0x00200000u };
	inline constexpr auto LCMAP_HALFWIDTH{ 0x00400000u };
	inline constexpr auto LCMAP_FULLWIDTH{ 0x00800000u };
	inline constexpr auto LCMAP_LINGUISTIC_CASING{ 0x01000000u };
	inline constexpr auto LCMAP_SIMPLIFIED_CHINESE{ 0x02000000u };
	inline constexpr auto LCMAP_TRADITIONAL_CHINESE{ 0x04000000u };

	// locale names
	inline constexpr auto LOCALE_NAME_USER_DEFAULT{ nullptr };
	inline constexpr auto LOCALE_NAME_INVARIANT{ L"" };
	inline constexpr auto LOCALE_NAME_SYSTEM_DEFAULT{ L"!x-sys-default-locale" };

	// process creation flags
	inline constexpr auto DEBUG_PROCESS{ 0x00000001u };
	inline constexpr auto DEBUG_ONLY_THIS_PROCESS{ 0x00000002u };
	inline constexpr auto CREATE_SUSPENDED{ 0x00000004u };
	inline constexpr auto DETACHED_PROCESS{ 0x00000008u };
	inline constexpr auto CREATE_NEW_CONSOLE{ 0x00000010u };
	inline constexpr auto NORMAL_PRIORITY_CLASS{ 0x00000020u };
	inline constexpr auto IDLE_PRIORITY_CLASS{ 0x00000040u };
	inline constexpr auto HIGH_PRIORITY_CLASS{ 0x00000080u };
	inline constexpr auto REALTIME_PRIORITY_CLASS{ 0x00000100u };
	inline constexpr auto CREATE_NEW_PROCESS_GROUP{ 0x00000200u };
	inline constexpr auto CREATE_UNICODE_ENVIRONMENT{ 0x00000400u };
	inline constexpr auto CREATE_FORCEDOS{ 0x00002000u };
	inline constexpr auto BELOW_NORMAL_PRIORITY_CLASS{ 0x00004000u };
	inline constexpr auto ABOVE_NORMAL_PRIORITY_CLASS{ 0x00008000u };
	inline constexpr auto INHERIT_PARENT_AFFINITY{ 0x00010000u };
	inline constexpr auto CREATE_PROTECTED_PROCESS{ 0x00040000u };
	inline constexpr auto EXTENDED_STARTUPINFO_PRESENT{ 0x00080000u };
	inline constexpr auto PROCESS_MODE_BACKGROUND_BEGIN{ 0x00100000u };
	inline constexpr auto PROCESS_MODE_BACKGROUND_END{ 0x00200000u };
	inline constexpr auto CREATE_SECURE_PROCESS{ 0x00400000 };
	inline constexpr auto CREATE_BREAKAWAY_FROM_JOB{ 0x01000000u };
	inline constexpr auto CREATE_PRESERVE_CODE_AUTHZ_LEVEL{ 0x02000000u };
	inline constexpr auto CREATE_DEFAULT_ERROR_MODE{ 0x04000000u };
	inline constexpr auto CREATE_NO_WINDOW{ 0x08000000u };

	// symbol name undecoration flags
	inline constexpr auto UNDNAME_NO_MS_KEYWORDS{ 0x00000002u };
	inline constexpr auto UNDNAME_NO_FUNCTION_RETURNS{ 0x00000004u };
	inline constexpr auto UNDNAME_NO_ALLOCATION_MODEL{ 0x00000008u };
	inline constexpr auto UNDNAME_NO_ALLOCATION_LANGUAGE{ 0x00000010u };
	inline constexpr auto UNDNAME_NO_THISTYPE{ 0x00000060u };
	inline constexpr auto UNDNAME_NO_ACCESS_SPECIFIERS{ 0x00000080u };
	inline constexpr auto UNDNAME_NO_THROW_SIGNATURES{ 0x00000100u };
	inline constexpr auto UNDNAME_NO_RETURN_UDT_MODEL{ 0x00000400u };
	inline constexpr auto UNDNAME_NAME_ONLY{ 0x00001000u };
	inline constexpr auto UNDNAME_NO_ARGUMENTS{ 0x00002000u };

	struct CRITICAL_SECTION
	{
	public:
		// members
		void* debugInfo;              // 00
		std::int32_t lockCount;       // 08
		std::int32_t recursionCount;  // 0C
		void* owningThread;           // 10
		void* lockSemaphore;          // 18
		std::uint64_t* spinCount;     // 20
	};
	static_assert(sizeof(CRITICAL_SECTION) == 0x28);

	struct FILETIME
	{
	public:
		// members
		std::uint32_t dwLowDateTime;   // 00
		std::uint32_t dwHighDateTime;  // 04
	};
	static_assert(sizeof(FILETIME) == 0x8);

	struct GUID
	{
		std::uint32_t data1;
		std::uint16_t data2;
		std::uint16_t data3;
		std::uint8_t data4[8];
	};
	static_assert(sizeof(GUID) == 0x10);

	// known folder ids
	inline constexpr GUID FOLDERID_Documents{ 0xFDD39AD0u, 0x238Fu, 0x46AFu, 0xADu, 0xB4u, 0x6Cu, 0x85u, 0x48u, 0x03u, 0x69u, 0xC7u };
	inline constexpr GUID FOLDERID_Pictures{ 0x33E28130u, 0x4E1Eu, 0x4676u, 0x83u, 0x5Au, 0x98u, 0x39u, 0x5Cu, 0x3Bu, 0xC3u, 0xBBu };
	inline constexpr GUID FOLDERID_ProgramData{ 0x62AB5D82u, 0xFDC1u, 0x4DC3u, 0xA9u, 0xDDu, 0x07u, 0x0Du, 0x1Du, 0x49u, 0x5Du, 0x97u };

	struct HWND__;
	using HWND = HWND__*;

	struct HINSTANCE__;
	using HINSTANCE = HINSTANCE__*;
	using HMODULE = HINSTANCE;

	struct HKEY__;
	using HKEY = HKEY__*;

	inline auto HKEY_CLASSES_ROOT{ reinterpret_cast<HKEY>(0x80000000ull) };
	inline auto HKEY_CURRENT_USER{ reinterpret_cast<HKEY>(0x80000001ull) };
	inline auto HKEY_LOCAL_MACHINE{ reinterpret_cast<HKEY>(0x80000002ull) };

	struct IMAGE_DATA_DIRECTORY
	{
		std::uint32_t virtualAddress;
		std::uint32_t size;
	};
	static_assert(sizeof(IMAGE_DATA_DIRECTORY) == 0x8);

	struct IMAGE_DOS_HEADER
	{
		std::uint16_t magic;
		std::uint16_t cblp;
		std::uint16_t cp;
		std::uint16_t crlc;
		std::uint16_t cparhdr;
		std::uint16_t minalloc;
		std::uint16_t maxalloc;
		std::uint16_t ss;
		std::uint16_t sp;
		std::uint16_t csum;
		std::uint16_t ip;
		std::uint16_t cs;
		std::uint16_t lfarlc;
		std::uint16_t ovno;
		std::uint16_t res[4];
		std::uint16_t oemid;
		std::uint16_t oeminfo;
		std::uint16_t res2[10];
		std::int32_t lfanew;
	};
	static_assert(sizeof(IMAGE_DOS_HEADER) == 0x40);

	struct IMAGE_FILE_HEADER
	{
		std::uint16_t machine;
		std::uint16_t numberOfSections;
		std::uint32_t timeDateStamp;
		std::uint32_t pointerToSymbolTable;
		std::uint32_t numberOfSymbols;
		std::uint16_t sizeOfOptionalHeader;
		std::uint16_t characteristics;
	};
	static_assert(sizeof(IMAGE_FILE_HEADER) == 0x14);

	struct IMAGE_IMPORT_BY_NAME
	{
		std::uint16_t hint;
		char name[1];
	};
	static_assert(sizeof(IMAGE_IMPORT_BY_NAME) == 0x4);

	struct IMAGE_IMPORT_DESCRIPTOR
	{
		union
		{
			std::uint32_t characteristics;
			std::uint32_t originalFirstThunk;
		};

		std::uint32_t timeDateStamp;
		std::uint32_t forwarderChain;
		std::uint32_t name;
		std::uint32_t firstThunk;
	};
	static_assert(sizeof(IMAGE_IMPORT_DESCRIPTOR) == 0x14);

	struct IMAGE_OPTIONAL_HEADER64
	{
		std::uint16_t magic;
		std::uint8_t majorLinkerVersion;
		std::uint8_t minorLinkerVersion;
		std::uint32_t sizeOfCode;
		std::uint32_t sizeOfInitializedData;
		std::uint32_t sizeOfUninitializedData;
		std::uint32_t addressOfEntryPoint;
		std::uint32_t baseOfCode;
		std::uint64_t imageBase;
		std::uint32_t sectionAlignment;
		std::uint32_t fileAlignment;
		std::uint16_t majorOperatingSystemVersion;
		std::uint16_t minorOperatingSystemVersion;
		std::uint16_t majorImageVersion;
		std::uint16_t minorImageVersion;
		std::uint16_t majorSubsystemVersion;
		std::uint16_t minorSubsystemVersion;
		std::uint32_t win32VersionValue;
		std::uint32_t sizeOfImage;
		std::uint32_t sizeOfHeaders;
		std::uint32_t checkSum;
		std::uint16_t subsystem;
		std::uint16_t dllCharacteristics;
		std::uint64_t sizeOfStackReserve;
		std::uint64_t sizeOfStackCommit;
		std::uint64_t sizeOfHeapReserve;
		std::uint64_t sizeOfHeapCommit;
		std::uint32_t loaderFlags;
		std::uint32_t numberOfRvaAndSizes;
		IMAGE_DATA_DIRECTORY dataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
	};
	static_assert(sizeof(IMAGE_OPTIONAL_HEADER64) == 0xF0);

	struct IMAGE_NT_HEADERS64
	{
		std::uint32_t signature;
		IMAGE_FILE_HEADER fileHeader;
		IMAGE_OPTIONAL_HEADER64 optionalHeader;
	};
	static_assert(sizeof(IMAGE_NT_HEADERS64) == 0x108);

	struct IMAGE_SECTION_HEADER
	{
		std::uint8_t name[IMAGE_SIZEOF_SHORT_NAME];
		union
		{
			std::uint32_t physicalAddress;
			std::uint32_t virtualSize;
		} misc;
		std::uint32_t virtualAddress;
		std::uint32_t sizeOfRawData;
		std::uint32_t pointerToRawData;
		std::uint32_t pointerToRelocations;
		std::uint32_t pointerToLinenumbers;
		std::uint16_t numberOfRelocations;
		std::uint16_t numberOfLinenumbers;
		std::uint32_t characteristics;
	};
	static_assert(sizeof(IMAGE_SECTION_HEADER) == 0x28);

	struct IMAGE_THUNK_DATA64
	{
		union
		{
			std::uint64_t forwarderString;  // PBYTE
			std::uint64_t function;         // PDWORD
			std::uint64_t ordinal;
			std::uint64_t addressOfData;  // PIMAGE_IMPORT_BY_NAME
		} u1;
	};
	static_assert(sizeof(IMAGE_THUNK_DATA64) == 0x8);

	struct MEMORY_BASIC_INFORMATION
	{
		void* baseAddress;
		void* allocationBase;
		std::uint32_t allocationProtect;
		std::uint16_t partitionId;
		std::size_t regionSize;
		std::uint32_t state;
		std::uint32_t protect;
		std::uint32_t type;
	};
	static_assert(sizeof(MEMORY_BASIC_INFORMATION) == 0x30);

	struct NLSVERSIONINFO;

	struct PROCESS_INFORMATION
	{
		void* hProcess;
		void* hThread;
		std::uint32_t dwProcessId;
		std::uint32_t dwThreadId;
	};
	static_assert(sizeof(PROCESS_INFORMATION) == 0x18);

	struct SECURITY_ATTRIBUTES
	{
		std::uint32_t nLength;
		void* lpSecurityDescriptor;
		bool bInheritHandle;
	};
	static_assert(sizeof(SECURITY_ATTRIBUTES) == 0x18);

	struct STARTUPINFOA
	{
		std::uint32_t cb;
		char* lpReserved;
		char* lpDesktop;
		char* lpTitle;
		std::uint32_t dwX;
		std::uint32_t dwY;
		std::uint32_t dwXSize;
		std::uint32_t dwYSize;
		std::uint32_t dwXCountChars;
		std::uint32_t dwYCountChars;
		std::uint32_t dwFillAttribute;
		std::uint32_t dwFlags;
		std::uint16_t wShowWindow;
		std::uint16_t cbReserved2;
		std::uint8_t* lpReserved2;
		void* hStdInput;
		void* hStdOutput;
		void* hStdError;
	};
	static_assert(sizeof(STARTUPINFOA) == 0x68);

	struct STARTUPINFOW
	{
		std::uint32_t cb;
		wchar_t* lpReserved;
		wchar_t* lpDesktop;
		wchar_t* lpTitle;
		std::uint32_t dwX;
		std::uint32_t dwY;
		std::uint32_t dwXSize;
		std::uint32_t dwYSize;
		std::uint32_t dwXCountChars;
		std::uint32_t dwYCountChars;
		std::uint32_t dwFillAttribute;
		std::uint32_t dwFlags;
		std::uint16_t wShowWindow;
		std::uint16_t cbReserved2;
		std::uint8_t* lpReserved2;
		void* hStdInput;
		void* hStdOutput;
		void* hStdError;
	};
	static_assert(sizeof(STARTUPINFOW) == 0x68);

	struct WIN32_FIND_DATAA
	{
		// members
		std::uint32_t dwFileAttributes;
		FILETIME ftCreationTime;
		FILETIME ftLastAccessTime;
		FILETIME ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		char cFileName[MAX_PATH];
		char cAlternateFileName[14];
	};
	static_assert(sizeof(WIN32_FIND_DATAA) == 0x140);

	struct WIN32_FIND_DATAW
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME ftCreationTime;
		FILETIME ftLastAccessTime;
		FILETIME ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		wchar_t cFileName[MAX_PATH];
		wchar_t cAlternateFileName[14];
	};
	static_assert(sizeof(WIN32_FIND_DATAW) == 0x250);

	struct SYSTEM_INFO
	{
		union
		{
			std::uint32_t dwOemId;
			struct
			{
				std::uint16_t wProcessorArchitecture;
				std::uint16_t wReserved;
			};
		};
		std::uint32_t dwPageSize;
		void* lpMinimumApplicationAddress;
		void* lpMaximumApplicationAddress;
		std::uintptr_t dwActiveProcessorMask;
		std::uint32_t dwNumberOfProcessors;
		std::uint32_t dwProcessorType;
		std::uint32_t dwAllocationGranularity;
		std::uint16_t wProcessorLevel;
		std::uint16_t wProcessorRevision;
	};
	static_assert(sizeof(SYSTEM_INFO) == 0x30);

	union ULARGE_INTEGER
	{
		struct
		{
			std::uint32_t lowPart;
			std::uint32_t highPart;
		};
		struct
		{
			std::uint32_t lowPart;
			std::uint32_t highPart;
		} u;
		std::uint64_t quadPart;
	};

	bool CloseHandle(
		void* a_handle) noexcept;

	void CoTaskMemFree(
		void* a_block) noexcept;

	[[nodiscard]] void* CreateFileMapping(
		void* a_file,
		SECURITY_ATTRIBUTES* a_mapAttr,
		std::uint32_t a_protect,
		std::uint32_t a_maxSizeHigh,
		std::uint32_t a_maxSizeLow,
		const char* a_name) noexcept;

	[[nodiscard]] void* CreateFileMapping(
		void* a_file,
		SECURITY_ATTRIBUTES* a_mapAttr,
		std::uint32_t a_protect,
		std::uint32_t a_maxSizeHigh,
		std::uint32_t a_maxSizeLow,
		const wchar_t* a_name) noexcept;

	[[nodiscard]] bool CreateProcess(
		const char* a_name,
		char* a_cmd,
		SECURITY_ATTRIBUTES* a_procAttr,
		SECURITY_ATTRIBUTES* a_threadAttr,
		bool a_inherit,
		std::uint32_t a_flags,
		void* a_env,
		const char* a_curDir,
		STARTUPINFOA* a_startInfo,
		PROCESS_INFORMATION* a_procInfo) noexcept;

	[[nodiscard]] bool CreateProcess(
		const wchar_t* a_name,
		wchar_t* a_cmd,
		SECURITY_ATTRIBUTES* a_procAttr,
		SECURITY_ATTRIBUTES* a_threadAttr,
		bool a_inherit,
		std::uint32_t a_flags,
		void* a_env,
		const wchar_t* a_curDir,
		STARTUPINFOW* a_startInfo,
		PROCESS_INFORMATION* a_procInfo) noexcept;

	[[nodiscard]] void* CreateRemoteThread(
		void* a_process,
		SECURITY_ATTRIBUTES* a_threadAttr,
		std::size_t a_stackSize,
		std::uint32_t (*a_startAddr)(void*),
		void* a_param,
		std::uint32_t a_flags,
		std::uint32_t* a_threadId) noexcept;

	[[nodiscard]] bool FindClose(
		void* a_findFile) noexcept;

	[[nodiscard]] void* FindFirstFile(
		const char* a_fileName,
		WIN32_FIND_DATAA* a_findFileData) noexcept;

	[[nodiscard]] void* FindFirstFile(
		const wchar_t* a_fileName,
		WIN32_FIND_DATAW* a_findFileData) noexcept;

	bool FindNextFile(
		void* a_findFile,
		WIN32_FIND_DATAA* a_findFileData) noexcept;

	bool FindNextFile(
		void* a_findFile,
		WIN32_FIND_DATAW* a_findFileData) noexcept;

	bool FlushInstructionCache(
		void* a_process,
		const void* a_baseAddr,
		std::size_t a_size) noexcept;

	bool FreeLibrary(
		HMODULE a_module) noexcept;

	[[nodiscard]] void* GetCurrentModule() noexcept;

	[[nodiscard]] void* GetCurrentProcess() noexcept;

	[[nodiscard]] std::uint32_t GetCurrentThreadID() noexcept;

	std::uint32_t GetEnvironmentVariable(
		const char* a_name,
		char* a_buffer,
		std::uint32_t a_size) noexcept;

	std::uint32_t GetEnvironmentVariable(
		const wchar_t* a_name,
		wchar_t* a_buffer,
		std::uint32_t a_size) noexcept;

	bool GetFileVersionInfo(
		const char* a_filename,
		std::uint32_t a_handle,
		std::uint32_t a_len,
		void* a_data) noexcept;

	bool GetFileVersionInfo(
		const wchar_t* a_filename,
		std::uint32_t a_handle,
		std::uint32_t a_len,
		void* a_data) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(
		const char* a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(
		const wchar_t* a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::uint32_t GetLastError() noexcept;

	[[nodiscard]] std::size_t GetMaxPath() noexcept;

	[[nodiscard]] std::uint32_t GetModuleFileName(
		void* a_module,
		char* a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t GetModuleFileName(
		void* a_module,
		wchar_t* a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] HMODULE GetModuleHandle(const char* a_moduleName) noexcept;

	[[nodiscard]] HMODULE GetModuleHandle(const wchar_t* a_moduleName) noexcept;

	[[nodiscard]] std::uint32_t GetPrivateProfileString(
		const char* a_appName,
		const char* a_keyName,
		const char* a_default,
		char* a_outString,
		std::uint32_t a_size,
		const char* a_fileName) noexcept;

	[[nodiscard]] std::uint32_t GetPrivateProfileString(
		const wchar_t* a_appName,
		const wchar_t* a_keyName,
		const wchar_t* a_default,
		wchar_t* a_outString,
		std::uint32_t a_size,
		const wchar_t* a_fileName) noexcept;

	[[nodiscard]] void* GetProcAddress(
		void* a_module,
		const char* a_procName) noexcept;

	void GetSystemInfo(
		SYSTEM_INFO* a_info) noexcept;

	[[nodiscard]] IMAGE_SECTION_HEADER* IMAGE_FIRST_SECTION(
		const IMAGE_NT_HEADERS64* a_header) noexcept;

	[[nodiscard]] bool IsDebuggerPresent() noexcept;

	[[nodiscard]] std::int32_t LCMapStringEx(
		const wchar_t* a_localeName,
		std::uint32_t a_mapFlags,
		const wchar_t* a_srcStr,
		std::int32_t a_srcLen,
		wchar_t* a_destStr,
		std::int32_t a_destLen,
		NLSVERSIONINFO* a_verInfo,
		void* a_reserved,
		std::intptr_t a_sortHandle) noexcept;

	[[nodiscard]] HMODULE LoadLibrary(const char* a_fileName) noexcept;

	[[nodiscard]] HMODULE LoadLibrary(const wchar_t* a_fileName) noexcept;

	[[nodiscard]] void* MapViewOfFile(
		void* a_fileMappingObject,
		std::uint32_t a_desiredAccess,
		std::uint32_t a_fileOffsetHigh,
		std::uint32_t a_fileOffsetLow,
		std::size_t a_numBytesToMap) noexcept;

	[[nodiscard]] void* MapViewOfFileEx(
		void* a_fileMappingObject,
		std::uint32_t a_desiredAccess,
		std::uint32_t a_fileOffsetHigh,
		std::uint32_t a_fileOffsetLow,
		std::size_t a_numBytesToMap,
		void* a_baseAddress) noexcept;

	std::int32_t MessageBox(
		void* a_wnd,
		const char* a_text,
		const char* a_caption,
		std::uint32_t a_type) noexcept;

	std::int32_t MessageBox(
		void* a_wnd,
		const wchar_t* a_text,
		const wchar_t* a_caption,
		std::uint32_t a_type) noexcept;

	[[nodiscard]] std::int32_t MultiByteToWideChar(
		std::uint32_t a_codePage,
		std::uint32_t a_flags,
		const char* a_multiByteStr,
		std::int32_t a_multiByte,
		wchar_t* a_wideCharStr,
		std::int32_t a_wideChar);

	[[nodiscard]] std::int32_t NormalizeString(
		std::int32_t a_normForm,
		const wchar_t* a_srcStr,
		std::int32_t a_srcLen,
		wchar_t* a_destStr,
		std::int32_t a_destLen);

	[[nodiscard]] void* OpenFileMapping(
		std::uint32_t a_desiredAccess,
		bool a_inheritHandle,
		const char* a_name) noexcept;

	[[nodiscard]] void* OpenFileMapping(
		std::uint32_t a_desiredAccess,
		bool a_inheritHandle,
		const wchar_t* a_name) noexcept;

	void OutputDebugString(
		const char* a_outputString) noexcept;

	void OutputDebugString(
		const wchar_t* a_outputString) noexcept;

	std::int32_t RegGetValue(
		HKEY a_key,
		const char* a_subKey,
		const char* a_value,
		std::uint32_t a_flags,
		std::uint32_t* a_type,
		void* a_data,
		std::uint32_t* a_length);

	std::int32_t RegGetValue(
		HKEY a_key,
		const wchar_t* a_subKey,
		const wchar_t* a_value,
		std::uint32_t a_flags,
		std::uint32_t* a_type,
		void* a_data,
		std::uint32_t* a_length);

	[[nodiscard]] std::uint32_t ResumeThread(
		void* a_handle) noexcept;

	bool SetEnvironmentVariable(
		const char* a_name,
		const char* a_value) noexcept;

	bool SetEnvironmentVariable(
		const wchar_t* a_name,
		const wchar_t* a_value) noexcept;

	std::int32_t SHGetKnownFolderPath(
		const GUID& a_id,
		std::uint32_t a_flags,
		void* a_token,
		wchar_t** a_path) noexcept;

	[[nodiscard]] std::int32_t ShowCursor(
		bool a_show) noexcept;

	bool TerminateProcess(
		void* a_process,
		std::uint32_t a_exitCode) noexcept;

	[[nodiscard]] void* TlsGetValue(
		std::uint32_t a_tlsIndex) noexcept;

	bool TlsSetValue(
		std::uint32_t a_tlsIndex,
		void* a_tlsValue) noexcept;

	[[nodiscard]] std::uint32_t UnDecorateSymbolName(
		const char* a_name,
		char* a_outputString,
		std::uint32_t a_maxStringLength,
		std::uint32_t a_flags) noexcept;

	[[nodiscard]] std::uint32_t UnDecorateSymbolName(
		const wchar_t* a_name,
		wchar_t* a_outputString,
		std::uint32_t a_maxStringLength,
		std::uint32_t a_flags) noexcept;

	bool UnmapViewOfFile(
		const void* a_baseAddress) noexcept;

	bool UnmapViewOfFileEx(
		void* a_baseAddress,
		std::uint32_t a_flags) noexcept;

	bool VerQueryValue(
		const void* a_block,
		const char* a_subBlock,
		void** a_buffer,
		std::uint32_t* a_len) noexcept;

	bool VerQueryValue(
		const void* a_block,
		const wchar_t* a_subBlock,
		void** a_buffer,
		std::uint32_t* a_len) noexcept;

	void* VirtualAlloc(
		void* a_address,
		std::size_t a_size,
		std::uint32_t a_type,
		std::uint32_t a_protect) noexcept;

	void* VirtualAllocEx(
		void* a_process,
		void* a_address,
		std::size_t a_size,
		std::uint32_t a_type,
		std::uint32_t a_protect) noexcept;

	bool VirtualFree(
		void* a_address,
		std::size_t a_size,
		std::uint32_t a_freeType) noexcept;

	bool VirtualFreeEx(
		void* a_process,
		void* a_address,
		std::size_t a_size,
		std::uint32_t a_freeType) noexcept;

	bool VirtualProtect(
		void* a_address,
		std::size_t a_size,
		std::uint32_t a_newProtect,
		std::uint32_t* a_oldProtect) noexcept;

	bool VirtualProtectEx(
		void* a_process,
		void* a_address,
		std::size_t a_size,
		std::uint32_t a_newProtect,
		std::uint32_t* a_oldProtect) noexcept;

	std::size_t VirtualQuery(
		const void* a_address,
		MEMORY_BASIC_INFORMATION* a_buffer,
		std::size_t a_bufferLen) noexcept;

	std::size_t VirtualQueryEx(
		void* a_process,
		const void* a_address,
		MEMORY_BASIC_INFORMATION* a_buffer,
		std::size_t a_bufferLen) noexcept;

	[[nodiscard]] std::uint32_t WaitForSingleObject(
		void* a_handle,
		std::uint32_t a_milliseconds) noexcept;

	[[nodiscard]] std::uint32_t WaitForSingleObjectEx(
		void* a_handle,
		std::uint32_t a_milliseconds,
		bool a_alertable) noexcept;

	[[nodiscard]] std::int32_t WideCharToMultiByte(
		std::uint32_t a_codePage,
		std::uint32_t a_flags,
		const wchar_t* a_wideCharStr,
		std::int32_t a_wideChar,
		char* a_multiByteStr,
		std::int32_t a_multiByte,
		const char* a_defaultChar,
		std::int32_t* a_usedDefaultChar);

	bool WriteProcessMemory(
		void* a_process,
		void* a_address,
		const void* a_buffer,
		std::size_t a_size,
		std::size_t* a_written) noexcept;
}

namespace RE::DirectX
{
	struct XMFLOAT4X4
	{
	public:
		// members
		float m[4][4];
	};
	static_assert(sizeof(XMFLOAT4X4) == 0x40);
}

#endif  // _INC_WINAPIFAMILY
