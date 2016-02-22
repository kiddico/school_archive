// bigint Test Program
//
// Tests:  times_10, uses ==
//

#include "bigint.hpp"

#include <cassert>

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi.timesDigit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * single digit" << std::endl;
}
