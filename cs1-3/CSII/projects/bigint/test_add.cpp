// bigint Test Program
//
// Tests:  int constructor, uses ==
//

#include "bigint.hpp"

#include <cassert>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }


    
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
}

