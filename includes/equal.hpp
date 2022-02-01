#ifndef _FT_EQUAL_
#define _FT_EQUAL_

namespace ft {

template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1,
           InputIt1 last1,
           InputIt2 first2) {
    while (first1!=last1) {
        if (!(*first1 == *first2)) return false;
        ++first1;
        ++first2;
    }
    return true;
}

}  // namespace ft

#endif //_FT_EQUAL_
