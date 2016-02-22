const int STRING_CAPACITY;


class string{
public:
    string();
    string(char);
    string(const char);
    int length()constr;
    char operator[](int)const;
    char& operator[](int);
    string operator +(const string&)const;
    string operator+=(const string&);
    string substring(int,int)const;
    bool operator==(const string&)const;
    bool operator <(const string&) const;
    friend std::ostream& operator<<(std::ostream&,const string&);
    friend std::istream operator >>(std::istream&,string&);
    string operator + (char, const string&);
    string opertaor + (const char[],const string&);
    bool operator == (char, const string&);
    bool operatot == (const char[], const string&);
    bool operator != (cons string&, const string&);
    
private:
    s[STRING_capacity];
}