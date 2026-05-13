#include <cassert>

import xtd;
import std;

template<typename T>
auto test_integer() -> void {
    assert(T{} == T{0});

    assert(T{1} + T{1} == T{2});
    {
        auto n = T{0};
        // NOLINTNEXTLINE
        n += T{1};
        assert(n == T{1});
    }

    assert(T{1} - T{1} == T{0});
    {
        auto n = T{1};
        // NOLINTNEXTLINE
        n -= T{1};
        assert(n == T{0});
    }

    assert(T{2} * T{2} == T{4});
    {
        auto n = T{2};
        // NOLINTNEXTLINE
        n *= T{2};
        assert(n == T{4});
    }

    assert(T{4} / T{2} == T{2});
    {
        auto n = T{4};
        // NOLINTNEXTLINE
        n /= T{2};
        assert(n == T{2});
    }

    assert(T{3} % T{2} == T{1});
    {
        auto n = T{3};
        // NOLINTNEXTLINE
        n %= T{2};
        assert(n == T{1});
    }

    assert((T{0b0011} & T{0b0101}) == T{0b0001});
    {
        auto n = T{0b0011};
        // NOLINTNEXTLINE
        n &= T{0b0101};
        assert(n == T{0b0001});
    }

    assert((T{0b0011} | T{0b0101}) == T{0b0111});
    {
        auto n = T{0b0011};
        // NOLINTNEXTLINE
        n |= T{0b0101};
        assert(n == T{0b0111});
    }

    assert((T{0b0011} ^ T{0b0101}) == T{0b0110});
    {
        auto n = T{0b0011};
        // NOLINTNEXTLINE
        n ^= T{0b0101};
        assert(n == T{0b0110});
    }

    assert(~T{0b00000000} == T{0b11111111});

    assert(T{0b01} << T{1} == T{0b10});
    {
        auto n = T{0b01};
        // NOLINTNEXTLINE
        n <<= T{1};
        assert(n == T{0b10});
    }

    assert(T{0b10} >> T{1} == T{0b01});
    {
        auto n = T{0b10};
        // NOLINTNEXTLINE
        n >>= T{1};
        assert(n == T{0b01});
    }

    {
        auto n = T{0};
        ++n;
        assert(n == T{1});
    }

    {
        auto n = T{1};
        --n;
        assert(n == T{0});
    }
}

auto main() -> int {
    test_integer<xtd::u8>();
}
