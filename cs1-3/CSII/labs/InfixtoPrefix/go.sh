clear
clear
clang++ -c -Wall Inftopre.cpp string.cpp
echo "Object Code Created"
clang++ Inftopre.o string.o -o output
echo "Executable Made"
echo "Output Below"
echo "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
./output
