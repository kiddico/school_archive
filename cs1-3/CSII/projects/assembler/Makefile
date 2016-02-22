#============================================================================
#  stack class makefile
#===========================================================================

CPP          = g++
CPP_FLAGS    = -g -Wall -W -Wunused -Wuninitialized -Wshadow 
INCLUDE_OPT  = -iquote . -iquote ../string
TEST_1 = test_constructors
TEST_2 = test_int 
TEST_3 = test_string

#-------------------------------------------------------------------------------
STRING_DIR = ../string/

#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   tests'
	@echo '   clean'
	@echo '   postfix'
	@echo '   assembler'

#===========================================================================
# Compile string.o from Project 2.

string.o:	${STRING_DIR}string.hpp  ${STRING_DIR}string.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_DIR}string.cpp

#===========================================================================
# No compile for stack is needed - it is a template.


#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%: string.o test_%.o
	${CPP} ${CPP_FLAGS} string.o test_$*.o -o test_$*

test_%.o: ${STRING_DIR}string.hpp stack.hpp test_%.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c test_$*.cpp


#===========================================================================
# Compile postfix

postfix.o: postfix.cpp ${STRING_DIR}string.hpp stack.hpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c postfix.cpp


postfix: postfix.o string.o
	${CPP} ${CPP_FLAGS} postfix.o string.o -o postfix

#===========================================================================
# Compile assembler

assembler.o: assembler.cpp ${STRING_DIR}string.hpp stack.hpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c assembler.cpp

assembler: assembler.o string.o
	${CPP} ${CPP_FLAGS} string.o assembler.o -o assembler


#===========================================================================
# Run test programs

tests: stack.hpp ${STRING_DIR}string.hpp ${TEST_1} ${TEST_2} ${TEST_3} 
	./test_constructors
	./test_int
	./test_string


#============================================================================
clean:
	rm -f *.o
	rm -f postfix 
	rm -f assembler
	rm -f test_constructors
	rm -f test_int
	rm -f test_string

