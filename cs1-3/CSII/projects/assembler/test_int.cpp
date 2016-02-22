#include <iostream>
#include "stack.hpp"
#include <cassert>

int main(){
	Stack<int> lolz;
	for(int i=0;i<10;i++)
		lolz.push(i);
	for(int i=9;i>-1;--i)
		assert(lolz.pop()==i);
	std::cout<<"stack works with int"<<std::endl;
}
