#include <iostream>
#include "stack.hpp"
#include "string.hpp"
#include <fstream>
#include <cassert>

String postfix(std::fstream& input){
    String rhs,op,lhs,token;

    Stack<String> s;
    
        while(input.peek()!=';'){
            token=getWord(input);
            if(token==')'){
                rhs=s.pop();
                op=s.pop();
                lhs=s.pop();
				s.push(lhs+" "+rhs+" "+op);
            }
            else{
                if(token!='(')
                    s.push(token);
            }
        }
        String garbage=getWord(input);
        String returnstr;
        while(!s.isEmpty()){
                returnstr=returnstr+s.pop();
            }
        return returnstr;
}

int main(int argc, char** argv){
    std::fstream input;
    input.open(argv[1]);
    std::ofstream output;
    bool tofile=false;
    String outstr,test;
    
    if(argc>2){
        tofile=true;
        output.open(argv[2]);
    }

    while(!input.eof()){
        outstr=postfix(input);
        test=test+outstr;
        
        if(tofile){
                output<<outstr<<std::endl;
        }
        else{
                std::cout<<outstr<<std::endl;
        }
        
    }
/*
String correct("data3-1.txt");
//tests for correctness with data3-1.txt    
		if(correct==argv[1]){
        	assert(test=="AXBC*+AXBCY*+DE-/AB+CE+*AXBXCYAY+BY+CX***HABC+D*+F*G*E**J+");
			std::cout<<"Test passed!"<<std::endl;
		}
		else{
        	std::cout<<"test only works for data3-1.txt"<<std::endl;
    		std::cout<<"You can still check your output file though"<<std::endl;
		}
*/
}


