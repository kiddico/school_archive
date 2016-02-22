//This Program Uses functions to sort numbers
//Nicholas Chirico
//2/22/2014 CSI Section 003

#include <iostream>

using namespace std;
void swapone(int& one,int& two){
	int tmp;
	tmp=one;
	one=two;
	two=tmp;
}

void swaptwo(int& one,int& three){
	int tmp;
	tmp=one;
	one=three;
	three=tmp;
}

void swapthree(int& two,int& three){
	int tmp;
	tmp=two;
	two=three;
	three=tmp;
}
int main(){
	cout<<"Enter three numbers"<<endl;
	int one,two,three;
	cin>>one>>two>>three;
	if(one>two)
		swapone(one,two);
	if(one>three)
		swaptwo(one,three);
	if(two>three)
		swapthree(two,three);

	cout<<"The numbers in order are:";
	cout<<one<<" "<<two<<" "<<three<<endl;
}