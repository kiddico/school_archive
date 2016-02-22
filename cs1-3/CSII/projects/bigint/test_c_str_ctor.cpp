//  bigint Test Program
//
//  Tests:  C-string constructor, uses ==
//
//  Change "output" to what ever you call your method to print a bigint.


#include "bigint.hpp"

#include <cassert>

//===========================================================================
int main () {

    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        bigint bi("0");

        // Verify
        assert(bi == 0);        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        bigint bi("1");

        // Verify
        assert(bi == 1);
    }

    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        bigint bi("27");

        // Verify
        assert(bi == 27);
    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test 
        bigint bi("456789");

        // Verify
        assert(bi == 456789);
    }
    

    {
        //------------------------------------------------------
        // Test: Construct with value that greater than an int will hold
        // Setup fixture
        // Larger than max int so need to check manually.

        // Test 
        bigint bi("6234567890");
    
        // Verify
        assert(bi == "6234567890");
        std::cout << "6234567890 == ";
        bi.output(std::cout);
        std::cout << std::endl;
        
    }
    std::cout << "Done testing constructor bigint(char[])." << std::endl;

}

