
#ifndef CS23001_P2_STRING_INTERFACE_HPP
#define CS23001_P2_STRING_INTERFACE_HPP

#include <iostream>

const int DEFAULT_STRING_CAPACITY = 256;

class String {
public: 
            String        ();               
            String        (char);
            String        (const char*);           
            String        (int, const char*);               
            String        (int);                            
            String        (const String&);                  
            ~String       ();                               
    String& operator=     (String);                         
    void    swap          (String&);                        
    void    resetCapacity (int);                            

    char&   operator[]    (int);                            
    char    operator[]    (int)                     const;  
    int     capacity      ()                        const;
    int     length        ()                        const; 
    bool    operator==    (const String&)           const; 
    bool    operator<     (const String&)           const;
    String  operator+     (const String&)           const;
	String substr(int,int);
	int findchar(char);
	int findstr(String);
	int nextblank(int);
    int nextchar(int);
	void justify(int);
	void insert(char,int);
	void insertStr(String,int);
	friend std::istream& operator>>(std::istream&, String&);
    friend  std::ostream& operator<<(std::ostream&, const String&);
private:
    char *s;
    int  Capacity;
};


String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

String getWord(std::istream&);
#endif

