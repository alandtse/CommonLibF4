# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

CommonLibF4 is a comprehensive C++ library for Fallout 4 modding that provides reverse-engineered game structures and utilities for F4SE (Fallout Script Extender) plugin development. It supports multiple Fallout 4 runtime variants through a sophisticated multi-runtime system.

## Build System Commands

### Primary Build Commands
```bash
# Quick start (all runtimes)
xmake f --runtime_preset=all
xmake build -v

# Clean build
xmake clean --all
xmake f --runtime_preset=all
xmake build -v

# Cross-platform build via WSL interop
cmd.exe /c "xmake config --runtime_preset=all && xmake build"
```

### Runtime Presets
- `all` - All supported runtimes (Pre-NG F4, NG, VR) - **default**
- `flat` - F4 Pre-NG + NG (no VR)
- `ng` - Next-Gen F4 only (1.10.984+)
- `f4` - Pre-NG F4 only (1.10.163)  
- `vr` - VR only (1.2.72)

```bash
# Build specific runtime
xmake f --runtime_preset=ng && xmake build -v

# Manual runtime configuration
xmake f --fallout_f4=y --fallout_f4ng=n --fallout_f4vr=n
xmake build -v
```

### Testing All Presets
```powershell
# Automated testing (parallel builds)
./tools/build_all_presets.ps1

# Sequential builds
./tools/build_all_presets.ps1 -Sequential
```

## Architecture Overview

### Multi-Runtime System
The core innovation is a template-based RelocationID system supporting 1-3 runtime variants:

```cpp
// Multi-runtime RelocationID usage
REL::RelocationID myFunc{1243, 5678};        // Pre-NG: 1243, NG: 5678  
REL::RelocationID legacyFunc{1234, 0};       // NG falls back to Pre-NG
REL::RelocationID allVersions{1234, 5678, 9012}; // Pre-NG, NG, VR

// Runtime detection
if (REL::IsF4()) { /* Pre-NG logic */ }
if (REL::IsNG()) { /* Next-Gen logic */ }  
if (REL::IsVR()) { /* VR logic */ }
```

### Shared Library Integration
Built on **commonlib-shared** with automatic dependency resolution:
- **Local development**: Uses `lib/commonlib-shared/` submodule when present
- **Remote package**: Automatically downloads compatible version via XMake
- **Seamless switching**: No code changes required between modes

Key shared library namespaces:
- `REL::` - Relocation utilities, hooks, trampolines, patterns
- `REX::` - Cross-platform utilities (Windows, PS4, general)

### Header Organization  
```
include/
├── F4SE/           # F4SE API integration
├── RE/             # Reverse-engineered game structures (1000+ headers)
│   └── A-Z/        # Alphabetically organized by class name
├── REL/            # Relocation & multi-runtime system
│   ├── F4/         # F4-specific runtime detection
│   └── IDDB.h      # F4-specific ID database extensions
└── Scaleform/      # UI system headers
```

### Key Implementation Files
- `include/REL/REL.h` - Main integration point with commonlib-shared
- `include/REL/F4/Runtime.h` - F4-specific runtime detection logic
- `src/REL/F4/Runtime.cpp` - Runtime detection implementation
- `xmake.lua` - Build configuration with dual dependency modes

## Configuration System

### Compiler Defines
The system uses compile-time configuration via XMake:
```lua
-- Force 3-runtime RelocationID for both local and remote cases
add_defines("REL_DEFAULT_RUNTIME_COUNT=3", { public = true })

-- Runtime enablement (configured via presets)
add_defines("ENABLE_FALLOUT_F4=1", { public = true })
add_defines("ENABLE_FALLOUT_NG=1", { public = true })  
add_defines("ENABLE_FALLOUT_VR=1", { public = true })
```

### Package Management
XMake automatically handles commonlib-shared dependency:
```lua
-- Remote package (when lib/commonlib-shared not present)
add_requires("commonlib-shared latest")

-- Local submodule (when lib/commonlib-shared exists)  
add_includedirs("lib/commonlib-shared/include", { public = true })
```

## Development Patterns

### Adding New RelocationIDs
When adding game function addresses:
1. Use appropriate runtime count based on availability
2. Zero values automatically fall back to first available ID
3. Test across all runtime presets before committing

```cpp
// Example: Function exists in Pre-NG and NG, but not VR
REL::RelocationID CreateObject{0x1234567, 0x2345678, 0}; // VR falls back to Pre-NG
```

### Header File Organization
- Follow alphabetical organization in `RE/` directory
- Split large monolithic headers into focused files
- Use appropriate namespaces: `RE::`, `REL::`, `F4SE::`

### Testing Requirements
Always test changes across all runtime presets:
```bash
# Required before submitting PRs
./tools/build_all_presets.ps1
```

## Troubleshooting

### Common Build Issues
1. **Missing headers**: Ensure commonlib-shared is properly installed
2. **RelocationID compilation errors**: Check `REL_DEFAULT_RUNTIME_COUNT` configuration
3. **Runtime detection failures**: Verify F4-specific runtime detection logic
4. **Cross-compilation issues**: Use WSL interop with Windows toolchain

### Dependency Resolution
- **Local development**: Clone with `--recursive` or run `git submodule update --init --recursive`
- **Remote package**: Let XMake handle automatic download
- **Cache issues**: Use `xmake clean --all` to clear build cache

## Key Files for Understanding

### Core Architecture
- `xmake.lua` - Build system and dependency management
- `include/REL/REL.h` - Integration layer with commonlib-shared
- `include/REL/F4/Runtime.h` - Multi-runtime detection system

### Development Tools
- `tools/build_all_presets.ps1` - Automated multi-runtime testing
- `res/commonlibf4.natvis` - Visual Studio debugging visualizers

### Documentation
- `README.md` - Complete build and usage instructions
- `MISSING_FILES_ANALYSIS.md` - Header refactoring progress tracking
- `RELOCATION_ID_DESIGN.md` - Multi-runtime system design documentation