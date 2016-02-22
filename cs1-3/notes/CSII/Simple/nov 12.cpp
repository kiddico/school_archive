/*
project 4
profiler tells you where you're spending the most time 
going to make a profiler for c++
need to parse the code
we get it fo frizzles yo!
We're gonna need to understand his shit
yeahhhhh
*/

/*process
    foo.cpp-srcml->foo.cpp.xml-profiler->internal astree(this is wheere we do stuff)-profiler->p-foo.cpp
*/

//example in class

void foo(){
    int i=0;
    ++i;
    cout<<i;
}

            <function>
        |       |       |                |
        type    name    parameter list    block
    
Type:name->void
name:foo
parameter list:
        /  \
       (    )
block:{}
       |
    |            |          |
    decl start   expr       expr
|   |   |   |   |   |       |        |    |
int i   =   0   ++  i       cout     <<   i