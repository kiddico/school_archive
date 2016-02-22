//This program mimics a scientific Calculator
//At least sort of.
//Nicholas Chirico
//2.4.14 Cs1 Section 003

#include <iostream>
#include <cmath>
#include <cstdlib>
using std::cin; using std::cout; using std::endl;
int main(){
	int choice;
	double precalc;
	double postcalc;
	int exponent;
	do{
		cout<<"1. Absolute Value"<<endl;
		cout<<"2. Square Root"<<endl;
		cout<<"3. Ceiling"<<endl;
		cout<<"4. Power"<<endl;
		cout<<"Input the number of the operation you want, 0 to quit"<<endl;

		cin>>choice;
		switch (choice){
			case 1:
				cout<<"Insert a value to get the absolute value of"<<endl;
				cin>>precalc;
				postcalc=abs(precalc);
				cout<<"The absolute value of "<<precalc<<" is "<<postcalc<<endl;
				continue;
			case 2:
				cout<<"Insert a value to get the square root of"<<endl;
				cin>>precalc;
				postcalc=sqrt(precalc);
				cout<<"The square root of "<<precalc<<" is "<<postcalc<<endl;
				continue;
			case 3:
				cout<<"Insert a value to round up"<<endl;
				cin>>precalc;
				postcalc=ceil(precalc);
				cout<<precalc<<" rounded "<<precalc<<" is "<<postcalc<<endl;
				continue;
			case 4:
				cout<<"First enter the base then the exponent seperated by a space"<<endl;
				cin>>precalc>>exponent;
				postcalc=pow(precalc, exponent);
				cout<<precalc<<" to the power of "<<exponent<<" is "<<postcalc<<endl;
				continue;
			case 0:
				cout<<"Bye then!"<<endl;
				continue;
		}

	}while(choice!=0);



}