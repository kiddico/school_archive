// variable size container class implemented with vectors
// Nicholas Chirico
// 4.16.14 CSI Section 003


#ifndef VECTORSOO_H_
#define VECTORSOO_H_

#include <vector>
using std::vector;

class vectorsoo{
public:
  void addNumber(int);    // adds number to the array
  void removeNumber(int); // deletes the number from the array
  void output(void);  // prints the values of the array in sorted order

  int vectorSize(void)const; // returns vector size

  // note that the big three member functions are not needed
  // as vector class handles dynamic allocation properly 
  // by itself

private:
  vector<int> container;
};

#endif /* VECTORSOO_H_ */