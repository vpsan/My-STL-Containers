#include <iostream>
#include <string.h>
#include <unistd.h>

#include <vector>
#include "Vector.hpp"

void vector_test_constructor();
void vector_test_iterators();
void vector_test_size();
void vector_test_resize();
void vector_test_capacity();
void vector_test_empty();
void vector_test_reserve();
void vector_test_at();
void vector_test_front();
void vector_test_back();
void vector_test_assign();
void vector_test_push_back();
void vector_test_pop_back();
void vector_test_insert();
void vector_test_erase();
void vector_test_swap();
void vector_test_clear();
void vector_test_operators();

int main(void)
{
    vector_test_constructor();
    vector_test_iterators();
    vector_test_size();
    vector_test_resize();
    vector_test_capacity();
    vector_test_empty();
    vector_test_reserve();
    vector_test_at();
    vector_test_front();
    vector_test_back();
    vector_test_assign();
    vector_test_push_back();
    vector_test_pop_back();
    vector_test_insert();
    vector_test_erase();
    vector_test_swap();
    vector_test_clear();
    vector_test_operators();

    // sleep(10);

    return (0);
}

void vector_test_constructor(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        // constructors used in the same order as described above:
        std::vector<int> first;                                // empty vector of ints
        std::vector<int> second (4,100);                       // four ints with value 100
        std::vector<int> third (second.begin(),second.end());  // iterating through second
        std::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are:";
        for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        // constructors used in the same order as described above:
        ft::vector<int> first;                                // empty vector of ints
        ft::vector<int> second (4,100);                       // four ints with value 100
        ft::vector<int> third (second.begin(),second.end());  // iterating through second
        ft::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are:";
        for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_iterators(){
    std::cout << "===================================================================" << std::endl;
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

void vector_test_size(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_capacity(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
        std::cout << "\033[0m";
    }
}

void vector_test_resize(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (unsigned long i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (unsigned long i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_empty(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;
        int sum (0);

        for (int i=1;i<=10;i++) myvector.push_back(i);

        while (!myvector.empty())
        {
            sum += myvector.back();
            myvector.pop_back();
        }

        std::cout << "total: " << sum << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;
        int sum (0);

        for (int i=1;i<=10;i++) myvector.push_back(i);

        while (!myvector.empty())
        {
            sum += myvector.back();
            myvector.pop_back();
        }

        std::cout << "total: " << sum << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_reserve(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int>::size_type sz;

        std::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) {
            foo.push_back(i);
            if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        std::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) {
            bar.push_back(i);
            if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int>::size_type sz;

        ft::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) {
            foo.push_back(i);
            if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        ft::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) {
            bar.push_back(i);
            if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }
        std::cout << "\033[0m";
    }
}

void vector_test_at(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
            myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector.at(i);
        std::cout << '\n';

        try {
            std::cout << myvector.at(10000) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
            myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector.at(i);
        std::cout << '\n';

        try {
            std::cout << myvector.at(10000) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "\033[0m";
    }
}

void vector_test_front(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;

        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16

        myvector.front() -= myvector.back();

        std::cout << "myvector.front() is now " << myvector.front() << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;

        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16

        myvector.front() -= myvector.back();

        std::cout << "myvector.front() is now " << myvector.front() << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_back(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
            myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
            myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_assign(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> first;
        std::vector<int> second;
        std::vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        std::vector<int>::iterator it;
        it=first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> first;
        ft::vector<int> second;
        ft::vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        ft::vector<int>::iterator it;
        it=first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_push_back(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;

        for (int i = 0; i < 100; i++) myvector.push_back(i);

        std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;

        for (int i = 0; i < 100; i++) myvector.push_back(i);

        std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        std::cout << "\033[0m";
    }
}

void vector_test_pop_back(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;
        int sum (0);
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        while (!myvector.empty())
        {
            sum+=myvector.back();
            myvector.pop_back();
        }

        std::cout << "The elements of myvector add up to " << sum << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;
        int sum (0);
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        while (!myvector.empty())
        {
            sum+=myvector.back();
            myvector.pop_back();
        }

        std::cout << "The elements of myvector add up to " << sum << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_insert(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector (3,100);
        std::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , 200 );

        myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        std::vector<int> anothervector (2,400);
        myvector.insert (it+2,anothervector.begin(),anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3);

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector (3,100);
        ft::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , 200 );

        myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        std::vector<int> anothervector (2,400);
        myvector.insert (it+2,anothervector.begin(),anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3);

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_erase(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        myvector.erase (myvector.begin(),myvector.begin()+3);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        myvector.erase (myvector.begin(),myvector.begin()+3);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_swap(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_clear(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void vector_test_operators(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::vector<int> vec;
        for (int i=0; i<5; ++i) vec.push_back(i);
        std::vector<int> vec1 = vec;
        std::cout << "== ? - " << (vec == vec1) << std::endl;
        std::cout << "!= ? - " << (vec != vec1) << std::endl;
        std::cout << ">  ? - " << (vec > vec1) << std::endl;
        std::cout << ">= ? - " << (vec >= vec1) << std::endl;
        std::cout << "<  ? - " << (vec < vec1) << std::endl;
        std::cout << "<= ? - " << (vec <= vec1) << std::endl;
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::vector<int> vec;
        for (int i=0; i<5; ++i) vec.push_back(i);
        ft::vector<int> vec1 = vec;
        std::cout << "== ? - " << (vec == vec1) << std::endl;
        std::cout << "!= ? - " << (vec != vec1) << std::endl;
        std::cout << ">  ? - " << (vec > vec1) << std::endl;
        std::cout << ">= ? - " << (vec >= vec1) << std::endl;
        std::cout << "<  ? - " << (vec < vec1) << std::endl;
        std::cout << "<= ? - " << (vec <= vec1) << std::endl;
        std::cout << "\033[0m";
    }
}
