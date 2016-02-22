#include <iostream>
#include "string.hpp"
#include <cassert>

int main(){
	{
		//== test
		String one("hello");
		String two("hello");
		assert(one==two);
	}
	{
		String one("hello");
		assert("hello"==one);
	}
	{
		String one('a');
		assert('a'==one);
	}
	std::cout<<"== test passed"<<std::endl;

	{
		String one("hello");
		String two("hello");
		String three("asdasdasd");
		String four("jjjjj");
		assert(!(one!=two));
		assert(one!=three);
		assert(one!=four);
		assert(three!=four);
	}
	std::cout<<"!= test passed"<<std::endl;	
	//< and <= test
	{
		String one("hello");
		String two("hellp");
		assert(one<two);
	}
	
	{
		String one("hello");
		assert("helld"<one);
	}
	std::cout<<"less than tests passed"<<std::endl;
	{
		String one("hello");
		String two("hello");
		assert(one<=two);
	}
	{
		String one("hello");
		String two("zzzzzzz");
		assert(one<=two);
		assert(!(two<=one));
	}
	std::cout<<"less than or equals to tests passed"<<std::endl;
	//> and >= tests
	
	{
		String one("zzz");
		String two("hello");
		String three("aaa");
		assert(one>two);
		assert(!(two>one));
		assert(one>three);
		
	}
	std::cout<<"> test passed"<<std::endl;	
	{
		String one("hello");
		String two("hello");
		String three("zzz");
		assert(one>=two);
		assert(three>=one);
	}
	std::cout<<"<= test passed"<<std::endl;
}
