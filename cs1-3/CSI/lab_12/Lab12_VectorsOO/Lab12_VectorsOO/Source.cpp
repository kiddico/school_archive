#include <iostream>
#include <vector>
#include <algorithm>
#include "vectorsoo.h"
using namespace std;

int main(){
	int number;
	char operation;
	vectorsoo array;
	do{
		cout<<"Enter operation [a,r,q] and number:"<<endl;
		cin>>operation;
		if(operation!='q')
			cin>>number;
		if(operation=='a'){
			array.addNumber(number);
		}
		if(operation=='r'){
			array.removeNumber(number);
		} 
		if(operation!='q')
			array.output();
	}
	while(operation!='q');
	array.output();
}