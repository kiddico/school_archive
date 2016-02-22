#include <iostream>
#include "string.hpp"
#include <fstream>

String::String(){
	Capacity=DEFAULT_STRING_CAPACITY;
	s=new char[Capacity];
	s[0]=0;
}

String::String(char input){
	Capacity=DEFAULT_STRING_CAPACITY;
	s=new char[Capacity];
	s[0]=input;
	s[1]=0;
}
String::~String(){
	delete []s;
}

String::String(const char* input){
	Capacity=DEFAULT_STRING_CAPACITY;
	s=new char[Capacity];
	int index=0;
	while(input[index]!=0){
		s[index]=input[index];
		index++;
	}
	s[index]=0;
}

String::String(int cap,const char* input){
	s=new char[cap];
	Capacity=cap;
	int index=0;
	while(input[index]!=0){
		s[index]=input[index];
		index++;
	}
	s[index]=0;
}
String::String(int cap){
	s=new char[cap];
	s[0]=0;
	Capacity=cap;
}

String::String(const String& input){
	s=new char[input.Capacity];
	Capacity=input.Capacity;
	for(int i=0;i<input.Capacity;++i){
		s[i]=input.s[i];
	}
}

int String::capacity()const{
	return Capacity;
}
int String::length()const{
	int index =0;
	while(s[index]!=0)
		index++;
	return index;
}
//You see I'm really not sure about this
//I'm no sure if capacity should include the zero at the end of the string or not
//if it does then... well ok. if not then I just need to go one more iteration 
//in the for loop that is
//it is nearly impossible to read this blue font in a putty window.... is there no way to change the colos?
void String::resetCapacity(int newsize){
	String temp=*this;
	Capacity=newsize;
	delete []s;
	s=new char[newsize];
	int index=0;
	for(int i=0;i<newsize;i++){
		s[i]=temp.s[i];
		index=i;
	}
	s[index]=0;
}

String String::operator +(const String& input)const{
	String temp;
	temp=*this;
	int end_of_string=0;
	while(temp.s[end_of_string]!=0)
		end_of_string++;
	int index=end_of_string;
	int orig=0;
	while(input.s[orig]!=0){
		temp.s[index]=input.s[orig];
		index++;
		orig++;
	}
	temp.s[index]=0;
	//This was just for testing. Remove as you please
	//three days later, and it's still there. Like a terrible memorial
	//a testament to my level of laziness.
	/*
	int tst=0;
	while(temp.s[tst])
	{
		std::cout<<temp.s[tst];
		tst++;
	}*/
	return temp;
}

void String::swap(String& rhs){
	char *tmp=rhs.s;
	rhs.s=this->s;
	this->s=tmp;
	int temp=rhs.Capacity;
	rhs.Capacity=this->Capacity;
	this->Capacity=temp;
}

String& String::operator=(String input){
	swap(input);
	return *this;
}

String operator+ (const char *lhs,const String& rhs){
	String temp(lhs);
	return temp+rhs;
}
String operator+ (char lhs,const String& rhs){
	String temp(lhs);
	return temp+rhs;
}

bool String::operator==(const String& input)const{
	int counter=0;
	if(length()==input.length()){
		if(length()==0){return true;}
		for(int i=0;i<length();++i){
			if(s[i]==input.s[i])
				counter++;
		}
	}
	if((counter==length())&&(length()!=0))
		return true;
	else
		return false;
}

bool String::operator<(const String& input)const{
	if(*this==input)
		return false;
	//keeps track of current position
	int index=0;
	//compares each digit
	//if one is longer than the other it ends.
	while((s[index]!=0)&&(input.s[index]!=0)){
		if(input.s[index]>s[index]){
			return true;
		}
		if(input.s[index]<s[index])
			return false;
		index++;
	}
	//if it has gotten to this stage then one is longer than the other
	//so which ever one was the one that didn't return zero is greater
	if(input.s[index]==0){
		return false;
	}
	else return true;	
	//this may not have been the best way to go about doing this...
	// but I like it :D
	// ...also it works so I don't care...
}

bool operator==(const char* lhs,const String& rhs){
	String temp(lhs);
	if(temp==rhs){return true;}
	else return false;
}
bool operator==(char lhs,const String& rhs){
	String temp(lhs);
	if(temp==rhs)
		return true;
	else return false;
}
bool operator!=(const String& lhs,const String& rhs){
	if((lhs==rhs)==false){
		return true;
	}
	else return false;
}

bool operator>(const String& lhs,const String& rhs){
	if(lhs==rhs)
		return false;
	if((lhs<rhs)==false)
		return true;
	else return false;

}
bool operator>=(const String& lhs,const String& rhs){
	if(lhs==rhs)
		return true;
	if((lhs<rhs)==false)
		return true;
	else return false;
}
bool operator<=(const String& lhs,const String& rhs){
	if(lhs==rhs)
		return true;
	if(lhs<rhs)
		return true;
	else return false;
}
bool operator< (const char *lhs,const String& rhs){
	String temp(lhs);
	if(temp<rhs)
		return true;
	else return false;

}
bool operator<(const char lhs, const String& rhs){
	String temp(lhs);
	if(temp<rhs)
		return true;
	else return false;

}

//stream related things... I hate streams...
//like... a lot
//oh well. I'll get this overwith then

std::ostream& operator<<(std::ostream& stream,const String& out){
	int index=0;
	while(out.s[index]!=0){
		stream<<out.s[index];
		++index;
	}
	return stream;
}

std::istream& operator>>(std::istream& stream,String& in){
	int index=0;
	while((stream.peek()!=' ')&&(stream.peek()!=-1)){
		//if(stream.peek()=='\n'){
		//	while(stream.peek()=='\n')
		//		stream.ignore();
		//}
		in.s[index]=stream.get();
		++index;
	}
	in.s[index]=0;
	if(stream.peek()!=-1)
		stream.ignore();
	return stream;
}


/* old things... pretty much the same thing
//but you know... different.
int String::length()const{
	int length=0;
	while(str[length]!=0){
		length++;
	}
	return length;
}
//best method ever
int String::capacity()const{
	return DEFAULT_STRING_CAPACITY;
}

String String::substr(int start,int length){
	String temp;
	int index=0;
	for(int i=start;i<length+2;i++){
		temp.s[index]=s[i];
		index++;
	}
	temp.s[index]=0;
	return temp;
}
*/

String String::substr(int start,int end){
	String temp;
	if(start==end){
		temp.s[0]=s[start];
		temp.s[1]=0;
		return temp;
	}	
	if(start<0){
		start=0;
	}
	int index=0;
	for(int i=start;i<end+1;i++){
		temp.s[index]=s[i];
		index++;
	}
	
	temp.s[index]=0;
	return temp;
}
int String::findchar(char input){
	for(int i=0;i<length();++i){
		if(s[i]==input)
			return i;
	}
	return -1;//not sure what to do with this
}


//findstr straight up doesn't work
//don't use it haha
//well it does
//in the string "qwerty"
//it will return 1 if you pass "wer"
//but also if you pass werr
int String::findstr(String input){
	int counter=0;
	for(int i=0; i<length();++i){
		for(int u=0;u<input.length();++u){
			if(s[u+i]==input.s[u]){
				++counter;
				if(counter==input.length())
					return i;
			}
		}
	}
	//return capacity();
	return -1;
}

char String::operator[](int in)const{
	return s[in];
}
char& String::operator[](int in){
	return s[in];
}

int String::nextblank(int start){
	int pos=start;
	while(s[pos]!=0){
		if(s[pos]==' ')
			return pos;
		++pos;
	}	
	return -1;
}

int String::nextchar(int start){
	int pos=start;
	while(s[pos]!=0){
		if(s[pos]!=' ')
			return pos;
		++pos;
	}
	return pos;
}

void String::justify(int width){
	int index=0;
	while(length()<width){
		index=nextblank(index);
			if(index==length())
				index=nextblank(0);
			insert(' ',index);
			index=nextchar(index);
	}
}
//this may be the worst way to go about doing this.
//but it works... so it has that going for it.
//It pushes everything down
//then it puts the character in the requested spot
void String::insert(char input,int spot){
	char temp[length()-(spot-1)];
	int arrlen=length()-(spot-1);
	int index=spot;
	for(int i=0;i<arrlen;++i){
		temp[i]=s[index];
		++index;
	}
	//This is when we put the character in
	s[spot]=input;
	index=spot+1;
	for(int i=0;i<arrlen;++i){
		s[index]=temp[i];
		index++;
	}
	s[index]=0;
}
void String::insertStr(String in,int spot){
	for(int i=0;i<in.length();++i){
		insert(in.s[i],spot);
	}
}
//honestly  have no idea what I'm gonna do with this
//or how to go about doing it -_-
String getWord(std::istream& stream){
	String word;
	stream>>word;
	return word;
}

