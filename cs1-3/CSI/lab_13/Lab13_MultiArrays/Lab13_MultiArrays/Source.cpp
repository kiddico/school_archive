// Keeping track of shots fired in Battleship game
// using multidimentional arrays
// Nichoals Chirico
// 4/22/2013 CSI Section 003

#include <iostream>
using namespace std;

// size of the ocean
const int OCEAN_LENGTH = 5;
const int OCEAN_WIDTH = 5;
int main(){
	bool shots[OCEAN_LENGTH][OCEAN_WIDTH];
	char q,letter;
	int number,letter2;
	//setting all spots to false
	for(int i=0; i < OCEAN_LENGTH; ++i)
		for(int j=0; j < OCEAN_WIDTH; ++j)
			shots[i][j] = false;
	do{
		cout<<"Another Shot? [y/n]"<<endl;
		cin>>q;
		if(q!='n'){
			cout<<"Location? ";
			cin>>letter>>number;
		}
		else
			break;
		number=number-1;
		letter2=letter-97;
		shots[number][letter2]=true;
		cout<<" a b c d e"<<endl;
		for(int i=0; i < OCEAN_LENGTH; ++i){
			cout<<i+1;
			for(int g=0; g < OCEAN_WIDTH; ++g)
				if(shots[i][g]==true)
					cout<<"* ";
				else
					cout<<"  ";

			cout<<endl;
		}	
	}
	while(q!='n');
}