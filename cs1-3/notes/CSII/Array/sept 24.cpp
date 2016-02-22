int *ptr = new int[10];
*ptr=10;
    assigns ptr[0] to 10
*(ptr+1)=20;
    assigns ptr[1] to 20



time to build and adt with a dynamic array
ok. 
goal array a[20]
a[0]=10
a.reset capacity(40);
a.capacity(); //retuns cap of a

we alsso want to do b=a
but that just moves the contents of a over to b.
    which is just a pointer....
    so now b points to a and b leaked memory
    
assignment-coppy semantics
    ok so this just means we have to make outr own assignment.
    that's cool

void fo(array x){
    
}

array b(20);
foo(b);
copy construction
    also needa  destructor
    
ok three new things
    assignment constructor
    copy constructor
    destructor

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class inv
//this is the point
//ptr->int[cap]; Kapish?
class Array{
    public:
            Array:ptr(0),cap(0){};
            Array(int); //for things like Array a(20); that has 20 elements
            Array(const Array&);//this i the copy constructor. it always looks like that
            //Array( Array);//would make in infinite loop. so don't use this!!!!
            ~Array();//destructor doesn't return anything, doesn't take parameters... just... chills.
            ///can't call exit in destructor, because that calls the destructor, which calls exit... which calls the destructor
            //old way for copy first
            Array& operator =(const Array&);//not a const method, but it does have a const parameter, yup.
            int operator[](int)const;
            int& operator[](int);
            int capacity()const{return cap;}
            void resetCapacity(int);
            void swap(Array&);
    private:
            int *ptr; //actually bit
            itn cap; //capacity
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//array.cpp
Array::Array(int n){
    //preconditions
    //n>0
    assert(n>0);
    cap=n;
    ptr=new int[cap];
    //pretty striaght forward
}
int Array::operator [](int i)const;{
    //has to actually be part of array
    assert((i>=0)&&(i<cap));
    return ptr[i];//or *(ptr+i)
}
//destructor time!!
Array::~Array(){
    delete[] ptr;//if you use brackets to allocate it you must use brackets to de-allocae it
}

Array& Array::operator=(const Array& rhs){
    if(ptr!=lhs.ptr){
    delete[] ptr;
    cap=rhs.cap;
    ptr=new int[cap];
    for(int i=0;i<cap;++i)
            ptr[i]=rhs.ptr[i];
        
    }
    return *this;
    //////////this is a pointer to the object you called the method on
}
Array::Array(const Array& actual){
    cap=actual.cap;
    ptr=new int[cap];
    for(int i=0;i<cap;++i)
        ptr[i]=actual.ptr[i];
    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    Array a(20), b(30);
    foo(a);
    
}
//^^^^here the compiler checks for destructors
//then it deallocates the object itself

void foo(Array x){
    cout<<x[i];
}//here we leave the scope of x
//allocated heap is deleted
//then the object is deleted, just liek it is in main.

consider this main

