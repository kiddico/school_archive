#include <iostream>
#include "string.hpp"
#include <cassert>

int main(){
	{
		String one('a');
		String two('a');
		assert(one==two);
	}
	
	{
		String one('a');
		String two('b');
		assert(one!=two);
	}
	
	{
		
		String one("aa");
		String two('a');
		two=two+two;
		assert(one==two);
	}
	std::cout<<"Char ctor test passed"<<std::endl;
}
