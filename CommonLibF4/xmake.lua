option("fallout_f4", function()
    set_default(true)
    set_description("Enable runtime support for Fallout 4")
    add_defines("FALLOUT_SUPPORT_F4=1")
end)

option("fallout_vr", function()
    set_default(true)
    set_description("Enable runtime support for Fallout 4 VR")
    add_defines("FALLOUT_SUPPORT_VR=1")
end)

option("f4se_xbyak", function()
    set_default(false)
    set_description("Enable trampoline support for Xbyak")
    add_defines("F4SE_SUPPORT_XBYAK=1")
end)

target("CommonLibF4")
    set_kind("static")

    -- add packages
    add_packages("boost", "fmt", "rapidcsv", "rsm-binary-io", "rsm-mmio", "spdlog", { public = true })

    if has_config("f4se_xbyak") then
        add_packages("xbyak")
    end

    -- add options
    add_options("fallout_f4", "fallout_vr", "f4se_xbyak")

    -- add system links
    add_syslinks("advapi32", "dbghelp", "ole32", "shell32", "user32", "version")

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("include", { public = true })
    add_headerfiles(
        "include/(RE/**.h)",
        "include/(REL/**.h)",
        "include/(F4SE/**.h)"
    )

    -- set precompiled header
    set_pcxxheader("include/F4SE/Impl/PCH.h")

    -- add defines
    add_defines("BOOST_STL_INTERFACES_DISABLE_CONCEPTS")

    -- add flags
    add_cxxflags("/permissive-", "cl::/Zc:preprocessor", "cl::/external:W0", "cl::/bigobj")

    -- add flags (warnings -> errors)
    add_cxxflags("cl::/we4715") -- `function` : not all control paths return a value

    -- add flags(disable warnings)
    add_cxxflags(
        "cl::/wd4005", -- macro redefinition
        "cl::/wd4061", -- enumerator `identifier` in switch of enum `enumeration` is not explicitly handled by a case label
        "cl::/wd4068", -- unknown pragma 'clang'
        "cl::/wd4200", -- nonstandard extension used : zero-sized array in struct/union
        "cl::/wd4201", -- nonstandard extension used : nameless struct/union
        "cl::/wd4264", -- 'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
        "cl::/wd4265", -- 'type': class has virtual functions, but its non-trivial destructor is not virtual; instances of this class may not be destructed correctly
        "cl::/wd4266", -- 'function' : no override available for virtual member function from base 'type'; function is hidden
        "cl::/wd4324", -- 'struct_name' : structure was padded due to __declspec(align())
        "cl::/wd4371", -- 'classname': layout of class may have changed from a previous version of the compiler due to better packing of member 'member'
        "cl::/wd4514", -- 'function' : unreferenced inline function has been removed
        "cl::/wd4582", -- 'type': constructor is not implicitly called
        "cl::/wd4583", -- 'type': destructor is not implicitly called
        "cl::/wd4623", -- 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
        "cl::/wd4625", -- 'derived class' : copy constructor was implicitly defined as deleted because a base class copy constructor is inaccessible or deleted
        "cl::/wd4626", -- 'derived class' : assignment operator was implicitly defined as deleted because a base class assignment operator is inaccessible or deleted
        "cl::/wd4686", -- 'user-defined type' : possible change in behavior, change in UDT return calling convention
        "cl::/wd4710", -- 'function' : function not inlined
        "cl::/wd4711", -- function 'function' selected for inline expansion
        "cl::/wd4820", -- 'bytes' bytes padding added after construct 'member_name'
        "cl::/wd5082", -- second argument to 'va_start' is not the last named parameter
        "cl::/wd5026", -- 'type': move constructor was implicitly defined as deleted
        "cl::/wd5027", -- 'type': move assignment operator was implicitly defined as deleted
        "cl::/wd5045", -- compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
        "cl::/wd5053", -- support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension
        "cl::/wd5105", -- macro expansion producing 'defined' has undefined behavior (workaround for older msvc bug)
        "cl::/wd5204", -- 'type-name': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
        "cl::/wd5220"  -- 'member': a non-static data member with a volatile qualified type no longer implies that compiler generated copy / move constructors and copy / move assignment operators are not trivial
    )

    -- add flags (clang)
    add_cxxflags("clang::-Wno-overloaded-virtual")
    add_cxxflags("clang::-Wno-delete-non-abstract-non-virtual-dtor")
    add_cxxflags("clang::-Wno-reinterpret-base-class")
