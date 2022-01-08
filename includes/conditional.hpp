#ifndef CONDITIONAL_HPP
# define CONDITIONAL_HPP

namespace ft {

template<bool B, class T, class U>
struct conditional {

};

template<class T, class U>
struct conditional<true, T, U> {
    typedef T type;
};

template<class T, class U>
struct conditional<false, T, U> {
    typedef U type;
};

}  // namespace ft

#endif