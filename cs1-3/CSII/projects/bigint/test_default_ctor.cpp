// bigint Test Program
//
// Tests:  default constructor, uses ==
//
//  Change "output" to what ever you call your method to print a bigint.

#include "bigint.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    // Setup

    // Test 
    bigint bi;

    // Verify
    assert(bi == 0);
    std::cout << "0 == ";
    bi.output(std::cout);
    std::cout << std::endl;

    std::cout << "Done testing default constructor." << std::endl;
}

