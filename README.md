# CommonLibF4 NG

This is a commonlibng version of CommonLibF4. NG comes from Skyrim Commonlib so multiple versions can use the same dll file (vs game specific dlls). This is currently for building flat and VR builds. Please note VR support is early stages and [not all addresses](https://github.com/alandtse/fallout_vr_address_library) are defined yet. In fact, no VR specific structs/functions exist yet and need to be added.

## General Requirements

### Build Dependencies
* [Visual Studio Community 2019 16.10.0 Preview 3.0](https://visualstudio.microsoft.com/vs/preview/)
	* Desktop development with C++

### Development
* [clang-format 12.0.0](https://github.com/llvm/llvm-project/releases)
* [CMake](https://cmake.org/)
* [vcpkg](https://github.com/microsoft/vcpkg)

## F4SE Plugin Requirements

### End User Dependencies
* [Address Library for F4SE Plugins](https://www.nexusmods.com/fallout4/mods/47327)
* [VR Address Library for F4SEVR Plugins](https://www.nexusmods.com/fallout4/mods/64879)
* [F4SE/VR](https://f4se.silverlock.org/)

### Development
* [Address Library for F4SE Plugins](https://www.nexusmods.com/fallout4/mods/47327)
* [VR Address Library for F4SEVR Plugins](https://www.nexusmods.com/fallout4/mods/64879)

## Credits
* Thanks to [Ryan McKenzie](https://github.com/Ryan-rsm-McKenzie) for original code
* Thanks to [CharmedBaryon](https://github.com/CharmedBaryon) for [NG code](https://github.com/CharmedBaryon/CommonLibSSE-NG) and initial porting to F4 by [alandtse](https://github.com/alandtse)
* Thanks to maintainers of active forks:
	[po3](https://github.com/powerof3/CommonLibF4)
	[shad0wshayd3](https://github.com/shad0wshayd3/CommonLibF4)