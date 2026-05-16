export module xtd:types;
import :concepts;

namespace xtd {
    template<Integral T>
    class integer {
        T inner{};

    public:
        integer() = default;

        explicit integer(const T inner) : inner{inner} {
        }

        auto operator==(const integer &rhs) const -> bool {
            return this->inner == rhs.inner;
        }

        auto operator!=(const integer &rhs) const -> bool {
            return this->inner != rhs.inner;
        }

        auto operator<(const integer &rhs) const -> bool {
            return this->inner < rhs.inner;
        }

        auto operator<=(const integer &rhs) const -> bool {
            return this->inner <= rhs.inner;
        }

        auto operator>(const integer &rhs) const -> bool {
            return this->inner > rhs.inner;
        }

        auto operator>=(const integer &rhs) const -> bool {
            return this->inner >= rhs.inner;
        }

        auto operator-() const -> integer requires Signed<T> {
            return integer{static_cast<T>(-this->inner)};
        }

        auto operator+(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner + rhs.inner)};
        }

        auto operator+=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner + rhs.inner);
        }

        auto operator-(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner - rhs.inner)};
        }

        auto operator-=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner - rhs.inner);
        }

        auto operator*(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner * rhs.inner)};
        }

        auto operator*=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner * rhs.inner);
        }

        auto operator/(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner / rhs.inner)};
        }

        auto operator/=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner / rhs.inner);
        }

        auto operator%(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner % rhs.inner)};
        }

        auto operator%=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner % rhs.inner);
        }

        auto operator&(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner & rhs.inner)};
        }

        auto operator&=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner & rhs.inner);
        }

        auto operator|(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner | rhs.inner)};
        }

        auto operator|=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner | rhs.inner);
        }

        auto operator^(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner ^ rhs.inner)};
        }

        auto operator^=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner ^ rhs.inner);
        }

        auto operator~() const -> integer {
            return integer{static_cast<T>(~this->inner)};
        }

        auto operator<<(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner << rhs.inner)};
        }

        auto operator<<=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner << rhs.inner);
        }

        auto operator>>(const integer &rhs) const -> integer {
            return integer{static_cast<T>(this->inner >> rhs.inner)};
        }

        auto operator>>=(const integer &rhs) & -> void {
            this->inner = static_cast<T>(this->inner >> rhs.inner);
        }

        auto operator++() & -> void {
            this->inner = static_cast<T>(this->inner + 1);
        }

        auto operator--() & -> void {
            this->inner = static_cast<T>(this->inner - 1);
        }
    };

    export using u8 = integer<unsigned char>;
    export using u16 = integer<unsigned short>;
    export using u32 = integer<unsigned int>;
    export using u64 = integer<unsigned long>;

    template<>
    struct is_integral<u8> : true_type {
    };

    template<>
    struct is_integral<u16> : true_type {
    };

    template<>
    struct is_integral<u32> : true_type {
    };

    template<>
    struct is_integral<u64> : true_type {
    };

    template<>
    struct is_unsigned<u8> : true_type {
    };

    template<>
    struct is_unsigned<u16> : true_type {
    };

    template<>
    struct is_unsigned<u32> : true_type {
    };

    template<>
    struct is_unsigned<u64> : true_type {
    };

    export using i8 = integer<signed char>;
    export using i16 = integer<signed short>;
    export using i32 = integer<signed int>;
    export using i64 = integer<signed long>;

    template<>
    struct is_integral<i8> : true_type {
    };

    template<>
    struct is_integral<i16> : true_type {
    };

    template<>
    struct is_integral<i32> : true_type {
    };

    template<>
    struct is_integral<i64> : true_type {
    };

    template<>
    struct is_signed<i8> : true_type {
    };

    template<>
    struct is_signed<i16> : true_type {
    };

    template<>
    struct is_signed<i32> : true_type {
    };

    template<>
    struct is_signed<i64> : true_type {
    };
}
