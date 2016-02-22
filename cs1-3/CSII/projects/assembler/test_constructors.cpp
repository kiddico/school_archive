#include <iostream>
#include "string.hpp"
#include "stack.hpp"
#include <cassert>

int main(){
	Stack<int> lol;
	assert(lol.isEmpty());
	std::cout<<"Constructor works, and isEmpty returns correctly"<<std::endl;
	
	lol.push(1);
	lol.push(2);
	
	assert(lol.pop()==2);
	assert(lol.pop()==1);
	std::cout<<"Push and pop work with correct order"<<std::endl;
}
