//This program takes an input then turns it into 4 figures
//2 triangles and 2 styles of blocks
//Nicholas CHirico
//2.6.14 CSI Section 3

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(){
	int number;
	cout<<"Enter the length of the sides, 0 to quit"<<endl;
	cin>>number;
	while (number!=0){

	//square maker
	for (int u=number; u>0; --u){
		for (int n=number; n>0; --n){
		cout<<"*";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;


	//first triangle
	int counter=0;
	for (int u=number; u>0; --u){
		for (int n=number-counter; n>0; --n){
		cout<<"*";
		}
		counter=counter+1;
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	//second triangle
	//there may be a better way of doing this
	//I'm really not sure what that way is though
	counter=0;
	for (int u=number; u>0; --u){
		for (int n=number-counter; n<number; n++){
		cout<<" ";
		}
		for (int n=number-counter; n>0; --n){
		cout<<"*";
		}
		counter=counter+1;
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	//weird empty block thing
	for(int l=number;l>0;--l)
		cout<<"*";
	cout<<endl;

	for(int p=number-2;p>0;--p){
	cout<<"*";
	for(int q=number-2;q>0;--q)
		cout<<" ";
	cout<<"*";
	cout<<endl;
	}

	for(int w=number;w>0;--w)
		cout<<"*";
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"enter your number, 0 to quit"<<endl;
	cin>>number;
	}
}