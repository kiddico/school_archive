#ifndef WORDLIST
#define WORDLIST

#include "WordOccurrence.hpp"
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

	private:
		// keeps track of the longest word
		// used to make the output look a bit nicer
		int longestOccurrence;
		WordOccurrence *wordArray_; 
		int size_;
		int max_;
};

#endif
