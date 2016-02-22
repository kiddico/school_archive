// Nicholas Chirico
// 23/1/16
// Lab 1
// CS 44001 Mihail Nesterenko / Jordan Adamek

#include <iostream>
#include <string>
#include <fstream>
using std::cout;using std::cerr;using std::endl;using std::string;

void loudmouth(char**,string[],int,int);     // Used to output things to console
bool fill_lines(std::ifstream[], string[]);  // fills up string vars with lines from the files

int main(int argc, char* argv[]){

	// let's start off easy and check command line arguments
	if( argc != 3 ){
		cerr<<"At least 2 command line arguments required."<<endl;
		cerr<<"One for each file to compare"<<endl;
		cerr<<"Try something like 'diff file1 file2'"<<endl;
		return 1;
	}

	/*
		Twice in this lab I use raw arrays.
		I would use an appropriate fancy container, but none seem better than just an array.
		We'll never be opening more than two files/streams.
		So why not use an array? ( the only reasonable answer would be "vectors are fun" )
		Another may just be why a container at all? I just think it's tidy...
	*/

	// Now to open the streams up
	std::ifstream streams[2];
	streams[0].open(argv[1]);
	streams[1].open(argv[2]);
	//Verify that things are in fact open.
	if(!streams[0] || !streams[1]){
		cerr<<"Files not opening properly. Verify the correct file names are being passed, and rerun the program."<<endl;
		cerr<<"The regular usage is 'diff file1 file2'"<<endl;
		return 1;
	}

	// holds lines until next getline
	string line[2];
	// the magic while loop obfuscates the line #
	int line_number=0; 
	// Calcualtes the number of spaces we'll need to add later
	int extra_spaces=std::char_traits<char>::length(argv[1])+5;

	// This will keep going as long as at least one file has another line
	while(fill_lines(streams,line)){
		line_number++;
		if( line[0].compare(line[1]) != 0 ){
			// this next line makes it so if the lines are different lengths
			// when we reset i it won't just keep going, and get stuck in a loop
			int larger_length = std::max(line[0].size(),line[1].size());
			for(int i = 0; i < larger_length; i++){
				if( line[0][i] != line[1][i] ){
					loudmouth(argv,line,extra_spaces+i,line_number);
					i = larger_length;
				}
			}
		}
	}


	// farewell
	streams[0].close();
	streams[1].close();
}



// the only one here that says anything
void loudmouth(char** argv, string line[], int extra_spaces, int line_number){
	cout<<argv[1]<<": "<<line_number<<": "<<line[0]<<endl;
	cout<<argv[2]<<": "<<line_number<<": "<<line[1]<<endl;
	string spaces(extra_spaces,' ');
	cout<<spaces<<"^"<<endl;
}

// I was having lots of inconsistency if there was a line in one file, and not another.
// So I decided to remove the functionality from the logic
// Like getline this returns true if things were 'successful'
// In this case that just means either line got filled.
bool fill_lines(std::ifstream streams[], string line[]){
	getline(streams[0],line[0]);
	getline(streams[1],line[1]);
	if( ( line[0].size() < 1 ) && ( line[1].size() < 1 ) )
		return 0;
	return 1;
}
