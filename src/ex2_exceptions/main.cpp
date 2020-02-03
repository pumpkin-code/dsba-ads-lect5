/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       23.01.2020
 *
 *  Bitwise operations
 */

#include <iostream>
#include <vector>
#include <cassert>          // needed for assert macros

using std::cout;
using std::string;


void sample1()
{
    // causes an unhandled exception
    int a = 5 / 0;
}

// Deals with a vector. Throws an std::out_of_range exception
// when an index is wrong
void sample2()
{
    std::vector<int> v = {1, 2, 3};
    int a = v.at(0);    // ok
    a = v.at(3);        // std::out_of_range exception
    a = v[3];           // undefined behavior, not an exception!
}


void sample3(int a)
{
    if(a != 42)
        throw std::logic_error("Not an answer!");

    std::cout << "All right!";
}

int main()
{
    cout << "Hello world of exceptions!\n\n";

    try {
        sample2();
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Someone tries to go beyond the array: "
                  << e.what();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Here we are handling any of "
                     "standard exceptions";
    }
    catch(...)
    {
        std::cerr << "I don't know what to do with this exception :(";
        throw;
    }
//    catch(...)
//    {
//        std::cerr << "We do not know the exact type of the exception. "
//                     "But we try our best...";
//    }

    std::cout << "Still working ok";

    cout << "\n\n";
    return 0;
}
