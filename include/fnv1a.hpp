#pragma once

#include <cstddef>
#include <cstdint>

namespace fnv1a {
// FNV-1a 32bit hashing algorithm.
constexpr std::uint32_t fnv1a_32(const char * const s, std::size_t count) noexcept {
    return ((count ? fnv1a_32(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u;
}
} // namespace fnv1a

constexpr std::uint32_t operator ""_fnv1a(const char * const s, std::size_t count) noexcept {
    return fnv1a::fnv1a_32(s, count);
}
