#pragma once

#include <exception>
#include <functional>
#include <string>
#include <type_traits>
#include <vector>

namespace strings {

template <typename Td, typename Ts>
Td cast(const Ts& src, unsigned int codepage = CP_UTF8) {
    typedef typename Td::value_type dst_type;

    if constexpr (std::is_same_v<Td, Ts>) {
        return src;
    } else {
        auto convert = [&](dst_type* buff, int capacity) -> int {
            if constexpr (std::is_same_v<Td, std::wstring>) {
                return ::MultiByteToWideChar(codepage, 0, src.data(),
                    static_cast<int>(src.size()), buff, capacity);
            } else if constexpr (std::is_same_v<Td, std::string>) {
                return ::WideCharToMultiByte(codepage, 0, src.data(),
                    static_cast<int>(src.size()), buff, capacity, nullptr, nullptr);
            } else {
                static_assert(false, "not support type");
            }
        };

        auto size = convert(nullptr, 0);
        if (size == 0) {
            throw std::exception{ "can not convert" };
        };

        std::vector<dst_type> buff(size);
        convert(&buff[0], size);

        return Td{ buff.begin(), buff.end() };
    }
}

} // namespace strings