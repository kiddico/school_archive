/*
	Nick Chirico
	EasyIO - File Stuffs
	Last Updated : 10/8/15
*/

#ifndef STRD_HPP
#define STRD_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class writef {
		//here begins the madness
		friend std::istream& operator>>(std::istream&,writef&);
		template <typename T>
		friend void operator<<(writef&,T);
		public:
		//constructor assigns filename and opens/assigns stream
		writef(std::string file){
			orig=file;
			streams.insert(std::make_pair(file,new std::fstream(file.c_str(),std::fstream::out)));
		}
		
		~writef(){
			std::map<std::string, std::fstream*>::iterator iter;
			for(iter=streams.begin();iter!=streams.end();++iter){
				iter->second->close();
				delete iter->second;
			}
		}
		template <typename T>
		void write(T object){
			*streams[orig]<<object;
		};
		//streams.insert(std::makepair("file",stream pointer))
		template <typename T>
		void write(T object,std::string newfile){
			std::ofstream temp;
			std::map<std::string,std::fstream*>::iterator search=streams.find(newfile);
			if(search==streams.end()){//in other words: if(it isn't already there)
				streams.insert(std::make_pair(newfile,new std::fstream(newfile.c_str(),std::fstream::out)));
				search = streams.find(newfile);
				*(search->second)<<object;
			}
			else{
				*(search->second)<<object;
			}
		};
	private:
		std::string orig;
		std::map<std::string,std::fstream*> streams;
		std::fstream* strm;
};

class readf{
	//operator overload friend functions
	//makes most stuff work.
	template <typename T>
	friend void operator>>(readf&, T&);
	friend std::ostream& operator<<(std::ostream&,readf&);
	
	public:
		readf(std::string file){
			orig=file;
			streams.insert(std::make_pair(file,new std::fstream(file.c_str(),std::fstream::in)));
		}
		
		~readf(){
			std::map<std::string, std::fstream*>::iterator iter;
			for(iter=streams.begin();iter!=streams.end();++iter){
				iter->second->close();
				delete iter->second;
			}
		}
		//I'm going to be honest I have no idea what the use in this even is
		//it's not used anywhere, but I took the time to make it so I figure it's important or something.
		//whatever I'll keep it.
		void look(){
			std::map<std::string, std::fstream*>::iterator iter;
			for(iter=streams.begin();iter!=streams.end();++iter)
				std::cout<<iter->first;
		}	
		std::string read(std::string newfile){
			std::string temp;
			 std::map<std::string,std::fstream*>::iterator search = streams.find(newfile);
			if(search==streams.end()){//in other words: if(it isn't already there)
				//makes a new pair. the name of the file the stream goes to
			   //and a stream with the appropriate stream pointer
				streams.insert(std::make_pair(newfile,new std::fstream(newfile.c_str(),std::fstream::in)));
				search = streams.find(newfile);
				*(search->second)>>temp;
				//std::cout<<search->second<<std::endl;
				return temp;
				//need to close this later in the destructor
			}
			else{
				*(search->second)>>temp;
				return temp;
			}
		}
//returns string of length zero if EOF
		std::string read(){
			std::string temp;
			*(streams[orig])>>temp;
			return temp;
		}

	private:
		std::string orig;
		std::fstream* strm;
		std::map<std::string,std::fstream*> streams;
};

#endif

//related friend functions
//I've tried these in so many different combinations, it's kind of ridiculous
//Do these operators make sense to you? They do to me...
std::istream& operator>>(std::istream& stream,writef& out){
	std::string temp;
	stream>>temp;
	out.write(temp);
	return stream;
};

template <typename T>
void operator<<(writef& out,T in){
	out.write(in);
};

template <typename T>
void operator>>(readf& from, T& into){
	into = from.read();
};

std::ostream& operator<<(std::ostream& to,readf& in){
	std::string temp = in.read();
	to<<temp;
	return to;
};
