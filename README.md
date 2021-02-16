# C++ programs
Some excercises for the course C++ (Electronic Engineering & Design)

## ColorConsoleLinux.h
I made a simple header file te use pretty color printing in your console.
You can include it with:

```
#include <ColorConsoleLinux.h>
```

To use the function, just use the 'setColor()' function. There are different
foreground colors and background colors.

## Compile
To compile a program with the library do:<br>
```
g++ -I ../libs/ <program.cpp> -o <outputname>
```
The '-I.' option is used to scan for the '.h' files in the current directory<br>
For some programs it could be useful to compile them with the c++11 standard. 
This is done by compiling with:
```
g++ -I ../libs/ <program.cpp> -o <outputname> -std=c++11
```
