//This Program takes info from a database
//and puts it in a check
//Nicholas Chirico
//3.3.14 CSI Section 3
//My Original code (which I reused in this) is pretty terrible
//I didn't make it much better this time around
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using std::fstream;
using namespace std;
void insert(string&,string&,string&,string&,string&,string&,string&);
void makelines(string&,string&,string&,string&,string&,string&,string&,string&,string&,string&,string&);
string makedollars(string&);

int main(){
string line1,line2,line3,date,name1,name2,payee1,payee2,dollarstring,dollars,cents;
insert(date,name1,name2,payee1,payee2,dollars,cents);
dollarstring=makedollars(dollars);
makelines(date,name1,name2,payee1,payee2,dollars,cents,line1,line2,line3,dollarstring);

ofstream finish;
	finish.open("check.txt");
	finish<<"Your Check"<<endl<<endl<<line1<<endl<<line2<<endl<<line3;
    finish.close();
}

//gets all of the numbers from the database and puts them in their respective variable
void insert(string& date,string& name1,string& name2,string& payee1,string& payee2,string& dollars,string& cents){
string trash=" ";
ifstream input;
input.open("database.txt");
input>>trash>>date>>trash>>name1>>name2>>trash>>trash>>dollars>>trash>>cents>>trash>>payee1>>payee2;
input.close();
}

//this smooshes all the lines together
void makelines(string& date,string& name1,string& name2,string& payee1,string& payee2,string& dollars,string& cents,string& line1,string& line2,string& line3,string& dollarstring){
	int spacing,length;
	line1.append(name1);
	line1.append(" ");
	line1.append(name2);
	length=line1.size();
	spacing=70-length;
	line1.append(spacing,' ');
	line1.append(date);

	string money;
	line2="Pay to "+payee1+" "+payee2;
	length=line2.size();
	spacing=70-length;
	line2.append(spacing,' ');
	money=dollars+"."+cents;
	line2.append(money);

	line3=dollarstring;
	line3.append(" and ");
	line3.append(cents);
	line3.append("/100");
	length=line3.size();
	spacing=70-length;
	line3.append(spacing,' ');
	line3.append("dollars");
}

//this convers the string dollars into its wtritten out form.
string makedollars(string& dollars){

int first, second;
string dollars1,dollars2,num;
dollars1=dollars.substr(0,1);
dollars2=dollars.substr(1,1);
first=atoi(dollars1.c_str());
second=atoi(dollars2.c_str());
  if (first == 1) switch (second){
	
	case 1:
	    num="Eleven";
	    break;
	case 2:
	    num="Twelve";
	    break;
	case 3:
	    num="Thirteen";
	    break;
	case 4:
	    num="Fourteen";
	    break;
	case 5:
	    num="Fifteen";
	    break;
	case 6:
	    num="Sixteen";
	    break;
	case 7:
	    num="Seventeen";
	    break;
	case 8:
	    num="Eighteen";
	    break;
	case 9:
	    num="Nineteen";
	    break;
	case 0:
	    num="Ten";
	    break;
	}
  else { switch (first){
	case 2:
	    num="Twenty-";
	    break;
	case 3:
	    num="Thirty-";
	    break;
	case 4:
	    num="Fourty-";
	    break;
	case 5:
	    num="Fifty-";
	    break;
	case 6:
	    num="Sixty-";
	    break;
	case 7:
	    num="Seventy-";
	    break;
	case 8:
	    num="Eighty-";
	    break;
	case 9:
	    num="Ninety-";
	    break;
	}
  switch (second){
  case 1:
	    num.append("One");
	    break;
	case 2:
	    num.append("Two");
	    break;
	case 3:
	    num.append("Three");
	    break;
	case 4:
	    num.append("Four");
	    break;
	case 5:
	    num.append("Five");
	    break;
	case 6:
	    num.append("Six");
	    break;
	case 7:
	    num.append("Seven");
	    break;
	case 8:
	    num.append("Eight");
	    break;
	case 9:
	    num.append("Nine");
	    break;
  }
  }
  return num;
}