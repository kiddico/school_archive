#include <iostream>
#include "string.hpp"
#include <fstream>
#include <cassert>

int main(){
	std::ifstream file;
	file.open("data2-1.txt");
	String one,two,three;
	file>>one>>two>>three;
	
	assert("Reporting"==one);
	assert("sdfsdfsdF"!=two);
	assert("Computer"==two);
	assert("Related"==three);
	std::cout<<"File stream test passed"<<std::endl;
	std::cout<<one<<std::endl;
	std::cout<<two<<std::endl;
	std::cout<<"if you can read those outputs then ostream test passed"<<std::endl;
}
