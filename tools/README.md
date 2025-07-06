# Tools

This directory contains utility scripts and tools for CommonLibF4 development.

## Available Tools

### build_all_presets.ps1
PowerShell script to build all CommonLibF4 runtime presets. **Parallel build is now the default.**

**Usage:**
```powershell
# From the project root

# Parallel build (default, up to 5 concurrent jobs)
./tools/build_all_presets.ps1

# Parallel build with custom max concurrent jobs
./tools/build_all_presets.ps1 -MaxJobs 6

# Sequential build (one preset at a time)
./tools/build_all_presets.ps1 -Sequential
```

**Parameters:**
- `-Sequential`: Build presets one at a time (sequential mode)
- `-MaxJobs <number>`: Maximum number of concurrent build jobs in parallel mode (default: 5)

**Features:**
- **Parallel by Default**: Builds all runtime presets in parallel for faster results
- **Timing Information**: Shows total elapsed time and individual job completion times
- **Real-time Status**: Displays which jobs are running and their completion status
- **Detailed Summary**: Reports success/failure counts and individual job performance
- **Error Handling**: Captures and reports build errors from parallel jobs
- **Performance Metrics**: Sorts jobs by duration to identify slowest builds

**What it does:**
- Builds all runtime presets: `all`, `flat`, `ng`, `f4`, `vr`
- Provides colored output for easy status tracking
- Shows timing breakdown for performance analysis
- Returns appropriate exit codes for CI/CD integration

**Output Example:**
```
Building presets in parallel (max 5 concurrent jobs)...
Total presets to build: 5

Starting build for preset: all
Starting build for preset: flat
Starting build for preset: ng
Starting build for preset: f4
Starting build for preset: vr

[SUCCESS] flat completed in 00:45.123
[SUCCESS] ng completed in 01:12.456
[SUCCESS] all completed in 01:23.789
[SUCCESS] f4 completed in 00:38.234
[SUCCESS] vr completed in 00:52.567

=== Parallel Build Summary ===
Total elapsed time: 01:23.789
Successful builds: 5/5

=== Individual Job Times ===
[PASS] all: 01:23.789
[PASS] ng: 01:12.456
[PASS] vr: 00:52.567
[PASS] flat: 00:45.123
[PASS] f4: 00:38.234
```

**What it does:**
- Builds all runtime presets: `all`, `flat`, `ng`, `f4`, `vr`
- Provides colored output for easy status tracking
- Exits on first failure to catch issues early
- **Sequential mode**: Builds presets one after another
- **Parallel mode**: Builds multiple presets simultaneously for faster overall build time
- Useful for contributors to test changes across all configurations

**Performance Notes:**
- **Sequential builds**: Slower but easier to debug, uses less system resources
- **Parallel builds**: Faster overall but uses more CPU/memory, may be harder to debug
- Each xmake process also uses parallel compilation internally (`-j` option)
- Recommended to use parallel builds on systems with sufficient resources (8+ cores, 16GB+ RAM)

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