// bigint Test Program
//
// Tests:  subscript, uses ==
//

#include "bigint.hpp"
#include <cassert>

//===========================================================================
int main ()
{
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }
    
    //Add test cases as needed.

    std::cout << "Done testing subscript." << std::endl;
}

