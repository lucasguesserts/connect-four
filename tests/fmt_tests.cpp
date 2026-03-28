#include <doctest/doctest.h>
#include <fmt/core.h>

#include <string>

TEST_CASE("fmt basic formatting works") {
    std::string s = fmt::format("Hello, {}!", "world");
    CHECK(s == "Hello, world!");
}
