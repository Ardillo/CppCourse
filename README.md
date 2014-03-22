#C++ programs
Some excercises for the course C++ (Electronic Engineering & Design)

##ColorConsoleLinux.h
I made a simple header file te use pretty color printing in your console.
You can include it with:<br>
<code>
\#include \<ColorConsoleLinux.h\>
</code>
<br>

To use the function, just use the 'setColor()' function. There are different
forground colors and background colors.

##Compile
To compile a program with the library do:<br>
<code>
g++ -I ../libs/ \<program.cpp\> -o \<outputname\>
</code><br>
The '-I.' option is used to scan for the '.h' files in the current directory<br>
For some programs it could be useful to compile them with the c++11 standard. 
This is done by compiling with:<br>
<code>
g++ -I ../libs/ \<program.cpp\> -o\<outputname\> -std=c++11
