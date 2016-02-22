//Went over the midterm at the biginning of class

//////////////////////////////////////////////////////
//Stacks and Queus
//////////////////////////////////////////////////////

//two operators
//push and pop
push puts a thing on the top
pop removes an item
TOS means top of stack.
[]
[5]
[10]
[20]
    push(5)
    push(10)
    push(20)
pop removes the top bit

    First in last out kind of thingymajigger
these are very efficient
    embed dat shit
    
//////////////////////////////////////////////////////
//implement it
//////////////////////////////////////////////////////
//as a template
    //Stack.hpp
    
    const int STACK_CAP=20;
template <typename T>
    class Stack{
    public:
        Stack(){tos=-1;}
        bool isEmpty(){return tos==-1;}
        bool isFull(){return tos==stack.STACK_CAP-1}
        T pop();
        void push(const T&);
    private:
        int tos;
        T s[STACKCAP];
}

//////////////////////////////////////////////////////
//push and pop for the example
//////////////////////////////////////////////////////
template <typename T>
    T Stack<T>::pop(){
        assert(!isEmpty())//termed as stack underflow
        T result=s[tos];
        --tos;
        return result;
        /*if you're tricky
        return s[tos--];
        */
    }

template <typename T>
    void Stack<T>::push(const T& item){
        assert(!isFull);//Stack overflow!! :D
        s[++tos]=item;
    }


//////////////////////////////////////////////////////
//Now what do we use this for?
//////////////////////////////////////////////////////
//parsing
//he gives: 3+7*2+1*8
//we need to find out precedence
//infix notation ((3+(7*2))+(1*8))
//prefix and postfix also exist
//infix 2+3
//prefix +2 3
//postfix 2 3+

/*to make it 
    prefix:
        move operator to corresponding left paren
    Postfix
        move to correspoinging right paren*/
//prefix of the above
    ++3 * 7 2 * 1 8
//Post
    3 7 2 * + 1 8 * +
//Operations never change order
//no more parens!!!
        
//////////////////////////////////////////////////////
//another example
//7+3*6*7-2*3*4
//parens
        ((7+((3*6)*7))-((2*3)*4))
//convert to prefix/post
//post
    7 3 6 * 7 * + 2 3 * 4 * -
//pre
    - + 7 **3 6 7 ** 2 3 4
        
//go over this a bit

//////////////////////////////////////////////////////
//writing a post fix evaluator
//////////////////////////////////////////////////////

        pseudo code!
            while(not done with expression){
                t=next token(expr)
                if(t is operand)
                    s.push(t)
                else{
                    right =s.pop();
                    left=s.pop();
                    s.push(eval(left,t,right))
                    }
            }
    tos is the final value
        so return it^^