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

void tree_test_insert();
void tree_test_delete();
void rbtree_test_insert_erase_isbalanced();
void rbtree_test_iterators();
void map_test_iterators();
void map_test_base();
void map_test_insert_el();
void map_test_insert_iter();
void map_test_insert_iter_range();
void map_test_erase();
void map_test_lower_upper_bound();
void map_test_operator_access();
void map_test_swap();
void map_test_find();
void map_test_count();
void map_test_equal_range();
void map_test_copy();
void map_test_operators();

int main()
{

//    tree_test_insert();
//    tree_test_delete();
//    rbtree_test_insert_erase_isbalanced();
//    rbtree_test_iterators();
//    map_test_iterators();
//    map_test_base();
//    map_test_insert_el();
//    map_test_insert_iter();
//    map_test_insert_iter_range();
//    map_test_erase();
//    map_test_lower_upper_bound();
//    map_test_operator_access();
//    map_test_swap();
//    map_test_find();
//    map_test_count();
//    map_test_equal_range();
//    map_test_copy();
//    map_test_operators();

//    sleep(10);

    return 0;
}

void tree_test_insert(){
    ft::red_black_tree<int> t = ft::red_black_tree<int>();
    t.insert(1);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(10);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(5);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(2);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(9);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(6);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(3);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(8);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(4);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(7);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(11);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(20);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
    t.insert(15);
    std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
}

// Проблемы - c удалением повторно/несуществующего элемента.
// Но стоит ли это править тут? Скорее нет, это задача класса map
void tree_test_delete(){
    ft::red_black_tree<int> t = ft::red_black_tree<int>();
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(12);

    // case 1
    std::cout << "-----------" << std::endl;
    t.erase(8);//-
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(2);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(10);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(12);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(3);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(11);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(9);//-
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(7);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(6);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(5);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(4);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
    t.erase(1);
    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;

//    // case 2
//    std::cout << "-----------" << std::endl;
//    t.erase(1);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(2);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(10);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(12);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(3);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(11);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(9);//-
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(7);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(6);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(5);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(4);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
//    t.erase(8);
//    std::cout << "size=" << t.size() << " is_isBalanced = " << t.isBalanced() << std::endl;
}

void rbtree_test_insert_erase_isbalanced(){
    {
        ft::red_black_tree<int> t = ft::red_black_tree<int>();
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

        t.insert(1);
        t.insert(10);
        t.insert(2);
        t.insert(3);
        t.insert(4);
        t.insert(20);
        t.insert(15);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

        t.insert(2);
        t.insert(10);
        t.insert(15);
        t.insert(200);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

        t.erase(2);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        t.erase(10);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        t.erase(15);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        t.erase(3);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> it = t.begin();
        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<true> c_it = t.begin();
        c_it = it;
        for (; it != t.end(); ++it){
            std::cout<< *it << std::endl;
        }

        ft::red_black_tree<int>::reverse_iterator rit = t.rbegin();
        for (; rit != t.rend(); ++rit){
            std::cout<< *rit << std::endl;
        }

        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter = t.begin();
        t.erase(iter);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
    }
//    {
//        // test for insert other iter elements
//        ft::red_black_tree<int> h = ft::red_black_tree<int>();
//        h.insert(-1);
//        h.insert(1000);
//        h.insert(2000);
//        h.insert(3000);
//        h.insert(4000);
//        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_11 = h.begin();
//        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_12 = (--h.end());
//
//        ft::red_black_tree<int> t = ft::red_black_tree<int>();
//        t.insert(iter_11, iter_12);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
////        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_21 = t.begin();
////        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_22 = (--t.end()); // t.end()
////        std::cout << *iter_21 << std::endl;
////        std::cout << *iter_22 << std::endl;
////        std::cout << "-------\n";
////        t.insert(iter_21, iter_22);
////        std::cout << "2\n";
////        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
////        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//        ft::red_black_tree<int>::iterator iter = t.begin();
//        std::cout << *iter << std::endl;
//        std::cout << *(iter++) << std::endl;
//    }
}

void rbtree_test_iterators(){
    {
         ft::red_black_tree<int> t = ft::red_black_tree<int>();
         t.insert(1);
         t.insert(2);
         t.insert(3);
         t.insert(4);
         t.insert(20);
         t.insert(15);

         t.print_sorted_tree();

        std::cout << "PART 1\n";
         std::cout << "---iterator---\n";
         for (ft::red_black_tree<int>::iterator it = t.begin(); it!=t.end(); ++it)
             std::cout << *it << std::endl;
         std::cout << "---const_iterator---\n";
         for (ft::red_black_tree<int>::const_iterator it = t.begin(); it!=t.end(); ++it)
             std::cout << *it << std::endl;
         std::cout << "---reverse_iterator---\n";
         for (ft::red_black_tree<int>::reverse_iterator it = t.rbegin(); it!=t.rend(); ++it)
             std::cout << *it << std::endl;
         std::cout << "---const_reverse_iterator---\n";
         for (ft::red_black_tree<int>::const_reverse_iterator it = t.rbegin(); it!=t.rend(); ++it)
             std::cout << *it << std::endl;
         std::cout << "size = " << t.size() << std::endl;

        std::cout << "PART 2\n";
         std::cout << "---iterator---\n";
         for (ft::red_black_tree<int>::iterator it = t.begin(); it!=t.end(); it++)
             std::cout << *it << std::endl;
         std::cout << "---const_iterator---\n";
         for (ft::red_black_tree<int>::const_iterator it = t.begin(); it!=t.end(); it++)
             std::cout << *it << std::endl;
         std::cout << "---reverse_iterator---\n";
         for (ft::red_black_tree<int>::reverse_iterator it = t.rbegin(); it!=t.rend(); it++)
             std::cout << *it << std::endl;
         std::cout << "---const_reverse_iterator---\n";
         for (ft::red_black_tree<int>::const_reverse_iterator it = t.rbegin(); it!=t.rend(); it++)
             std::cout << *it << std::endl;
         std::cout << "size = " << t.size() << std::endl;

        std::cout << "PART 3\n";
         std::cout << "---iterator---\n";
         for (ft::red_black_tree<int>::iterator it = --t.end(); it!=t.begin(); --it)
             std::cout << *it << std::endl;
         std::cout << "---const_iterator---\n";
         for (ft::red_black_tree<int>::const_iterator it = --t.end(); it!=t.begin(); --it)
             std::cout << *it << std::endl;
         std::cout << "---reverse_iterator---\n";
         for (ft::red_black_tree<int>::reverse_iterator it = --t.rend(); it!=t.rbegin(); --it)
             std::cout << *it << std::endl;
         std::cout << "---const_reverse_iterator---\n";
         for (ft::red_black_tree<int>::const_reverse_iterator it = --t.rend(); it!=t.rbegin(); --it)
             std::cout << *it << std::endl;
         std::cout << "size = " << t.size() << std::endl;

        std::cout << "PART 4\n";
         std::cout << "---iterator---\n";
         for (ft::red_black_tree<int>::iterator it = --t.end(); it!=t.begin(); it--)
             std::cout << *it << std::endl;
         std::cout << "---const_iterator---\n";
         for (ft::red_black_tree<int>::const_iterator it = --t.end(); it!=t.begin(); it--)
             std::cout << *it << std::endl;
         std::cout << "---reverse_iterator---\n";
         for (ft::red_black_tree<int>::reverse_iterator it = --t.rend(); it!=t.rbegin(); it--)
             std::cout << *it << std::endl;
         std::cout << "---const_reverse_iterator---\n";
         for (ft::red_black_tree<int>::const_reverse_iterator it = --t.rend(); it!=t.rbegin(); it--)
             std::cout << *it << std::endl;
         std::cout << "size = " << t.size() << std::endl;
    }
}

void map_test_iterators(){
    {
        ft::map<char, int> mymap;
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('b', 20));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));

        std::cout << "PART 1\n";
        std::cout << "---iterator---\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::map<char, int>::const_iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::map<char, int>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::map<char, int>::const_reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;

        std::cout << "PART 2\n";
        std::cout << "---iterator---\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::map<char, int>::const_iterator it = mymap.begin(); it!=mymap.end(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::map<char, int>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::map<char, int>::const_reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;

        std::cout << "PART 3\n";
        std::cout << "---iterator---\n";
        for (ft::map<char, int>::iterator it = --mymap.end(); it!=mymap.begin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::map<char, int>::const_iterator it = --mymap.end(); it!=mymap.begin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::map<char, int>::reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::map<char, int>::const_reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;

        std::cout << "PART 4\n";
        std::cout << "---iterator---\n";
        for (ft::map<char, int>::iterator it = --mymap.end(); it!=mymap.begin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (ft::map<char, int>::const_iterator it = --mymap.end(); it!=mymap.begin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (ft::map<char, int>::reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (ft::map<char, int>::const_reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;
    }
}

void map_test_base(){
    {
        ft::map<int, std::string> m;
        m.insert(ft::pair<int, std::string>(161, "Hinata1"));
        std::cout << "size = " << m.size() << std::endl;
        m.insert(ft::pair<int, std::string>(162, "Hinata2"));
        std::cout << "size = " << m.size() << std::endl;
        m.insert(ft::pair<int, std::string>(161, "Hinata0"));
        std::cout << "size = " << m.size() << std::endl;
        for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
            std::cout << "iter_i = " << (it->second) << std::endl;
        }
        m.erase(160);
        m.erase(161);
        m.erase(161);
        std::cout << "size = " << m.size() << std::endl;
        for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
            std::cout << "iter_i = " << (it->second) << std::endl;
        }
        m.clear();
        std::cout << "size = " << m.size() << std::endl;
        for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
            std::cout << "iter_i = " << (it->second) << std::endl;
        }
    }
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
         for (std::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
             std::cout << it->first << " => " << it->second << '\n';
     }
     {
         ft::map<char,int> mymap;
         // second insert function version (with hint position):
         ft::map<char,int>::iterator it = mymap.begin();
         mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
         mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
         mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
         std::cout << "size = " << mymap.size() << std::endl;
         for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
             std::cout << it->first << " => " << it->second << '\n';
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
        mymap.insert(std::pair<char, int>('a', 10));
        mymap.insert(std::pair<char, int>('b', 20));
        mymap.insert(std::pair<char, int>('c', 30));
        mymap.insert(std::pair<char, int>('d', 40));
        mymap.insert(std::pair<char, int>('e', 50));

         // erasing by iterator
         it=mymap.find('b');
         mymap.erase (it);

         // erasing by key
         mymap.erase ('c');

         // erasing by range
         it=mymap.find ('e');
         mymap.erase ( it, mymap.end() );

         // show content:
         for (it=mymap.begin(); it!=mymap.end(); ++it)
             std::cout << it->first << " => " << it->second << '\n';
         std::cout << "size = " << mymap.size() << std::endl;
     }
     {
         ft::map<char,int> mymap;
         ft::map<char,int>::iterator it;

         // insert some values:
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('b', 20));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));

         // erasing by iterator
         it=mymap.find('b');
         mymap.erase (it);

         // erasing by key
         mymap.erase ('c');

         // erasing by range
         it=mymap.find ('e');
         mymap.erase ( it, mymap.end() );

         // show content:
         for (it=mymap.begin(); it!=mymap.end(); ++it)
             std::cout << it->first << " => " << it->second << '\n';
         std::cout << "size = " << mymap.size() << std::endl;
     }
 }

void map_test_lower_upper_bound() {
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator itlow,itup;

        // insert some values:
        mymap.insert(std::pair<char, int>('a', 10));
        mymap.insert(std::pair<char, int>('b', 20));
        mymap.insert(std::pair<char, int>('c', 30));
        mymap.insert(std::pair<char, int>('d', 40));
        mymap.insert(std::pair<char, int>('e', 50));

        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        // erases [itlow,itup)
         mymap.erase(itlow, itup);

        // print content:
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator itlow,itup;

        // insert some values:
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('b', 20));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));

        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        // erases [itlow,itup)
         mymap.erase(itlow, itup);

        // print content:
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
}

void map_test_operator_access(){
    {
        std::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    {

        ft::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
}

void map_test_swap() {
    {
        std::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
}

void map_test_find(){
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase (it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
    {
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase (it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
}

void map_test_count(){
    {
        std::map<char,int> mymap;
        char c;

        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c)>0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    {
        ft::map<char,int> mymap;
        char c;

        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c)>0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
}

void map_test_equal_range(){
    {
        std::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    {
        ft::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
}

void map_test_copy(){
    ft::map<char, int> mymap;
    mymap.insert(ft::pair<char, int>('a', 10));
    mymap.insert(ft::pair<char, int>('b', 20));
    mymap.insert(ft::pair<char, int>('c', 30));
    mymap.insert(ft::pair<char, int>('d', 40));
    mymap.insert(ft::pair<char, int>('e', 50));

    std::cout << "PART 1\n";
    std::cout << "---iterator---\n";
    for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    ft::map<char, int> mymap1 = mymap;
    std::cout << "PART 1\n";
    std::cout << "---iterator---\n";
    for (ft::map<char, int>::iterator it = mymap1.begin(); it!=mymap1.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void map_test_operators(){
    ft::map<char, int> mymap;
    mymap.insert(ft::pair<char, int>('a', 10));
    mymap.insert(ft::pair<char, int>('b', 20));
    mymap.insert(ft::pair<char, int>('c', 30));
    mymap.insert(ft::pair<char, int>('d', 40));
    mymap.insert(ft::pair<char, int>('e', 50));

    std::cout << "PART 1\n";
    std::cout << "---iterator---\n";
    for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    ft::map<char, int> mymap1 = mymap;
    std::cout << "PART 1\n";
    std::cout << "---iterator---\n";
    for (ft::map<char, int>::iterator it = mymap1.begin(); it!=mymap1.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "== ? - " << (mymap == mymap1) << std::endl;
    std::cout << "!= ? - " << (mymap != mymap1) << std::endl;
    std::cout << ">  ? - " << (mymap > mymap1) << std::endl;
    std::cout << ">= ? - " << (mymap >= mymap1) << std::endl;
    std::cout << "<= ? - " << (mymap < mymap1) << std::endl;
    std::cout << "<= ? - " << (mymap <= mymap1) << std::endl;
}
