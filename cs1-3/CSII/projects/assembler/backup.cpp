#include <iostream>
#include "stack.hpp"
#include "string.hpp"
#include <fstream>
#include <cassert>

String postfix(std::fstream& input,String& infix){
    String rhs,op,lhs,token;

    Stack<String> s;
    String empty;
	//empties infix
	infix=empty;
        while(input.peek()!=';'){
            token=getWord(input);
            if(token==')'){
                rhs=s.pop();
                op=s.pop();
                lhs=s.pop();
				s.push(lhs+" "+rhs+" "+op);
				infix=infix+token;
            }
            else{
                if(token!='(')
                    s.push(token);
				infix=infix+token;
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
    String poststr,test,infix;
    
    if(argc>2){
        tofile=true;
        output.open(argv[2]);
    }
    while(!input.eof()){
		poststr=postfix(input,infix);
    	int blank=0,prevblank;
		String t; 
	    Stack<String> assem;
		int tmpmem=1;
		if(tofile){
			output<<"Infix Expression: "<<infix<<std::endl;
			output<<"Postfix Expression: "<<poststr<<std::endl;
			output<<std::endl;
		}
		else{
			std::cout<<"Infix Expression: "<<infix<<std::endl;
			std::cout<<"Postfix Expression: "<<poststr<<std::endl;
			std::cout<<std::endl;
		}
//assembler while
/////////////////////////////////////////////////////////////////////////////////		
		while(blank!=-1){
			//get next chunk of expression
			if(blank==0){
				blank=poststr.nextblank(0);
				t=poststr.substr(0,blank-1);
			}
			else{
				t=poststr.substr(blank+1,poststr.nextblank(blank+1)-1);//holy crap haha
				prevblank=blank;
                blank=poststr.nextblank(blank+1);
			}
			if(t=='*' || t=='/' || t=='+' || t=='-'){
				String first(assem.pop());
				String second(assem.pop());
				    
                    if(tofile)
					   output<<"   "<<"LDR"<<"   "<<second<<std::endl;
                    else{
                        std::cout<<"   "<<"LDR"<<"   "<<second<<std::endl;
                    }
					
					if(t=='-'){
						String op("SUB");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
                        else{
                            std::cout<<"   "<<op<<"   "<<first<<std::endl;
                        }
					}	
					if(t=='+'){
						String op("ADD");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
                        else{
                            std::cout<<"   "<<op<<"   "<<first<<std::endl;
                        }
					}	
					if(t=='/'){
						String op("DIV");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
					}	
					if(t=='*'){
						String op("MUL");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
                        else{
                            std::cout<<"   "<<op<<"   "<<first<<std::endl;
                        }
					}	
					
					String tmpstr="TMP"+String(char('0'+tmpmem));
                    if(tofile)
					   output<<"   "<<"STR"<<"   "<<tmpstr<<std::endl;
                    else{
                        std::cout<<"   "<<"STR"<<"   "<<tmpstr<<std::endl;
                    }
					tmpmem++;
					assem.push(tmpstr);
					
			}
			else{
					assem.push(t);
			}
		}
        t=poststr.substr(prevblank+1,poststr.length()-1);
				//get rid of something dumb	
				assem.pop();
                String first(assem.pop());
				String second(assem.pop());
                if(tofile)
					   output<<"   "<<"LDR"<<"   "<<second<<std::endl;
                    else{
                        std::cout<<"   "<<"LDR"<<"   "<<second<<std::endl;
                    }
					
					if(t=='-'){
						String op("SUB");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
                        else{
                            std::cout<<"   "<<op<<"   "<<first<<std::endl;
                        }
					}	
					if(t=='+'){
						String op("ADD");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
                        else{
                            std::cout<<"   "<<op<<"   "<<first<<std::endl;
                        }
					}	
					if(t=='/'){
						String op("DIV");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
					}	
					if(t=='*'){
						String op("MUL");
                        if(tofile)
						  output<<"   "<<op<<"   "<<first<<std::endl;
                        else{
                            std::cout<<"   "<<op<<"   "<<first<<std::endl;
                        }
					}	
					
					String tmpstr="TMP"+String(char('0'+tmpmem));
                    if(tofile)
					   output<<"   "<<"STR"<<"   "<<tmpstr<<std::endl;
                    else{
                        std::cout<<"   "<<"STR"<<"   "<<tmpstr<<std::endl;
                    }
					tmpmem++;
					assem.push(tmpstr);
		if(tofile)
			output<<std::endl;
		else	
			std::cout<<std::endl;				
    }
}

