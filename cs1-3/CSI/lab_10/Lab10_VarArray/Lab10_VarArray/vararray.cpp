//These are the functon defenitions
//Nicholas Chirico
//4.1.14 CSI Section 003
#include "vararray.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

void addNumber(int *& arrayPtr, int number, int &size){
	int *tmp;//newSize;
	//pretend all the green bit's aren't here
	//newSize=size+1;
	tmp=new int[size+1];
	for(int i=0;i<size;i++){
		tmp[i]=arrayPtr[i];
	}
	tmp[size]=number;
	//I'm pretty sure this delets the old array. Not too sure
	//I'll get over it.
	delete [] arrayPtr;
	arrayPtr=tmp;
	++size;
}

void removeNumber(int *& arrayPtr, int number, int &size){
	bool hit=false;
	int nmbr;
	for(int i=0;i<size;i++){
		if(arrayPtr[1]==number)
		{
			hit=true;
			nmbr=i;
			size--;
		}
	}
	if(hit==true){
		int *tmparray=new int[size];
		for(int i=0;i<size+1;i++){
			if(i!=nmbr)
			{
				if(i>nmbr)
					tmparray[i-1]=arrayPtr[i];
				else
					tmparray[i]=arrayPtr[i];
			}
		
		}
		delete []arrayPtr;
		arrayPtr=tmparray;
	}
	else
		cout<<"There were no matches for"<<number<<endl;

}

void copyArray(int *original, int *& copy, int size);

void output(int *arrayPtr, int size);