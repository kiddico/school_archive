#include <iostream>
#include "LabStack.hpp"
#include "string.hpp"
int main(){
	Stack<String> s1;
	String w("qwerty");
	String x("trololol");
	String h("hahaha");
	s1.push(w);
	s1.push(x);
	s1.push(h);
	
	std::cout<<s1.pop()<<std::endl;
	std::cout<<s1.pop()<<std::endl;
	std::cout<<s1.pop()<<std::endl;
}
