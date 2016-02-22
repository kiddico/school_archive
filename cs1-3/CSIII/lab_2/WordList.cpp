// Nicholas Chirico
// 5/2/16
// Lab 2
// CS 44001 Mihail Nesterenko / Jordan Adamek
#include <iostream>
#include "WordOccurrence.h"
#include "WordList.h"

/*

	I can never tell if the way that I'm doing somethimg is dumb or not
	I feel like this is one of those times.
	Either way this is the basic idea of what we've got going on here:
		When we make a new list we set the size to zero, and the max to 10.
			max is the current size (well... capacity) of the dyn array.
		if we reach the max # of elements in our array we'll create a new array
			new array is 2x the size of the original.
				in theory this keeps us at a reasonable size (not too large)
				w/o having to make a new, slightly larger one very 10 seconds.

*/

// Simple constructor
WordList::WordList(){
	size_=0;
	max_=10;
	longestOccurrence_ = 0;
	wordArray_=new WordOccurrence[max_];
}
// Destroyer of worlds, and wordlists
WordList::~WordList(){
	delete[] wordArray_;
}

// This is used both to find the location of a word
// and to test if a word is in the array/list.
// if the word is not in the list then the number -1 is returned.

int WordList::location(std::string to_test)const{
	for(int i = 0; i < size_; ++i){
		if(wordArray_[i].getWord()==to_test)
			return i;
	}
	// this is for when we don't find it.
	return -1;
}




// This doubles the length of our array.
// I think it's a pretty good system. 
// This way the size doesn't grow too fast,
// but also reduces the amount of times we need to resize/copy over
// oh by the way: in terms of the actual goal:
//	we assume that any symbols have been removed previously.
//	so... don't be stupid, stupid.
void WordList::doubleMax(){
	WordOccurrence *temp=new WordOccurrence[max_*2];
	for(int i =0; i < size_; ++i){
		temp[i]=wordArray_[i];
	}
	max_=max_*2;
	delete []wordArray_;
	wordArray_=temp;
}

// This is where most of the magic happens.
// First we check to see if the word is already on our list.
// if not be sure we have room, and add it.
// otherwise just increment.
void WordList::addWord(const std::string &input_word){

	int loc=location(input_word);
	if( loc==-1 ){
		// Didn't find it? We're gonna need to add it.
		// first be sure that we've got somewhere to put it.
		if( size_==max_ ) // aka if the array is full.
			doubleMax();
		// we've made room. lets add it to the list!
		WordOccurrence tempWordOcc(input_word,1);
		// new values go to the end of the list anyways. no need to pick where to put them.
		wordArray_[size_]=tempWordOcc;
		// adjusts the value for the length of the longest word.
		if(tempWordOcc.getWord().size() > longestOccurrence_)
			longestOccurrence_=tempWordOcc.getWord().size();
		++size_;
	}
	// So it was already on the list? increment it's entry and move on!
	else{
		wordArray_[loc].increment();
		int new_val=wordArray_[loc].getNum();
		int new_loc=0;
		if(loc!=0){//if incremented isn't not the first value...
			for(int i = 0; i < size_; ++i){
				if(wordArray_[i].getNum() < new_val){
					// if we find a location lower than the one we're in
					// remeber where to go, and break form this silly loop
					// again... not sure what to do... I don't like to use breaks...
					new_loc=i;
					i=size_;
				}
			}
			// after we've decided where to put things we need to rearrange a bit.
			arrange(loc,new_loc);
		}
	}
}

void WordList::arrange(int old_loc, int new_loc){
	if(size_==max_)
		doubleMax();
	// starting at the old location, and moving toward the beginning of the Array
	// move each occurrence one position toward the end.
	//WordOccurence temp=wordArray[old_loc];
	for(int i = old_loc; i > new_loc; --i){
		wordArray_[i].swapValues(wordArray_[i-1]);
	}
}


void WordList::printList(){
	for(int i = 0; i < size_; ++i){
		// this makes a string that spaces out the output so it looks a bit nicer
		// sorry if it makes you vomit all over the place.
		// try not to get it on your computer.
		std::string spaces(longestOccurrence_-wordArray_[i].getWord().size()+2,' ');
		std::cout<<wordArray_[i].getWord()<<":"<<spaces<<wordArray_[i].getNum()<<std::endl;

	}
}

WordList WordList::operator=(WordList input){
	*wordArray_=*input.wordArray_;
	max_=input.max_;
	size_=input.size_;
	longestOccurrence_=input.longestOccurrence_;
	return *this;
}
// Super duper copy contructor
WordList::WordList(const WordList &input){
	wordArray_=new WordOccurrence[input.max_];
	for(int i = 0; i < input.size_; ++i){
		wordArray_[i]=input.wordArray_[i];
	}
	size_=input.size_;
	max_=input.max_;
	longestOccurrence_=input.longestOccurrence_;
}


// this part is just for fun
void WordList::clear(){
	delete[] wordArray_;
	size_=longestOccurrence_=0;
	wordArray_=new WordOccurrence[max_];
}
