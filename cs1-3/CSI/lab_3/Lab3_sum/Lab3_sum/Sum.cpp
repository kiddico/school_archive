//This program adds together only positive numbers
//Nicholas Chirico
//2.4.14 Secion 003 CSI
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(){
	int adder;
	int sum=0;
	cout << "Type numbers you want to add. End with a Zero" << endl;
	
	do{
	cin >> adder;
	if(adder>0) sum = sum + adder;
	}while(adder != 0);

	if(sum > 0){
	cout << "The sum of the positive numbers is ";
	cout << sum << endl;
	}
	else {cout << "Your total did not exceed 0"<< endl;}
}