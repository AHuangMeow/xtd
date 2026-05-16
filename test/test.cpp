#include <cassert>

import xtd;

template<xtd::Unsigned T>
auto test_unsigned() -> void {
    assert(T{} == T{0});
    assert(T{1} != T{0});

    assert(T{1} < T{2});
    assert(T{1} <= T{2});
    assert(T{1} <= T{1});
    assert(T{2} > T{1});
    assert(T{2} >= T{1});
    assert(T{2} >= T{2});

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

template<xtd::Signed T>
auto test_signed() -> void {
    assert(T{} == T{0});
    assert(T{1} != T{0});

    assert(T{1} < T{2});
    assert(T{1} <= T{2});
    assert(T{1} <= T{1});
    assert(T{2} > T{1});
    assert(T{2} >= T{1});
    assert(T{2} >= T{2});

    assert(-T{1} >= T{-1});

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
static_assert(xtd::SameAs<int, int>);
static_assert(!xtd::SameAs<int, float>);

static_assert(!xtd::Integral<bool>);
static_assert(!xtd::Integral<char>);
static_assert(xtd::Integral<signed char>);
static_assert(xtd::Integral<unsigned char>);
static_assert(xtd::Integral<short>);
static_assert(xtd::Integral<unsigned short>);
static_assert(xtd::Integral<int>);
static_assert(xtd::Integral<unsigned int>);
static_assert(xtd::Integral<long>);
static_assert(xtd::Integral<unsigned long>);
static_assert(xtd::Integral<long long>);
static_assert(xtd::Integral<unsigned long long>);
static_assert(!xtd::Integral<float>);
static_assert(!xtd::Integral<double>);
static_assert(!xtd::Integral<long double>);

static_assert(!xtd::Integral<const bool>);
static_assert(!xtd::Integral<const char>);
static_assert(xtd::Integral<const signed char>);
static_assert(xtd::Integral<const unsigned char>);
static_assert(xtd::Integral<const short>);
static_assert(xtd::Integral<const unsigned short>);
static_assert(xtd::Integral<const int>);
static_assert(xtd::Integral<const unsigned int>);
static_assert(xtd::Integral<const long>);
static_assert(xtd::Integral<const unsigned long>);
static_assert(xtd::Integral<const long long>);
static_assert(xtd::Integral<const unsigned long long>);
static_assert(!xtd::Integral<const float>);
static_assert(!xtd::Integral<const double>);
static_assert(!xtd::Integral<const long double>);

static_assert(!xtd::Integral<volatile bool>);
static_assert(!xtd::Integral<volatile char>);
static_assert(xtd::Integral<volatile signed char>);
static_assert(xtd::Integral<volatile unsigned char>);
static_assert(xtd::Integral<volatile short>);
static_assert(xtd::Integral<volatile unsigned short>);
static_assert(xtd::Integral<volatile int>);
static_assert(xtd::Integral<volatile unsigned int>);
static_assert(xtd::Integral<volatile long>);
static_assert(xtd::Integral<volatile unsigned long>);
static_assert(xtd::Integral<volatile long long>);
static_assert(xtd::Integral<volatile unsigned long long>);
static_assert(!xtd::Integral<volatile float>);
static_assert(!xtd::Integral<volatile double>);
static_assert(!xtd::Integral<volatile long double>);

static_assert(!xtd::Integral<const volatile bool>);
static_assert(!xtd::Integral<const volatile char>);
static_assert(xtd::Integral<const volatile signed char>);
static_assert(xtd::Integral<const volatile unsigned char>);
static_assert(xtd::Integral<const volatile short>);
static_assert(xtd::Integral<const volatile unsigned short>);
static_assert(xtd::Integral<const volatile int>);
static_assert(xtd::Integral<const volatile unsigned int>);
static_assert(xtd::Integral<const volatile long>);
static_assert(xtd::Integral<const volatile unsigned long>);
static_assert(xtd::Integral<const volatile long long>);
static_assert(xtd::Integral<const volatile unsigned long long>);
static_assert(!xtd::Integral<const volatile float>);
static_assert(!xtd::Integral<const volatile double>);
static_assert(!xtd::Integral<const volatile long double>);

static_assert(xtd::Integral<xtd::u8>);
static_assert(xtd::Integral<xtd::u16>);
static_assert(xtd::Integral<xtd::u32>);
static_assert(xtd::Integral<xtd::u64>);
static_assert(xtd::Integral<xtd::i8>);
static_assert(xtd::Integral<xtd::i16>);
static_assert(xtd::Integral<xtd::i32>);
static_assert(xtd::Integral<xtd::i64>);

static_assert(xtd::Integral<const xtd::u8>);
static_assert(xtd::Integral<const xtd::u16>);
static_assert(xtd::Integral<const xtd::u32>);
static_assert(xtd::Integral<const xtd::u64>);
static_assert(xtd::Integral<const xtd::i8>);
static_assert(xtd::Integral<const xtd::i16>);
static_assert(xtd::Integral<const xtd::i32>);
static_assert(xtd::Integral<const xtd::i64>);

static_assert(xtd::Integral<volatile xtd::u8>);
static_assert(xtd::Integral<volatile xtd::u16>);
static_assert(xtd::Integral<volatile xtd::u32>);
static_assert(xtd::Integral<volatile xtd::u64>);
static_assert(xtd::Integral<volatile xtd::i8>);
static_assert(xtd::Integral<volatile xtd::i16>);
static_assert(xtd::Integral<volatile xtd::i32>);
static_assert(xtd::Integral<volatile xtd::i64>);

static_assert(xtd::Integral<const volatile xtd::u8>);
static_assert(xtd::Integral<const volatile xtd::u16>);
static_assert(xtd::Integral<const volatile xtd::u32>);
static_assert(xtd::Integral<const volatile xtd::u64>);
static_assert(xtd::Integral<const volatile xtd::i8>);
static_assert(xtd::Integral<const volatile xtd::i16>);
static_assert(xtd::Integral<const volatile xtd::i32>);
static_assert(xtd::Integral<const volatile xtd::i64>);

static_assert(!xtd::Signed<bool>);
static_assert(!xtd::Signed<char>);
static_assert(xtd::Signed<signed char>);
static_assert(xtd::Signed<signed int>);
static_assert(xtd::Signed<signed long>);
static_assert(xtd::Signed<signed long long>);
static_assert(!xtd::Signed<unsigned char>);
static_assert(!xtd::Signed<unsigned short>);
static_assert(!xtd::Signed<unsigned int>);
static_assert(!xtd::Signed<unsigned long>);
static_assert(!xtd::Signed<unsigned long long>);

static_assert(!xtd::Signed<const bool>);
static_assert(!xtd::Signed<const char>);
static_assert(xtd::Signed<const signed char>);
static_assert(xtd::Signed<const signed int>);
static_assert(xtd::Signed<const signed long>);
static_assert(xtd::Signed<const signed long long>);
static_assert(!xtd::Signed<const unsigned char>);
static_assert(!xtd::Signed<const unsigned short>);
static_assert(!xtd::Signed<const unsigned int>);
static_assert(!xtd::Signed<const unsigned long>);
static_assert(!xtd::Signed<const unsigned long long>);

static_assert(!xtd::Signed<volatile bool>);
static_assert(!xtd::Signed<volatile char>);
static_assert(xtd::Signed<volatile signed char>);
static_assert(xtd::Signed<volatile signed int>);
static_assert(xtd::Signed<volatile signed long>);
static_assert(xtd::Signed<volatile signed long long>);
static_assert(!xtd::Signed<volatile unsigned char>);
static_assert(!xtd::Signed<volatile unsigned short>);
static_assert(!xtd::Signed<volatile unsigned int>);
static_assert(!xtd::Signed<volatile unsigned long>);
static_assert(!xtd::Signed<volatile unsigned long long>);

static_assert(!xtd::Signed<const volatile bool>);
static_assert(!xtd::Signed<const volatile char>);
static_assert(xtd::Signed<const volatile signed char>);
static_assert(xtd::Signed<const volatile signed int>);
static_assert(xtd::Signed<const volatile signed long>);
static_assert(xtd::Signed<const volatile signed long long>);
static_assert(!xtd::Signed<const volatile unsigned char>);
static_assert(!xtd::Signed<const volatile unsigned short>);
static_assert(!xtd::Signed<const volatile unsigned int>);
static_assert(!xtd::Signed<const volatile unsigned long>);
static_assert(!xtd::Signed<const volatile unsigned long long>);

static_assert(!xtd::Signed<xtd::u8>);
static_assert(!xtd::Signed<xtd::u16>);
static_assert(!xtd::Signed<xtd::u32>);
static_assert(!xtd::Signed<xtd::u64>);
static_assert(xtd::Signed<xtd::i8>);
static_assert(xtd::Signed<xtd::i16>);
static_assert(xtd::Signed<xtd::i32>);
static_assert(xtd::Signed<xtd::i64>);

static_assert(!xtd::Signed<const xtd::u8>);
static_assert(!xtd::Signed<const xtd::u16>);
static_assert(!xtd::Signed<const xtd::u32>);
static_assert(!xtd::Signed<const xtd::u64>);
static_assert(xtd::Signed<const xtd::i8>);
static_assert(xtd::Signed<const xtd::i16>);
static_assert(xtd::Signed<const xtd::i32>);
static_assert(xtd::Signed<const xtd::i64>);

static_assert(!xtd::Signed<volatile xtd::u8>);
static_assert(!xtd::Signed<volatile xtd::u16>);
static_assert(!xtd::Signed<volatile xtd::u32>);
static_assert(!xtd::Signed<volatile xtd::u64>);
static_assert(xtd::Signed<volatile xtd::i8>);
static_assert(xtd::Signed<volatile xtd::i16>);
static_assert(xtd::Signed<volatile xtd::i32>);
static_assert(xtd::Signed<volatile xtd::i64>);

static_assert(!xtd::Signed<const volatile xtd::u8>);
static_assert(!xtd::Signed<const volatile xtd::u16>);
static_assert(!xtd::Signed<const volatile xtd::u32>);
static_assert(!xtd::Signed<const volatile xtd::u64>);
static_assert(xtd::Signed<const volatile xtd::i8>);
static_assert(xtd::Signed<const volatile xtd::i16>);
static_assert(xtd::Signed<const volatile xtd::i32>);
static_assert(xtd::Signed<const volatile xtd::i64>);

static_assert(xtd::Unsigned<xtd::u8>);
static_assert(xtd::Unsigned<xtd::u16>);
static_assert(xtd::Unsigned<xtd::u32>);
static_assert(xtd::Unsigned<xtd::u64>);
static_assert(!xtd::Unsigned<xtd::i8>);
static_assert(!xtd::Unsigned<xtd::i16>);
static_assert(!xtd::Unsigned<xtd::i32>);
static_assert(!xtd::Unsigned<xtd::i64>);

static_assert(xtd::Unsigned<const xtd::u8>);
static_assert(xtd::Unsigned<const xtd::u16>);
static_assert(xtd::Unsigned<const xtd::u32>);
static_assert(xtd::Unsigned<const xtd::u64>);
static_assert(!xtd::Unsigned<const xtd::i8>);
static_assert(!xtd::Unsigned<const xtd::i16>);
static_assert(!xtd::Unsigned<const xtd::i32>);
static_assert(!xtd::Unsigned<const xtd::i64>);

static_assert(xtd::Unsigned<volatile xtd::u8>);
static_assert(xtd::Unsigned<volatile xtd::u16>);
static_assert(xtd::Unsigned<volatile xtd::u32>);
static_assert(xtd::Unsigned<volatile xtd::u64>);
static_assert(!xtd::Unsigned<volatile xtd::i8>);
static_assert(!xtd::Unsigned<volatile xtd::i16>);
static_assert(!xtd::Unsigned<volatile xtd::i32>);
static_assert(!xtd::Unsigned<volatile xtd::i64>);

static_assert(xtd::Unsigned<const volatile xtd::u8>);
static_assert(xtd::Unsigned<const volatile xtd::u16>);
static_assert(xtd::Unsigned<const volatile xtd::u32>);
static_assert(xtd::Unsigned<const volatile xtd::u64>);
static_assert(!xtd::Unsigned<const volatile xtd::i8>);
static_assert(!xtd::Unsigned<const volatile xtd::i16>);
static_assert(!xtd::Unsigned<const volatile xtd::i32>);
static_assert(!xtd::Unsigned<const volatile xtd::i64>);
// end test concepts

auto main() -> int {
    test_unsigned<xtd::u8>();
    test_unsigned<xtd::u16>();
    test_unsigned<xtd::u32>();
    test_unsigned<xtd::u64>();

    test_signed<xtd::i8>();
    test_signed<xtd::i16>();
    test_signed<xtd::i32>();
    test_signed<xtd::i64>();
}
