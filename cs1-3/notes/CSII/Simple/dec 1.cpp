//Exceptions, and stuff
/* NEWS
    Final on monday at 12:30?
    name project 4 profiler
*/

/*
    Exceptions are for exceptional situations; not for control flow or input validation.
    Pretty much a fancy goto. So yeah.
    For emergencies, like poping an empty stack.
    
    if an error is encountered
    -handle locally.
        like if substring was requested past the end of the string, it just sends back to the end of the string.
    -terminate program
        -it's ok right now
        -but not really in the future
    -return a legal value and leave the program in illegal state- lol
    -return a value representing an error
        -every function returns a value
        -like in c a nonzero value represents a value
    -call a function (supplied) in case of an error (error handler)
*/

try{//in here we can throw exceptions
    foo();//assume foo will throw an excpt;
    ....
}
catch(expcetion){
    //handler code
    //jumps straight from the error ro here
}

catch(exception2){
    //could use a rethrow
    rethrow;//cant handle it here so it passes it back up
}
////////
//inside of foo
foo(){
    
    throw excpt;
}


///////his example

bool stack<T>::isFull(){
    try{
        node<T> *ptr=new node<T>();
        delete ptr;
        return false;
    }
    catch(std::badalloc){return true;}//if it doesn't allocate correctly then it returns true for full
}


/*
    building our own exceptions
    
*/

class error{
    public:
        error(std::string fn="",int LN=0)line(LN),file(fn){};//if you pass it something it will replace theose default parameters with what you pass
        virtual std::string message(){return "error: in file "+file+" at line "+itos(line);}//itos is int to string
    protected:
        int lne;
        std::string file;
        //we want to know wheere the error occured. so file and line. 
}
class stackerr :public error{
    public:
        stackerr(string fn="",int LN=0):error(fn,ln){};
        virtual std::string message(){return "Stack error: in file "+file+" at line "+itos(line);}
}

class underflow:public stackerr{
    public:
        underflow(std::string fn="",int LN=0):stackerr(fn,ln){};
        virtual std::string message(){return "Stack underflow: in file "+file+" at line "+itos(line);};
    
}
//musign this in stack's pop 
T stack<T>::pop(){
    if(isEmpty())
        throw underflow(__FILE__,__LINE__);
}

//now inside of main

int main(){
    try{
        stack<int> S;
        S.pop();//this'll throw our exception
    }
    
}

//this will only say error....
catch(error e){
    std::cout<<e.messages<<std::endl;
}

//super duper error
catch(error &e){//remember references are pointers so you can use them to take advantage of pointers
    std::cout<<e.messages<<std::endl;        
}

//could have done
catch(error *e){
    std::cout<<e->message()<<std::endl;    
}


//////////////////////////////
//wonderful new features
class set{
    public:
        set();
        set(std::initializer_list<int>);//gives us set(1,3,2,4,5,6,) and set a={1.4.3.2.5.5}
}

void foo(std::initialize_list<std::string>){}

//then you can call 
foo("joe","jim","jane","lolz");

//r-value reference variables
//this is put in for optimization
//&&//
//r values can only occur on right hand sign of assignment
//l values can be on either side
int a;
a=a;
a=2+3;
//can't do 2+3=10
//now we can define variables that are r values

int a;
int f();
int &r1=a;//so r1 and a are the same thing
int &r2=f();//this is an error, can't have a ref to a function
//this is the new bits
int &&rr1=f();
int &&rr2=a;//this won't work

//now where is this even useful?
std::string& operator= (std::string rhs){
    swap(rhs);
    return *this;
}

std::string a;
a="ABC"+"XY";

//so alternatively you could use
std::string& operator= (std::string&& rhs){//if it's an r value just call it be reference
    swap(rhs);
    return *this;
}
//this is ALLLLLL optimization

//there is a constant expression now
//constexpr
const double minwage=7.95;
constexpr double weekly=minwage*40;
//why would this eb=ven be nice?
constexpr getsize(){return 10};
int table[getsize()];//we couldn't do this with a const int before, but now... yeah. go us

//range based loops
//this is like a for each

int range[5]={0,1,2,3,4};
for(int &x:range) cout<<std::x;//works with any c style array, or anything with begin() and end() and works with an iterator

std::vector<std::string> tbl;
tbl.pushback("sue");
tbl.pushback("fred");
tbl.pushback("joe");
for(std::string &i:tbl) std::cout<<i;
//prints suefredjoe

//AUTO-type inference
//the bomb
auto a=10;//performance hit is pretty high.. not really for this example. that is just done at compile time

//lambda functions- functions without names

//you're going to sort a vector, but the stl vector takes a comparator
//here is the sort being passed, beginning, end, then the sorting style
sort(tbl.begin(),tbl.end(),[](int a,int b){return abs(a)>abs(b);})
//anytime you pass a fucntion pointer you can pass a lambda function
    
//this comes from lambda calculus
    
//shared_ptr and unique_ptr
//automatic garbage collection
