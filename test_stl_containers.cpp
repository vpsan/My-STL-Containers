#include <iostream>

#include <stack>
#include <vector>
#include <map>

#include <string>
#include <unistd.h>

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

void map_test_insert_el();
void map_test_insert_iter();
void map_test_insert_iter_range();
void map_test_erase();

int main()
{
//    std::cout << "Start!\n";
//    std::cout << '\n';
//
//    ft::red_black_tree<int> t = ft::red_black_tree<int>();
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//    t.insert(1);
//    t.insert(10);
//    t.insert(2);
//    t.insert(3);
//    t.insert(4);
//    t.insert(20);
//    t.insert(15);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//    t.insert(2);
//    t.insert(10);
//    t.insert(15);
//    t.insert(200);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//    t.erase(2);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(10);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(15);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(3);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> it = t.begin();
//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<true> c_it = t.begin();
//    c_it = it;
//    for (; it != t.end(); ++it){
//        std::cout<< *it << std::endl;
//    }
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//
//    ft::red_black_tree<int>::reverse_iterator rit = t.rbegin();
//    for (; rit != t.rend(); ++rit){
//        std::cout<< *rit << std::endl;
//    }
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//
//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter = t.begin();
//    t.erase(iter);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//
//    // test for insert other iter elements
//    ft::red_black_tree<int> h = ft::red_black_tree<int>();
//    h.insert(-1);
//    h.insert(1000);
//    h.insert(2000);
//    h.insert(3000);
//    h.insert(4000);
//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter1 = h.begin();
//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter2 = (--h.end());
//    t.insert(iter1, iter2);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter1 = t.begin();
//    ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter2 = (--t.end());
//    t.insert(iter1, iter2);
//    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//    std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

//    std::cout << '\n';
//    std::cout << "Finish\n";

//    std::vector<int> v(5);
//    for (int i = 0; i != 5; i++){
//        v[i] = i;
//    }
//    std::cout << "rb = " << *(v.rbegin()) << std::endl;
//    std::cout << "re = " << *(v.rend()) << std::endl;
//    for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
//        std::cout << *it << std::endl;
//    }
//
//    std::map<int, std::string> m;
//    for (int i = 0; i != 5; i++){
//        m[i] = "my_str";
//    }
//    std::cout << "rb = " << (m.rbegin()->first) << std::endl;
//    // std::cout << "re = " << (m.rend()->first) << std::endl;
//    std::cout << "--re = " << ((--m.rend())->first) << std::endl;
//    for (std::map<int, std::string>::reverse_iterator it = m.rbegin(); it != m.rend(); it++){
//        std::cout << (it->first) << std::endl;
//    }

// test map
//    ft::map<int, std::string> m;
//    m.insert({161, "Hinata1"});
//    std::cout << "size = " << m.size() << std::endl;
//    m.insert({162, "Hinata2"});
//    std::cout << "size = " << m.size() << std::endl;
//    m.insert({161, "Hinata0"});
//    std::cout << "size = " << m.size() << std::endl;
//    for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
//        std::cout << "iter_i = " << (it->second) << std::endl;
//    }
//    m.erase(160);
//    m.erase(161);
//    m.erase(161);
//    std::cout << "size = " << m.size() << std::endl;
//    for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
//        std::cout << "iter_i = " << (it->second) << std::endl;
//    }
//    m.clear();
//    std::cout << "size = " << m.size() << std::endl;
//    for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
//        std::cout << "iter_i = " << (it->second) << std::endl;
//    }
//    sleep(10);

//    map_test_insert_el();
//    map_test_insert_iter();
//    map_test_insert_iter_range();
    map_test_erase();

    return 0;
}


void map_test_insert_el(){
    {
        std::map<char,int> mymap;
        // first insert function version (single parameter):
        mymap.insert ( std::pair<char,int>('a',100) );
        mymap.insert ( std::pair<char,int>('z',200) );

        std::pair<std::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( std::pair<char,int>('z',500) );
        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
    }
    {
        ft::map<char, int> mymap;
        // first insert function version (single parameter):
        mymap.insert(ft::pair<char, int>('a', 100));
        mymap.insert(ft::pair<char, int>('z', 200));

        ft::pair<ft::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(ft::pair<char, int>('z', 500));
        if (ret.second == false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
    }
}

void map_test_insert_iter(){
    {
        std::map<char,int> mymap;
        // second insert function version (with hint position):
        std::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
        mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
        std::cout << "size = " << mymap.size() << std::endl;
    }
    {
        ft::map<char,int> mymap;
        // second insert function version (with hint position):
        ft::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
        mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
        std::cout << "size = " << mymap.size() << std::endl;
    }
}

void map_test_insert_iter_range(){
    {
        std::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( std::pair<char,int>('a',100) );
        mymap.insert ( std::pair<char,int>('z',200) );

        std::pair<std::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( std::pair<char,int>('z',500) );

        // second insert function version (with hint position):
        std::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        std::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {

        ft::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( ft::pair<char,int>('a',100) );
        mymap.insert ( ft::pair<char,int>('z',200) );

        ft::pair<ft::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( ft::pair<char,int>('z',500) );

        // second insert function version (with hint position):
        ft::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
}

void map_test_erase(){
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;

        // insert some values:
        mymap.insert({'a', 10});
        mymap.insert({'b', 20});
        mymap.insert({'c', 30});
        mymap.insert({'d', 40});
        mymap.insert({'e', 50});
        mymap.insert({'f', 60});

        it=mymap.find('b');
        mymap.erase (it);                   // erasing by iterator

        mymap.erase ('c');                  // erasing by key

        it=mymap.find ('e');
//        mymap.erase ( it, mymap.end() );    // erasing by range

        // show content:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;
    }
    {
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator it;

        // insert some values:
        mymap.insert({'a', 10});
        mymap.insert({'b', 20});
        mymap.insert({'c', 30});
        mymap.insert({'d', 40});
        mymap.insert({'e', 50});
        mymap.insert({'f', 60});

        it=mymap.find('b');
        mymap.erase (it);                // erasing by iterator

        mymap.erase ('c');                  // erasing by key

        it=mymap.find ('e');
//        mymap.erase ( it, mymap.end() );    // erasing by range

        // show content:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;
    }
}
