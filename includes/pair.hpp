#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair {

    typedef T1  first_type;
    typedef T2  second_type;

    first_type  first;
    second_type second;

    pair()  : first(first_type()),
              second(second_type()) {}

    pair (const first_type& obj1, const second_type& obj2) : first(obj1),
                                                             second(obj2) {}

    template<class U1, class U2>
    pair (const pair<U1, U2>& obj) : first(first_type(obj.first)),
                                     second(second_type(obj.second)) {}

    pair& operator=(const pair& other) {
        if(this == &other) return *this;
        first = other.first;
        second = other.second;
        return *this;
    }
};

template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return lhs.first == rhs.first && lhs.second == lhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return (lhs.first < rhs.first
            || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs < rhs);
}

template <class T1, class T2>
pair<T1, T2> make_pair(T1 obj1, T2 obj2) {
    return pair<T1,T2>(obj1, obj2);
}

} // namespace ft

#endif
