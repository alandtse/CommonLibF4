target("Tests")
    -- set build by default
    set_default(false)

    -- set build group
    set_group("tests")

    -- add packages
    add_packages("catch2")

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("../CommonLibF4/include", "src")

    -- set precompiled header
    set_pcxxheader("src/pch.h")

    -- add defines
    add_defines("F4SE_TEST_SUITE")
