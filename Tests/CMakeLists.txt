add_project(
	TARGET_TYPE EXECUTABLE
	PROJECT Tests
	COMPILE_DEFINITIONS
		F4SE_TEST_SUITE
	INCLUDE_DIRECTORIES
		"../CommonLibF4/include"
		src
	GROUPED_FILES
		"src/RE/B/BSTHashMap.cpp"
		"src/pch.h"
	PRECOMPILED_HEADERS
		"src/pch.h"
)

find_package(Catch2 REQUIRED CONFIG)

include(Catch)
catch_discover_tests("${PROJECT_NAME}")

target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
		Catch2::Catch2WithMain
)
