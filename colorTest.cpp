/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 3-02-2014
 * 
 * Beschrijving:
 * Test programma ANSI escape codes om console van kleur te voorzien.
 * https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes 
 */

#include <iostream>
#include <ConsoleColorLinux.h>

using namespace std;


int main() {
  cout << endl;
  
  cout << "Hello World!" << endl << endl;
  
  // text kleur aanpassen
  for(int i=30; i<38; i++){
    setColor(i);
    cout << "***";      
  }
  cout << endl;
  setColor(39);

  // achtergrond kleur aanpassen
  for(int i=40; i<48; i++){
    setColor(i);
    cout << "***";      
  }
  // reset kleur en print lege regel
  setColor(49);
  cout << endl << endl; 
  
  //setManualColor(fg_location, colorMode_type, 255, 0, 0);
  cout << "End of Program" << endl << endl;
  return 0;
}