#include "doctest.h"

#include <windows.h>
#include <strings.hpp>

TEST_CASE("testing the strings function") {
    CHECK(strings::cast<std::string>(std::wstring{ L"test" }) == std::string("test"));
    CHECK(strings::cast<std::string>(std::string{ "test" }) == std::string("test"));
    CHECK(strings::cast<std::wstring>(std::string{ "test" }) == std::wstring(L"test"));
    CHECK(strings::cast<std::wstring>(std::wstring{ L"test" }) == std::wstring(L"test"));
}