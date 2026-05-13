export module xtd;

namespace xtd {
    export class u8 {
        unsigned char inner{};
    public:
        u8() = default;
        explicit u8(const unsigned char inner): inner{inner} {}

        auto operator==(const u8& rhs) const -> bool {
            return this->inner == rhs.inner;
        }

        auto operator+(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner + rhs.inner)};
        }

        auto operator+=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner + rhs.inner);
        }

        auto operator-(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner - rhs.inner)};
        }

        auto operator-=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner - rhs.inner);
        }

        auto operator*(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner * rhs.inner)};
        }

        auto operator*=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner * rhs.inner);
        }

        auto operator/(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner / rhs.inner)};
        }

        auto operator/=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner / rhs.inner);
        }

        auto operator%(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner % rhs.inner)};
        }

        auto operator%=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner % rhs.inner);
        }

        auto operator&(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner & rhs.inner)};
        }

        auto operator&=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner & rhs.inner);
        }

        auto operator|(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner | rhs.inner)};
        }

        auto operator|=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner | rhs.inner);
        }

        auto operator^(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner ^ rhs.inner)};
        }

        auto operator^=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner ^ rhs.inner);
        }

        auto operator~() const -> u8 {
            return u8{static_cast<unsigned char>(~this->inner)};
        }

        auto operator<<(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner << rhs.inner)};
        }

        auto operator<<=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner << rhs.inner);
        }

        auto operator>>(const u8& rhs) const -> u8 {
            return u8{static_cast<unsigned char>(this->inner >> rhs.inner)};
        }

        auto operator>>=(const u8& rhs) & -> void {
            this->inner = static_cast<unsigned char>(this->inner >> rhs.inner);
        }

        auto operator++(int) & -> void {
            this->inner = static_cast<unsigned char>(this->inner + 1);
        }

        auto operator--(int) & -> void {
            this->inner = static_cast<unsigned char>(this->inner - 1);
        }
    };
}
