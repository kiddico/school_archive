//these are all the function definitions 
//Nicholas Chirico
//3.17.14 CSI Section 003

#include "battleship.h"
#include <iostream>
using namespace std;

void location::pick(){
x=rand()%5+1;
int tmp;
tmp=rand()%5+1;
switch(tmp){
case 1:
		y='a';
		break;
	case 2:
		y='b';
		break;
	case 3:
		y='c';
		break;
	case 4:
		y='d';
		break;
	case 5:
		y='e';
	};
}

location::location(){
x=-1;
y=-1;
}
void location::fire(){
cout<<endl<<"Where would you like to fire? (Ex: 'c 4')"<<endl;
cin>>x>>y;
}

void location::print(void) const{
	cout<<x<<y;
}
bool compare(location one,location two){
	if(one.x==two.x && one.y==two.y)
		return true;
	else
		return false;
}

ship::ship(){
	sunk=false;
}
void ship::setLocation(const location& spot){
loc=spot;
}

bool ship::match(const location& userShot) const{
	return compare(loc,userShot);
}

void ship::printShip(void) const{
loc.print();
if(sunk==true)
	cout<<" Sunk"<<endl;
else
	cout<<" Not Sunk"<<endl;
}
void ship::sink(){
	sunk=true;
}

void fleet::deployFleet(){
	for(int i=0;i<5;i++)
	{location tmp;
	tmp.pick();
	ships[i].setLocation(tmp);
	
	}
}
bool fleet::operational() const{
	for(int i=0;i<5;i++){
	if(ships[i].isSunk()==false)
	return true;
	}
	return false;
}

bool fleet::isHitNSink(const location& shot){
	for(int i=0;i<5;i++)
	{
		if(ships[i].match(shot)==true){
		ships[i].sink();
		return true;
		}
	}
	return false;
}
void fleet::printFleet(void) const{
	for(int i=0;i<5;i++){
		ships[i].printShip();
	}
}