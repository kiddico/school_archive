#include <iostream>
#include "string.hpp"
#include "stack.hpp"
#include <cassert>

int main(){
	String one("world");
	String two("hello");
	Stack<String> lolzz;

	lolzz.push(one);
	lolzz.push(two);
	
	String temp;
	temp=lolzz.pop();
	std::cout<<temp<<std::endl;
	assert(temp=="hello");
	temp=lolzz.pop();
	std::cout<<temp<<std::endl;
	assert(temp=="world");
	std::cout<<"String test passed"<<std::endl;
}
