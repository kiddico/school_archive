#include <iostream>
#include "string.hpp"
#include <cassert>

int main(){
	{
		String one("abcdefghijkl");
		one.resetCapacity(50);
		assert(one=="abcdefghijkl");
		std::cout<<"Reset Capacity test one passed"<<std::endl;
	}

	{
		String one("qwerty");
		one.resetCapacity(3);
		assert(one=="qw");	
		std::cout<<"Reset Capacity test two passed"<<std::endl;
	}
}
