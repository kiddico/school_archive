#include <iostream>

int fib(int input){
	if(input==0)
		return 0;
	if(input==1)
		return 1;
	else{
		return fib(input-1)+fib(input-2);
	}
}
int fibtail(int input,int left,int right){
	if(input==0){
		return left;
	}
	else if(input==1){
		return right;
	}
	return fibtail(input-1,right,left+right);
}
int main(){
	for(int i=0;i<7;++i){
		std::cout<<fib(i);
	}
	std::cout<<std::endl;
	for(int i=0;i<7;++i){
		std::cout<<fibtail(i,0,1);
	}
	std::cout<<std::endl;
}
