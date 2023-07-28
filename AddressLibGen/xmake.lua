target("AddressLibGen")
    -- set build by default
    set_default(false)

    -- set build group
    set_group("tools")

    -- add packages
    add_packages("srell")

    -- add source files
    add_files("src/**.cpp")
