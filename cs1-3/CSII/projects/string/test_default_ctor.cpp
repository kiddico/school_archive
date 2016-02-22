//Default constructor tester

#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
	{
		String one, two;
		assert(one==two);
	}
	std::cout<<"default constructor test passed"<<std::endl;	
}
