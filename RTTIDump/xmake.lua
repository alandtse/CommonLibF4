target("commonlibf4-ng-rttidump")
    -- set build kind
    set_kind("shared")

    -- set build by default
    set_default(false)

    -- set build group
    set_group("commonlibf4-ng/plugin")

    -- add dependencies
    add_deps("commonlibf4-ng")

    -- add packages
    add_packages("spdlog")

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_headerfiles("src/**.h")

    -- add header files
    add_includedirs("src")

    -- set precompiled header
    set_pcxxheader("src/pch.h")
