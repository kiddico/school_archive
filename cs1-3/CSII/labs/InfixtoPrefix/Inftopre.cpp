#include <iostream>
#include "LabStack.hpp"
#include "string.hpp"
#include <fstream>
int main(){
	std::fstream input;
	input.open("inf.txt");
	String one;
	
	
	String rhs,op,lhs,token;
	
	Stack<String> s;
	while(!input.eof()){
		while(input.peek()!=';'){	
			token=getWord(input);
			if(token==')'){
				rhs=s.pop();
				op=s.pop();
				lhs=s.pop();
				s.push(op+lhs+rhs);
			}
			else{
				if(token!='(')
					s.push(token);
			}
		}
		String garbage=getWord(input);
		//outputs the results
		while(!s.isEmpty()){
			std::cout<<s.pop()<<std::endl;
		}
	}
}
