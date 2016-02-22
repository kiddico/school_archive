#include <iostream>
#include <vector>
#include <algorithm>
#include "vectorsoo.h"
using namespace std; 



void vectorsoo::addNumber(int number){
	container.push_back(number);
}
void vectorsoo::removeNumber(int number){
	vector<int>::iterator toRemove=container.begin();
	for(vector<int>::iterator ip=toRemove; ip != container.end(); ++ip){
		if(*ip==number)
			toRemove=ip;
	}
	container.erase(toRemove);
}
void vectorsoo::output(void){
	sort(container.begin(),container.end());
	for(vector<int>::iterator ip=container.begin();
      ip != container.end(); ++ip){
    cout << *ip << " ";
	}
	cout << endl;
}