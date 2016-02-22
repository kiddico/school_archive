/*trees
"Directed Acyclic Graphs"
Root->children
there is one unique parth from root to all other nodes

Multiple is a lattice.
    aka multiple parents

root is level zero, goes up from there.
last level is a leaf.


Binary trees yo!
n-ary tree can be represented as a binary tree

*/

/*
can have zero children, a left child, right or both

full binary tree-full from left to right

complete binary tree- When it's symetric

*/

class bnode{
    public:
        bnode *left,*right;
        bnode():left(0),right(0){};
        bnode(int x):left(0),right(0),data(x){};
        int data;
}

//so
bnode *ptr=new bnode(10);
ptr->left=new bnode(25);
ptr->right=new bnode (20);
//not actually how we are going to do it

//to deallocate use postorder
//for copy constructor use preorder


//this time around we're going to put everything in the tree class
//everything is recursive!!

//tree is going to have 4 things
//a pointer left and right, data, and a bool for is empty

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
            bool empty;
            T data;
    }