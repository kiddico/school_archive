//this file stores all the functions for the battleship game.
//Nicholas Chirico
//3.11.14 CSI Section 003
#include "battleship.h"
#include <iostream>
#include <ctime>
using namespace std;

location pick(){
	location tmp;
	int tmp2;
	tmp.x=rand()%5+1;
	tmp2=rand()%5+1;
	switch(tmp2){
	case 1:
		tmp.y='a';
		break;
	case 2:
		tmp.y='b';
		break;
	case 3:
		tmp.y='c';
		break;
	case 4:
		tmp.y='d';
		break;
	case 5:
		tmp.y='e';
	};
	return tmp;
};
location fire(){
	location tmp;
	int in1;
	char in2;
	cout<<"Pick a Coordinate to fire at! (ex 2 b)"<<endl;
	cin>>in1>>in2;
	tmp.x=in1;
	tmp.y=in2;
	return tmp;
}
void printShip(ship tmp){
	cout<<"X Coordinate= "<<tmp.loc.x<<" Y Coordinate= "<<tmp.loc.y;
	if (tmp.sunk==false)
		cout<<" Not Sunk"<<endl;
	if (tmp.sunk==true)
		cout<<" Sunk"<<endl;
}
bool match(ship tmp, location tmp2){
	if (tmp.loc.x==tmp2.x && tmp.loc.y==tmp2.y)
		return true;
	else
		return false;
}
void sink(ship& it){
it.sunk=true;
}
//return true if at least on ship is not sunk
bool operational(const ship ships[]){
		if (ships[0].sunk==true && ships[1].sunk==true && ships[2].sunk==true && ships[3].sunk==true && ships[4].sunk==true)
			return false;
		else
			return true;
}

void initialize(ship ships[]){
	for (int i=0;i<5;i++){
		ships[i].loc.x=-1;
		ships[i].loc.y=-1;
	}

}
int check(const ship ships[], location tmploc){
	for (int l=0;l<5;l++){
		if (ships[l].loc.x == tmploc.x)
			if(ships[l].loc.y == tmploc.y)
				return l;
			
	}
	return -1;
}
void deploy(ship ships[]){
	for(int e=0;e<5;e++){
	ships[e].loc=pick();
	ships[e].sunk=false;
	}
}
void printFleet(const ship ships[]){
	for(int d=0;d<5;d++){
	cout<<ships[d].loc.x<<" "<<ships[d].loc.y;
	if(ships[d].sunk==true)
		cout<<"Sunk"<<endl;
	else
		cout<<"Not Sunk"<<endl;
	}
}