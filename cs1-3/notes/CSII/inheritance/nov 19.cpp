//visit->child 1->child 2->child n...

/*
Inheritance and dynamic variable binding (virtuals

Inheritance- Allows us to extend types
    Helps to solve OO design problems (wut?)
    Allow data modeling (data bases do this a whole hell of a lot better)
    
    shape object-rect, circle, triangle...
    
    shape class hase some functionality, all those shapes inherit said functionality.
    Inheritance is an Is_a relationship (another relationship we taked about is a has_a relationship. aka a car has an engine)
    but is_a is like a car is a vehicle, and a truck is a vehicle. 
    
    back to shape
    shapes will need to be moved(has an x and y position), and drawn, no matter the shape.
    so all the children inherit that
    "shape" is called a super class or a parent class.
    circle/rect/tri are children/subclass/derived class
    
    ^^^^^Unified modeling language^^^^^ more on this in software engineering
    
    Vehicle(motors, wheels)
      /      \
    car    truck
      \      /
      el camino
      
      
        Person
     /     |     \
    |      |      |   
  staff faculty student



*/

///////
    
class shape{
    public:
        shape():x(0),y(0){};
        void move(int newx,int newy){x=newx;y=newy;};
        void draw(){std::cout<<"shape "<<'('<<x<<','<<y<<')'<<std::endl;}
    //kinda like private objects. only objects of that type and all derived types have access to it
    //nobody really even uses private
    protected:
        int x,y;
    private:
}
//can also inherit private and protected.
class rectangle:public shape{
    public:
        rectanlge():shape() , h(0) , w(0){};
        rectanlge(int height,int width)shape(),h(height),w(width){};//ewwww
        void draw(){std::cout<<"rectangle "<<'('<<x<<','<<y<<')'<<std::endl;};
    protected:
        int h,w;
}

//we're also gonna do square b/c its inheriting from rec and not shape

class square:public rectangle{
    public:
        square():rectanlge(){};
        square(int heigth):rectangle(height,height){};
        void draw(){std::cout<<square<<'('<<x<<','<<y<<')'<<std::endl;}
    
}

//supose....
/*
int main(){
    shape x;
    rectangle y;
    x.draw();//shape 0,0
    y.draw();//rectangle 0,0
    y.move (4,4);
}
*/
//can you have a child from 2 parent objects?
int main(){
    shape s1;
    rectangle s2(2,3);
    square(4);
    circle(5);
    s2.move(4,4);
    s3.move(10,10);
    s1.draw();
    s2.draw();
}

//now to see the flaws in this sort of code and the need for aditional features

int main(){
    shape *tbl[10];//10 shape pointers
    tbl[0]=new shape();
    tbl[1]=new rectanlge(4,10);
    tbl[2]=new square(10,20);
    
    for(int i=0;i<10;++i){
        tbl[i]->draw();//at compile time this will print out shapes draw(), because that's all it knows
    //this is called satic variable binding :(
    //everything is thought out at compie time
    }
}
//time for virtuals
//python for examle has delayed typing (akadynamic type)

/*
Static type resolution- Determine type of objects at compile time
Dynamic type resolution- Delay type resolution until runtime
Virtual Methods-telling compiler which methods need to be delayed until runtime.
this is only useful for inheritance and overloaded methods
or you could do somthing funcy with function pointers.
in reality that's all that virtual methods are.

function pointers are slightly more efficient
*/


///////////////////////////////////////////////////////////////////////
//Virtual versions of old classes
///////////////////////////////////////////////////////////////////////
class shape{
    public:
        shape():x(0),y(0){};
        void move(){whatever we did before};
        virtual void draw(){std::cout<<"shape "<<'('<<x<<','<<y<<')'<<std::endl;};//once it's virtual it's always vitual.
        //so you don't relly need to have it say virtual in rectanlge, but you can have it there anyways
    protected:
        
    
}

class rectanlge:public shape{
    public:
        //same old shit as before
        rectangle():{...};
        rectanlge (int,int);
        virtual void draw(){std::cout<<"rectangle "<<'('<<x<<','<<y<<')'<<std::endl;};
}
///////////////////////////////////////////////////////////////////////
//end of virtual stuff
///////////////////////////////////////////////////////////////////////


//now this works!! vvvvv
int main(){
    shape *tbl[10];//10 shape pointers
    tbl[0]=new shape();
    tbl[1]=new rectanlge(4,10);
    tbl[2]=new square(10,20);
    
    for(int i=0;i<10;++i){
        tbl[i]->draw();
    }
}
  



