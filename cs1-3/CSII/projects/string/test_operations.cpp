#include <iostream>
#include "string.hpp"
#include "cassert"

int main(){
	
	//substr
	{
		String one("pudding");
		String two("ddi");
		//std::cout<<one.substr(2,3)<<std::endl;
		assert(one.substr(2,4)==two);
	}
	std::cout<<"substr test passed"<<std::endl;
	//findchar
	{
		String one("pudding");
		assert(one.findchar('i')==4);
	}
	std::cout<<"Find char test passed"<<std::endl;
	//findstr
	{
		String one("pudding");
		assert(one.findstr("ddi")==2);
	}	
	std::cout<<"Find string test passed"<<std::endl;

}
