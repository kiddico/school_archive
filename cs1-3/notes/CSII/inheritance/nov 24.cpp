/*
    More Virtuals
    
    Dynamic type resolution
    virtual
    
*/

    shape *ptr;//could point to any shape
    ptr=new ssquare(10);
    ptr->draw();
    


//abstract classes
//objects cannot defined
class shape{
    public:
        shape()x(0),y(0){};
        void move(){};
        virtual void draw()=0;              //pure virtual function. essentially a place holder. 
        virtual bool isSquare()const=0;     //these will never be called
        virtual bool isRectangle()const=0;  //this is just saying the funct is equal to zero,
        virtual bool isCircle()const=0;     //aka no implementation
        virtual bool isTriangle()const=0;
    
    protected:
        int x,y;
}
//if we try that
main(){
    shape x;//would noot work
    shape *ptr;
}

class rectangle:pubblic shape(){
    public:
        rectangle():shape(),h(0),w(0){};
        rectangle(int height,int width)shape(),h(height),w(width){};
        virtual void draw(){std::cout<<"rectangle"<<std::endl;}
        virtual bool isSquare()const{return false;};    //this is where we define all the pure virtual functions
        virtual bool isRectangle()const{return true;};  //"I get it, but why is it useful"
        virtual bool isTriangle()const{return false;};
        virtual bool isCircle()const{return false;};
    protected:
        int h,w;
}

//using inheritance to solve some problems

//Design Patterns
//The Gang of 4 book
//Strategy Pattern

[client]-------[strategy interface]
                ^       ^       ^
                |       |       |
                |       |       |
            [strat1] [strat2] [strat3]
            [alg 1]  [alg 2]  [alg 3]
    
//////////////////////////////////////////////
//like a word processor kind of thing
class format{
    public:
        format(int w):width(w){};
        void output();
    protected:
        int width;
    private:
        //oooh private method
        virtual void justify(const string&)=0;//this is going to be the formating algorithm
    
}

void format::output(){
    string line,word;
    std::ifstream in("data.txt");
    in>>word;
    line=word;
    while(in>>word){
        if(word.length()+line.length()+1>width)}
            justify(line);
            line="";
        }
        line=line+" "+word;
    }
    justify(line);
    line=" ";
    in.close();
}

class leftjustify:public format{
    public:
        leftjustify(int w):width(w){};
    private:
        virtual void justify(){
            std::cout<<line<<std::endl;//for(int =0;i<width-line.length();i++){
                                       //std::cout<<" ";
                                       //std::cout<<line;}
            
        }
}
//word processor class
class WP{
    WP():width(10){};
    void selectformattingoption();
    
    private:
        int width;
    
}
void WP::selectformattingoption(){
    format *txt;
    txt=new leftjustify(width);
    txt->output;
    delete txt;
    txt=new rightjustify(width);
    delete txt;
}

//now inside of main

int main(){
    WP w;
    w.selectformatting option;
}