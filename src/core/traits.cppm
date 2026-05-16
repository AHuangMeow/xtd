export module xtd:traits;

namespace xtd {
    export struct true_type {
        static constexpr bool value = true;
    };

    export struct false_type {
        static constexpr bool value = false;
    };

    export template<typename T, typename U>
    struct is_same_as : false_type {
    };

    template<typename T>
    struct is_same_as<T, T> : true_type {
    };

    export template<typename T>
    struct is_integral : false_type {
    };

    template<>
    struct is_integral<unsigned char> : true_type {
    };

    template<>
    struct is_integral<unsigned short> : true_type {
    };

    template<>
    struct is_integral<unsigned int> : true_type {
    };

    template<>
    struct is_integral<unsigned long> : true_type {
    };

    template<>
    struct is_integral<unsigned long long> : true_type {
    };

    template<>
    struct is_integral<signed char> : true_type {
    };

    template<>
    struct is_integral<signed short> : true_type {
    };

    template<>
    struct is_integral<signed int> : true_type {
    };

    template<>
    struct is_integral<signed long> : true_type {
    };

    template<>
    struct is_integral<signed long long> : true_type {
    };

    template<typename T>
    struct is_integral<const T> : is_integral<T> {
    };

    template<typename T>
    struct is_integral<volatile T> : is_integral<T> {
    };

    template<typename T>
    struct is_integral<const volatile T> : is_integral<T> {
    };

    export template<typename T>
    struct is_signed : false_type {
    };

    template<>
    struct is_signed<signed char> : true_type {
    };

    template<>
    struct is_signed<signed short> : true_type {
    };

    template<>
    struct is_signed<signed int> : true_type {
    };

    template<>
    struct is_signed<signed long> : true_type {
    };

    template<>
    struct is_signed<signed long long> : true_type {
    };

    template<typename T>
    struct is_signed<const T> : is_signed<T> {
    };

    template<typename T>
    struct is_signed<volatile T> : is_signed<T> {
    };

    template<typename T>
    struct is_signed<const volatile T> : is_signed<T> {
    };

    export template<typename T>
    struct is_unsigned : false_type {
    };

    template<>
    struct is_unsigned<unsigned char> : true_type {
    };

    template<>
    struct is_unsigned<unsigned short> : true_type {
    };

    template<>
    struct is_unsigned<unsigned int> : true_type {
    };

    template<>
    struct is_unsigned<unsigned long> : true_type {
    };

    template<>
    struct is_unsigned<unsigned long long> : true_type {
    };

    template<typename T>
    struct is_unsigned<const T> : is_unsigned<T> {
    };

    template<typename T>
    struct is_unsigned<volatile T> : is_unsigned<T> {
    };

    template<typename T>
    struct is_unsigned<const volatile T> : is_unsigned<T> {};
}
