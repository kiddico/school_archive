#include <iostream>
#include "string.hpp"
#include <cassert>

int main(){
	{
		String one("hello");
		String two("hello");
		assert(one==two);
		
	}
	
	{	
		String one("hello");
		String two("hey there");
		assert(one!=two);
	}

	{	
		String one("hello");
		String two("he");
		String three("llo");
		String four;
		four=two+three;
		assert(one==four);
	}
	std::cout<<"Char array test passed"<<std::endl;
}
