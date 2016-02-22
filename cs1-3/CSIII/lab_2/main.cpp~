// Nicholas Chirico
// 5/2/16
// Lab 2
// CS 44001 Mihail Nesterenko / Jordan Adamek

#include <iostream>
#include "WordOccurrence.h"
#include "WordList.h"
#include <fstream>
#include <cctype>


/*
	HEY! I decided to have a little fun with this.
	I've made another version that can handle multiple files.
	it gives you a total at the end too.
	just run:
		> make extra
	or:
		> make extra_run
	to run a sample after it compiles
	
	WARNING: sample will fill up your screen. Unless you have the highest res screen in all of recorded history.
*/

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cout<<"Not enough arguments provided at command line."<<std::endl;
		std::cout<<"Please provide the name of input file as first argument."<<std::endl;;
		return 1;
	}

	std::ifstream sample;
	sample.open(argv[1]);
	WordList wl;
	// This is where all the fun starts!
	// first we get a word
	// then cycle through it and remove all non-alphanumerics

	std::string temp;
	while(!sample.eof()){
		sample>>temp;
		for(int i = 0; i < temp.size(); i++){
			if( !isalnum(temp[i]) )
				temp.erase(i,1);
		}
		wl.addWord(temp);
	}

	wl.printList();
}
