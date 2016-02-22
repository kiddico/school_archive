//This Program Outputs a Check
//And it does it very badly
//Nicholas Chirico
//2.25.14 CSI Section 003

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using std::fstream;
using namespace std;
void ask(string& date,string& name1,string& name2,string& dollars,string& cents,string& payee1,string& payee2);
void make1(string& name1,string& name2,string& date,string& line1);
void make2(string& payee1,string& payee2,string& dollars,string& cents,string& line2);
string numspell(string& dollars);
void make3(string& dspell,string& cents,string& line3);
int main(){
	string date,name1,name2,payee1,payee2,dstring,line1,line2,line3,dollars,cents,dspell;
	ask(date,name1,name2,dollars,cents,payee1,payee2);
	make1(name1,name2,date,line1);
	make2(payee1,payee2,dollars,cents,line2);
	cout<<line1<<endl<<line2<<endl;
	dspell=numspell(dollars);
	make3(dspell,cents,line3);
	cout<<line3<<endl;
	ofstream finish;
	finish.open("check.txt");
	finish<<"Your Check"<<endl<<endl<<line1<<endl<<line2<<endl<<line3;
    finish.close();
}

void ask(string& date,string& name1,string& name2,string& dollars,string& cents,string& payee1,string& payee2){
	cout<<"Insert Date (month/day/year)"<<endl;
	cin>>date;
	cout<<"Insert Your First then last name"<<endl;
	cin>>name1>>name2;
	cout<<"How many dollars? Also how many cents?"<<endl;
	cin>>dollars>>cents;
	cout<<"Name of Payee"<<endl;
	cin>>payee1>>payee2;
	cout<<endl<<endl<<endl<<endl<<endl;
}

void make1(string& name1,string& name2,string& date, string& line1){
	int spacing,length;
	line1.append(name1);
	line1.append(" ");
	line1.append(name2);
	length=line1.size();
	spacing=70-length;
	line1.append(spacing,' ');
	line1.append(date);
}

void make2(string& payee1,string& payee2,string& dollars,string& cents,string& line2){
	int length,spacing;
	string money;
	line2="Pay to "+payee1+" "+payee2;
	length=line2.size();
	spacing=70-length;
	line2.append(spacing,' ');
	money=dollars+"."+cents;
	line2.append(money);

}

//void make3(string& dollars,string& cents,string& line3){}
string numspell(string& dollars){
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

void make3(string& dspell,string& cents,string& line3){
int length,spacing;
line3=dspell+" and "+cents+"/100";
length=line3.size();
spacing=70-length;
line3.append(spacing,' ');
line3.append("dollars");
}