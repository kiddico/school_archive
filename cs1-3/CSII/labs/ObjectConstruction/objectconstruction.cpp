#include "objectconstruction.hpp"
#include <iostream>
String::String(){
	std::cout<<"Object Created"<<std::endl<<std::endl;
}

String::String(const String& copyof){
	std::cout<<"Object Copied"<<std::endl<<std::endl;
}

String::~String(){
	std::cout<<"Destructor"<<std::endl<<std::endl;
}

String String::operator =(String){
	std::cout<<"Comparing"<<std::endl<<std::endl;
	return *this;
}

