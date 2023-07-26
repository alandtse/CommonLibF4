set_xmakever("2.8.1")

-- set project
set_project("CommonLibF4")
set_arch("x64")
set_languages("c++20")
set_optimize("faster")
set_warnings("allextra", "error")

-- add rules
add_rules("mode.debug", "mode.release")

-- require packages
add_requires("boost", "catch2", "fmt", "rapidcsv", "robin-hood-hashing", "rsm-binary-io", "rsm-mmio", "srell", "xbyak")
add_requires("spdlog", { configs = { header_only = false, fmt_external = true } })

-- include subprojects
includes("CommonLibF4")
includes("AddressLibDecoder")
includes("AddressLibGen")
includes("RTTIDump")
includes("Tests")
