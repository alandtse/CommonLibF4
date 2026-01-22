# Smart RelocationID Design for commonlib-shared

## Overview

This design provides a flexible multi-runtime RelocationID system with smart fallback logic that can be upstreamed to commonlib-shared to benefit all CommonLib projects.

## Key Features

### 1. Smart Fallback Logic
```cpp
// If second ID is 0, automatically falls back to first ID
REL::RelocationID<2> SomeFunction{ 1243, 0 };  // NG falls back to Pre-NG ID

// Three-runtime example with selective fallbacks
REL::RelocationID<3> ComplexFunction{ 1000, 0, 3000 };  // Runtime 1 falls back to 1000, Runtime 2 uses 3000
```

### 2. Configurable Runtime Mapping
```cpp
// F4 Example - 2 runtimes (Pre-NG+VR share, NG separate)
using F4RelocationID = REL::RelocationID<2>;
F4RelocationID AddPerk{ 187096, 2230121 };  // Pre-NG+VR: 187096, NG: 2230121

// F4 Example - 3 runtimes (explicit VR support)  
using F4RelocationID3 = REL::RelocationID<3>;
F4RelocationID3 SomeFunc{ 1000, 2000, 1000 };  // Pre-NG: 1000, NG: 2000, VR: 1000 (explicit)

// Skyrim Example - 3 runtimes (LE/SSE, AE, VR)
using SkyrimRelocationID = REL::RelocationID<3>;
SkyrimRelocationID PlayerUpdate{ sse_id, ae_id, vr_id };
```

### 3. Flexible Patterns for Different Games

#### Pattern 1: F4 Traditional (VR shares Pre-NG)
```cpp
// Index 0: Pre-NG + VR (shared)
// Index 1: NG
REL::RelocationID<2> MyFunction{ 1243, 5678 };
```

#### Pattern 2: F4 Explicit VR
```cpp  
// Index 0: Pre-NG
// Index 1: NG  
// Index 2: VR (explicit)
REL::RelocationID<3> MyFunction{ 1243, 5678, 1243 };  // VR explicitly set to Pre-NG value
```

#### Pattern 3: Skyrim (SSE, AE, VR relative offset)
```cpp
// Index 0: SSE base
// Index 1: AE  
// Index 2: VR (base + offset)
REL::RelocationID<3> MyFunction{ sse_id, ae_id, vr_offset };
```

## API Design

### Core Methods
```cpp
template<std::size_t N = 2>
class RelocationID {
    // Smart resolution with fallback
    std::uint64_t resolve_id(std::size_t runtime_index) const;
    
    // Check if runtime has explicit ID (not using fallback)
    bool has_explicit_id(std::size_t runtime_index) const;
    
    // Access raw ID before fallback resolution
    std::uint64_t raw_id(std::size_t index) const;
    
    // Configurable fallback strategy (can be specialized per game)
    std::uint64_t resolve_fallback_for_runtime(std::size_t runtime_index) const;
};
```

### Usage Examples

### Configuration-First Approach

#### Step 1: Downstream Configuration (F4 Example)
```cpp
// include/REL/Config.h - F4-specific
#pragma once

// Configure default runtime count for entire library
#define REL_DEFAULT_RUNTIME_COUNT 2

namespace REL::F4 {
    enum RuntimeIndex : std::size_t {
        PRE_NG_VR = 0,  // Pre-NG and VR share IDs
        NG = 1          // Next-Gen separate
    };
}
```

#### Step 2: Clean Usage Everywhere
```cpp
#include "REL/Config.h"  // Must be first

namespace RE::ID::Actor {
    // Clean! No template parameters needed
    inline constexpr REL::RelocationID AddPerk{ 187096, 2230121 };
    
    // Pre-NG only - NG falls back to Pre-NG
    inline constexpr REL::RelocationID LegacyFunction{ 123456, 0 };
    
    // NG only - Pre-NG falls back to NG  
    inline constexpr REL::RelocationID NewFunction{ 0, 654321 };
}
```

#### Advanced F4 Usage (Explicit VR)
```cpp
namespace RE::ID::Actor {
    // VR has different ID than Pre-NG
    inline constexpr REL::RelocationID<3> SpecialVRFunction{ 1000, 2000, 1500 };
    
    // VR shares Pre-NG, but NG is different
    inline constexpr REL::RelocationID<3> SharedFunction{ 1000, 2000, 0 };  // VR falls back to Pre-NG
}
```

#### Other Games Configuration Examples

**Skyrim Configuration:**
```cpp
// CommonLibSSE/include/REL/Config.h
#define REL_DEFAULT_RUNTIME_COUNT 3

namespace REL::Skyrim {
    enum RuntimeIndex : std::size_t {
        SSE = 0,    // Special Edition
        AE = 1,     // Anniversary Edition  
        VR = 2      // VR Edition
    };
}
```

**Skyrim Usage:**
```cpp
namespace RE::ID::Player {
    // Clean syntax across all Skyrim versions
    inline constexpr REL::RelocationID UpdatePlayer{ 12345, 23456, 34567 };
    
    // AE not mapped yet, falls back to SSE
    inline constexpr REL::RelocationID LegacyFunction{ 12345, 0, 34567 };
}
```

**Single-Runtime Game (like Oblivion):**
```cpp
// CommonLibOB/include/REL/Config.h  
#define REL_DEFAULT_RUNTIME_COUNT 1
// Now REL::RelocationID works exactly like REL::ID
```

## Benefits for Upstreaming

1. **Game Agnostic**: Works for any game with multiple runtimes
2. **Smart Defaults**: Zero values automatically fall back to available IDs
3. **Flexible Mapping**: Each game can define its own runtime index semantics
4. **Backward Compatible**: Single-runtime `REL::ID` still works unchanged
5. **Performance**: All resolution logic is `constexpr` and compile-time
6. **Debugging**: Methods to inspect raw vs resolved IDs for troubleshooting

## Migration Path

1. **Phase 1**: Add `RelocationID` to commonlib-shared (alongside existing `ID`)
2. **Phase 2**: Games adopt `RelocationID` for multi-runtime support
3. **Phase 3**: Share runtime detection logic patterns between games
4. **Phase 4**: Potential `REL::ID` and `REL::RelocationID` unification

This design solves the multi-runtime problem in a general way that benefits the entire CommonLib ecosystem!