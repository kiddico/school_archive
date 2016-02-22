//This program is a simple guessing game
//Nicholas Chirico
//2.4.14 Cs1 Section 003

#include <iostream>
#include <ctime>
using std::cin; using std::cout; using std::endl;
int main(){
	int guess,answer;
	int count=0;
	srand(time(NULL));
	answer=rand()%100;
	cout<<"What's your first guess?"<<endl;
	cin>>guess;
	++count;
	do{
		++count;
		if(guess>answer){
			cout<<"your guess was too high! Guess again"<<endl;
			cout<<endl;
			cin>>guess;
			continue;
		}
		if(guess<answer){
			cout<<"your guess was too low! Guess again"<<endl;
			cout<<endl;
			cin>>guess;
			continue;
		}
	}
	while(guess!=answer);
	//I added a number of guesses thing. Yay
	cout<<"you guessed it! It was "<<answer<<"."<<"It took you "<<count<<" Guesses!"<<endl;
}