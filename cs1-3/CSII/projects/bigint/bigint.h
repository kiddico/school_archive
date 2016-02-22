#include <iostream>
const int SIZE = 500;
class bigint{
public:
	bigint();
	bigint(int);
	bigint(const char *);
	//Just used to debug early on	
	void readout();
	int getval(int);
	void output(std::ostream&);
	bool compare(bigint);
	bool operator == (int);
	bool operator == (bigint &);
	bool operator == (char*);
	int operator [] (int);
	bigint operator + (bigint);
	bigint operator * (bigint);
	friend std::ostream& operator<<(std::ostream&,bigint&);
	friend std::istream& operator>>(std::istream&,bigint&);
	void shiftleft (int);
	void timesDigit(int);
private:
	int arr [SIZE];
	int digits;
};
