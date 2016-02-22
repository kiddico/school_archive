clear
clear
clang++ -c -Wall assembler.cpp ../string/string.cpp
echo "Object Code Created"
clang++ assembler.o string.o -o output
echo "Executable Made"
echo "Output Below"
echo "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
./output data3-1.txt
