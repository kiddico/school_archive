# Nicholas Chirico
# 5/2/16
# Lab 2
# CS 44001 Mihail Nesterenko / Jordan Adamek

# all sample text is public domain
# at least I'm fairly sure...

CXX = clang++
CXXFLAGS  = -O0 -std=c++11 -Wall
RM = rm -f
SRCS = main.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

### just make it all ( but don't run anything )
all: main


run: main
	./output

main: $(OBJS)
	$(CXX) -o output $(OBJS)


### Test Related Nonsense
tests:
	$(CXX) $(CXXFLAGS) -o output testCollection.cpp

tests_run: tests
	valgrind ./output



# God I hate left overs
clean:
	$(RM) *~
	$(RM) *.o
	$(RM) .*~
	$(RM) output
	$(RM) test
	clear;ls
