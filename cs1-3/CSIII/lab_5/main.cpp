#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>
#include <list>

using std::vector; using std::string;
using std::cout; using std::endl;


// way to get split names with only a stream as a parameter.
vector<string> getAndSplit(std::ifstream&); 
struct name_comp{
	bool operator()(const vector<string> &a,const vector<string> &b ){
		return a[0]<b[0];
	}
};

int main(int argc, char** argv){
	if ( argc < 2 ){
		cout<<"Please provide filename with students to this program."<<endl;
			return 1;
	}

	// This will be what we read from files with the whole time
	std::ifstream stream;
	stream.open(argv[argc-1]);//open dropouts.txt
	if (!stream ){
		cout<<"Dropouts file (or last provided file) not opening correctly. Did you spell it correctly?"<<endl;
		return 1;
	}

	// Where we're going to get our drop outs for added 'convenience'.
	vector<vector<string> > dropouts;
	vector<string> to_drop;
	do{
		to_drop = getAndSplit(stream);
		if( to_drop.size() == 2)
			dropouts.push_back(to_drop);
	}
	while( to_drop.size() == 2 );
	stream.close();

	// I hope to got I did that less correctly
	std::map<vector<string>,std::list<string>,name_comp> roster;
	for( size_t i =1; i < argc-1; i++ ){
		stream.open( argv[i] );
		if(!stream){
			cout<<"File \""<<argv[i]<<"\" not opening properly, did you type it right?"<<endl;
			return 1;
		}
		//remove .txt nonsense
		string classname(string(argv[i]).substr(0,string(argv[i]).find_last_of(".")));
		vector<string> temp_name;
		do{
			temp_name = getAndSplit(stream);
			if( ( temp_name.size() == 2 ) && // if we found a name...
				// ...and the name isn't in the dropouts list
				( dropouts.end() == std::find(dropouts.begin(),dropouts.end(),temp_name) ) )
			{
				auto location = roster.find(temp_name);
				if( location != roster.end() ){ // if the student is already on the roster...
					location -> second.push_back(classname);
				}
				else{ // otherwise we need to add them.
					roster.insert(std::make_pair(temp_name,std::list<string>()));
					location = roster.find(temp_name);
					location -> second.push_back(classname);
				}
			}
		}
		while( temp_name.size() == 2);

		stream.close();
	}

	//I've learned my lesson. Get name length after we're done. Not during.
	int f_len=0,l_len=0;
	for( auto student:roster ){
		if( student.first[0].size() > l_len )
			l_len = student.first[0].size();
		if( student.first[1].size() > f_len )
			f_len = student.first[1].size();
	}
	
	cout<<"Last Name\tFirst Name\tCourse Name"<<endl<<endl;
	for(auto student: roster){
		string f_spaces(f_len-student.first[1].size(),' ');
		string l_spaces(l_len-student.first[0].size(),' ');
		cout<<student.first[0]<<l_spaces<<"\t"<<student.first[1]<<f_spaces<<"\t";
		for(auto course: student.second){
			cout<<course<<" ";
		}
		cout<<endl;
	}

}

// Will return a vector of length 2
// any other length means it failed and we're at the end of the file.
vector<string> getAndSplit(std::ifstream& stream){
	vector<string> temp;
	string temp_str;
	if( getline(stream, temp_str) ){
		size_t end_of_fname=0;
		for(size_t i = 0; i < temp_str.size(); i++){
			if( std::isspace(temp_str[i]) ){
				end_of_fname=i;
				i=temp_str.size();
			}
		}
		temp_str.erase( std::remove_if( temp_str.begin(),
										temp_str.end(),
										[](char x){return std::isspace(x);}),
										temp_str.end());// New end of range is given, but all iterators are invalidated, so it doesn't do much.
		temp.push_back(temp_str.substr(end_of_fname,temp_str.size()+1));
		temp.push_back(temp_str.substr(0,end_of_fname));
	}
	else{
		return temp; // return vecotr of size 1. will let calling logic know what to do
	}
	return temp;
}

