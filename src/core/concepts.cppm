export module xtd:concepts;
import :traits;

namespace xtd {
    export template<typename T, typename U> concept SameAs = is_same_as<T, U>::value;
    export template<typename T> concept Integral = is_integral<T>::value;
    export template<typename T> concept Signed = is_signed<T>::value;
    export template<typename T> concept Unsigned = is_unsigned<T>::value;
}
