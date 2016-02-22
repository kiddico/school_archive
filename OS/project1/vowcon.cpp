/*
	Nick Chirico
	Operating System Concepts
	10/13/15
*/

#include <iostream>
#include <thread>
#include <string>
//it's 2015, and I have an 8 core cpu and 16 gb of ram, I don't see why not to use fancy stuff
#include <vector>
//strd.hpp is a library I made about a year ago.
//you can find it here http://github.com/kiddico/EasyIO
//it's my way of keeping myself from messing up file streams.
//it's an...interesting implementation if you want to have a look at it.
#include "strd.hpp"

//function that returns the contents of phrase.txt
//it packages it in a vector of strings.
//the final word will end in a period. so break there
std::vector<std::string> get_words(){
	//Using my library to read the file
	//if you want to change what file is read from just change phrase.txt to whatever
	readf phrase("phrase.txt");
	bool done = false;
	std::vector<std::string> words;
	while(!done){
		words.push_back(phrase.read());
		if(words.back().back()=='.'){
			done++;
		}
	}
	return words;}

std::vector<std::string> phrase = get_words(); //this is a global vector filled with the contents of phrase.txt
const char vowels[12] = {'a','e','i','o','u','y','A','E','I','O','U','Y'}; //just an array of vowels for ease of use
int turn = 1; //keeps track of whos turn it is.
int current_word = 0; //keeps both threads on the same word.
bool the_end = false; //lets the threads know when they can go home and get some rest

//I know it's not the pretiest
//If I were to do this again I could probably do it with like half the lines.
//because we always check vow first, it its a vowel then we don't bother to do con
void vow(){
	while(!the_end){
		if(turn == 1){
			bool was_a_vowel=false;//slight afterthought
			std::string word = phrase[current_word];
			//loops through, checking to see if it starts with a vowel
			for(int i = 0 ; i < 12 ; i++){
				if(word.front()==vowels[i]){
					std::cout<<"Vow:   "<<word<<std::endl;
					current_word++;
					was_a_vowel=true;
					if(word.back()=='.')
						the_end = true;
				}
				
			}
				if(!was_a_vowel){
					turn = 2;
				}
		}
	}
}

void cons(){
	while(!the_end){
		if(turn==2){
			std::string word = phrase[current_word];
			std::cout<<"Cons:  "<<word<<std::endl;
			current_word++;
			if(word.back() == '.')
				the_end = true;
			turn = 1;
		}
	}
}

//loading everything as a global has made for a very clean main()
int main(){
	std::thread t1(vow);
	std::thread t2(cons);
	t1.join();
	t2.join();
}
