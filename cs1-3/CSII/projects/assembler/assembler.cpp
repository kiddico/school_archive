#include <iostream>
#include "stack.hpp"
#include "string.hpp"
#include <fstream>
#include <cassert>

String postfix(std::fstream& input,String& infix){
    //I passed infix as a ref because it was the only way to have an infix expression to output later
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
    
	//sets tofile to true if there is a 2nd parameter
	//it made things a little bit easier later
    if(argc>2){
        tofile=true;
        output.open(argv[2]);
    }
	//primary loop, ends when the entire file has been used
    while(!input.eof()){
		poststr=postfix(input,infix);
    	int blank=0,prevblank;
		String t; 
	    Stack<String> assem;
		int tmpmem=1;
		//outputs infix and postfix
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
/////////////////////////////////////////////////////////////////////////////////
//assembler loop
//breaks when nextblamk returns -1
//-1 is only returned when no more spaces were found
/////////////////////////////////////////////////////////////////////////////////		
		while(blank!=-1){
			///////////////////////////////////////////////
			//get next chunk of expression
			//special case for first token
			if(blank==0){
				blank=poststr.nextblank(0);
				t=poststr.substr(0,blank-1);
			}
			else{
				//I heard you like functions
				//so I functioned your function for hte main function
				//function(function(function)));
				t=poststr.substr(blank+1,poststr.nextblank(blank+1)-1);//holy crap haha
				prevblank=blank;
                blank=poststr.nextblank(blank+1);
			}
			///////////////////////////////////////////////
			//does stuff to operations
			if(t=='*' || t=='/' || t=='+' || t=='-'){
				//temp holding of top 2 of stack
				String first(assem.pop());
				String second(assem.pop());
				    //outputs LDR line
                    if(tofile)
					   output<<"   "<<"LDR"<<"   "<<second<<std::endl;
                    else{
                        std::cout<<"   "<<"LDR"<<"   "<<second<<std::endl;
                    }
					///////////////////////////
					//changes the token to the op string
					//then outputs it accordingly
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
					/////////////////////////////
		
					//Creates TMPn
					String tmpstr="TMP"+String(char('0'+tmpmem));
                    if(tofile)
					   output<<"   "<<"STR"<<"   "<<tmpstr<<std::endl;
                    else{
                        std::cout<<"   "<<"STR"<<"   "<<tmpstr<<std::endl;
                    }
					//incrememnts TMPn
					tmpmem++;
					//puts it back on stack for later
					assem.push(tmpstr);
			}
			else{
					assem.push(t);
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//because the other loop breaks before the final operation can be done, you basically have to do it all over again
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        t=poststr.substr(prevblank+1,poststr.length()-1);
				//somewhere along the way the stack picks up another piece
				//so I just drop it here
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
		//adds an endline to make things look pretty
		if(tofile)
			output<<std::endl;
		else	
			std::cout<<std::endl;				
    }
}

