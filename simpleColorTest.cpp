#include <iostream>
#include <ConsoleColorLinux.h>

using namespace std;

int main(){
   
   cout ///OLD METHOD
        << endl << "OLD" 
	<< endl << "===" << endl;
   setColor(FG_GREEN); 
        cout << "Green\t-> hello green" << endl;
   setColor(FG_BLUE);
        cout << "Blue\t-> 2nd line" << endl;
   setColor(FG_RED);
        cout << "Red\t-> cross the thin red line" << endl;
   setColor(FG_DEFAULTC);
	/// New Method
   cout	<< endl << "NEW" 
	<< endl << "===" << endl
	<< green << "Green\t-> hello green" << endl
	<< blue << "Blue\t-> 2nd line" << endl
	<< red << "Red\t-> cross the thin red line" << endl;

   cout << "\033[9mHallo\033[0m" << endl
        << "\033[7mInverse\033[0m" << endl;
   // reset de kleur anders blijftconsole in laatste kleur staan
   //cout << setColor(fg_defaultC);
	
	
   return 0;
}