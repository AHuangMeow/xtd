export module xtd:concepts;
import :traits;

namespace xtd {
    export template<typename T> concept integral = xtd::is_integral<T>::value;
}
