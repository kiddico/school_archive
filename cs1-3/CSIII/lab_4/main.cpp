/*
	Nick Chirico
	2/19/16
	Mikhail Nesterenko / Jordan Adamek
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

/*
	I know we were kind of expected to reuse the wordoccurence thing to some degree
	I thought that was kinda boring, and I wanted to play with vectors
	So the logic is completely different! Yay!
	also like... waaaaayyy overkill.
*/

using std::cout; using std::endl;
using std::vector; using std::list; using std::string;
void getFirstLast(string,vector<string>&);
void prettyOutput(vector<vector<vector<string>>>&,list<vector<string>>,vector<string>&,int,int); // shhhhhhh

int main(int argc,char** argv){
	if(argc < 2){
		cout<<"Please pass the filenames with students to this program"<<endl;
		return 1;
	}
	vector<string> classnames;
	for(int i = 1; i < argc; i++){
		string temp = argv[i];
		size_t dot_loc = temp.find_last_of(".");
		classnames.push_back(temp.substr(0,dot_loc));
	}
	std::ifstream file_stream;
	/*
	   Deep breath. This is more reasonable than it seems.
	   the first vector is the roster its self. the next is each student on the roster
	   the next is the first and last name of said person.
	   I had it as an array with 2 elements, but holy crap does that get really weird really fast.
	   the reason I even need 2 elements for each person is to split the names (see below)
	*/
	vector<vector<vector<string>>> class_rosters;
	list<vector<string>> students;
	// speaking of spliting the names I need to keep track of the longest
	// that way I can do spacing magic later.
	int first_longest, last_longest;
	first_longest=last_longest=0;
	string first_name,last_name,full_name;
	vector<string> split_name;

	for( size_t i = 1; i < argc-1 ; i++ ){
		file_stream.open(argv[i]);
		if(!file_stream){
			cout<<argv[i]<<" not opened properly, did you type it right?"<<endl;
			return 1;
		}
		// add a new roster to the list
		vector<vector<string>> temp;
		class_rosters.push_back(temp);

		while( getline( file_stream, full_name) ){
			getFirstLast(full_name,split_name);
			// Keeping track of the length of the longest names
			if( split_name[0].size()>first_longest )
				first_longest=split_name[0].size();
			if( split_name[1].size()>last_longest )
				last_longest=split_name[1].size();
			class_rosters[i-1].push_back(split_name);
			students.push_back(split_name); // don't worry, we fix it later.
		}
		file_stream.close(); // Yeah, you do in fact need to close it before you open another. stupid.
	}
	file_stream.open("dropouts.txt");
	// Now for the dropouts
	while(getline(file_stream,full_name)){
		for(size_t i = 0;i < class_rosters.size(); i++){
			getFirstLast(full_name,split_name);
			auto iter=std::find(std::begin(class_rosters[i]),std::end(class_rosters[i]),split_name);
			auto student_iter=std::find(std::begin(students),std::end(students),split_name);
				if(iter!=class_rosters[i].end()){
				class_rosters[i].erase(iter);
			}
			if(student_iter!=std::end(students)){
				students.erase(student_iter);
			}
		}
	}
	//students.unique(); //get rid of anyone on multiple rosters
	// for some reason that's not actually working... cool. I assume it's not great at comparing vectors of strings...
	list<vector<string>> unique_students;
	for(auto student: students){
		auto student_iter=std::find(std::begin(unique_students),std::end(unique_students),student);
		if(student_iter==std::end(std::move(unique_students))){
			unique_students.push_back(student);
		}
	}
	// Now to display things
	prettyOutput(class_rosters, unique_students, classnames,first_longest,last_longest);
} // wooh! time for some snacks!

// Name says it all. Makes it look nice.
void prettyOutput(vector<vector<vector<string>>>& rosters,list<vector<string>> students,vector<string>& classnames, int f_long,int l_long){ // That header makes me want to vomit
	std::cout<<"First Name\tLast Name\tCourses Enrolled"<<endl;
	for(const auto& student: students ){ // this feels so python-y! I love it.
		string classes;
		for(int i=0; i < classnames.size(); i++ ){
			if(std::find(std::begin(rosters[i]),std::end(rosters[i]),student)!=std::end(rosters[i]))
				classes+=classnames[i]+" ";
		}
		// This is when I can actually make use of that length and name splitting BS I spent so much time on.
		string f_space(f_long-student[0].size(),' ');
		string l_space(l_long-student[1].size(),' ');
		cout<<student[0]<<f_space<<"\t"<<student[1]<<l_space<<"\t"<<classes<<endl;
	}
}

// This operates a lot like get line. You give it something to pull from, and some where to put it after.
void getFirstLast(string full_name, vector<string>& split_name){
	split_name.clear();
	// first go through the list to find first whitespace character
	size_t end_of_fname=0;
	for(size_t i = 0; i < full_name.size(); i ++){
		if( std::isspace(full_name[i]) ){
			end_of_fname=i;
			i=full_name.size();
		}
	}
	// removes whitespace with algorithms magic
	// you can thank maletic for teaching us that inlined function crap
	full_name.erase(	std::remove_if( full_name.begin(), // remove from here...
						full_name.end(), // to here
						[](char x){return std::isspace(x);} ), // if it's a space
						full_name.end()); // and do so from start to finish
	split_name.push_back(full_name.substr(0,end_of_fname));
	split_name.push_back(full_name.substr(end_of_fname,full_name.size()+1));
}
