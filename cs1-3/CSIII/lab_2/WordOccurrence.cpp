// Nicholas Chirico
// 5/2/16
// Lab 2
// CS 44001 Mihail Nesterenko / Jordan Adamek

#include "WordOccurrence.h"
#include <iostream>
#include <string>


bool WordOccurrence::matchWord(const std::string &input){
	if(input==word_)
		return true;
	else
		return false;
}

void WordOccurrence::increment(){
	++num_;
}

std::string WordOccurrence::getWord()const{
	return word_;
}

int WordOccurrence::getNum()const{
	return num_;
}

bool WordOccurrence::operator==(const WordOccurrence &rhs){
	if( (rhs.getWord()==word_) && (rhs.getNum()==num_) )
		return true;
	else
		return false;

}

void WordOccurrence::swapValues(WordOccurrence &to_swap){
	int temp_num=num_;
	std::string temp_word=word_;
	num_=to_swap.num_;
	word_=to_swap.word_;
	to_swap.num_=temp_num;
	to_swap.word_=temp_word;
}
