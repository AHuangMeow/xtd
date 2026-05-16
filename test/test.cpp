#include <cassert>

import xtd;

template<typename T>
auto test_integer() -> void {
    assert(T{} == T{0});
    assert(T{1} != T{0});

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

    if constexpr (xtd::is_same_as<T, xtd::u8>::value) {
        assert(~T{0x00} == T{0xff});
    } else if constexpr (xtd::is_same_as<T, xtd::u16>::value) {
        assert(~T{0x0000} == T{0xffff});
    } else if constexpr (xtd::is_same_as<T, xtd::u32>::value) {
        assert(~T{0x00000000} == T{0xffffffff});
    } else if constexpr (xtd::is_same_as<T, xtd::u64>::value) {
        assert(~T{0x0000000000000000} == T{0xffffffffffffffff});
    } else {
        static_assert(false, "unknown type");
    }

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

// test_concepts
static_assert(xtd::same_as<int, int>);
static_assert(!xtd::same_as<int, float>);

static_assert(!xtd::integral<bool>);
static_assert(!xtd::integral<char>);
static_assert(xtd::integral<signed char>);
static_assert(xtd::integral<unsigned char>);
static_assert(xtd::integral<short>);
static_assert(xtd::integral<unsigned short>);
static_assert(xtd::integral<int>);
static_assert(xtd::integral<unsigned int>);
static_assert(xtd::integral<long>);
static_assert(xtd::integral<unsigned long>);
static_assert(xtd::integral<long long>);
static_assert(xtd::integral<unsigned long long>);
static_assert(!xtd::integral<float>);
static_assert(!xtd::integral<double>);
static_assert(!xtd::integral<long double>);

static_assert(!xtd::integral<const bool>);
static_assert(!xtd::integral<const char>);
static_assert(xtd::integral<const signed char>);
static_assert(xtd::integral<const unsigned char>);
static_assert(xtd::integral<const short>);
static_assert(xtd::integral<const unsigned short>);
static_assert(xtd::integral<const int>);
static_assert(xtd::integral<const unsigned int>);
static_assert(xtd::integral<const long>);
static_assert(xtd::integral<const unsigned long>);
static_assert(xtd::integral<const long long>);
static_assert(xtd::integral<const unsigned long long>);
static_assert(!xtd::integral<const float>);
static_assert(!xtd::integral<const double>);
static_assert(!xtd::integral<const long double>);

static_assert(!xtd::integral<volatile bool>);
static_assert(!xtd::integral<volatile char>);
static_assert(xtd::integral<volatile signed char>);
static_assert(xtd::integral<volatile unsigned char>);
static_assert(xtd::integral<volatile short>);
static_assert(xtd::integral<volatile unsigned short>);
static_assert(xtd::integral<volatile int>);
static_assert(xtd::integral<volatile unsigned int>);
static_assert(xtd::integral<volatile long>);
static_assert(xtd::integral<volatile unsigned long>);
static_assert(xtd::integral<volatile long long>);
static_assert(xtd::integral<volatile unsigned long long>);
static_assert(!xtd::integral<volatile float>);
static_assert(!xtd::integral<volatile double>);
static_assert(!xtd::integral<volatile long double>);

static_assert(!xtd::integral<const volatile bool>);
static_assert(!xtd::integral<const volatile char>);
static_assert(xtd::integral<const volatile signed char>);
static_assert(xtd::integral<const volatile unsigned char>);
static_assert(xtd::integral<const volatile short>);
static_assert(xtd::integral<const volatile unsigned short>);
static_assert(xtd::integral<const volatile int>);
static_assert(xtd::integral<const volatile unsigned int>);
static_assert(xtd::integral<const volatile long>);
static_assert(xtd::integral<const volatile unsigned long>);
static_assert(xtd::integral<const volatile long long>);
static_assert(xtd::integral<const volatile unsigned long long>);
static_assert(!xtd::integral<const volatile float>);
static_assert(!xtd::integral<const volatile double>);
static_assert(!xtd::integral<const volatile long double>);

static_assert(xtd::integral<xtd::u8>);
static_assert(xtd::integral<xtd::u16>);
static_assert(xtd::integral<xtd::u32>);
static_assert(xtd::integral<xtd::u64>);

static_assert(xtd::integral<const xtd::u8>);
static_assert(xtd::integral<const xtd::u16>);
static_assert(xtd::integral<const xtd::u32>);
static_assert(xtd::integral<const xtd::u64>);

static_assert(xtd::integral<volatile xtd::u8>);
static_assert(xtd::integral<volatile xtd::u16>);
static_assert(xtd::integral<volatile xtd::u32>);
static_assert(xtd::integral<volatile xtd::u64>);

static_assert(xtd::integral<const volatile xtd::u8>);
static_assert(xtd::integral<const volatile xtd::u16>);
static_assert(xtd::integral<const volatile xtd::u32>);
static_assert(xtd::integral<const volatile xtd::u64>);
// end test concepts

auto main() -> int {
    test_integer<xtd::u8>();
    test_integer<xtd::u16>();
    test_integer<xtd::u32>();
    test_integer<xtd::u64>();
}
