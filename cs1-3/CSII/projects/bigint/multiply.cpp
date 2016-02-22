#include <iostream>
#include "bigint.hpp"
#include <fstream>
#include <cassert>


int main(){
std::fstream file;
        file.open("data1-2.txt");
        if(!file.is_open()){
                std::cout<<"File Stream did not open correctly"<<std::endl;
        }
	
	bigint b1,b2,b3,b4,b5,b6,result1,result2,result3;
	file>>b1>>b2>>b3>>b4>>b5>>b6;
	
	std::cout<<"First "<<b1<<std::endl<<std::endl<<"Second "<<b2<<std::endl<<std::endl;
	result1=b1*b2;	
	std::cout<<"Result of one and two "<<result1<<std::endl;

	std::cout<<"First "<<b3<<std::endl<<std::endl<<"Second "<<b4<<std::endl<<std::endl;
	result2=b3*b4;	
	std::cout<<"Result of three and four "<<result2<<std::endl;

}
