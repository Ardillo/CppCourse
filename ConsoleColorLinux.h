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

#include <sstream> // for old solution
#include <string>  // for old solution

using namespace std;

// Foreground colors
static int fg_defaultC = 39;
static int fg_black = 30;
static int fg_red = 31;
static int fg_green = 32;
static int fg_yellow = 33;
static int fg_blue = 34;
static int fg_magenta = 35;
static int fg_cyan = 36;
static int fg_white = 37;

// Background colors
static int bg_defaultC = 49;
static int bg_black = 40;
static int bg_red = 41;
static int bg_green = 42;
static int bg_yellow = 43;
static int bg_blue = 44;
static int bg_magenta = 45;
static int bg_cyan = 46;
static int bg_white = 47;

// OLD function declaration
string setColor(int &color){  
  ostringstream stream;
  stream << "\033[" << color << "m";
  return stream.str();
}

/////// NEW Inline with stream //////
/// Foreground colors ///
inline std::ostream& black(std::ostream &s){
   s << "\033[" << fg_black << "m";
   return s;
}

inline std::ostream& red(std::ostream &s){
   s << "\033[" << fg_red << "m";
   return s;
}

inline std::ostream& green(std::ostream &s){
   s << "\033[" << fg_green << "m";
   return s;
}

inline std::ostream& yellow(std::ostream &s){
   s << "\033[" << fg_yellow << "m";
   return s;
}

inline std::ostream& blue(std::ostream &s){
   s << "\033[" << fg_blue << "m";
   return s;
}

inline std::ostream& magenta(std::ostream &s){
   s << "\033[" << fg_magenta << "m";
   return s;
}

inline std::ostream& cyan(std::ostream &s){
   s << "\033[" << fg_cyan << "m";
   return s;
}

inline std::ostream& white(std::ostream &s){
   s << "\033[" << fg_white << "m";
   return s;
}

///Background colors ///
inline std::ostream& BG_black(std::ostream &s){
   s << "\033[" << bg_black << "m";
   return s;
}

inline std::ostream& BG_red(std::ostream &s){
   s << "\033[" << bg_red << "m";
   return s;
}

inline std::ostream& BG_green(std::ostream &s){
   s << "\033[" << bg_green << "m";
   return s;
}

inline std::ostream& BG_yellow(std::ostream &s){
   s << "\033[" << bg_yellow << "m";
   return s;
}

inline std::ostream& BG_blue(std::ostream &s){
   s << "\033[" << bg_blue << "m";
   return s;
}

inline std::ostream& BG_magenta(std::ostream &s){
   s << "\033[" << bg_magenta << "m";
   return s;
}

inline std::ostream& BG_cyan(std::ostream &s){
   s << "\033[" << bg_cyan << "m";
   return s;
}

inline std::ostream& BG_white(std::ostream &s){
   s << "\033[" << bg_white << "m";
   return s;
}
