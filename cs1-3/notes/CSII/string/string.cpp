#include "string.h"
string::string(){
    s[0]=0;
}
string::string(char ch){
    s[0]=ch;
    s[1]=0;
}
//hey fucker use this in the bigint project for char
string::(const char str[]){
    int i=0;
    while(str[i]!=0){
        s[i]=str[i];
        i++;
        if(i>STRING_CAPACITY-1)
            break;//oh my god really? so ugly.
    }
    
    /*or instead of while....
    while((str[i]!=0)&&i<STRING_CAPACITY-1)){}
    hey! he fixed it!
    */
    
    s[i]=0;
}

// REQUIRES
//ENSURES: returns length of the string
int string::length(){
    int len=0;
    while(s[len]!=0)++len;
    return len;
}

char string::operator [](int i)const{
    assert(i>=0);
    assert(i<length());
    return s[i];
}   
char& string::operator[](int i){
    assert(i>=0);
    assert(i<length());
    return a[i];
}
//even if there wasn't a const ^^^^ version things would still work.
//but why const then?
//if the string itself is constant...
if you have VVVV
string string::operator + (const string& rhs)const{
   // rhs[i]; //would shit out an error.
    //this is cause a const method can only call a const method
    //pretend all this is gone
    string result(s);
    int offset=length();
    while(rhs.s[i]!=0){
        result.s[offset+i]=rhs.s[1];
        ++i;
    }
    result.s[offset+i]=0;
    return result;
}