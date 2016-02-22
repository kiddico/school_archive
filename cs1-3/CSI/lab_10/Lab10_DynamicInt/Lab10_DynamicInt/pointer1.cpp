//Nicholas Chirico
//This is a program that makes a dynamic array from user input
//3.31.14 CSI Section 003

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(){

  int *dynArray;  // pointer to the dynamically allocated array
  int size;       // array size

  cout << "Enter number of integers: ";
  cin >> size;
  dynArray=new int[size];
  cout<<"Enter Integers:"<<endl;
  int input;
  for(int i=0;i<size;i++){
	  cin>>input;
  dynArray[i]=input;
  }
  cout<<"You Entered: "<<endl;
  for(int u=0;u<size;u++){
  cout<<dynArray[u]<<" ";
  }
  cout<<endl;
}