// function prototypes to manipulate variable size array
// nick chirico
//4.1.14
#ifndef VARARRAY_H_
#define VARARRAY_H_
// adds "number" to the array pointed to by "arrayPtr" of "size". 
// Note the size of the array is thus increased. 
void addNumber(int *& arrayPtr, int number, int &size);

// removes a "number" from the "arrayPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(int *& arrayPtr, int number, int &size);

// creates a copy of the array
// dynamically allocates an arry, makes "copy" point to it
// then copies contents of the "original" to "copy"
void copyArray(int *original, int *& copy, int size);

// prints the values in "arrayPtr" of "size" in sorted order
void output(int *arrayPtr, int size);
#endif