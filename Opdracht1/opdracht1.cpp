/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 3-02-2014
 * 
 * Beschrijving:
 * Practicum Opdracht 1 
 * 
 * Voorwaarden:
 * de excecutable moet een consoleapplicatie zijn
 * maximaal 100 sourceregels
 * regelbreedte maximaal 80 karakters
 * opmaak volgens één van de stijlen, beschreven in hoofdstuk 3.3.5
 * naast main tenminste twee andere functies
 * deze functies staan onder main gedefinieerd
 * de ene functie heeft default argumenten, de andere reference argumenten
 * invoer van het toetsenbord
 * uitvoer in kleur op het zwarte scherm
 * tenminste de volgende typen gebruiken: int, bool, double
 * de double moet met een aantal cijfers achter de decimale punt worden geprint
 * tenminste één van de loops gebruiken: for, while, do-while
 */

#include <iostream>
#include <iomanip>
#include <ConsoleColorLinux.h>

using namespace std;

void tekenRechthoek(int breedte=5, int hoogte=5);
void tekenRandLijn(int &breedte);
void tekenBodyLijn(int &breedte);

bool EndOfProgram = false;
double var = 1.0;

int main() {
   cout << endl;
   setColor(fg_blue);
   cout << "Hello World!" << endl;
   setColor(fg_defaultC);
   cout << endl; 
   
   tekenRechthoek();
   tekenRechthoek(30,8);
   cout << endl;
   
   EndOfProgram = !EndOfProgram;
   setColor(bg_blue);
   cout << EndOfProgram;
   setColor(bg_defaultC);
   cout << endl << endl;
   
   
   cout << "print double var: " 
        << setprecision(4) << var+.123456 
        << endl << endl;
   return 0;
}

void tekenRechthoek(int breedte, int hoogte){
   for (int ctr = hoogte; ctr>0; ctr--){
      if (ctr == hoogte || ctr == 1){
	 tekenRandLijn(breedte);
      }
      else {
	 //cout << "hier";
	 tekenBodyLijn(breedte);
      }
   }
}

void tekenRandLijn(int &breedte){
   for (int ctr = breedte; ctr>0; ctr--){
      cout << "-";
   }
   cout << endl;
}
void tekenBodyLijn(int &breedte){
   for (int ctr = breedte; ctr>0; ctr--){
      if (ctr == breedte || ctr == 1){
         cout << "|";
      }
      else {
	 cout << " ";
      }      
   }
   cout << endl;
}

