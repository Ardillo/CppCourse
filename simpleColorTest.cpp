#include <iostream>
#include <ConsoleColorLinux.h>
#include <string>

using namespace std;

int main(){
   
   cout ///OLD METHOD
	<< setColor(fg_green) 
	<< "Green\t-> Hello World!" << endl
	<< setColor(fg_blue)
	<< "Blue\t-> 2nd line" << endl
	<< setColor(fg_red)
	<< "Red\t-> cross the thin red line" << endl
	<< setColor(fg_defaultC)
	/// New Method
	<< endl << "TEST" << endl << "====" << endl
	<< green << "Green\t-> Hello World!" << endl
	<< blue << "Blue\t-> 2nd line" << endl
	<< red << "Red\t-> cross the thin red line" << endl;
	
	
   return 0;
}