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

using namespace std;

// Foreground colors
const int FG_DEFAULTC = 39;
const int FG_BLACK = 30;
const int FG_RED = 31;
const int FG_GREEN = 32;
const int FG_YELLOW = 33;
const int FG_BLUE = 34;
const int FG_MAGENTA = 35;
const int FG_CYAN = 36;
const int FG_WHITE = 37;

// Background colors
const int BG_DEFAULTC = 49;
const int BG_BLACK = 40;
const int BG_RED = 41;
const int BG_GREEN = 42;
const int BG_YELLOW = 43;
const int BG_BLUE = 44;
const int BG_MAGENTA = 45;
const int BG_CYAN = 46;
const int BG_WHITE = 47;

/////// NEW Inline with stream //////
/// Reset foreground and background colors (reset all ANSI escape codes///
inline std::ostream& reset(std::ostream &s){
   s << "\033[0m";
   return s;
}

/// Foreground colors ///
inline std::ostream& black(std::ostream &s){
   s << "\033[" << FG_BLACK << "m";
   return s;
}

inline std::ostream& red(std::ostream &s){
   s << "\033[" << FG_RED << "m";
   return s;
}

inline std::ostream& green(std::ostream &s){
   s << "\033[" << FG_GREEN << "m";
   return s;
}

inline std::ostream& yellow(std::ostream &s){
   s << "\033[" << FG_YELLOW << "m";
   return s;
}

inline std::ostream& blue(std::ostream &s){
   s << "\033[" << FG_BLUE << "m";
   return s;
}

inline std::ostream& magenta(std::ostream &s){
   s << "\033[" << FG_MAGENTA << "m";
   return s;
}

inline std::ostream& cyan(std::ostream &s){
   s << "\033[" << FG_CYAN << "m";
   return s;
}

inline std::ostream& white(std::ostream &s){
   s << "\033[" << FG_WHITE << "m";
   return s;
}

///Background colors ///
inline std::ostream& bg_black(std::ostream &s){
   s << "\033[" << BG_BLACK << "m";
   return s;
}

inline std::ostream& bg_red(std::ostream &s){
   s << "\033[" << BG_RED << "m";
   return s;
}

inline std::ostream& bg_green(std::ostream &s){
   s << "\033[" << BG_GREEN << "m";
   return s;
}

inline std::ostream& bg_yellow(std::ostream &s){
   s << "\033[" << BG_YELLOW << "m";
   return s;
}

inline std::ostream& bg_blue(std::ostream &s){
   s << "\033[" << BG_BLUE << "m";
   return s;
}

inline std::ostream& bg_magenta(std::ostream &s){
   s << "\033[" << BG_MAGENTA << "m";
   return s;
}

inline std::ostream& bg_cyan(std::ostream &s){
   s << "\033[" << BG_CYAN << "m";
   return s;
}

inline std::ostream& bg_white(std::ostream &s){
   s << "\033[" << BG_WHITE << "m";
   return s;
}
