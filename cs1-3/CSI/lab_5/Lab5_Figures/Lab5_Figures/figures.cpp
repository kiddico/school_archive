#include "figures.h"
#include <iostream>
using namespace std;
//this makes the first triangle
void leftTriangle(int number){
	int counter=0;
	for (int u=number; u>0; --u){
		for (int n=number-counter; n>0; --n){
			cout<<"*";
		}
		counter=counter+1;
		cout<<endl;
	}
}


//this makes the second triangle
void rightTriangle(int number){
	int counter=0;
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
}


//This makes the filled block
void filledSquare(int number){
	for (int u=number; u>0; --u){
		for (int n=number; n>0; --n){
			cout<<"*";
		}
		cout<<endl;
	}
}


//this makes the hollow block
void hollowSquare(int number){
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
}