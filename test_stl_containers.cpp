#include <iostream>

#include <stack>
#include <vector>
#include <map>

#include "Stack/Stack.hpp"
#include "Vector/Vector.hpp"
#include "Map/Map.hpp"

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

}

    std::cout << '\n';
    std::cout << "Finish\n";
    return 0;
}
