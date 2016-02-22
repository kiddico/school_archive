// testing the implementation of class WordList
// Mikhail Nesterenko
// 9/04/2015

#include <iostream>
#include <string>
#include "WordList.h" // class definitions

using std::cout; using std::endl;

void testfunc(WordList); // function to test pass-by-value for WordList class

int main(){

   WordList wl;

   // testing regular member functions
   wl.addWord("one");
   wl.addWord("one"); // adding duplicate
   wl.addWord("two");
   wl.addWord("three");

   cout << "word list is:\n";
   wl.printList();


   WordList wl2, wl3;

   wl3=wl2=wl; // testing overloaded assignment
   wl3=wl3; // testing protection against self-assingment

   testfunc(wl); // testing copy constructor
   wl.printList(); // if destructor is implemented correctly
                // this should print properly after testfunc completes
}


// tests pass-by-value for object of class varArray
void testfunc(WordList myList){ // copy constructor is invoked on "myList"
   cout << "word list in testfunc: \n";
   myList.printList(); 
} // destructor is invoked when "myList" goes out of scope

