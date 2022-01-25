#include <iostream>

#include <stack>
#include <vector>
#include <map>

#include "Stack/Stack.hpp"
#include "Vector/Vector.hpp"
#include "Map/Map.hpp"

#include "includes/ReverseIterator.hpp"

#include "includes/red_black_tree.hpp"

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

//    ft::pair<int, int>
    ft::red_black_tree<int> t = ft::red_black_tree<int>();
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(110);
    t.insert(100);
    t.insert(90);
    t.insert(40);
    t.insert(50);
    t.insert(70);
    t.insert(80);
    t.insert(150);
    t.insert(120);
    t.insert(1);
    t.insert(2);
    t.insert(3);

//    std::cout << "1\n";
//    t.insert(10);
//    std::cout << "2\n";
//    t.insert(1);
//    std::cout << "3\n";
//    t.insert(20);
//    std::cout << "4\n";
//    t.insert(2);
    t.inorder(t.root_);
    std::cout << "---------\n";
    t.erase(3);
    t.erase(1);
    t.erase(120);
    t.inorder(t.root_);


    std::cout << '\n';
    std::cout << "Finish\n";
    return 0;
}
