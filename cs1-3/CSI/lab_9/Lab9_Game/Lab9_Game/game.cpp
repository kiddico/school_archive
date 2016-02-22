//This is the game batttleship
//done with classes! yay
//Nicholas Chirico
//3.18.14 CSI Section 003
#include "battleship.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){
	fleet myFleet;
	char cheater;
	srand(time(NULL));
	myFleet.deployFleet();
	cout<<"Would You like to know the possitions of the ships? y/n"<<endl;
	cin>>cheater;
	if(cheater=='y')
		myFleet.printFleet();
	do{
		location shot;
		shot.fire();
		if(myFleet.isHitNSink(shot)){
			cout<<"You hit one!"<<endl;
		}
		else
			cout<<"You missed!"<<endl;
		if(cheater=='y')
			myFleet.printFleet();
	}
	while(myFleet.operational());
	cout<<"You got em all!"<<endl;
}