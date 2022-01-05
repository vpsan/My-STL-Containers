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

    // ...

    std::cout << '\n';
    std::cout << "Finish\n";
    return 0;
}
