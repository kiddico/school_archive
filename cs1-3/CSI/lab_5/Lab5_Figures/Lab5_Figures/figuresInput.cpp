//This program makes shapes!
//but it does it with more files...
//Nicholas Chirico
//2.11.14 CSI Section 003

#include <iostream>
#include "figures.h"
using namespace std;

int main(){
	int choice,number;
	char blockChoice;
	cout<<"How long do you want each side to be?";
	cin>>number;
	cout<<"Do you want to make:"<<endl<<"1. Square"<<endl<<"2. Left Triangle"<<endl<<"3. Right Triangle"<<endl<<"Anything else to quit"<<endl;
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"Hollow block or filled? (H/F)"<<endl;
		cin>>blockChoice;
		if (blockChoice=='h'){
			hollowSquare(number);
		}
		if(blockChoice=='f'){
			filledSquare(number);
		}

		break;
	case 2:
		leftTriangle(number);
		break;
	case 3:
		rightTriangle(number);
		break;
	default:
		break;
	}
}