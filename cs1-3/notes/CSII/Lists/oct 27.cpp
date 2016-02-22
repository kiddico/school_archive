//Double linked lists
/*
[Data]
[Next]
[Prev]
*/

//To delete a middle link
x->next->prev=x->prev;
x->prev->next=x->next;
delete x;

//to insert
tmp->next=x->next;
tmp->prev=x;
x->next->prev=tmp;
x->next=tmp;

////////////////////////////////////////////
//Make an iterator that allows access to the list, but it's safe
////////////////////////////////////////////
//container class/iterator


//dammit I needed that.
//he decided not to write it :(
template <typename T>
class dnode{
    public
}
//balls to it then
////I got this from that one dude. I put it into oct 22.

//here is the iterator
template <typename T>
class itr{
    private:
        dnode<T> *current;
    public:
        itr():current(0){};
        //I really don't understand this syntax
        //lol ask ben
        ////ok past me here we go.
        ////it's a default constructor that simply sets current to zero.
        ////current in this case is a pointer to nothing.
    
        itr(dnode<T> *ptr=0):current(ptr){};////this I don't fully undertand. what is the "=0" for?
    
        //makes sure current is pointing somewhere, and if it is, points it to the next node
        itr& operator++(){if(current)current=current->next; return *this;}
        //same thing but the other way
        itr& operator--(){if(current)current=current->prev; return *this;}
        
        //it's a little different for post
        //use a dummy int in the parameter
        //it's just for the compiler
        //save original result and then incrememnt
        //this uses the funky constructor
        itr operator++(int){itr<T>original(current);if(currenet)current=current->next; return original;}
        //same old same old
        itr operator--(int){itr<T>original(current);if(currenet)current=current->prev; return original;}
    
        T operator*()const{return current->data;};//why do we need semis on these but not the others?
        T& operator*(){return current->data;};//b/c they're one liners
    //we use this later in list::remove
        dnode<T>* operator->()const{return current;};
        dnode<T>* operator->(){return current};//"kinda dangerous"
                                               ////I like it !
        
        bool opertator==(itr<T> rhs)const{return current==rhs.current;};//yeah by the looks of it it's only for one liners
}


//oh yeah itr is used like this
itr<int> i=l.begin();
++i;
i++;//etc


//these are tightly coupled classes
//they need to be made to work with each other
////////////////////////////////////////////
//this is the list or whatever  
template <typename T>
class List{
    private:
        dnode<T> *begnning, *ending;
    public:
        List():beginning(0),ending(0){};
        ~List();
        List(const List<T>&);
        void swap(List<T>&);
        List<T>& operator=(List<T> rhs){
            swap(rhs);return *this;}
        bool isEmptry()const{return beginning;};
        bool isFull()const;
        int length()const;
        itr<T> begin()const{return itr<T>(beginning);};
        itr<T> end()const{return itr<T>(ending);};//lol he said the semis are just for consistency, don't need em
        //some non const versions
        itr<T> begin(){return itr<T> (begining);};
        T front()const{return begining->data;};
        T back()const{return ending->data;};
        //could write non const of these^^^^^ just return a referance
        ////////////////////////////////////////////
        //other bits
        void insertBefore(const T&,itr<T>);
        void insertAfter(const T&,itr<T>);
        void remove(itr<T>);
        itr<T> operator[](int)const;
        itr<T> operator[](int);
        itr<T> find(const T&) const;
}

//implementation!

template <typename T>
    int List<T>::length()const){
        int len=0;
        itr<T> i=begin();
        while(i!=0){
            ++len;
            ++i;
        }
        return len;
        //cool
        //cool cool cool
    }





//so here is what we can do
list<int> L;
for(itr<int> i=L.begin();i!=0;++i)
    cout<<*i;