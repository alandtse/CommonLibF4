#include "RE/NetImmerse/NiTArray.h"

struct string : std::string
{
	operator bool() const noexcept { return this->empty(); }
};

TEST_CASE("test object array")
{
	RE::NiTObjectArray<string> t1;

	// assert initial state
	REQUIRE(t1.empty());
	REQUIRE(t1.size() == 0);
	REQUIRE(t1.begin() == t1.end());
	REQUIRE(std::distance(t1.begin(), t1.end()) == 0);
}

TEST_CASE("test primitive array")
{
	RE::NiTPrimitiveArray<std::uint32_t> t1;

	// assert initial state
	REQUIRE(t1.empty());
	REQUIRE(t1.size() == 0);
	REQUIRE(t1.begin() == t1.end());
	REQUIRE(std::distance(t1.begin(), t1.end()) == 0);
}
