#include <iostream>
#include <vector>
#include"header.h"
#include <algorithm>
using namespace std;

//adds a number to the vector usng pushback
void adder(int number,vector<int>& dynArray){
	dynArray.push_back(number);

}

//iterates through the vector
//if the input matches an element it is removed
void subber(int number,vector<int>& dynArray){
	vector<int>::iterator toRemove=dynArray.begin();
	for(vector<int>::iterator ip=toRemove; ip != dynArray.end(); ++ip){
		if(*ip==number)
			toRemove=ip;
	}
	dynArray.erase(toRemove);
}

//sorts then couts thye vector
void output(vector<int> dynArray){
	sort(dynArray.begin(),dynArray.end());
	for(vector<int>::iterator ip=dynArray.begin();
      ip != dynArray.end(); ++ip){
    cout << *ip << " ";
	}
	cout << endl;
}
