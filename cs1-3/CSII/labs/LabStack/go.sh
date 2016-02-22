clear
clear
clang++ -c -Wall main.cpp LabStack.cpp string.cpp
echo "Object Code Created"
clang++ main.o LabStack.o string.o -o output
echo "Executable Made"
echo "Output Below"
echo "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
./output
