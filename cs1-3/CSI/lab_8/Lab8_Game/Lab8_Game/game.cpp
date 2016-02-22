//This is a recreation of the game battleship.
//kind of.
//Nicholas Chirico
//3.11.14 CSI Section 003
#include "battleship.h"
#include <iostream>
#include <ctime>
using namespace std;
int main(){
	ship ships[FLEET_SIZE];
	location spot;
	int current;
	srand(time(NULL));
	initialize(ships);
	deploy(ships);
	do{
		spot=fire();
		current=check(ships,spot);
		if (current==-1)
			cout<<"You didn't hit anything"<<endl;
		else
			cout<<"You got the ship"<<endl;
			sink(ships[current]);
	}
	while(operational(ships)==true);
	cout<<"You got em all!"<<endl;
}