// Nick Chirico
// 3/19/2016
// demoes hashmap implementation
// Mikhail Nesterenko
// 4/15/2014

#include "hashmap.h"
#include <iostream>
#include <string>
#include <ctime>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
	std::vector<int> to_insert;
	srand(time(nullptr));
	hashmap<int, int> myHash;
	for( int i = 0; i < 10; ++i){
		int to_keep = rand()%100;
		myHash.insert(std::make_pair(i,to_keep));
	}
	cout<<"Before erase: "<<endl;
	for(int i =0;i<10;++i)
		cout<<myHash[i]<<endl;
	
	cout<<endl<<"After erase: ";
	int to_erase=rand()%9;
	myHash.erase(to_erase);
	for(int i =0;i<10;++i)
		if(i!=to_erase)
		cout<<myHash[i]<<endl;

	myHash.rehash(120);
	cout<<endl<<"After rehash"<<endl;
	for(int i =0;i<10;++i)
		if(i!=to_erase)
		cout<<myHash[i]<<endl;
}
