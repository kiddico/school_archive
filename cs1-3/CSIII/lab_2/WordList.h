// Nicholas Chirico
// 5/2/16
// Lab 2
// CS 44001 Mihail Nesterenko / Jordan Adamek
#ifndef WORDLIST
#define WORDLIST

#include "WordOccurrence.h"
#include <string>

class WordList{
	public:
		WordList();
		~WordList();
		WordList(const WordList &);
		WordList operator=(WordList);
	
		void addWord(const std::string &);
		void printList();

		// my crap
		void arrange(int,int);
		void doubleMax();
		int location(std::string)const;
		void clear();

	private:
		// keeps track of the longest word
		// used to make the output look a bit nicer
		WordOccurrence *wordArray_; 
		int size_;
		int max_;
		int longestOccurrence_;
};

#endif
