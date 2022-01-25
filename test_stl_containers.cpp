#include <iostream>

#include <stack>
#include <vector>
#include <map>

#include <string>

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

//    typedef ft::pair<int, std::string> pr;
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
    t.inorder(t.root_);
    std::cout << "---------\n";
    t.erase(3);
    t.erase(1);
    t.erase(120);
    t.inorder(t.root_);

//    // check for default constructor
//    std::pair<int, std::string> p = std::pair<int, std::string>();
//    std::cout << "p.first = " << p.first << '1' << std::endl;
//    std::cout << "p.second = " << p.second << '1' << std::endl;

//    ft::pair<int, std::string> p = ft::pair<int, std::string>();
//    std::cout << "p.first = " << p.first << '1' << std::endl;
//    std::cout << "p.second = " << p.second << '1' << std::endl;

    std::cout << '\n';
    std::cout << "Finish\n";
    return 0;
}
