//C++ Standard Library
//Generic Everything
////any type
////algorithms library
//Important b/c
////Protmotes using the right tool for the job
////good style/use the language how it was meant to be used

//Iterators
////Abstraction over accessing members of a sequesnce 

/*
//std::vector<int> vec;
//std::vetor<int>::iterator it=vec.begin();
//or
//std::vetor<int>::iterator it=vec.end();
*/

//STL Containers
////List,vector,deque,array(c++11)
////Set/map
////unordered set/map
////stack,queue,priority queue

////Deque////"double ended queue"////
//pretty much vecotr, but managed different in memory.
//vect is continuous in memory, 
//but deque is defined as pages in memory.
//several sets of vectos with pointers between them
//random access in constant time
//don't need to have it all in a line to have it work.
//better for your poor OS
//standard says you should prefer vector over deque


////<Array>////
//allows you to passarrays as value

//Set and Map//
//SET can only have one unique of each type of object
//{1,2,3,4}, if you try to insert another 2, it'll just say the same.
//good for scenarios where duplicates aren't wanted
//MAP
//like dictionary in c#
//has a key, and a value
//like a student ID and student namee
/*
 KEY   ,Value
[810002,bob]
[810003,sam]
key is unique,value isn't necessarily
code:
std::map<int,std::string> mp;
mp find(810003);//sam
*/

//PAIR
/*
std::pair<int,string>P;
p.first==810002;
p.second=="sam";
*/
//Unordered map and set are just that, they use hash tables

//List based vs array based.
//random access/searching/deleting/insertion/deletion
/*array access is constant time
random access is array like
merge sort an array
[3 , 1 , 2 , 0]
       |
[3][1]  [2][0]
[1,3]   [0,2]
[0,1,2,3]
now to search that
for 2
[0 , 1 , 2 , 3]
       |
        [2,3]
        found it
*/
//list is good for inserting shit everywhere
//array is better for sorting and searching

//Memory management

////////////////////////
//Algorithms
//////
//Function pointers
//we'll do this in lab so I'm not gonna write it down
//////





