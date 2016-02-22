//Yeah!
//Algorithms and a data structure

//Graphs and backtracking algorithms
//Map coloring problem
//4 colors can be used to color any map so no 2 neighbors have the same color
//How do we represent this map as a data structure
//Adjacency <SP?> Matrix
     1    2     3    4     5 
-----------------------------
1|        1           1     1
2|   1    1     1     1     1
3|        1           1     1  
4|   1    1     1           1 
5|   1    1     1     1  
         
//There ya go. 1 means that they touch.

     1    2     3    4     5    6
 ---------------------------------
1|                                  
2|                                  
3|                                  
4|                                  
5|                                  
6|                                  

                   0    
            |       |      |       |
            R       B      G       Y
         | | | |
         r B G Y
         //one path wont work. backtrack
         //Really just gonna try everything until one works
         4^6 possibilities
//recursive algorithm to solve for colory bits

/////////////////////////////////////////////////////
//weird coloring thing
/////////////////////////////////////////////////////
enum theColors{red,blue,green,yellow,none};
//red is zero,blue is two, green is three etc...

class color{
    private:
        theColors hue;
    public:
        color(theColors c=none):hue(c){};//this syntax is all kinds of funky
        color& operator++(){
            hue=theColors(int(hue)+1);//could %5 here. So if it goes above 5....
            return *this;
        }
        std::ostream operator<<(std::ostream&,color);
    
}//now we need a map

class map{
    public:
        map();
        int numOfCountries()const{return numOfC;};
        bool validColoring(int,color)const;
        void colorCountry(int c,color h){
            coloring[c] = h;
        }
        friend ostream& operator<<(ostream&,const map);
    private:
        int numOfC;
        //this is one of those map things we made earlier
        bool neighbor[size][size];
        color coloring[size];
}

//funcs!

bool map::validColoring(int country,color h)const{
    for(int i=0;i<numOfC;++i)
        if(neighbor[country][i] && h==coloring[i];)
            return false;
    return true;
}

//the constructor would just read in the number of countries and the adjacency matrix

//a free func that actually does stuff
//recursive func
bool MapColor(int country,map& world){
    bool aColorRemaining=true, donecoloring=false;
    color hue;//current collor we are going to try to color with
    if(country<world.numOfCountries()){
        hue=red;
        while(!donecoloring && aColorRemaining){//going to systematically try all the colors
            if(world.validColoring(country,hue)){
                world.colorCountry(country,hue);
                donecoloring=MapColor(country+1,world);
            }
            if(hue==yellow)
                aColorRemaining=false;
            else
                ++hue;
        }
        if(!doneColoring)//this is our backtrack
            world.colorCountry(country,none);
    }
    else
        doneColoring=true;
    return doneColoring;//holy recursion batman
}