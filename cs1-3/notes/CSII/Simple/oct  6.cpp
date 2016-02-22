//////////////////////////////////////////////////////
//EXAM STUFF
//////////////////////////////////////////////////////

/*Golden Rules:
    1.Include Guards in .hpp files
    2.Default Constructor for all classes
    3.If using dynamic data structures
        -Copy Constructor
        -destructor
        -assignment
        -swap if possible

ADT-Not a class, but an idea
3 Parts
    data
    operations on data
    rules of usage

No questions on templates.
    maybe what they're about
    
Up to dynamic memory

Classes
    operation overloads
    const methods
    
pointers
    new
    delete
    -3rd rule of golden rules
        -all of 'em



*/
//////////////////////////////////////////////////
//End of exam stuff
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//Recursion
//////////////////////////////////////////////////
/*some languages lack loops
so you use recusrion to make your own


Factorial for example.
     n!={1 n<=1         Basis
        {n(n+1)! n>1    Recursive step

    Implement this in c++
    
*/

int nfact(int n){
    if(n<=1)
        return 1;
    else
        return r*nfact(n-1);
}

nfact(4);
    4*nfact(3)
    3*nfact(2)
    2*nfact(1)
    1
        
//fibinacci       
inf fib(int n){
        if(n<=2)
            return 1;
        else
            return fib(n-1)+fib(n-2);
}

//////////////////////////////////////////////////
//Towers of Hanoi
/////////////////////////////////////////////////
//three poles
//one disc at a time
//three discs total
//get all discs to other pole

move(n,src,temp,dest)
    move(n-1,src,des,temp)
        move(src,dest)
            move (n-1,temp,src,dest)
    
//code it!!
////dude fuck this thing. I am not going to give it the chance for me to care about it even slightly
enum thePoles{left,right,middle};

class pole{
    public:
        pole();
        pole(thePoles x){p=x;}
        friend std::ostream& operator(std::ostream&, pole);
    private:
        thePoles P;
}

void move(int n, pole src,pole aux,pole dest){
    if(n==1)
        cout<<"move disc from "<< src <<" to destination"<<endl;
    else{
        move(n-1,src,dest,aux);
        cout<<"move disc from "<< src <<" to "<< dest;
        move(n-1,aux,src,dest);
    }
}

//so in main

int main(){
    move(4,left,middle,right);
}


//to be honest I'm not sure what exactly you're trying to accomplish here...


so!
    move(4,l,m,r)