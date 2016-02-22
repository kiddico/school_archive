#include <iostream>
#include "string.hpp"
#include <fstream>
#include <cstdlib>
int main(int argc,char** argv){
	//uses the command line to get the requested I/O files
	std::fstream input;
	input.open(argv[3]);
	std::ofstream output;
	output.open(argv[4]);
	//corrctly assigns the column values as ints instead of strings
	//(as they were provided)
	int column_one=atoi(argv[1]);
	int column_two=atoi(argv[2]);
	//the two strings used to create a line
	String line;
	String word;
	String spaces;
	for(int i=0;i<column_one;++i){
	spaces=spaces+' ';
	}
	int width=column_two-column_one;
	while(!input.eof()){
		word=getWord(input);
		if(line.length()+word.length()+1<=width)
			line=line+' '+word;
		else{
			line.justify(width);
			line=line+'\n';
			//std::cout<<line<<std::endl;
			//For some reason the spaces don't go in sometimes.
			//I really don't know why
			output<<spaces<<line;
			line=word;
		}
	}
		output<<spaces<<line;

}
