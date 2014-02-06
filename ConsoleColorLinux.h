/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 3-02-2014
 * 
 * colorConsoleLinux.h
 * 
 * Beschrijving:
 * Test programma ANSI escape codes om console van kleur te voorzien.
 * https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes 
 */

#include <iostream>

// Foreground colors
int fg_defaultC = 39;
int fg_black = 30;
int fg_red = 31;
int fg_green = 32;
int fg_yellow = 33;
int fg_blue = 34;
int fg_magenta = 35;
int fg_cyan = 36;
int fg_white = 37;

// Background colors
int bg_defaultC = 49;
int bg_black = 40;
int bg_red = 41;
int bg_green = 42;
int bg_yellow = 43;
int bg_blue = 44;
int bg_magenta = 45;
int bg_cyan = 46;
int bg_white = 47;

// function declaration
void setColor(int &color){  
  std::cout << "\033[" << color << "m";
}

