#include <iostream>
#include <fstream>
#include "bigint.hpp"
#include "cassert"
int main(){
	std::fstream file;
	file.open("data1-1.txt");
	if(!file.is_open()){
		std::cout<<"File Stream did not open correctly"<<std::endl;
	}
	bigint bi1, bi2, bi3, bi4, bi5, bi6, result1, result2, result3;
	file>>bi1>>bi2;
		std::cout<<"First Number "<<bi1<<std::endl<<"Second Number "<<bi2<<std::endl<<std::endl;
	result1=bi1+bi2;
		std::cout<<"First plus the second number "<<result1<<std::endl<<std::endl;

	file>>bi3>>bi4;
	result2=bi3+bi4;
		std::cout<<"Third Number "<<bi3<<std::endl<<"Fourth Number "<<bi4<<std::endl<<std::endl;
	std::cout<<"Third plus Fourth "<<result2<<std::endl<<std::endl;


	file>>bi5>>bi6;
	result3=bi5+bi6;	
		std::cout<<"Fifth Number "<<bi5<<std::endl<<"Sixth Number "<<bi6<<std::endl<<std::endl;
	std::cout<<"add.cpp works!"<<std::endl;
}
