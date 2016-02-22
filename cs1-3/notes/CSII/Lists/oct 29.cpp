//implementation of the list

//plans for main
int main(){
    List<int> L;
    L.insertBefore(5,L.begin());
    L.insertAfter(L,L.end());
    L.remove(L.begin());
    
}


template<typeanem T>
    void List<T>::remove(itr<T> ptr){
        assert(!isEmpty());
        if(begining==ptr)
            begining=begining->next;
        else
            ptr->prev->next=ptr->next;
        if(ending==ptr)
            ending=ending->prev;
        else
            ptr->next->prev=ptr->prev;
        //cant say delete ptr.current
        delete ptr.operator->();
    }
template <typename T>
    void List<T>::insertBefore(const T& x,itr<T> ptr){
        dnode<T> *tmp=new dnode<T>(x);
        if(isEmpty()){
            begining=tmp;
            ending=tmp;
        }
        else{
            //I still do not completely understand this
            tmp->next=ptr.opertor->();
            tmp->prev=ptr->prev;
            if(ptr->prev!=0)
                ptr->prev->next=tmp;
            else
                begining=tmp;
            ptr->prev=tmp;
        }
    }
///////////////////////////
//for HW make insertAfter()
///////////////////////////

template <typename T>
    itr<T> List::operator[](int i)const{
       //want to get the ith element out of the list 
        itr<T> result(begin());
        int n=0;
        while(result!=0){
            if(n==i)
                return result;
            ++n;
            ++result;
        }
        return itr<T>();
    }


template <typename T>
    List<T>::~List(){
        while(begining!=0){
            dnode<T> *tmp=begining;
            begining=begining->next;
            delete tmp;
        }
        
    }

//copy ctor
template<typename T>
    List<T>::List(const List<T>& actual){
        dnode<T> *tmp=actian.begining;
        begining=0;
        ending=0;
        while(tmp!=0){//"I'm gonna do a bunch of stuff"
            if(begining==0){
                begining=new dnode<T> (tmp->data);
                ending=begining;
            }
            else{
            ending->next=new dnode<T>(tmp->data);
            ending->next->prev=ending;
            ending=ending->next;
            }
            temp=temp->next;
        }
    }