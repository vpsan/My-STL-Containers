#include <iostream>
#include <deque>
#include <vector>
#include <unistd.h>

#include <stack>
#include "Stack.hpp"

void stack_test_constructor();
void stack_test_empty();
void stack_test_size();
void stack_test_top();
void stack_test_push();
void stack_test_pop();
void stack_test_operators();

int main(void)
{
    stack_test_constructor();
    stack_test_empty();
    stack_test_size();
    stack_test_top();
    stack_test_push();
    stack_test_pop();
    stack_test_operators();

    // sleep(10);

    return 0;
}

void stack_test_constructor(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::deque<int> mydeque (3,100);          // deque with 3 elements
        std::vector<int> myvector (2,200);        // vector with 2 elements

        std::stack<int> first;                    // empty stack
        std::stack<int> second (first);         // stack initialized to copy of deque

        std::stack<int,std::vector<int> > third;  // empty stack using vector
        std::stack<int,std::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        std::deque<int> mydeque (3,100);          // deque with 3 elements
        std::vector<int> myvector (2,200);        // vector with 2 elements

        ft::stack<int> first;                    // empty stack
        ft::stack<int> second(first);         // stack initialized to copy of deque

        ft::stack<int,std::vector<int> > third;  // empty stack using vector
        ft::stack<int,std::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
        std::cout << "\033[0m";
    }
}

void stack_test_empty(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }

        std::cout << "total: " << sum << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }

        std::cout << "total: " << sum << '\n';
        std::cout << "\033[0m";
    }
}

void stack_test_size(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
        std::cout << "\033[0m";
    }
}

void stack_test_top(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
        std::cout << "\033[0m";
    }
}

void stack_test_push(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void stack_test_pop(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        std::cout << "\033[0m";
    }
}

void stack_test_operators(){
    std::cout << "===================================================================" << std::endl;
    {
        std::cout << "\033[33m";
        std::stack<int> mystack;
        for (int i=0; i<5; ++i) mystack.push(i);
        std::stack<int> mystac1 = mystack;
        std::cout << "== ? - " << (mystack == mystac1) << std::endl;
        std::cout << "!= ? - " << (mystack != mystac1) << std::endl;
        std::cout << ">  ? - " << (mystack > mystac1) << std::endl;
        std::cout << ">= ? - " << (mystack >= mystac1) << std::endl;
        std::cout << "<  ? - " << (mystack < mystac1) << std::endl;
        std::cout << "<= ? - " << (mystack <= mystac1) << std::endl;
        std::cout << "\033[0m";
    }
    {
        std::cout << "\033[34m";
        ft::stack<int> mystack;
        for (int i=0; i<5; ++i) mystack.push(i);
        ft::stack<int> mystac1 = mystack;
        std::cout << "== ? - " << (mystack == mystac1) << std::endl;
        std::cout << "!= ? - " << (mystack != mystac1) << std::endl;
        std::cout << ">  ? - " << (mystack > mystac1) << std::endl;
        std::cout << ">= ? - " << (mystack >= mystac1) << std::endl;
        std::cout << "<  ? - " << (mystack < mystac1) << std::endl;
        std::cout << "<= ? - " << (mystack <= mystac1) << std::endl;
        std::cout << "\033[0m";
    }
}