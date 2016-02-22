// Nick Chirico
// CSIII
// 2/11/16


#ifndef LIST_HPP_
#define LIST_HPP_

template <typename T>
class Collection;

////////////////////////
// Begin Node Class
////////////////////////
template <typename T>
class node{
public:
	node(): next_(nullptr) {}
	node(node<T> *next,node<T> *prev):next_(next),prev_(prev){}
	T getData()const{return data_;}
	void setData(const T& data){data_=data;}
	node<T>* getNext() const;
	node<T>* getPrev() const;
	void setNext(node<T> *const);
	void setPrev(node<T> *const);
private:
	T data_;
	node<T> *next_,*prev_;
};

template <typename T>
node<T>* node<T>::getNext()const{
	return next_;
}

template <typename T>
node<T>* node<T>::getPrev()const{
	return prev_;
}

template<typename T>
void node<T>::setNext(node<T> *const next){
	next_=next;
}

template <typename T>
void node<T>::setPrev(node<T> *const prev){
	prev_=prev;
}

//////////////////////////////
// Begin Collection Class
//////////////////////////////

template <typename T>
class Collection{
	public:
		Collection();
		~Collection();
		Collection(const Collection<T>&);
		Collection<T> operator=(Collection<T>);
		
		void addItem(T);
		void removeItem(T);
		void printCollection();

		T lastItem();
		
		size_t getSize();

	private:
		size_t size_;
		node<T> *head_, *tail_;
};

// Hey future me!
// if you're wondering what's wrong it's cause you need to put
// template <typename T>
// before each function definition. idiot.
template <typename T>
Collection<T>::Collection(){
//	std::cout<<"New Collection!"<<std::endl;
	// safety first children
	head_=nullptr;
	tail_=nullptr;
	size_=0;
}

template <typename T>
Collection<T>::~Collection(){
	// let's break stuff!
	// god I love to break stuff
	node<T> *walker=head_;
	node<T> *tempnext;
	// just step through, and delete each element
	while(walker!=nullptr){
		tempnext=walker->getNext();
		delete walker;
		walker=tempnext;
	}
}

template <typename T>
void Collection<T>::addItem(T new_guy){

	// this means we're in a new list
	if( (head_ == nullptr)  && (tail_ == nullptr) ){
		// make the new node
		node<T> *temp = new node<T>;
		// give new node data
		temp->setData(new_guy);
		// set n/p to nothing, as this node is alone.
		// poor little guy
		temp->setNext(nullptr);
		temp->setPrev(nullptr);
		// set head and tail to temp
		head_=temp;
		tail_=temp;
		// population of oooonnnneeeee
		size_=1;
	}
	
	else if( (head_ != nullptr) && (tail_ != nullptr) ){
		// new node
		node<T> *temp = new node<T>;
		// give the new node some data
		temp->setData(new_guy);
		// set old tail's next to new guy
		tail_->setNext(temp);
		// set new_guy prev to old tail
		temp->setPrev(tail_);
		// make tail the new guy
		tail_=temp;
		// set the new guy's next_ to nullptr
		temp->setNext(nullptr);
		// increase the size, now go home.
		++size_;
	}
	
}

template <typename T>
void Collection<T>::removeItem( T to_remove ){
	node<T> *walker=head_;
	// move pointer until we're at the end, or the element to remove.
	while ( (walker->getData() != to_remove) || (walker == nullptr) ) {
		walker=walker->getNext();
	}
	// here we can either be at the end, or the target.
	// so double check we're not at the end then remove the element.
	if( walker != nullptr ){
		// if we're removing a solo node, then it's n/p are already set to nullptr
		// so we can do the following just fine 

		// handle removing tail
		if(walker==tail_){
			tail_=walker->getPrev();
			tail_->setNext(nullptr);
		}
		//handle removing head
		if(walker==head_){
			head_=walker->getNext();
			head_->setPrev(nullptr);
		}

		// adding prev was a wonderful idea.
		// thanks csii book
		if(walker->getPrev() != nullptr)
			walker->getNext()->setPrev(walker->getPrev());
		if(walker->getNext() != nullptr)
			walker->getPrev()->setNext(walker->getNext());
		// make the size smaller. not sure why I'm bothering. I never use size
		--size_;
		delete walker; // so long, and god speed my friend
	}

}

template <typename T>
void Collection<T>::printCollection(){
	node<T> *walker=head_;
	while( walker!=nullptr ){
		std::cout<<walker->getData()<<" ";
		walker=walker->getNext();
	}
	std::cout<<std::endl;
}

template <typename T>
T Collection<T>::lastItem(){
	return tail_->getData();
}

template <typename T>
size_t Collection<T>::getSize(){
	return size_;
}

// despite help I've still not managed to fix it.
// by the way your eyes will bleed from this copy constructor
template <typename T>
Collection<T>::Collection(const Collection<T>& input){
	node<T> *pinput=input.head_;
	node<T> *pnew=new node<T>;
	node<T> *last=pnew;
	head_=pnew;
	pnew->setPrev(nullptr);
	pnew->setData(pinput->getData());
	size_=input.size_;

	while(pinput->getNext()!=nullptr){ 
		pinput=pinput->getNext();
		pnew=new node<T>;
		pnew->setPrev(last);
		last->setNext(pnew);
		last=pnew;
		pnew->setData(pinput->getData());
		//std::cout<<"ehh: "<<pnew->getData()<<std::endl;
	}
	tail_=pnew;
	pnew->setNext(nullptr);
}


template <typename T>
Collection<T> Collection<T>::operator=(Collection<T> RHS){
	head_=RHS.head_;
	tail_=RHS.tail_;
	// seriously nick. our implementation doesn't use this at all. why keep doing it?
	// idk. it just seems like the right thing to do.
	// don't wanna leave the poor guy out...
	size_=RHS.size_;
	RHS.tail_=nullptr;
	RHS.head_=nullptr;
	RHS.size_=0;
	return *this;
}


#endif // LIST_H_
