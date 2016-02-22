// structure definitions and function prototypes
// Nick Chirico
// 3/10/2014

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_

//
// data structures definitions
//

const int FLEET_SIZE=5; // number of battleships
const int FIELD_SIZE=5;  // the field (ocean) is FIELD_SIZExFIELD_SIZE

// coordinates (location) of the ship and shots
struct location{
  int x;  // 1 through FIELD_SIZE
  char y; // 'a' through FIELD_SIZE
};

// contains ship's coordinates (location) and whether is was sunk
struct ship{
  location loc;
  bool sunk;
};

//
// initialization functions
//
void initialize(ship[]); // places all ships in -1 X location to signify
                        // that the ship is not deployed
location pick(void); // generates a random location
bool match(ship, location); // returns true if this location matches
                            // the location of the ship
                            // returns false otherwise
int check(const ship[], location); // returns the index of element of the array
                                   // that matches the location
                                   // returns -1 if none do
                                   // uses match()
void deploy(ship[]); // places an array of battleships in
                     // random locations in the ocean

//
// display functions
//
void printShip(ship); // prints the location and status (sunk or not) 
                      // of a single ship
void printFleet(const ship[]); // prints the locations of all the ships and 
                               // whether they are sunk


//
// battle functions
//
bool operational(const ship[]);  // returns true if at least one ship in the array
                                 // is not sunk
location fire(void);       // asks the user to input the coordinates of the next
                           // shot
// note that check() is also used in the battle

void sink(ship&);          // sets "sunk" member variable of the ship to true

#endif /* BATTLESHIP_H_ */