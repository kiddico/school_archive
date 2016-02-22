#include <iostream>
#include "collection.h"
#include <string>

int main(){
	Collection<int> lol;
	lol.addItem(1);
	lol.addItem(2);
	lol.addItem(3);
	lol.printCollection();
	lol.removeItem(2);
	lol.printCollection();
	std::cout<<lol.lastItem()<<std::endl;

	{
		Collection<char> lolz;
		lolz.addItem('l');
		lolz.addItem('o');
		lolz.addItem('l');
		lolz.addItem('z');
		lolz.printCollection();
	}

}
