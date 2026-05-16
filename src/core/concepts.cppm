export module xtd:concepts;
import :traits;

namespace xtd {
    export template<typename T, typename U> concept same_as = is_same_as<T, U>::value;
    export template<typename T> concept integral = is_integral<T>::value;
}
