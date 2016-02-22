/*
    main.cpp

    Shows use of string class.

    Michael J. Decker
    mdecker6@kent.edu
*/

#include "string.h"

#include <iostream>
#include <cassert>

int main(int argc, char * argv[]) {

  {

    String s1;
    
    assert(s1 == "");

  }

  {

    String s1('a');
    
    assert(s1 == 'a');

  }

  {

    String s1("abc");
    
    assert(s1 == "abc");

  }

  {

    String s1("abc");
    String s2("defg");
    String s3 = s1 + s2;

    assert(s3 == "abcdefg");

  }

  {

    String s1("abcdefg");
    String s2 = s1.substr(2, 6);
	assert(s2 == "cdefg");

  }

  {

    String s1("abc");
    String s2("defg");
    s1 += s2;

    assert(s1 == "abcdefg");

  }
std::cout<<"things work!"<<std::endl;
  return 0;
}
