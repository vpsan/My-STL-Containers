#ifndef _FT_ENABLE_IF_
#define _FT_ENABLE_IF_

namespace ft {

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {
    typedef T type;
};

template<class T, bool VALUE>
struct integral_constant {

    static const bool value = VALUE;

    typedef T                   value_type;
    typedef integral_constant   type;

    operator value_type() const {
        return value;
    }

};

template <class T> struct is_integral               : public ft::integral_constant<  T , false>{};

template <> struct is_integral<bool>                : public ft::integral_constant<bool, true> {};
template <> struct is_integral<char>                : public ft::integral_constant<bool, true> {};
template <> struct is_integral<signed char>         : public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned char>       : public ft::integral_constant<bool, true> {};
template <> struct is_integral<wchar_t>             : public ft::integral_constant<bool, true> {};
template <> struct is_integral<char16_t>            : public ft::integral_constant<bool, true> {};
template <> struct is_integral<short>               : public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned short>      : public ft::integral_constant<bool, true> {};
template <> struct is_integral<int>                 : public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned int>        : public ft::integral_constant<bool, true> {};
template <> struct is_integral<long>                : public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned long>       : public ft::integral_constant<bool, true> {};
template <> struct is_integral<long long>           : public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned long long>  : public ft::integral_constant<bool, true> {};

}  // namespace ft

#endif //_FT_ENABLE_IF_
