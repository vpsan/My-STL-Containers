#ifndef _FT_CONDITIONAL_
# define _FT_CONDITIONAL_

namespace ft {

template<bool B, class T, class U>
struct conditional {};

template<class T, class U>
struct conditional<true, T, U> {
    typedef T type;
};

template<class T, class U>
struct conditional<false, T, U> {
    typedef U type;
};

}  // namespace ft

#endif // _FT_CONDITIONAL_