target("RTTIDump")
    -- set build kind
    set_kind("shared")

    -- set build by default
    set_default(false)

    -- set build group
    set_group("plugins")

    -- add dependencies
    add_deps("CommonLibF4")

    -- add packages
    add_packages("spdlog", "srell")

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("src")

    -- set precompiled header
    set_pcxxheader("src/PCH.h")
