/*
	Nick Chirico
	Operating System Concepts
	12/3/2015
*/

#include <iostream>
#include <string>
#include "memory.hpp"

std::vector<std::string> pages;


int main(){

	//let's start out simple, and bring in all our data
	//this function is in the memory.hpp file
	fill_pages(pages);
	
	//creating our memory pool
	memorypool memory;
	int current_ref; //I use this to hold stuff. mostly cause I'm bad at planning ahead
	std::string current_page;//same concept as ^^^^


	//this is the main loop where all the magic happens.
	for(int i = 0; i < pages.size(); i++){
		current_page = pages[i];//not necessary, but it makes things easier to read
		if(current_page.length() > 2 || current_page.at(0) == '-'){
			std::cout<<"Page "<<current_page << " out of range! Exiting"<<std::endl;
			memory.panic();
		}
		//first thing to do is check if the requested page is already in a frame
		current_ref = memory.check_if_in_frame(current_page);
		if( current_ref != -1){ //aka if in memory
			//give the fella another chance
			memory.give_second_chance(current_ref);
		}

		else{//didn't find it. let's put it somewhere

			current_ref = memory.find_next_empty_frame();//see if we've got any free space
			if(current_ref != -1){ //if it found an empty frame...
				memory.fill_frame(current_page,current_ref);//fill 'er up
			}

			else{//no empty space. time to find a victim *evil laugh*
				current_ref = memory.find_next_last_chance();//look for 0 ref. changing 1s to 0s as we go
				memory.fill_frame(current_page,current_ref);
			}
		}
	}
}
