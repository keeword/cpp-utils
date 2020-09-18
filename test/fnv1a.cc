#include "doctest.h"

#include <fnv1a.hpp>

TEST_CASE("testing the fnv1a function") {
    CHECK("test"_fnv1a == 2854439807);
}