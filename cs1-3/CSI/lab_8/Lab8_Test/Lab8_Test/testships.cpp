// Nicholas Chirico
// tests battleship functions implementation
// 3/10/2013

#include "battleship.h"
#include <iostream>
#include <ctime>

using std::cout; using std::cin; using std::endl;

int main(){

  //
  // checking location functions
  // 

  // create location
  location mySpot;
  mySpot.x=5;
  mySpot.y='e';

  // print location 
  cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;
  srand(time(NULL));
  mySpot = pick(); // assign randomly generated location to mySpot
  cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

  mySpot = fire(); // assign user input location to mySpot
  cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;


  //
  // checking ship functions
  //

  
  ship myShip;

  myShip.loc = pick(); // assign random location to myShip
  myShip.sunk = false;  // myShip is not sunk
  printShip(myShip); // print myShip information
  if(match(myShip,mySpot))
      cout << "myShip is at mySpot location\n";
  else
      cout << "myShip is not at mySpot location\n";

  sink(myShip); // sinking myShip
  printShip(myShip); // print sunk ship
  

  //
  // checking fleet functions
  // 


  ship myFleet[FLEET_SIZE];

  initialize(myFleet); //assigning -1 to all ship's locations in myFleet
  printFleet(myFleet);

  deploy(myFleet); // deploying ships at random locations
  printFleet(myFleet);

  if(check(myFleet,mySpot) != -1)
    cout << "myFleet has a ship at mySpot\n";
  else
    cout << "myFleet does not have a ship at mySpot\n";

  if(operational(myFleet))
    cout << "at least one ship is not sunk\n";
  else
    cout << "all ships are sunk\n";

}
