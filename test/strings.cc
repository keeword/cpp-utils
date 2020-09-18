#include "doctest.h"

#include <windows.h>
#include <strings.hpp>

TEST_CASE("testing the strings function") {
    CHECK(strings::cast<std::string>(std::wstring(L"test")) == std::string("test"));
}