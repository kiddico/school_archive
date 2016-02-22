// Keeping track of shots fired in Battleship game
// using multidimentional arrays
// Nicholas Chirico
// 4/22/2013

#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;


int main(){
	char q,letter;
	int number,letter2;

	cout << "Enter ocean length: ";
	int oceanLength;
	cin >> oceanLength;

	cout << "Enter ocean width ";
	int oceanWidth;
	cin >> oceanWidth;

	vector <vector <bool>> shots; // vector of vectors of shots

	vector<bool> shotsRow(oceanWidth); // one row of shots

	// consider initializing the row of shots

	for(int rows=0; rows < oceanLength; ++rows) 
		shots.push_back(shotsRow);

	// place your code here
	for(int i=0; i < oceanLength; ++i)
		for(int j=0; j < oceanWidth; ++j)
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
		cout<<" ";
		for(char i='a';i<oceanWidth+97;++i)
			cout<<i<<" ";
		cout<<endl;
		for(int i=0; i < oceanLength; ++i){
			cout<<i+1;
			for(int g=0; g < oceanWidth; ++g)
				if(shots[i][g]==true)
					cout<<"* ";
				else
					cout<<"  ";

			cout<<endl;
		}
	}
	while(q!='n');
}