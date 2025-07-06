-- set minimum xmake version
set_xmakever("2.8.2")

-- set project
set_project("commonlibf4")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

-- add rules
add_rules("mode.debug", "mode.releasedbg")

-- add includes
includes("lib/commonlib-shared")
includes("xmake-rules.lua")

-- define options
option("commonlib_ini", function()
    set_default(false)
    set_description("enable REX::INI settings support")
end)

option("commonlib_json", function()
    set_default(false)
    set_description("enable REX::JSON settings support")
end)

option("commonlib_toml", function()
    set_default(false)
    set_description("enable REX::TOML settings support")
end)

option("commonlib_xbyak", function()
    set_default(false)
    set_description("enable xbyak support for trampoline")
end)


-- Runtime preset option (XMake native approach)
option("runtime_preset")
    set_default("all")
    set_description("Runtime configuration preset")
    set_values("all", "flat", "ng", "f4", "vr")
option_end()


-- F4 runtime support options
option("fallout_f4")
    set_default(true)
    set_description("Enable runtime support for Fallout 4 (Pre-NG)")
    -- Defines handled manually in target to support presets
option_end()

option("fallout_f4ng")
    set_default(true)
    set_description("Enable runtime support for Fallout 4 NG")
    -- Defines handled manually in target to support presets
option_end()

option("fallout_f4vr")
    set_default(true)
    set_description("Enable runtime support for Fallout 4 VR")
    -- Defines handled manually in target to support presets
option_end()

-- Runtime preset logic will be handled in the target configuration

-- check for local commonlib-shared (for development)
local use_local_commonlib = os.isdir("extern/commonlib-shared")
local commonlib_path = "extern/commonlib-shared"

if use_local_commonlib then
    -- Add commonlib-shared dependencies manually for local version
    add_requires("spdlog", { configs = { header_only = false, wchar = true, std_format = true } })
    if has_config("commonlib_ini") then add_requires("simpleini") end
    if has_config("commonlib_json") then add_requires("nlohmann_json") end
    if has_config("commonlib_toml") then add_requires("toml11") end
    if has_config("commonlib_xbyak") then add_requires("xbyak") end
    -- CSV parsing now uses standard C++, no external dependency needed
else
    print("Using remote commonlib-shared package")
    -- Use remote package
    add_requires("commonlib-shared aa0b8a6434e170b5230e012f6b22b8a1e2a8bf2f", { configs = {
        ini = has_config("commonlib_ini"),
        json = has_config("commonlib_json"),
        toml = has_config("commonlib_toml"),
        xbyak = has_config("commonlib_xbyak")
    } })
end

-- Project-level early check for empty submodule directory
on_load(function ()
    local submodule_path = "extern/commonlib-shared"
    if os.isdir(submodule_path) then
        local files = os.files(path.join(submodule_path, "**"))
        if #files == 0 then
            raise("commonlib-shared submodule directory exists but is empty!\nPlease run: git submodule update --init --recursive\nIf you want to use the fallback, remove the extern/commonlib-shared directory before building.")
        end
    end
end)

-- define targets
target("commonlibf4", function()
    -- set target kind
    set_kind("static")

    -- set build by default
    set_default(os.scriptdir() == os.projectdir())

    -- conditionally add commonlib-shared (local vs remote)
    if use_local_commonlib then
        -- Use local submodule
        add_includedirs(commonlib_path .. "/include", { public = true })
        add_files(commonlib_path .. "/src/**.cpp")
        
        -- Add commonlib-shared dependencies
        add_packages("spdlog", { public = true })
        if has_config("commonlib_ini") then add_packages("simpleini", { public = true }) end
        if has_config("commonlib_json") then add_packages("nlohmann_json", { public = true }) end
        if has_config("commonlib_toml") then add_packages("toml11", { public = true }) end
        if has_config("commonlib_xbyak") then add_packages("xbyak", { public = true }) end
        
    else
        -- Use remote package
        add_deps("commonlib-shared", { public = true })
    end

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("include", { public = true })
    add_headerfiles(
        "include/(F4SE/**.h)",
        "include/(RE/**.h)",
        "include/(REL/**.h)",
        "include/(Scaleform/**.h)"
    )

    -- add extra files
    add_extrafiles("res/commonlibf4.natvis")

    -- set precompiled header
    set_pcxxheader("include/F4SE/Impl/PCH.h")

    -- add flags
    add_cxxflags("/EHsc", "/permissive-", { public = true })

    -- add flags (cl)
    add_cxxflags(
        "cl::/bigobj",
        "cl::/cgthreads8",
        "cl::/diagnostics:caret",
        "cl::/external:W0",
        "cl::/fp:contract",
        "cl::/fp:except-",
        "cl::/guard:cf-",
        "cl::/Zc:preprocessor",
        "cl::/Zc:templateScope"
    )

    -- add flags (cl: disable warnings)
    add_cxxflags(
        "cl::/wd4200", -- nonstandard extension used : zero-sized array in struct/union
        "cl::/wd4201", -- nonstandard extension used : nameless struct/union
        "cl::/wd4324", -- structure was padded due to alignment specifier
        { public = true }
    )

    -- add flags (cl: warnings -> errors)
    add_cxxflags(
        "cl::/we4715", -- not all control paths return a value
        { public = true }
    )

    -- Runtime options handled manually in on_config to support presets
    
    -- Print configuration summary once configuration is resolved
    on_config(function(target)
        local preset = get_config("runtime_preset") or "all"
        
        -- Determine effective runtime configuration based on preset
        local f4_enabled, ng_enabled, vr_enabled
        
        if preset == "flat" then
            f4_enabled, ng_enabled, vr_enabled = true, true, false
        elseif preset == "ng" then
            f4_enabled, ng_enabled, vr_enabled = false, true, false
        elseif preset == "f4" then
            f4_enabled, ng_enabled, vr_enabled = true, false, false
        elseif preset == "vr" then
            f4_enabled, ng_enabled, vr_enabled = false, false, true
        else
            -- "all" preset or individual options take precedence
            f4_enabled = has_config("fallout_f4")
            ng_enabled = has_config("fallout_f4ng") 
            vr_enabled = has_config("fallout_f4vr")
        end
        
        -- Apply effective configuration by adding/removing defines
        if f4_enabled then
            target:add("defines", "ENABLE_FALLOUT_F4=1", {public = true})
        end
        if ng_enabled then
            target:add("defines", "ENABLE_FALLOUT_NG=1", {public = true})
        end
        if vr_enabled then
            target:add("defines", "ENABLE_FALLOUT_VR=1", {public = true})
        end

        print("=== CommonLibF4 Configuration ===")
        
        -- Show commonlib-shared source
        local use_local = os.isdir("extern/commonlib-shared")
        if use_local then
            print("CommonLib source: Local (extern/commonlib-shared)")
        else
            print("CommonLib source: Remote package")
        end
        
        print("Runtime preset: " .. preset)
        print("Runtimes enabled:")
        print("  - Fallout 4 1.10.163 (Pre-NG): " .. (f4_enabled and "YES" or "NO"))
        print("  - Fallout 4 1.10.984 NG: " .. (ng_enabled and "YES" or "NO"))
        print("  - Fallout 4 1.2.72 VR: " .. (vr_enabled and "YES" or "NO"))

        local runtime_count = (f4_enabled and 1 or 0) + (ng_enabled and 1 or 0) + (vr_enabled and 1 or 0)
        print("Total runtimes: " .. runtime_count)

        if runtime_count == 0 then
            print("WARNING: No runtimes enabled! This will cause build errors.")
        elseif runtime_count == 1 then
            print("Single runtime build - optimized for specific version")
        elseif runtime_count == 2 then
            print("Dual runtime build - supports 2 versions")
        else
            print("Multi runtime build - supports all versions")
        end

        print("==================================")
    end)
end)

-- CommonLibF4-NG: Multi-Runtime Fallout 4 Library
-- 
-- This library provides a unified interface for Fallout 4 modding across
-- multiple runtime versions using a shared commonlib-shared foundation.
--
-- Supported Runtimes:
--   - Fallout 4 1.10.163 (Pre-NG): Traditional F4 before Next-Gen Update
--   - Fallout 4 1.10.984+ (NG): Next-Gen Update and later versions  
--   - Fallout 4 VR 1.2.x: Virtual Reality edition
--
-- Runtime Configuration:
--
-- Method 1: Runtime presets (convenient)
--   xmake config --runtime_preset=f4       # F4 Pre-NG only
--   xmake config --runtime_preset=flat     # F4 + NG (no VR)
--   xmake config --runtime_preset=ng       # NG only 
--   xmake config --runtime_preset=vr       # VR only
--   xmake config --runtime_preset=all      # All runtimes (default)
--
-- Method 2: Individual options (fine-grained control)
--   xmake config --fallout_f4=y --fallout_f4ng=n --fallout_f4vr=n    # F4 only
--   xmake config --fallout_f4=y --fallout_f4ng=y --fallout_f4vr=n    # Flat
--   xmake config --fallout_f4=n --fallout_f4ng=y --fallout_f4vr=n    # NG only 
--   xmake config --fallout_f4=n --fallout_f4ng=n --fallout_f4vr=y    # VR only
--
-- Additional Options:
--   --commonlib_ini=y           # Enable REX::INI settings support
--   --commonlib_json=y          # Enable REX::JSON settings support  
--   --commonlib_toml=y          # Enable REX::TOML settings support
--   --commonlib_xbyak=y         # Enable Xbyak trampoline support
--
-- Architecture:
--   - commonlib-shared: Game-agnostic base library with template RelocationID
--   - CommonLibF4: F4-specific runtime detection, API compatibility, extensions
--   - Smart fallback: Local development uses extern/, production uses remote package
--   - Template count: REL_DEFAULT_RUNTIME_COUNT automatically set (1-3 runtimes)
--
-- Note: runtime_preset overrides individual options when specified

