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

    ft::red_black_tree<int> t = ft::red_black_tree<int>();
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;

    t.insert(1);
    t.insert(10);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(20);
    t.insert(15);
    std::cout << "---------\n";
    t.inorder(t.root_);
    std::cout << "---------\n";
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;
    t.erase(2);
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;
    t.erase(10);
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;
    t.erase(15);
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;
    t.erase(4);
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;
    std::cout << "---------\n";
    t.inorder(t.root_);
    std::cout << "---------\n";
    t.insert(2);
    t.insert(10);
    t.insert(15);
    t.insert(200);
    t.insert(20);
    std::cout << "is_isBalanced = " << t.isBalanced(t.root_) << std::endl;
    std::cout << "---------\n";
    t.inorder(t.root_);
    std::cout << "---------\n";

    std::cout << '\n';
    std::cout << "Finish\n";


    return 0;
}
