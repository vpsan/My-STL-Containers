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

void rbtree_test_insert_erase_isbalanced();
void rbtree_test_iterators();
void map_test_iterators();
void map_test_base();
void map_test_insert_el();
void map_test_insert_iter();
void map_test_insert_iter_range();
void map_test_erase();
void map_test_lower_upper_bound();

int main()
{

//    rbtree_test_insert_erase_isbalanced();
//    rbtree_test_iterators();
//    map_test_iterators();
//    map_test_base();
//    map_test_insert_el();
//    map_test_insert_iter();
//    map_test_insert_iter_range();
//    map_test_erase();
//    map_test_lower_upper_bound();

//    sleep(10);

    return 0;
}

void rbtree_test_insert_erase_isbalanced(){
    {
//        ft::red_black_tree<int> t = ft::red_black_tree<int>();
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//        t.insert(1);
//        t.insert(10);
//        t.insert(2);
//        t.insert(3);
//        t.insert(4);
//        t.insert(20);
//        t.insert(15);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//        t.insert(2);
//        t.insert(10);
//        t.insert(15);
//        t.insert(200);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//        t.erase(2);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        t.erase(10);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        t.erase(15);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        t.erase(3);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
//
//        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> it = t.begin();
//        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<true> c_it = t.begin();
//        c_it = it;
//        for (; it != t.end(); ++it){
//            std::cout<< *it << std::endl;
//        }
//
//        ft::red_black_tree<int>::reverse_iterator rit = t.rbegin();
//        for (; rit != t.rend(); ++rit){
//            std::cout<< *rit << std::endl;
//        }
//
//        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter = t.begin();
//        t.erase(iter);
//        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
//        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
    }
    {
        // test for insert other iter elements
        ft::red_black_tree<int> h = ft::red_black_tree<int>();
        h.insert(-1);
        h.insert(1000);
        h.insert(2000);
        h.insert(3000);
        h.insert(4000);
        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_11 = h.begin();
        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_12 = (--h.end());

        ft::red_black_tree<int> t = ft::red_black_tree<int>();
        t.insert(iter_11, iter_12);
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";

        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_21 = t.begin();
        ft::red_black_tree<int>::RedBlackTreeBidirectionalIterator<false> iter_22 = (--t.end()); // t.end()
        std::cout << "1\n";
        t.insert(iter_21, iter_22);
        std::cout << "2\n";
        std::cout << "is_isBalanced = " << t.isBalanced() << std::endl;
        std::cout << "--Start-Print--\n"; t.print_sorted_tree(); std::cout << "--End-Print--\n";
    }
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
    {
        // ft::red_black_tree<ft::pair<char, int> > t = ft::red_black_tree<ft::pair<char, int> >();
        // t.insert(ft::pair<char, int>('a', 10));
        // t.insert(ft::pair<char, int>('b', 20));
        // t.insert(ft::pair<char, int>('c', 30));
        // t.insert(ft::pair<char, int>('d', 40));
        // t.insert(ft::pair<char, int>('e', 50));
        // t.insert(ft::pair<char, int>('f', 60));

        // t.print_sorted_tree();

        // std::cout << "---iterator---\n";
        // for (ft::red_black_tree<int>::iterator it = t.begin(); it!=t.end(); ++it)
        //     std::cout << *it << std::endl;
        // std::cout << "---const_iterator---\n";
        // for (ft::red_black_tree<int>::const_iterator it = t.begin(); it!=t.end(); ++it)
        //     std::cout << *it << std::endl;
        // std::cout << "---reverse_iterator---\n";
        // for (ft::red_black_tree<int>::reverse_iterator it = t.rbegin(); it!=t.rend(); ++it)
        //     std::cout << *it << std::endl;
        // std::cout << "---const_reverse_iterator---\n";
        // for (ft::red_black_tree<int>::const_reverse_iterator it = t.rbegin(); it!=t.rend(); ++it)
        //     std::cout << *it << std::endl;
        // std::cout << "size = " << t.size() << std::endl;
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

        // print content:
        for (ft::map<char, int>::const_reverse_iterator it = mymap.rbegin();
             it != mymap.rend(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
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
        // mymap.erase(itlow, itup);
        mymap.erase(itlow);
        mymap.erase(itup);

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
        // mymap.erase(itlow, itup);
        mymap.erase(itlow);
        mymap.erase(itup);

        // print content:
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
}
