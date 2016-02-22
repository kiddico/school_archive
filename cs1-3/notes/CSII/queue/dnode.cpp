So we talked about implementing the stack with a linked list last time I want to do a queue with a linked list

Similar but a queue is easier than the circular boundary queue 

I’m going to use the exact same node class just going to be a node 

Class node{
Public:
Node();
Node(const T&)
Node <T> *next;
T data;

Private:
Node<T> *beginning,
	*ending;
};


We have two pointers beginning and ending for the front and back and that’s all we really need 

//CLASS INV : beginning ->A->B->…x->ending
//
Template<typename T>
Class queue{
Public:
Queue():beginning(0),ending(0){};
Queue(const queue<T> &)//copy const 
~queue();//dest 
Void swap(queue<T>&);//swap
Queue<T>& operator=(queue<T> rhs)
	{swap(rhs); return *this;}
Void enqueue(const T&);
T dequeue();
Bool isEmpty()const {return beginning ==0;};
Bool isFull()const;


So lets do the enqueue and dequeue then we will do the other ones.

Enqueue w eare adding something to the end of this list the only weird thing is if it is empty then we have to set beginning and ending to both point otwards tat new element,  otherwise al lwe hav to do is add this to the end of the qeue and the move the ending.  

//REQUIRES: !isFull && beginning -> A->B->ending
//ensures beginning ->A->B->X -> node(item ->ending
template<typename T>
Void queue<T>::enqueue(const T&){
Assert(!isfull());
//Create a new node and put item in it.
Node<T> *temp = new node <T>(item);

If(beginning ==0)
	Beginning = temp;
Else
	Ending ->next = temp;
Ending = temp;
}//Queues are first in first out 

//Now lets do the dequeue 

//REQUIRES: !isFull && beginning ->A->B->.. ->z ->ending
//ENSURES: beginning -> B ->…->z -> ending
Template<typename T>
T queue<T>::dequeue(){
Assert(!isempty());
T result = beginning -> data; //data is in the node class data and next are both there
Beginning = beginning -> next;

If (if beginning == 0) ending = 0;
Delete temp;//what temp?!
Return result;
}

These are really the only operators, so now lets build our other things we need 
Lets do the destructor first.  

Template<typename T>
Queue <T>::~Queue(){
While(beginning){
Node<T> *temp = beginning;

Beginning = beginning -> next;
Delete temp  temp;
}
}









//copy constructor 
//
//
Template<typename T>
Queue<T>::Queue(const Queue<T>& atual){

Node <T> *temp = actual.beginning;
Beginning = 0; ending = 0;
While(temp !=0){
If(beginning ==0){
	Beginning  new node<T>(temp -> data);
	Ending = beginning;
}else{
	Ending ->next = new node<T>(temp -> data);
	Ending = ending ->next;
}
Temp = temp ->next;
}
}

//So we have a situation like this say we create a queue that isa quque trhat has a beginning and an ending 
Queue<int>x(Q);
Void foo(queue<int> x){
…
}
Int main(){
Queue<int> Q;
Foo(Q);
…	

Data	Next 
-	From the node class 

At the end we have a local variable with a copy of foo inside of it.  

The swap just basically swaps the beginning and ending values 
//swap function 

Template<typename T>
Void queue<T>::swap(Queue<T> & rhs){
Node <T> *temp = rhs.beginning;
Rhs.beginning = beginning
Beginning = temp;
Temp = rhs.ending
Rhs.ending = ending;
Ending  temp;
}

//Assignment
Template<typename T>
Queue<int> x,y;
x.enqueue(5);
x.enqueue(10);
x.enqueue(10);
y.enqueue(10);

y = x;

The stl queue is not that much different from this so that is a reasonably good impe,enmttation of this data structure.  But we didn find some things that are lacking.  We can only add and delete from one end and we can add and delete from another end.  If you think of a more genereric list that you could add and delete from either end or the middle.  

The answer is double lnked lists 

Template<typename T>
Class dnode{
Public:
Dnode():previous(0),next(0){};
Dnode(const T& x):previous(0),next(0),data(x){}
D node<T> *previous,*next;
T data;
}


I’m going to talk about containers or an interator to get through these lists.  It will be our first OO problem.



