# Tools

This directory contains utility scripts and tools for CommonLibF4 development.

## Available Tools

### build_all_presets.ps1
PowerShell script to build all CommonLibF4 runtime presets in sequence.

**Usage:**
```powershell
# From the project root
./tools/build_all_presets.ps1
```

**What it does:**
- Builds all runtime presets: `all`, `flat`, `ng`, `f4`, `vr`
- Provides colored output for easy status tracking
- Exits on first failure to catch issues early
- Useful for contributors to test changes across all configurations

**Requirements:**
- PowerShell (available by default on Windows)
- xmake installed and configured
- Visual Studio 2022 with C++ development tools

## Adding New Tools

When adding new tools to this directory:
1. Use descriptive names
2. Include usage instructions in this README
3. Add appropriate error handling
4. Consider cross-platform compatibility when possible 