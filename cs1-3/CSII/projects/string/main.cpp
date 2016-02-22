#include <iostream>
#include "string.hpp"
#include <fstream>
int main(){
	String one("AX B C * +");
	//std::cout<<one.nextblank(5)<<std::endl;
	std::cout<<one.substr(1,1)<<std::endl;
	std::cout<<one.substr(0,one.nextblank(0))<<std::endl;
}
