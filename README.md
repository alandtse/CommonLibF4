# CommonLibF4

A comprehensive library for Fallout 4 modding, providing reverse-engineered game structures and utilities for F4SE plugin development.

## General Requirements

### Build Dependencies
* [Visual Studio Community 2022 Preview][vs_preview]
	* Desktop development with C++
* [xmake][xmake] - Build system
* [binary-io][binary_io]
* [mmio][mmio]
* [spdlog][spdlog]

### Development
* [xmake][xmake]

## Building

### Prerequisites
1. Install [xmake][xmake] globally
2. Install Visual Studio 2022 with C++ development tools
3. Clone the repository (submodules are optional):
   ```bash
   # Option 1: Clone without submodules (recommended for most users)
   git clone https://github.com/alandtse/CommonLibF4.git
   cd CommonLibF4
   
   # Option 2: Clone with submodules (for development/contributing)
   git clone --recursive https://github.com/alandtse/CommonLibF4.git
   cd CommonLibF4
   ```

### Build Instructions

#### Quick Start
```bash
# Configure and build with all runtimes enabled (default)
xmake f --runtime_preset=all
xmake build -v
```

#### Runtime Presets
CommonLibF4 supports multiple Fallout 4 runtime configurations:

- **all** - Build for all supported runtimes (default)
- **flat** - Build for flat runtime only (F4 and NG)
- **ng** - Build for Next Generation runtime only (1.10.984)  
- **f4** - Build for pre next Generation Fallout 4 runtime only (1.10.163)
- **vr** - Build for VR runtime only (1.2.72)

```bash
# Build for specific runtime
xmake f --runtime_preset=flat
xmake build -v

# Build for Next Generation
xmake f --runtime_preset=ng
xmake build -v

# Build for VR
xmake f --runtime_preset=vr
xmake build -v
```

#### Manual Runtime Configuration
You can also manually configure which runtimes to build:

```bash
# Enable specific runtimes
xmake f --fallout_f4=y --fallout_f4ng=n --fallout_f4vr=n
xmake build -v
```

#### Clean Build
```bash
# Clean previous builds
xmake clean

# Rebuild from scratch
xmake f --runtime_preset=all
xmake build -v
```

### Output
Built libraries will be placed in the `build/` directory, organized by runtime configuration.

### Automatic Dependency Management
CommonLibF4 automatically handles the `commonlib-shared` dependency:

- **Without submodules**: xmake automatically downloads the latest compatible version from the remote package repository
- **With submodules**: Uses the local `extern/commonlib-shared` directory for development
- **Fallback**: If local submodule is missing, automatically falls back to remote package

This means you don't need to manually manage the shared library - it's handled automatically during the build process.

## Shared Library

CommonLibF4 includes `commonlib-shared`, a GPL-3.0 licensed shared utilities library that provides relocation utilities, cross-platform APIs, and optional features like INI/JSON/TOML parsing and xbyak support.

For detailed information about the shared library's capabilities and configuration options, see the [commonlib-shared documentation][commonlib_shared].

## F4SE Plugin Requirements

### End User Dependencies
* [Address Library for F4SE Plugins][address_library]
* [VR Address Library for F4SEVR Plugins][vr_address_library]
* [F4SE/VR][f4se]


## Project Structure

- `include/` - Header files organized by namespace
  - `F4SE/` - F4SE API headers
  - `RE/` - Reverse-engineered game structures
  - `REL/` - Relocation and runtime utilities
  - `Scaleform/` - Scaleform UI headers
- `src/` - Source files
- `extern/` - External dependencies
  - `commonlib-shared/` - Shared utilities library (GPL-3.0 licensed)
    - `REL/` - Relocation utilities (hooks, trampolines, patterns)
    - `REX/` - Cross-platform utilities (Windows, PS4, general utilities)
- `res/` - Resources and build scripts
- `tools/` - Development and build utility scripts

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test with multiple runtime presets
5. Submit a pull request

### Testing Multiple Runtimes

To ensure your changes work across all supported Fallout 4 runtimes, you should test every runtime preset before submitting a pull request.

**Recommended:** Use the provided PowerShell script to build all presets automatically:

```powershell
# From the project root
./tools/build_all_presets.ps1
```

This script will sequentially build the following presets: `all`, `flat`, `ng`, `f4`, and `vr`.

If you prefer, you can run the commands manually:

```powershell
xmake f --runtime_preset=all; xmake build -v
xmake f --runtime_preset=flat; xmake build -v
xmake f --runtime_preset=ng; xmake build -v
xmake f --runtime_preset=f4; xmake build -v
xmake f --runtime_preset=vr; xmake build -v
```

> **Note:** Most users on Windows will have PowerShell available by default.

## License

[GPL-3.0-or-later][LICENSE] WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS).

Specifically, the **Modded Code** is Fallout 4 (and its variants) and **Modding Libraries** include [F4SE][f4se] ([GitHub link][f4se_github]).

### Explanation
It is recommended to read the [FSF FAQ][fsf_faq] for a full explanation on what this license requires.

The main requirement of this license is: if you link your mod against CommonLib, and you distribute the binaries for that mod, you must also distribute the source code under the same license as CommonLib along with the source code for any other libraries you link against, with the exception of the Modded Code and Modding Libraries defined above.

To the extent that you want the [MIT licensed code][CommonLib_MIT], please reference [CommonLibF4 and its forks][CommonLibF4].

## Credits

- Thanks to [Ryan McKenzie][ryan_mckenzie] for original code
- Thanks to [CharmedBaryon][charmed_baryon] for [NG code][ng_code] and initial porting to F4 by [alandtse][alandtse]
- Thanks to maintainers of active forks:
  [po3][po3]
  [shad0wshayd3][shad0wshayd3]


[vs_preview]: https://visualstudio.microsoft.com/vs/preview/
[xmake]: https://xmake.io/
[binary_io]: https://github.com/Ryan-rsm-McKenzie/binary_io
[mmio]: https://github.com/Ryan-rsm-McKenzie/mmio
[spdlog]: https://github.com/gabime/spdlog
[address_library]: https://www.nexusmods.com/fallout4/mods/47327
[vr_address_library]: https://www.nexusmods.com/fallout4/mods/64879
[f4se]: https://f4se.silverlock.org/
[f4se_github]: https://github.com/ianpatt/f4se
[fsf_faq]: https://www.gnu.org/licenses/gpl-faq.en.html
[ryan_mckenzie]: https://github.com/Ryan-rsm-McKenzie
[charmed_baryon]: https://github.com/CharmedBaryon
[ng_code]: https://github.com/CharmedBaryon/CommonLibSSE-NG
[alandtse]: https://github.com/alandtse
[po3]: https://github.com/powerof3/CommonLibF4
[shad0wshayd3]: https://github.com/shad0wshayd3/CommonLibF4
[commonlib_shared]: https://github.com/alandtse/commonlib-shared
[CommonLib_MIT]: LICENSE_HISTORICAL
[LICENSE]: COPYING
[CommonLibF4]: https://github.com/Ryan-rsm-McKenzie/CommonLibF4