#include <iostream>

#include <stack>
#include <vector>
#include <map>

#include "Stack/Stack.hpp"
#include "Vector/Vector.hpp"
#include "Map/Map.hpp"

#include "includes/ReverseIterator.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "\033[33m";
    os << "size = " << v.size() << std::endl;
    os << "capacity_ = " << v.capacity() << std::endl;
    int i = 0;
    for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it){
        os << "arr[" << i << "] = " << *it << std::endl;
        i++;
    }
    os << "\033[33m";
    return os;
}

int main(void)
{
    std::cout << "Start!\n";
    std::cout << '\n';

{ // test ft::Vector

    {
        std::cout << " -- test ----------------- reserve" << std::endl;

        ft::Vector<int>         v1(3, 1);
        ft::Vector<std::string> v2(3, "one");
        v1.reserve(5);
        v2.reserve(5);
        std::cout << v1 << std::endl;
        std::cout << v2 << std::endl;

        std::cout << " -- finish_test ---------- reserve" << std::endl;
    }
    {
        std::cout << " -- test ----------------- resize" << std::endl;

        ft::Vector<int>         v1(3, 1);
        ft::Vector<std::string> v2(3, "one");
        v1.resize(4, 2);
        v2.resize(4, "two");
        std::cout << v1 << std::endl;
        std::cout << v2 << std::endl;

        std::cout << " -- finish_test ---------- resize" << std::endl;
    }
    {
        std::cout << " -- test ----------------- RandomAccessIterator" << std::endl;

        ft::Vector<std::string>         ft_v1(1, "one");
        const ft::Vector<std::string>   ft_v2(1, "const_one");

        ft::Vector<std::string>::RandomAccessIterator<false>    iter;
        ft::Vector<std::string>::RandomAccessIterator<true>     const_iter;
        iter = ft_v1.begin();
        const_iter = ft_v2.begin();

        std::cout << "*iter = " << *iter << std::endl;
        std::cout << "*const_iter = " << *const_iter << std::endl;

        const_iter = iter;
        std::cout << "*const_iter = " << *const_iter << std::endl;

        std::cout << " -- finish_test ---------- RandomAccessIterator" << std::endl;
    }
    {
        std::cout << " -- test ----------------- ReverseIterator" << std::endl;

        ft::Vector<std::string>         ft_v1(2, "one");
        const ft::Vector<std::string>   ft_v2(2, "const_one");
        ft::ReverseIterator<ft::Vector<std::string>::RandomAccessIterator<false> >   r_iter;
        ft::ReverseIterator<ft::Vector<std::string>::RandomAccessIterator<true> >    const_r_iter;

//        const_r_iter = ft_v1.rbegin();
//        r_iter = ft_v2.rbegin();

//        const_r_iter = r_iter;
//        r_iter = const_r_iter;

//        r_iter = ft_v1.rbegin();
//        std::cout << *r_iter << std::endl;
//        r_iter++;
//        std::cout << *r_iter << std::endl;

        std::cout << " -- finish_test ---------- ReverseIterator" << std::endl;
    }
}

    std::cout << '\n';
    std::cout << "Finish\n";
    return 0;
}
