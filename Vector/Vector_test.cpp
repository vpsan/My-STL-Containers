#include <iostream>
#include <vector>
#include <string.h>

#include "Vector.hpp"

void vector_test_iterators();

int main(void)
{
    vector_test_iterators();

    return (0);
}

void vector_test_iterators(){
    {
        std::cout << "\033[33m";
        std::vector<std::string> v;

        v.push_back("one");
        v.push_back("two");
        v.push_back("three");
        v.push_back("four");
        v.push_back("five");

        std::cout << "PART 1\n";
        std::cout << "---iterator---\n";
        for (std::vector<std::string>::iterator it = v.begin(); it!=v.end(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (std::vector<std::string>::const_iterator it = v.begin(); it!=v.end(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::vector<std::string>::reverse_iterator it = v.rbegin(); it!=v.rend(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::vector<std::string>::const_reverse_iterator it = v.rbegin(); it!=v.rend(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;

        std::cout << "PART 2\n";
        std::cout << "---iterator---\n";
        for (std::vector<std::string>::iterator it = v.begin(); it!=v.end(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (std::vector<std::string>::const_iterator it = v.begin(); it!=v.end(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::vector<std::string>::reverse_iterator it = v.rbegin(); it!=v.rend(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::vector<std::string>::const_reverse_iterator it = v.rbegin(); it!=v.rend(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;

        std::cout << "PART 3\n";
        std::cout << "---iterator---\n";
        for (std::vector<std::string>::iterator it = --v.end(); it!=v.begin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (std::vector<std::string>::const_iterator it = --v.end(); it!=v.begin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::vector<std::string>::reverse_iterator it = --v.rend(); it!=v.rbegin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::vector<std::string>::const_reverse_iterator it = --v.rend(); it!=v.rbegin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;

        std::cout << "PART 4\n";
        std::cout << "---iterator---\n";
        for (std::vector<std::string>::iterator it = --v.end(); it!=v.begin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (std::vector<std::string>::const_iterator it = --v.end(); it!=v.begin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::vector<std::string>::reverse_iterator it = --v.rend(); it!=v.rbegin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::vector<std::string>::const_reverse_iterator it = --v.rend(); it!=v.rbegin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<std::string> v;

        v.push_back("one");
        v.push_back("two");
        v.push_back("three");
        v.push_back("four");
        v.push_back("five");

        std::cout << "PART 1\n";
        std::cout << "---iterator---\n";
        for (ft::vector<std::string>::iterator it = v.begin(); it!=v.end(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::vector<std::string>::const_iterator it = v.begin(); it!=v.end(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it!=v.rend(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::vector<std::string>::const_reverse_iterator it = v.rbegin(); it!=v.rend(); ++it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;

        std::cout << "PART 2\n";
        std::cout << "---iterator---\n";
        for (ft::vector<std::string>::iterator it = v.begin(); it!=v.end(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::vector<std::string>::const_iterator it = v.begin(); it!=v.end(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it!=v.rend(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::vector<std::string>::const_reverse_iterator it = v.rbegin(); it!=v.rend(); it++)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;

        std::cout << "PART 3\n";
        std::cout << "---iterator---\n";
        for (ft::vector<std::string>::iterator it = --v.end(); it!=v.begin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::vector<std::string>::const_iterator it = --v.end(); it!=v.begin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::vector<std::string>::reverse_iterator it = --v.rend(); it!=v.rbegin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::vector<std::string>::const_reverse_iterator it = --v.rend(); it!=v.rbegin(); --it)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;

        std::cout << "PART 4\n";
        std::cout << "---iterator---\n";
        for (ft::vector<std::string>::iterator it = --v.end(); it!=v.begin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::vector<std::string>::const_iterator it = --v.end(); it!=v.begin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::vector<std::string>::reverse_iterator it = --v.rend(); it!=v.rbegin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::vector<std::string>::const_reverse_iterator it = --v.rend(); it!=v.rbegin(); it--)
            std::cout << "*it=" << *it << '\n';
        std::cout << "size = " << v.size() << std::endl;
        std::cout << "\033[0m";
    }
}