//This program makes a drynamic array
//Nicholas Chirico
//4.1.14 CSI Section 003
#include "vararray.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(){
	char operation;
	int input,size=0;
	int *dynArray=new int[size];

	do{
		//here the user is asked for the operation
		cout<<"Enter the operation [a,r,q]"<<endl;
		cin>>operation;
			//in order to stay in the loop the the user must enter 'a' or 'r'
			//if they don't then they are never even prompted for a number. 
			//this avoids confusion
			//on a side note this is the most commenting I've done all year.
			//just thought I would throw that out there.
			if (operation=='a'||operation=='r'){
				cout<<"enter the number!"<<endl;
				cin>>input;
			}
		//BRANCH A
		if(operation=='a'){
			//addNumber...This is a tough one...
			//what could addNumber possibly do?
			addNumber(dynArray,input,size);
		}
		//BRANCH R
		if(operation=='r'){
			removeNumber(dynArray,input,size);
		}

	}
	while(operation!='q');

	//debugging stuff!
	for(int o=0;o<size;o++){
		cout<<dynArray[o]<<" ";
	}
	cout<<endl;
}