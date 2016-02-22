//This program will calculate the BMR of a male or female
//Nicholas Chirico
//2.11.14 CSI Section 003

#include <iostream>
using namespace std;

double bmrMen(double height, double weight, double age){
	double tmp;
	tmp=66+(6.3*weight)+(12.9*height)-(6.8*age);
	return tmp;
}
double bmrWomen(double height, double weight, double age){
	double tmp;
	tmp=655+(4.3*weight)+(4.7*height)-(4.7*age);
	return tmp;
}
int main(){ 
	char gender;
	int height, weight, age, bagels;
	double cals;
	cout<<"Are you male or female? (M/F)"<<endl;
	cin>>gender;
	cout<<"What is your height?(in inches)"<<endl;
	cin>>height;
	cout<<"What is your weight? (in pounds)"<<endl;
	cin>>weight;
	cout<<"What is your age? (in years)"<<endl;
	cin>>age;
	if(gender=='m'){
		cals=bmrMen(height,weight,age);
	}
	if(gender=='f'){
		cals=bmrWomen(height,weight,age);
	}
	bagels=cals/354;

	cout<<"You burn "<<cals<<" calories without doing anything!"<<endl;
	cout<<"So you can eat "<<bagels<<" bagels!"<<endl;
}