#include <cassert>

import xtd;

auto test_u8() -> void {
    using xtd::u8;

    assert(u8{} == u8{0});

    assert(u8{1} + u8{1} == u8{2});
    {
        auto n = u8{0};
        // NOLINTNEXTLINE
        n += u8{1};
        assert(n == u8{1});
    }

    assert(u8{1} - u8{1} == u8{0});
    {
        auto n = u8{1};
        // NOLINTNEXTLINE
        n -= u8{1};
        assert(n == u8{0});
    }

    assert(u8{2} * u8{2} == u8{4});
    {
        auto n = u8{2};
        n *= u8{2};
        assert(n == u8{4});
    }

    assert(u8{4} / u8{2} == u8{2});
    {
        auto n = u8{4};
        n /= u8{2};
        assert(n == u8{2});
    }

    assert(u8{3} % u8{2} == u8{1});
    {
        auto n = u8{3};
        n %= u8{2};
        assert(n == u8{1});
    }

    assert((u8{0b0011} & u8{0b0101}) == u8{0b0001});
    {
        auto n = u8{0b0011};
        n &= u8{0b0101};
        assert(n == u8{0b0001});
    }

    assert((u8{0b0011} | u8{0b0101}) == u8{0b0111});
    {
        auto n = u8{0b0011};
        n |= u8{0b0101};
        assert(n == u8{0b0111});
    }

    assert((u8{0b0011} ^ u8{0b0101}) == u8{0b0110});
    {
        auto n = u8{0b0011};
        n ^= u8{0b0101};
        assert(n == u8{0b0110});
    }

    assert(~u8{0b00000000} == u8{0b11111111});

    assert(u8{0b01} << u8{1} == u8{0b10});
    {
        auto n = u8{0b01};
        n <<= u8{1};
        assert(n == u8{0b10});
    }

    assert(u8{0b10} >> u8{1} == u8{0b01});
    {
        auto n = u8{0b10};
        n >>= u8{1};
        assert(n == u8{0b01});
    }

    {
        auto n = u8{0};
        n++;
        assert(n == u8{1});
    }

    {
        auto n = u8{1};
        n--;
        assert(n == u8{0});
    }
}

auto main() -> int {
    test_u8();
}