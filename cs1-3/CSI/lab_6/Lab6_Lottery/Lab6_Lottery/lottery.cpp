//This program picks 10 random number
//the user takes a guess of what one of the numbers is.
//Nicholas Chirico
//2.23.14 CSI Section 003

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initialize(int[]);
void entry(int&);
void draw(int[]);
bool check(int,int[]);
bool win(int,int[]);

int main(){
	int guess, wins[10];
	initialize(wins);
	draw(wins);
	entry(guess);
	if (win(guess,wins)==true)
		cout<<"You won!"<<endl;
	else
		cout<<"You didn't win!"<<endl;
	cout<<"The numbers were!"<<endl;
	for(int p=0;p<9;p++)
		cout<<wins[p]<<",";
	cout<<" and "<<wins[9];
	cout<<" you guessed "<<guess<<".\n";

}

void initialize(int wins[]){
	for(int n=0;n<10;n++)
		wins[n]=-1;
}

void draw(int wins[]){
	srand(time(NULL));
	for(int i=0;i<10;i++){
		wins[i]=rand()%100;
		if(check(i,wins)==false)
			wins[i]=rand()%100;
	}
}

void entry(int& guess){
	cout<<"Guess a number"<<endl;
	cin>>guess;
}

bool check(int on,int wins[]){
	for(int p=0;p<on;p++){
		if(wins[on]==wins[p])
			return false;
	}
	return true;
}

bool win(int guess,int wins[]){
	for(int p=0;p<10;p++){
		if(guess==wins[p])
			return true;
	}
	return false;
}