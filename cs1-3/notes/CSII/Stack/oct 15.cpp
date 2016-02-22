//Convert from infix to either post or pre
//expr is a fully () infix (correct) expression
////////////
//postfix!
////////////
    stack s 
    while(not done with expr){
        t=nexttoken(expr);
        if(t==')'){
            rhs=s.pop();
            op=s.pop();
            lhs=s.pop();
            s.push(lhs+rhs+op);
        }
        else{
            if(t!='(')
                s.push(t);
        }
    TOS is postfix expr
    }

//prefix is the same but the line  "s.push(lhs+rhs+op);" becomes  s.push(op+lhs+rhs);

//Queue-first in first out
/*
enqueue-add element the the end of queue
dequeue-remove element from beginning(front) of queue

instead of thinking linearly things circularly
"Circular Queue"

*/

//now to implememnt one!!

//queue.hpp

const int QSIZE=20;

template <typename T>
class Queue{
    private:
        int front, back;
        bool empty;
        T q[QSIZE];
    public:
    Queue():front(0),back(0),empty(true){};
    bool isEmtpy()const{return empty;}
    bool isFull()const{return (front==back)&&!empty};
    T dequeue();
    void enqueue(const T&);
}

//cpp!

template <typename T>
    void Queue<T>::enqueue(const T& x){
        assert(!isfull());
        q[back]=x;
        back=(back+1)%QSIZE;
        empty=false;
    }

template <typename T>
    T Queue<T>::dequeue(){
        assert(!empty);
        T result=q[front];
        front=(front+1)%QSIZE;
        if(front==back)
            empty=true;
        return result;
    }

int main(){
    Queue<int> Q;
    Q.enqueue(2);
    Q.enqueue(3);
    Q.dequeue();
}



/////////////////////////////////
//Linked lists
/////////////////////////////////

template <typename T>
    class node{
        public:
            T data;
            node<T> *next;
        ////////Constructor funcs
            node():next(0){};
            node(const T& x):data(x),next(0){};
    }


//inside of main
node int *ptr=0;
prt=new node<int>(5);
//create anoother node and point the old one at it
ptr->next=new node<int>(10);
//lol another
//(*((*ptr).next)).next=new node <int>(20);
ptr->next->next=new node <int>(20);

//if we do:
ptr=0;
//lol the memory leaks! oh lawdy!
//to deallocate:
delete ptr->next->next;
delete ptr->next;
delete ptr;
ptr=0;
//very simple as you can clearly see