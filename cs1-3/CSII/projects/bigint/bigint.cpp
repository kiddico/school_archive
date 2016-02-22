#include <iostream>
#include "bigint.hpp"

bigint::bigint(){
	for(int i=0;i<SIZE;i++)
		arr[i]=0;
	arr[0]=0;
	digits=1;
}

bigint::bigint(int input){
	//first set everything to zero
	for(int i=SIZE-1;i>-1;--i){
		arr[i]=0;
	}
	int mod=10;
	int counter=0;
	int postmod=0;
	if(input==0){
	arr[0]=0;
	digits=1;
	}
	else{
	while(input!=0){
		postmod=input%mod;
		arr[counter]=postmod;
		input=input-postmod;
		input=input/10;
		counter++;
	}
	digits=counter;	
	}	
}

void bigint::output(std::ostream& out){
	//int counter=digits;
	for(int i=digits-1;i>-1;--i){
	out<<arr[i];
	}
	out<<std::endl;
}

bigint::bigint(const char *input){
	//first part is to determine the number of digits
	digits=0;
	while(input[digits]!=0){
		digits++;
	}
	for(int i=SIZE-1;i>-1;--i){arr[i]=0;}
	//this is the difference between the character zero and the integer zero
	//aka how much higher ascii values are than their integer brethren
	int diff='0';
	//this counts where in arr[] the digit should be placed.
	int arrcounter =0;
	int counter =digits-1;
	while(input[arrcounter]!=0){
		arr[arrcounter]=input[counter]-diff;
		++arrcounter;
		--counter;
	}
}

int bigint::getval(int input){
	return arr[input];
}

bool bigint::compare(bigint input){
	/*if(digits!=input.digits)
		return false;
	if(this->digits==1){	
	std::cout<<"heyo!"<<std::endl;
		if(arr[0]==input.arr[0])
			return true;
	}
	for(int i=0;i<digits;i++){
		if(arr[i]!=input.arr[i]){
			return false;}}
	return true;*/
	int counter=0;
	//counts the amount of digits that they share
	if(digits==input.digits){
		for(int i=0;i<digits;++i){
			if(arr[i]==input.arr[i]){
				counter++;
			}
		}
	}
	//if they share the amount of digits they have, then they're the same
	if(counter==digits){
		return true;
	}
	else
		return false;
}
bool bigint::operator ==(bigint & rhs){
	if(this->compare(rhs))
		return true;
	else
		return false;
}
bool bigint::operator == (int rhs){
	bigint input(rhs);
	if(compare(input))
		return true;
	else
		return false;	

}

bool bigint::operator ==(char *rhs){
	bigint input(rhs);
	if(this->compare(input))
		return true;
	else
		return false;
}

int bigint::operator [](int input){
	return arr[input];
}



///////////I retired this one... but just in case I'm going to keep it....
/*
bigint bigint::operator + (bigint input){
	bigint temp;
	std::cout<<"input digits "<<input.digits<<std::endl;
	for(int i=0;i<input.digits;++i){
		std::cout<<"I've gone through here "<<i+1<<" times"<<std::endl;
		temp.arr[i]+=arr[i]+input.arr[i];
		if(temp.arr[i]>9){
			++temp.arr[i+1];
			temp.arr[i]=temp.arr[i]-10;
		}
	}
	int notzero;
	for(int i=SIZE-1;i>-1;--i){
		std::cout<<temp.arr[i];
		if(temp.arr[i]>0)
			notzero=i;
	}
	std::cout<<"the first nonzero is "<<notzero<<std::endl;	
	return temp;	
}*/

bigint bigint::operator + (bigint input){
	bigint smaller, larger;
	//this part just organizes the code so adding actually works... otherwise I tend to break things.
	if(input.digits>digits){
		for(int i=0;i<input.digits;i++){
			larger.arr[i]=input.arr[i];
			larger.digits=input.digits;
		}
		for(int i=0;i<digits;i++){
			smaller.arr[i]=arr[i];
			smaller.digits=digits;
		}
	}
	if(digits>input.digits){
		for(int i=0;i<digits;i++){
			larger.arr[i]=arr[i];
			larger.digits=digits;
		}	
		for(int i=0;i<digits;i++){
			smaller.arr[i]=input.arr[i];
			smaller.digits=input.digits;
		}
	}
	//in case they have the same length, in which case it doesn't really matter which is labeled "larger"
	if(input.digits==digits){
		for(int i=0;i<digits;++i){
			larger.arr[i]=arr[i];	
			larger.digits=digits;
			smaller.arr[i]=input.arr[i];
			smaller.digits=input.digits;}}
	for(int i=0;i<larger.digits;++i){
		larger.arr[i]=larger.arr[i]+smaller.arr[i];
		if(larger.arr[i]>9){
			//this detects if the digits needs to be carried up to the next
			larger.arr[i]=larger.arr[i]-10;
			larger.arr[i+1]=larger.arr[i+1]+1;
			//if its the last digit and there is going to be a carry
			//the digits tracker is increased
			if(i==larger.digits-1){
				larger.digits++;
			}
		}
	}
	return larger;
}

void bigint::shiftleft(int input){
	bigint temp;
	int digcount=digits;
	int looptracker=0;
	for(int i=SIZE-1;i>-1;--i){
		temp.arr[i]=0;
	}	
	while(looptracker<input){
		temp.arr[looptracker]=0;
		++looptracker;
		digcount++;
	}
	while(looptracker<input+digits){
		temp.arr[looptracker]=arr[looptracker-input];
		++looptracker;
	}
//this->digits=this->digits+input;
*this=temp;
this->digits=digcount;
}


bigint bigint::operator *(bigint input){
	bigint temp;
	bigint product;
	for(int i=0;i<input.digits;++i){
		temp=*this;
		temp.timesDigit(input.arr[i]);
		temp.shiftleft(i);
		product=product+temp;
	}	

return product;
}


std::ostream& operator<<(std::ostream& stream,bigint& out){	
	//int counter=digits;
	int counter=0;
	for(int i=out.digits-1;i>-1;--i){
	stream<<out.arr[i];
	counter++;
	if(counter==60){
	stream<<std::endl;
	counter=0;
	}}
	return stream;
}

std::istream& operator>>(std::istream& stream,bigint& in){
	int index=0;
	int diff='0';
	//so when I did it the first time it was all backwards... I'm just gonna spin it around
	bigint temp;
	while(stream.peek()!=';'){
		if(stream.peek()=='\n'||stream.peek()==' ')
			stream.ignore();
		else{
			temp.arr[index]=stream.get()-diff;
			++index;
		}	
}
stream.ignore();
temp.digits=index;
int counter=index;
for(int i=0;i<index;++i){
	in.arr[i]=temp.arr[counter-1];
	--counter;
}
in.digits=index;
return stream;
}
//this isn't finished yet.
void bigint::timesDigit(int input){
/*	int carry=0;
	int tocarry
	int leftover=0;
	bigint temp;
	for (int i=0;i<digits;++i){i
		temp.arr[i]=arr[i]*input;
		if(temp.arr[i]>9){
			leftover=temp.arr[i]%10;
			carry=temp.arr[i]/10;
			temp.arr[i]=leftover;
			if(i==digits-1)
				++digits;
		}
	}*/
	//so I thought: hey, wouldn't it be great if I could just reuse add? so I tried it, and it works. yaaaaayyyyy.
	bigint temp=*this;
	if(input!=0){
	for(int i=0;i<input-1;++i){
		temp=temp+*this;
	}
	*this=temp;}
	if(input==0){
	bigint temp2;
	*this=temp2;
	}
}
