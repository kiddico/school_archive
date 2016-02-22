say you use a.swap(b);VVVV

void Array::swap(array& rhs){
    //swap the capcaity
    int temp=rhs.cap;
    rhs.cap=cap;
    cap=temp;
    
    //swap the pointers around
    int *ptemp=rhs.ptr;
    rhs.ptr=ptr;
    ptr=ptemp;
    
}

/////////////////destructor!
Array::~Array(){
    delete[] ptr;
}
/////////////
now to rewite assignment op using swap and copy constructor

Array& Array::operator=(Array rhs){
    //this is already a copy of the RHS not actually rhs.
    swap(rhs);
    return *this;
    //lolz
}

we can use this for this

Array a(20), b(10);
a=b;
//now we have to b's!!

more golden rules
    define destructor
    copy ctor
    assign const copy semanctics
    
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////
    
Say:
    a(10);
    //puts old in new
    a.resetCapacity(20);
    //cuts off a bit
    a.resetCapacity(5);
    
//preconditions
////ptr->int [cap]

//postcondition
////ptr->int[n] && preserves content
reset capacity!
void Array::resetCapacity(int n){
        int *temp=new int [n];
        
        //copy everything from ptr into new temp
        for(int i=0;(i<n)&&(i<cap);++i){
        //stops at the first smaller one
        temp[i]=ptr[i];}
        delete[] ptr;
        ptr=temp;
        cap=n;
}






/////////////////////////////
generics!!!!
templates!!!

    
template <typename T>////T is the template parameter
    void swap(T&a, T&b){
        T temp=a;
        a=b;
        b=temp;
    }
    
   which is the template version of thisVVVV
    it doesn't actually compile it,
    
    
//actual defenition
  void swap(int& a, int& b){
    int tmp=a;
    a=b;
    b=temp;
}  

so imagine this main
    
itn main(){
    int a=5,b=6;
    swap<int>(a,b);
    //cool
    char x='a', y='b';
    swap<char>(x,y);/
    //sooooooo cool!!
    //would even work with
    swap(a,b);
    //it figures it out
}

normally requires copy ctor and assignable


template with 2 types
    template <typename T, typename A>