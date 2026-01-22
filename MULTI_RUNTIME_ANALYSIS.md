# Multi-Runtime Support Analysis and Implementation Plan

## Executive Summary

This document outlines the current state of multi-runtime support in CommonLibF4, analyzes what work has been completed, and provides a comprehensive plan to finish the implementation while rebasing onto the latest upstream (libxse/commonlibf4).

**Date:** 2026-01-21  
**Branch:** clean-upstream-structure  
**Upstream:** libxse/commonlibf4 (main branch at 7c36cdd6)

## Background

### Fallout 4 Runtime Variants

As of January 2026, Fallout 4 has **four major runtime variants**:

1. **Pre-NG (1.10.163)** - Original Fallout 4 before Next-Gen update
2. **NG (1.10.984+)** - Next-Gen update with significant internal changes
3. **VR (1.2.72)** - VR edition (shares most IDs with Pre-NG)
4. **AE (1.11.137)** - Anniversary Edition released November 10, 2025

### Project Goals

- **Primary:** Support AE/VR as main target (future-focused)
- **Secondary:** Maintain Pre-NG/NG support as long as it's not a maintenance nightmare
- **Architecture:** Use libxse's multi-runtime RelocationID system from commonlib-shared

## Current State Analysis

### What Has Been Done

#### 1. commonlib-shared Integration (✅ Complete)
- Submodule at `lib/commonlib-shared` pointing to alandtse fork
- Contains full multi-runtime `RelocationID<N>` implementation
- Provides `REL::ID.h` with smart fallback logic
- Current commit: 125a4f5 (feat: add multi-runtime support)

#### 2. F4-Specific Runtime Files (✅ Created)
Three new files in `include/REL/F4/`:
- **Config.h** - Defines `REL_DEFAULT_RUNTIME_COUNT` and runtime indices
- **Runtime.h** - Forward declares runtime detection functions
- **Module.h** - F4-specific Module singleton wrapper

#### 3. Runtime Detection Implementation (✅ Complete)
File: `src/REL/Runtime.cpp`
- Implements `REL::get_runtime_index()` (required by commonlib-shared)
- Detects VR vs F4 vs NG based on executable and version
- Supports both compile-time (single runtime) and runtime detection (multi-runtime)

#### 4. XMake Build System (✅ Functional)
File: `xmake.lua`
- Runtime preset system (`all`, `flat`, `ng`, `f4`, `vr`)
- Defines `ENABLE_FALLOUT_F4`, `ENABLE_FALLOUT_NG`, `ENABLE_FALLOUT_VR`
- Sets `REL_DEFAULT_RUNTIME_COUNT` based on enabled runtimes
- Currently supports 1, 2, or 3 runtime configurations

#### 5. Documentation (✅ Created)
- `RELOCATION_ID_DESIGN.md` - Comprehensive design document
- `MISSING_FILES_ANALYSIS.md` - Analysis of upstream merge
- `.claude/CLAUDE.md` - Development notes

### What Needs To Be Done

#### 1. Add AE Runtime Support (❌ Not Started)

**Required Changes:**

a) **Runtime Detection** (`src/REL/Runtime.cpp`)
   - Add `AE` to `Runtime` enum
   - Update version detection logic to distinguish AE (1.11.137)
   - Current logic only checks for NG (>= 1.10.980)
   
b) **Runtime Indices** (`include/REL/F4/Config.h`)
   - Current: 2-runtime system (Pre-NG+VR, NG)
   - Need: 4-runtime system (Pre-NG, NG, VR, AE)
   - Define new `RuntimeIndex4` enum

c) **XMake Configuration** (`xmake.lua`)
   - Add `fallout_f4ae` option
   - Update runtime presets to include AE
   - Add new preset: `ae` (AE-only build)
   - Update `all` preset to include AE

d) **Runtime Index Mapping** (`src/REL/Runtime.cpp`)
   - Update `get_runtime_index()` to handle 4-runtime builds
   - Map AE to correct index based on build configuration

#### 2. Rebase onto Latest Upstream (❌ Not Started)

**Upstream State:**
- Remote: libxse/commonlibf4
- Branch: main
- Latest commit: 7c36cdd6 (feat: add rotating log option)
- Notable: Already includes AE support work (commit 34736526: "misc RE, last before AE")
- Notable: Version 1.11.137 support added (commit 765b0771)

**Merge Strategy:**
1. Create backup of current work
2. Fetch latest upstream
3. Rebase `clean-upstream-structure` onto `upstream/main`
4. Resolve conflicts (likely in REL/ files)
5. Preserve our multi-runtime changes

**Potential Conflicts:**
- Upstream has **removed** old REL files (Common.h, Config.h, Module.h, etc.)
- Upstream now uses commonlib-shared as submodule (commit 6ab4fdb8)
- Our branch has custom F4-specific REL implementation
- Need to ensure compatibility between our F4 layer and upstream changes

#### 3. Update commonlib-shared Submodule (❌ Not Started)

**Current State:**
- Points to alandtse/commonlib-shared
- Commit: 125a4f5 (feat: add multi-runtime support)

**Action Needed:**
- Check if upstream (libxse/commonlib-shared) has newer multi-runtime features
- Potentially rebase our changes onto libxse upstream
- Ensure 4-runtime support in RelocationID

#### 4. Complete ID Migration (⚠️ Partial)

**Status:**
- Upstream has extensive ID updates for version 1.11.137
- Our branch may be missing these updates
- Need to review `include/RE/IDs.h` and related files

#### 5. Testing & Validation (❌ Not Started)

**Test Plan:**
a) Build all runtime configurations:
   - Single runtime: f4, ng, vr, ae
   - Dual runtime: f4+ng, f4+ae, ng+ae, vr+ae
   - Triple runtime: f4+ng+vr, f4+ng+ae, f4+vr+ae, ng+vr+ae
   - Quad runtime: f4+ng+vr+ae

b) Runtime detection verification
c) RelocationID resolution correctness
d) IDDB loading for each runtime

## Implementation Plan

### Phase 1: Backup and Preparation (CRITICAL)

**Actions:**
1. ✅ Create this analysis document
2. ⏳ Create comprehensive git stash with all current work
3. ⏳ Tag current state: `pre-ae-rebase`
4. ⏳ Document all custom changes vs upstream

**Commands:**
```bash
git tag -a pre-ae-rebase -m "State before AE support and upstream rebase"
git stash push -u -m "Complete state before AE implementation - $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
```

### Phase 2: Add AE Runtime Support

**Priority: HIGH**  
**Estimated Time: 2-3 hours**

#### Step 2.1: Update Runtime Enum and Detection

**File: `include/REL/F4/Runtime.h`**
```cpp
enum class Runtime
{
    Unknown,  // Unknown runtime
    F4,       // Pre-NG Fallout 4 (1.10.163)
    NG,       // Next-Gen Fallout 4 (1.10.984+)
    VR,       // Fallout 4 VR (1.2.x)
    AE        // Anniversary Edition (1.11.137+)
};
```

**File: `src/REL/Runtime.cpp`**
```cpp
// Update version detection
if (version.major() == 1 && version.minor() == 11 && version.patch() >= 137) {
    g_runtime = Runtime::AE;
} else if (version.major() == 1 && version.minor() == 10 && version.patch() >= 980) {
    g_runtime = Runtime::NG;
} else {
    g_runtime = Runtime::F4;
}
```

#### Step 2.2: Add 4-Runtime Configuration

**File: `include/REL/F4/Config.h`**
```cpp
// Add 4-runtime indices
enum RuntimeIndex4 : std::size_t
{
    PRE_NG_4 = 0,  // Pre-NG
    NG_4 = 1,      // Next-Gen
    VR_4 = 2,      // VR
    AE_4 = 3       // Anniversary Edition
};
```

**File: `src/REL/Runtime.cpp`**
Update `get_runtime_index()` to handle 4-runtime builds.

#### Step 2.3: Update XMake Build Configuration

**File: `xmake.lua`**
- Add `fallout_f4ae` option
- Update runtime presets
- Add AE to runtime count calculation

### Phase 3: Rebase onto Upstream

**Priority: HIGH**  
**Estimated Time: 4-6 hours**

#### Step 3.1: Fetch and Analyze
```bash
git fetch upstream
git diff HEAD upstream/main --stat
git log HEAD..upstream/main --oneline
```

#### Step 3.2: Interactive Rebase
```bash
git rebase -i upstream/main
```

**Expected Conflicts:**
- REL/ directory structure (we have F4/ subfolder, upstream uses commonlib-shared)
- xmake.lua (we have extensive runtime configuration)
- src/REL/ files (different runtime implementation)

**Resolution Strategy:**
- Keep our F4-specific REL layer
- Adopt upstream commonlib-shared updates
- Merge runtime configurations

#### Step 3.3: Verify Build
```bash
xmake f --runtime_preset=all
xmake build -v
```

### Phase 4: Commonlib-Shared Updates

**Priority: MEDIUM**  
**Estimated Time: 2-3 hours**

#### Step 4.1: Check Upstream Commonlib-Shared
```bash
cd lib/commonlib-shared
git fetch upstream
git log HEAD..upstream/main --oneline
```

#### Step 4.2: Update if Needed
- Verify 4-runtime support in `RelocationID<N>`
- Test with N=4 configuration

### Phase 5: Testing and Validation

**Priority: HIGH**  
**Estimated Time: 3-4 hours**

#### Step 5.1: Build Matrix Testing
Test all runtime configurations:
- Single: f4, ng, vr, ae
- Dual: f4+ng, f4+ae, ng+ae, vr+ae, f4+vr, ng+vr
- Triple: f4+ng+vr, f4+ng+ae, f4+vr+ae, ng+vr+ae
- Quad: f4+ng+vr+ae

#### Step 5.2: Runtime Detection Testing
Create test program to verify:
- Correct runtime detected at startup
- Correct runtime index returned
- RelocationID selects correct ID

#### Step 5.3: Integration Testing
- Test with F4SE plugin
- Verify IDDB loading
- Test address resolution

## Technical Architecture

### Multi-Runtime System Overview

```
┌─────────────────────────────────────────────────────────┐
│                  Game-Specific Layer                     │
│         (CommonLibF4: include/REL/F4/)                   │
│                                                          │
│  ┌────────────┐  ┌────────────┐  ┌──────────────┐      │
│  │ Config.h   │  │ Runtime.h  │  │  Module.h    │      │
│  │            │  │            │  │              │      │
│  │ - Indices  │  │ - Detection│  │ - Singleton  │      │
│  │ - Fallback │  │ - IsVR()   │  │ - Wrapper    │      │
│  └────────────┘  └────────────┘  └──────────────┘      │
└─────────────────────────────────────────────────────────┘
                        │
                        │ get_runtime_index()
                        ▼
┌─────────────────────────────────────────────────────────┐
│              Shared Library Layer                        │
│       (commonlib-shared: include/REL/)                   │
│                                                          │
│  ┌────────────────────────────────────────────┐         │
│  │         RelocationID<N>                    │         │
│  │                                            │         │
│  │  - Smart fallback logic                   │         │
│  │  - Compile-time optimization              │         │
│  │  - Runtime selection via get_runtime_index│         │
│  │  - IDDB integration                       │         │
│  └────────────────────────────────────────────┘         │
│                                                          │
│  ┌────────────┐  ┌────────────┐  ┌──────────────┐      │
│  │   IDDB.h   │  │  Module.h  │  │  Version.h   │      │
│  └────────────┘  └────────────┘  └──────────────┘      │
└─────────────────────────────────────────────────────────┘
```

### 4-Runtime Configuration Example

```cpp
// include/RE/IDs.h
namespace RE::ID {
    namespace Actor {
        // Pre-NG: 187096, NG: 2230121, VR: 187096 (fallback), AE: 2340567
        inline constexpr REL::RelocationID<4> AddPerk{
            187096,    // [0] Pre-NG
            2230121,   // [1] NG
            0,         // [2] VR (falls back to Pre-NG)
            2340567    // [3] AE
        };
        
        // When VR fallback is automatic, can use 3-param constructor
        inline constexpr REL::RelocationID<4> RemovePerk{
            187097,    // [0] Pre-NG
            2230122,   // [1] NG
            2340568    // [2] AE
            // VR will automatically fall back to Pre-NG
        };
    }
}
```

### Runtime Index Mapping (4-Runtime Build)

```cpp
std::size_t get_runtime_index() noexcept {
    const auto runtime = F4::GetRuntime();
    
    #if defined(ENABLE_FALLOUT_F4) && defined(ENABLE_FALLOUT_NG) && \
        defined(ENABLE_FALLOUT_VR) && defined(ENABLE_FALLOUT_AE)
        // Four runtime build
        switch (runtime) {
            case F4::Runtime::F4:  return 0;  // Pre-NG
            case F4::Runtime::NG:  return 1;  // NG
            case F4::Runtime::VR:  return 2;  // VR
            case F4::Runtime::AE:  return 3;  // AE
            default:               return 0;
        }
    #elif ...
    // Other configurations
    #endif
}
```

## Risks and Mitigation

### Risk 1: Upstream Conflicts During Rebase
**Severity:** HIGH  
**Mitigation:**
- Comprehensive backup via git stash and tags
- Incremental rebase with conflict resolution
- Ability to rollback to `pre-ae-rebase` tag

### Risk 2: AE Address Database Availability
**Severity:** MEDIUM  
**Mitigation:**
- Check if AE address library exists at nexusmods
- May need to wait for community to generate IDDB
- Can support AE structurally even if IDDB not ready

### Risk 3: Build Complexity
**Severity:** MEDIUM  
**Mitigation:**
- Maintain simple runtime presets (`ae`, `all`)
- Document build configurations clearly
- Provide PowerShell script for testing all configs

### Risk 4: Maintenance Burden
**Severity:** MEDIUM  
**Mitigation:**
- Focus on AE/VR as primary targets (per goals)
- Allow Pre-NG/NG to gracefully degrade if needed
- Use fallback logic extensively to minimize ID duplication

## Success Criteria

1. ✅ Clean build of all runtime configurations
2. ✅ Correct runtime detection for all 4 variants
3. ✅ RelocationID resolves to correct addresses
4. ✅ Successfully rebased onto latest upstream
5. ✅ No regressions in existing Pre-NG/NG/VR support
6. ✅ Documentation updated
7. ✅ All tests pass

## Timeline Estimate

- **Phase 1 (Backup):** 30 minutes
- **Phase 2 (AE Support):** 2-3 hours
- **Phase 3 (Rebase):** 4-6 hours
- **Phase 4 (Commonlib-shared):** 2-3 hours
- **Phase 5 (Testing):** 3-4 hours

**Total:** 12-17 hours of development work

## Next Steps

1. **IMMEDIATE:** Create backup (tag + stash)
2. **SHORT TERM:** Implement AE runtime support (Phase 2)
3. **MEDIUM TERM:** Rebase onto upstream/main (Phase 3)
4. **LONG TERM:** Complete testing and validation (Phase 5)

## References

- [libxse/commonlibf4](https://github.com/libxse/commonlibf4)
- [alandtse/commonlib-shared](https://github.com/alandtse/commonlib-shared)
- [Fallout 4 AE Announcement](https://fallout.bethesda.net/en/article/N00XVTawnzBBH7HNwv0hN/fallout-4-anniversary-edition)
- [Nexus Mods F4 AE Update News](https://www.nexusmods.com/news/15400)

---

**Document Status:** DRAFT  
**Last Updated:** 2026-01-21  
**Author:** AI Analysis  
**Review Status:** Pending User Approval
