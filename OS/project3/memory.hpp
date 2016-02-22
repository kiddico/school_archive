/*
	Nicholas Chirico
	Operating Systems
	12/3/2015
*/


#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> //for when I break things.
#include <cassert>
#include <vector>
#include <fstream>

class memorypool{
	//Lovely operators
	public:
		
		//constructor
		
		//make stuff right
		memorypool(){
			//set some values and move on in life
			full = false;
			current = 0;
			for(int i = 0; i < 10; i++){
					frames[i] = "empty";
					//for debugging
					//std::cout<<"filled frame "<<i<<std::endl;
			}
			
			for(int i = 0; i < 10; i++){
					refs[i] = 0;
					//for debugging
					//std::cout<<"filled ref "<<i<<std::endl;
			}
		}

		//destructor
		//mostly just hangs out
		~memorypool(){
		}

		//returns the array index of an empty frame if there is one
		//if there is not it returns -1
		//assumes that if a frame is empty it doesn't need to touch the ref value.
		int find_next_empty_frame(){
			//look through the frames array.
			for(int i = 0; i < 10; i++){
				if(frames[i] == "empty") //if any frame has value "empty"
					return i; //return that frames location
			}
			//if none of them are empty set full to true
			full = true;
			//and send back -1
			return -1;
		}


		//search through ref array looking for 0
		//moves current as it goes.
		//returns location of last chance frame.
		//then moves current to the next one.
		//only ever call if full == true
		//which would be set by find_next_empty_frame when it doesn't find one.
		int find_next_last_chance(){
			//just in case I'm dumb.
			if(full!=true){
				std::cout<<"find_next_last_chance() called w/ full!=true"<<std::endl;
				panic();
				//exit(EXIT_FAILURE);//this is that part where I break things
			}
			bool not_done = true;
			while(not_done){//keep going until we accomplish something. I'm sure that won't go badly
				//if the current place in the queue has been given a second chance 
				if(refs[current] == 1){ 
					refs[current] = 0;//take away said second chance
					current = (current+1)%10;//then put current on the next one.
				}
				else{
					not_done = false;//prep to bail!
					int to_return = current;
					current = (current+1)%10;
					return to_return;
				}
			}
		}



		//looks for a page in the frames.
		//if it finds it it returns the location
		//otherwise returns -1
		int check_if_in_frame(std::string input){
			for(int i =0; i < 10; i++){
				if(frames[i] == input){
					//say what needs to be said
					std::cout<<input<<": page hit, page  "<<input<<" is in page "<<i<<std::endl;
					return i;
				}
			}
			return -1;
		}

		//if a request is already in a frame this sets it's ref bit to 1
		//takes the location of the proper frame. 
		//which we can get from check_if_in_frame()
		void give_second_chance(int input){
			refs[input]=1;
		}


		//still need to make a method to put stuff in frames.
		//be sure to double check the ref is zero
		void fill_frame(std::string page, int location){
			if(refs[location] != 1){
			std::string old_value = frames[location];//save the old value if we're replacing it.
			frames[location] = page;//replace it

			//tell the world
			if(old_value != "empty"){
				std::cout<<page<<": page miss, page  "<< page << " replaces page "<<old_value<<" in frame "<< location <<std::endl;
			}

			else{
				std::cout<<page<<": page miss, page  "<< page << " fills empty frame "<< location <<std::endl;
			}

			}
			else{//never learned how to do proper error catching. I should do that.
				std::cout<<"tried to fill a frame with a second chance"<<std::endl;
				panic();
				//exit(EXIT_FAILURE);
			}
		}
		
		//verification methods

		void check_values(){
			for(int i = 0; i < 10; i++)
				std::cout<<"refs: "<< i << " "<< refs[i] <<std::endl;
			for(int i = 0; i < 10; i++)
				std::cout<<"frames: "<< i <<" " << frames[i] <<std::endl;
			std::cout<<"full: "<< full <<std::endl;
			std::cout<<"current: "<< current <<std::endl;
			assert(current == 0);
			assert(full == false);
		}


	void panic(){
		exit(EXIT_FAILURE);
	}


	private:
		
		int refs[10];//init to 0s
		std::string frames[10];//init to "empty". real easy to search through.
		bool full;//init to false. gets set to full if find_next_empty_frame() return
		int current;
};

void fill_pages(std::vector<std::string> &pages){
	std::string temp; //temp string cause I'm bad at C style code
	std::fstream pagefile;
	pagefile.open("requests");
	if(pagefile.is_open()){
		while(!pagefile.eof()){
		pagefile >> temp;
		pages.push_back(temp);
		}
	}
	else{
		std::cout<<"Pages file didn't open correctly, bailing out"<<std::endl;
	}
	pagefile.close(); //tidy up a bit

	//I'm bad at reading files. I always end up with a duplicate element at the end.
	//I always just delete the last one, and move on in life.
	//If you can see where I go wrong I'd love to know.
	//Seriously. Please tell me.
	pages.pop_back();
}

//dear god this might just be functional
#endif
