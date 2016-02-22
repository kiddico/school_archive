#include <iostream>
#include "string.hpp"
#include "LabStack.hpp"

int main(int argc, char** argv){
	Stack<char*> s1;
	s1.push(argv[1]);
	s1.push(argv[2]);
	s1.push(argv[3]);
	
	std::cout<<s1.pop()<<std::endl;
	std::cout<<s1.pop()<<std::endl;
	std::cout<<s1.pop()<<std::endl;
}
