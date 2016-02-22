#include <iostream>
#include <cstring>
#include <map>
#include <unordered_map>
void hello(){std::cout<<"hello world!"<<std::endl;}
void lolz(){std::cout<<"lolololol"<<std::endl;}

void (*fptr)();
int main(int argc,char** argv){

	std::unordered_map<std::string, void (*)()> mp;
	mp.insert(std::make_pair("Function1", &hello));
	mp.insert(std::make_pair("Function2", &lolz));
	
//std::cout<<"lol= "<<mp.find(argv[1])->second<<std::endl;
	
	std::unordered_map<std::string, void (*)()>::iterator it=mp.find(argv[1]);
	
	if(it==mp.end())
		std::cout<<"Hey! That's nt a function ya dumb!"<<std::endl;
	
	else{
		fptr=it->second;
		fptr();
	}
	
}
