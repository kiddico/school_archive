#include <iostream>
#include "stack.hpp"
#include "string.hpp"
#include <fstream>
int main(int argc, char** argv){
	std::fstream input;
	input.open(argv[1]);
	std::ofstream output;
	String one;
	bool tofile=false;
	if(argc>2){
		tofile=true;
		output.open(argv[2]);
	}	
	
	String rhs,op,lhs,token;
	
	Stack<String> s;
	while(!input.eof()){
		while(input.peek()!=';'){	
			token=getWord(input);
			if(token==')'){
				rhs=s.pop();
				op=s.pop();
				lhs=s.pop();
				s.push(lhs+rhs+op);
			}
			else{
				if(token!='(')
					s.push(token);
			}
		}
		String garbage=getWord(input);
		//outputs the results
		if(tofile){
			while(!s.isEmpty()){
				output<<s.pop()<<std::endl;
			}
		}
		else{
			while(!s.isEmpty()){
				std::cout<<s.pop()<<std::endl;
			}
		}
	}
}
