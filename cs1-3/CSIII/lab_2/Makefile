# Nicholas Chirico
# 5/2/16
# Lab 2
# CS 44001 Mihail Nesterenko / Jordan Adamek

# all sample text is public domain
# at least I'm fairly sure...

CXX = clang++
CXXFLAGS  = -g -O0 -Wall
RM = rm -f
SRCS = main.cpp WordOccurrence.cpp WordList.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

### just make it all ( but don't run anything )
all: main extra tests


### Original Functionality
run: main
	./wordCount sample
main: $(OBJS)
	$(CXX) -o wordCount $(OBJS)


### Test Related Nonsense
tests: objects main
	$(CXX) $(CXXFLAGS) -o test testWordList.cpp WordOccurrence.o WordList.o

tests_run: tests
	echo "TEST REQUIRES VALGRIND"
	sleep 1
	valgrind ./test
	valgrind ./wordCount sample

### Extra
extra: objects
	clang++ $(CXXFLAGS) -o for_fun for_fun.cpp WordList.o WordOccurrence.o
extra_run: extra
	./for_fun sample sample2 sample3


### Object Files Creation

objects: $(OBJS)

testWordList.o: testWordList.cpp WordOccurrence.o WordList.o
	$(CXX) $(CXXFLAGS) -c testWordList.cpp

WordList.o: WordList.cpp WordList.h WordOccurrence.o
	$(CXX) $(CXXFLAGS) -c WordList.cpp

WordOccurrence.o: WordOccurrence.h WordOccurrence.cpp 
	$(CXX) $(CXXFLAGS) -c WordOccurrence.cpp


# God I hate left overs
clean:
	$(RM) *~
	$(RM) *.o
	$(RM) .*~
	$(RM) test
	$(RM) wordCount
	$(RM) for_fun
	clear;ls
