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
	Extra crap, my favorite kind of crap.
	EX:
		> ./for_fun sample sample2 sample3
*/

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cout<<"Not enough arguments provided at command line."<<std::endl;
		std::cout<<"Please provide the name of an input file as first argument."<<std::endl;
		std::cout<<"Or use multiple files as the input."<<std::endl<<"like: ./for_fun sample sample2 sample3"<<std::endl;
		return 1;
	}

	std::ifstream sample;
	//sample.open(argv[1]);
	WordList wl;
	WordList all;
	// This is where all the fun starts!
	// first we get a word
	// then cycle through it and remove all non-alphanumerics

	std::string temp;
	for(int args = 1; args < argc; args++){
		sample.open(argv[args]);
		while(!sample.eof()){
			sample>>temp;
			for(int i = 0; i < temp.size(); i++){
				if( !isalnum(temp[i]) )
					temp.erase(i,1);
			}
			wl.addWord(temp);
			all.addWord(temp);
		}
		sample.close();
		if(argc>2)
			std::cout<<"Input file #"<<args<<std::endl;
		wl.printList();
		if(args!=argc-1)
			std::cout<<std::endl<<std::endl;
		wl.clear();
	}

	if(argc>2){
	std::cout<<std::endl<<std::endl;
	std::cout<<"# of files read: "<<argc-1<<std::endl<<std::endl;
	std::cout<<"Word Count totals:"<<std::endl<<std::endl;
		all.printList();
	}
}
