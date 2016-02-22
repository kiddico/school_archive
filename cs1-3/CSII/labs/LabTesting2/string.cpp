//File:        string.cpp   
//       
//Version:     5.0
//Date:        1/25/2012 - Current Version 
//Creation:    10/08/1996 - Version 1.0 Wayne State University
//             Modified at Kent State University, University of Memphis
//
//Author:      Dr. J. Maletic
//
//Description: -Implementation of String class member functions. 
//             -Exception handlers for String
//             


#include "string.h"


//////////////////////////////////////////////////////////
// Default Constructor
// Default: n == DEFAULT_STRING_CAPACITY
// POST: str[0] == 0 && Capacity = n 
//
String::String() { 
      str[0] = 0;
} 


////////////////////////////////////////////////////////// 
// PRE:  s->char[] && s->char[length] == 0
// POST: str == s && Capacity = DEFAULT_STRING_CAPACITY
// Example:  String("abcd")
//
String::String(const char *s) { 
    int i = 0;
    
    while (s[i] != 0) {
        str[i] = s[i];
        i++;
    }
    str[i] = 0;
} 

//////////////////////////////////////////////////////////
// PRE:  assigned(ch)
// POST: str[0] == ch && str[1] == 0 && Capacity == DEFAULT_STRING_CAPACITY 
//
String::String(char ch) { 
      str[0] = ch;
      str[1] = 0;
} 

//////////////////////////////////////////////////////////
// POST: RetVal == i, where str[i] = 0.
//       The number of charaters in String.
//
inline int String::length() const { 
    int i = 0;  
    while (str[i] != 0) i++;  
    return i;
}
 
//////////////////////////////////////////////////////////
//Equivalence
//Return (String == s)
//
bool String::operator==(const String& rhs)  const {
    int i = 0;  
    while ((str[i] != 0) && (rhs.str[i] != 0)) {
        if (str[i] != rhs.str[i]) return false;
        ++i;
    }
    return (str[i] == 0) && (rhs.str[i] == 0);
}

// POST: Return String s concatentated to the end of String. 
//
String String::operator+(const String& rhs) const { 
    int start = length(), i = 0;
    int len   = start + rhs.length() + 1;
    
    if (len >= DEFAULT_STRING_CAPACITY) exit(1);
    String result(*this);

    while (rhs.str[i] != 0) {
        result.str[start+i] = rhs.str[i];
        ++i;
    }
    result.str[len] = 0;
    return result;
}        

//////////////////////////////////////////////////////////
// Concatenation.
// POST: Return string s concatentated to the end of this. 
//
String& String::operator+=(const String& rhs) { 
    int    start = length(), 
           i = 0;
    int    len = start + rhs.length() + 1;
    if (len > DEFAULT_STRING_CAPACITY) {
      exit(1);
    }

    while (rhs.str[i] != 0)  {
        str[start+i] = rhs.str[i];
        ++i;
    }
    str[len] = 0;
    return *this;
}        



//////////////////////////////////////////////////////////
// PRE:  0 <= start <= end < length
// POST: RetVal == str[start .. end]   
//
String String::substr(int start, int end) const { 
    int len = length();
    if (start < 0) start = 0;
    if (end >= len) end = len - 1;
    String result; 
    for (int i = start; i < end+1; ++i) 
        result.str[i-start] = str[i];
    result.str[end-start+1] = 0;
 	 
  return result;                    
}

//////////////////////////////////////////////////////////
// Output.
//
std::ostream& operator<<(std::ostream& out, const String& s) { 
  out << s;
  return out;
}
