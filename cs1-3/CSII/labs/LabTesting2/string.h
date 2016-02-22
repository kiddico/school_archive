#ifndef JM_NEWSTR_H_
#define JM_NEWSTR_H_

//File:        string.h   
//       
//Version:     5.0
//Date:        1/26/2012 - Current Version Kent State University
//Creation:    10/08/1996 - Version 1.0 Wayne State University 

//Author:      Dr. J. Maletic
//
//Description: Class definition for a String.
//
//
//  Class: String 
//
//  Defines a character String data type with associated operators.
//  Examples:  String a;              //of capacity DEFAULT_STRING_CAPACITY
//             String b(20);          //of capacity 20
//             String c(300) = "abc"; //of capacity 300 with init "abc"
//
//  - Strings are indexed from 0 to capacity-1 of char.
//  - a = ""; assigns a to the empty String.
//  - Exceptions are defined for the class.


#include <iostream>
#include <cstdlib>

const int DEFAULT_STRING_CAPACITY = 256;

////////////////////////////////////////////////////
// CLASS INV: 0 < capacity &&
//            length() <= capacity-1  && 
//            str[length()] == 0
//            
class String {
public: 
            String        (); 
            String        (const char*); 
            String        (const char);                       
    String& operator=     (String);                         //Assignment Copy.    

    int     length        ()                        const; 
    bool    operator==    (const String&)           const; 

    String  operator+     (const String&)           const; // Concatenation.
    String& operator+=    (const String&);

    String  substr       (int, int)                 const;
        
protected:  
    char    str[DEFAULT_STRING_CAPACITY];  
};

std::ostream& operator<<(std::ostream&, const String&);

#endif

