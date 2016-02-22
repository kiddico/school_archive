//Yeahhhhhhh
//I need a nap

//Pointers point down from top of stack

//////////////////////////////////////////////////////////////////////////////////
//Stack class
//class inv TOS->A->b->...->bottom->NULL

template <typename T>
    class Stack{
    private:
        node <T> *TOS;
    public:
    Stack():TOS(0){};
    ~Stack();
    Stack(const stack<T>&);
    void swap(Stack<T>&);
    Stack<T> operator=(stack<T> RHS){
    swap(rhs);return *this;}//what the hell is going on here?
    bool isEmpty()const{return TOS==0;}
    bool isFull()const;//when we run out of heap space then it's full
    //now we need push and pop
    T pop();
    void push(const T&);
}

///////////////////////////////////////////////////////////////////
//here is the node class from thew other day. for reference
///////////////////////////////////////////////////////////////////
template <typename T>
    class node{
        public:
            T data;
            node<T> *next;
        ////////Constructor funcs
            node():next(0){};
            node(const T& x):data(x),next(0){};
    }
///////////////////////////////////////////////////////////////////
//end of node class
///////////////////////////////////////////////////////////////////


//must have #include <new>
template <typename T>
bool Stack<T>::isFull(){
    node<T> *temp=new (nothrow)node<T>():
    if(tmp==0)
        return true;
    delete temp;
    return false;
}
//////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////

//push and pop first
//for push we need to make sure it works for both the empty case and the non empty case

template <typename T>
T Stack<T>::pop(){
    assert(TOS!=0);
    T result=TOS->data;
    node<T> *tmp=TOS;
    TOS=TOS->next;//OH ok. TOS is a pointer so we point it to next, then delete the tmp that points to the old TOS
    delete tmp;//gotcha
    return result;
}

//now for push


///////////////////////////////////////////////////////////////////
//wow these things make sense!
//my education has done something!!
///////////////////////////////////////////////////////////////////

template <typename T>
void Stack::push(const T& x){
    assert(!isFull());//That would be a stack overflow
    node <T> *tmp=new node <T> (x);
    tmp->next=TOS;
    TOS=tmp;
}

//now for a destructor
//Just loops till TOS points to zero
template <typename T>
Stack<T>::~Stack(){
    while(TOS!=0){          //only stops when TOS points nowhere aka there are no nodes to be heard of
        node<T> *temp=TOS;  // a temp pointer to a node is made and set to TOS
        TOS=TOS->next;      //TOS is set to the next in line
        delete temp;        //the temp goes poof
    }
}//this is very simple yet suprisingly complex. Ok not all that complex but still.

template <typename T>
    Stack<T>::Stack(const Stack<T>& actual){
        node<T> *bottom=0;
        *temp=actual.TOS;
        TOS=0;
        //just gonna find the bottom now
        while(temp1=0){
            if(bottom==0){
                TOS=new node<T>(temp->data);
                bottom->TOS;
            }
            else{
                bottom->next=new node <T>(temp->data);
                bottom=bottom->next;
            }
            temp=temp->next;
        }
    }//does there need to be a return anywhere? Or am I just dumb?
     //Turns out I'm just dumb. I checked assembler lab (which we know works) and this is how I did it...
     //granted I copied it from here so that's not too much of an argument.
     //But it does work so who cares?

//just flip flops the TOS pointers, everything else stays as is
//this is why linked lists are kinda the shit
//or whatever these are. node things that consist of far too many pointers.
template <typename T>
void Stack<T>::swap(Stack<T>& x){
    node<T> *temp=x.TOS;
    x.TOS=TOS:
    TOS=temp;
}


//////////////////////////////////////////////////////////////////////////////////
//inside of main
void foo(stack<int> x){

}

int main(){
    Stack<int> S1;
    foo(S1);
    
}
//thank god we included this. I was soooooo confused before.
////asshole