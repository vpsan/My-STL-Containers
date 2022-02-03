#include <iostream>
#include <string>
#include <unistd.h>

#include <map>
#include "Map.hpp"

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
void map_test_at();
void map_test_count();
void map_test_equal_range();
void map_test_copy();
void map_test_operators();
void map_test_iterator_invalidation();

int main(void)
{
    map_test_iterators();
    map_test_base();
    map_test_insert_el();
    map_test_insert_iter();
    map_test_insert_iter_range();
    map_test_erase();
    map_test_lower_upper_bound();
    map_test_operator_access();
    map_test_swap();
    map_test_find();
    map_test_at();
    map_test_count();
    map_test_equal_range();
    map_test_copy();
    map_test_operators();
    map_test_iterator_invalidation();

    // sleep(10);

    return (0);
}

void map_test_iterators(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 10));
        mymap.insert(std::pair<char, int>('b', 20));
        mymap.insert(std::pair<char, int>('c', 30));
        mymap.insert(std::pair<char, int>('d', 40));
        mymap.insert(std::pair<char, int>('e', 50));

        std::cout << "PART 1\n";
        std::cout << "---iterator---\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (std::map<char, int>::const_iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::map<char, int>::const_reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;

        std::cout << "PART 2\n";
        std::cout << "---iterator---\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (std::map<char, int>::const_iterator it = mymap.begin(); it!=mymap.end(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::map<char, int>::const_reverse_iterator it = mymap.rbegin(); it!=mymap.rend(); it++)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;

        std::cout << "PART 3\n";
        std::cout << "---iterator---\n";
        for (std::map<char, int>::iterator it = --mymap.end(); it!=mymap.begin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (std::map<char, int>::const_iterator it = --mymap.end(); it!=mymap.begin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::map<char, int>::reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::map<char, int>::const_reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); --it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;

        std::cout << "PART 4\n";
        std::cout << "---iterator---\n";
        for (std::map<char, int>::iterator it = --mymap.end(); it!=mymap.begin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_iterator---\n";
        for (std::map<char, int>::const_iterator it = --mymap.end(); it!=mymap.begin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---reverse_iterator---\n";
        for (std::map<char, int>::reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "---const_reverse_iterator---\n";
        for (std::map<char, int>::const_reverse_iterator it = --mymap.rend(); it!=mymap.rbegin(); it--)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "size = " << mymap.size() << std::endl;
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

void map_test_base(){
    std::cout << "===================================================================" << std::endl;
        {
        std::cout << "\033[33m";
        std::map<int, std::string> m;
        m.insert(std::pair<int, std::string>(161, "Hinata1"));
        std::cout << "size = " << m.size() << std::endl;
        m.insert(std::pair<int, std::string>(162, "Hinata2"));
        std::cout << "size = " << m.size() << std::endl;
        m.insert(std::pair<int, std::string>(161, "Hinata0"));
        std::cout << "size = " << m.size() << std::endl;
        for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
            std::cout << "iter_i = " << (it->second) << std::endl;
        }
        m.erase(160);
        m.erase(161);
        m.erase(161);
        std::cout << "size = " << m.size() << std::endl;
        for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
            std::cout << "iter_i = " << (it->second) << std::endl;
        }
        m.clear();
        std::cout << "size = " << m.size() << std::endl;
        for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it){
            std::cout << "iter_i = " << (it->second) << std::endl;
        }
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

 void map_test_insert_el(){
    std::cout << "===================================================================" << std::endl;
    {
         std::cout << "\033[33m";
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
         std::cout << "\033[0m";
     }
     {
        std::cout << "\033[34m";
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
         std::cout << "\033[0m";
     }
 }

 void map_test_insert_iter(){
     std::cout << "===================================================================" << std::endl;
     {
         std::cout << "\033[33m";
         std::map<char,int> mymap;
         // second insert function version (with hint position):
         std::map<char,int>::iterator it = mymap.begin();
         mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
         mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
         mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
         std::cout << "size = " << mymap.size() << std::endl;
         for (std::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
             std::cout << it->first << " => " << it->second << '\n';
        std::cout << "\033[0m";
     }
     {
         std::cout << "\033[34m";
         ft::map<char,int> mymap;
         // second insert function version (with hint position):
         ft::map<char,int>::iterator it = mymap.begin();
         mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
         mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
         mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
         std::cout << "size = " << mymap.size() << std::endl;
         for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
             std::cout << it->first << " => " << it->second << '\n';
        std::cout << "\033[0m";
     }
 }

 void map_test_insert_iter_range(){
     std::cout << "===================================================================" << std::endl;
     {
         std::cout << "\033[33m";
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
        std::cout << "\033[0m";
     }
     {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
     }
 }

 void map_test_erase(){
     std::cout << "===================================================================" << std::endl;
     {
         std::cout << "\033[33m";
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
        std::cout << "\033[0m";
     }
     {
         std::cout << "\033[34m";
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
        std::cout << "\033[0m";
     }
 }

void map_test_lower_upper_bound() {
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
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
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

void map_test_operator_access(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        std::cout << "\033[0m";
    }
}

void map_test_swap() {
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
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
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

void map_test_find(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
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
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

void map_test_at() {
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;
        try {
            std::cout << mymap.at('a') << std::endl;
            std::cout << mymap.at('z') << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;
        try {
            std::cout << mymap.at('a') << std::endl;
            std::cout << mymap.at('z') << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "\033[0m";
    }
}

void map_test_count(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
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
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

void map_test_equal_range(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
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
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
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
        std::cout << "\033[0m";
    }
}

void map_test_copy(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 10));
        mymap.insert(std::pair<char, int>('b', 20));
        mymap.insert(std::pair<char, int>('c', 30));
        mymap.insert(std::pair<char, int>('d', 40));
        mymap.insert(std::pair<char, int>('e', 50));

        std::cout << "---iterator---\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::map<char, int> mymap1(mymap);
        std::cout << "---iterator---\n";
        for (std::map<char, int>::iterator it = mymap1.begin(); it!=mymap1.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::map<char, int> mymap;
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('b', 20));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));

        std::cout << "---iterator---\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        ft::map<char, int> mymap1(mymap);
        std::cout << "---iterator---\n";
        for (ft::map<char, int>::iterator it = mymap1.begin(); it!=mymap1.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "\033[0m";
    }
}

void map_test_operators(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        ft::map<char, int> mymap;
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('b', 20));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));
        ft::map<char, int> mymap1 = mymap;

        std::cout << "== ? - " << (mymap == mymap1) << std::endl;
        std::cout << "!= ? - " << (mymap != mymap1) << std::endl;
        std::cout << ">  ? - " << (mymap > mymap1) << std::endl;
        std::cout << ">= ? - " << (mymap >= mymap1) << std::endl;
        std::cout << "<  ? - " << (mymap < mymap1) << std::endl;
        std::cout << "<= ? - " << (mymap <= mymap1) << std::endl;
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::map<char, int> mymap;
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('b', 20));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));
        ft::map<char, int> mymap1 = mymap;

        std::cout << "== ? - " << (mymap == mymap1) << std::endl;
        std::cout << "!= ? - " << (mymap != mymap1) << std::endl;
        std::cout << ">  ? - " << (mymap > mymap1) << std::endl;
        std::cout << ">= ? - " << (mymap >= mymap1) << std::endl;
        std::cout << "<  ? - " << (mymap < mymap1) << std::endl;
        std::cout << "<= ? - " << (mymap <= mymap1) << std::endl;
        std::cout << "\033[0m";
    }
}

void map_test_iterator_invalidation(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('b', 20));

        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(std::pair<char, int>('a', 10));
        mymap.insert(std::pair<char, int>('c', 30));
        mymap.insert(std::pair<char, int>('d', 40));
        mymap.insert(std::pair<char, int>('e', 50));
        for (; it!= mymap.end(); ++it){
            std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::map<char, int> mymap;
        mymap.insert(ft::pair<char, int>('b', 20));

        ft::map<char, int>::iterator it = mymap.begin();
        mymap.insert(ft::pair<char, int>('a', 10));
        mymap.insert(ft::pair<char, int>('c', 30));
        mymap.insert(ft::pair<char, int>('d', 40));
        mymap.insert(ft::pair<char, int>('e', 50));
        for (; it!= mymap.end(); ++it){
            std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << "\033[0m";
    }
}
