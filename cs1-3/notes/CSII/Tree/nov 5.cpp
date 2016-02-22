//Class from the previous...class
    
    template <typename T>
    class btree{
        public:
            btree():left(0),right(0),emptry(true){};//empty b/c no data
            btree(const T&x)left(0),right(0),empty(false),data(x){};
            ~btree();
            btree(const btree<T>&);
            void swap(btree<T>&);
            btree<T>& operator=(btree<T> rhs){swap(rhs);return *this;};
            bool isEmpty()const{return empty;};
            bool isFull()const;
            void preorder(std::ostream&)const;
            void postorder(std::ostream&)const;
            void inorder(std::ostream&)const;
            bool bsearch(const T&)const;
            void binsert(const T&);
            //we aren't going to do remove because that would include rewriting
        private:
            btree<T> *left,*right;
            bool emprty;
            T data;
    }



template <typename T>
    void btree<T>::binsert(const T& x){
        if(empty){
            data=x;
            empty=false;
        }else
            {
                if(x<data){
                    if(left)
                        left->binsert(x);//this is a method call using a pointer deref
                    else
                        left=new btree(x);
                }
                else{//(x>data)
                    if(right)
                        right->binsert(x);
                    else
                        right=new btree(x);
                }
            }//end large else
    }//end func
//this is really sloppy looking
//just sayin

///////////////////////////////////////////////
//IMPORTANT SHIT
//POSTORDEER PRINT OUT!!!
///////////////////////////////////////////////

template <typename T>
    void btree<T>::postorder(std::ostream& out)const{
        if(!empty){
            if(left){//if its true then it's nonzero
                left->postorder(out);
            }
            if(right){
                right->postorder(out);
            }
            out<<data;
        }
    }

///////////////////////////////////////////////
//IMPORTANT SHIT
//DESTRUCTOR
//NEEDS TO USE POST TRAVERSAL
///////////////////////////////////////////////
//to call a destructor just call delete :D it'll do the hard work
template <typename T>
    btree<T>::~btree(){
        if(left)
            delete left;
        if(right)
            delete right;
        //pointers, data, and empty deallocated by our friend the compiler
        //the "visit" is done by the compiler itself
        //"thanks bjarne"
    }


////////////////////////////////////////////////////////
//Copy Constructor
//calls itself recursively
//neat-o
/////////////////////////////////////////////////////////
template <typename T>
    btree<T>::btree(const btree<T>& actual){
        if(actual.empty){
            empty=true;
            left=0;
            right=0;
        }
        else{
            empty=false;
            data=actual.data;
            
            /////////////////////////////////////////////////////////
            //left side
            /////////////////////////////////////////////////////////
            if(actual.left){
                left=new btree<T>(*(actual.left));//need to deref left so you actually pass the tree, not a pointer to it    
            }
            else{
                left=0;
            }
            /////////////////////////////////////////////////////////
            //right side
            /////////////////////////////////////////////////////////
            
            if(actual.right){
                right=new btree<T>(*(actual.left));
            }
            else{
                right=0;
            }
        }
    }

template <typenme T>
    bool btree<T>::bsearch(const T& key)const{
        if(empty)
            return false;//BAM! that was easy
        if(key==data)
            return true;
        if(key<data)
            if(left)
                return left->bsearch(key);
            else
                return false;
        else(key>data)    
            if(right)
                    return right->bsearch(key);
            else
                return false;
    }


//this looks freaking gross
//I hate it
template <typename T>
    void btree::swap(btree<T>& rhs){
        //data swap
        T Ttemp=rhs.data;
        rhs.data=data;
        data=Ttemp;
        //empty swap
        bool btemp=rhs.empty;
        rhs.empty=empty;
        empty=btemp;
        //left swap
        
        btree<T> *temp=rhs.left;
        rhs.left=left;
        left=temp;
        //right swap
        temp=rhs.right;
        rhs.right=right;
        right=temp;
    }



