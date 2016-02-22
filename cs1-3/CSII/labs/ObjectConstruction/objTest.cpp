#include "objectconstruction.hpp"
#include <iostream>
int main(){
	std::cout<<std::endl<<"Object one"<<std::endl;
	{
		String one;	
	}
	std::cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////////"<<std::endl;
	std::cout<<"Object two"<<std::endl;
	{
		String two;
	}
	
	{
		std::cout<<"Object 3 and 4"<<std::endl;
		String one,two;
		one=two;
		std::cout<<std::endl;
	}
}
