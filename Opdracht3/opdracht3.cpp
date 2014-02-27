/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 24-02-2014
 * 
 * Bescrhijving:
 * Practicum opdracht 3
 * H8.12: opg 5 + 6
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctype.h>

using namespace std;

class Teller{
   private:
      int integer;
   public:
      Teller();   
      void verhoog();
      void verlaag();
      void setWaarde(int waarde);
      const int getWaarde() const;
};

class MV{
   private:
      Teller mannen;
      Teller vrouwen;
   public:
      void man();
      void vrouw();
      friend ostream& operator<< (ostream &out, const MV &mvObject);
};
   


int main(){
   char command;
   MV statistiek;
   bool end = false;

   while(!end){
      cout << "press command (M)an, (V)rouw, (S)top:" << endl;
      cin >> command;
      
      switch(toupper(command)){
	 case 'M':
	    statistiek.man();
	    break;
	 case 'V':
	    statistiek.vrouw();
	    break;
	 case 'S':
	    cout << "Statistiek:" << endl
	         << statistiek << endl;
            end = true;
	    break;
	 default:
	    break;
      }
   }
   return 0;
}


/*
 * Teller class constructor + functies
 */
Teller :: Teller() : integer(0){
}

void Teller::verhoog(){
   integer++;
}

void Teller::verlaag(){
   integer--;
}

void Teller::setWaarde(int value){
   integer = value;
}

const int Teller::getWaarde() const{
   return integer;
}

/*
 * MV class functies
 */
void MV::man(){
   mannen.verhoog();
}

void MV::vrouw(){
   vrouwen.verhoog();
}

ostream& operator<< (ostream &out, const MV &mvObject){
   out << "\t" << setw(9) << left 
       << "Mannen:" << mvObject.mannen.getWaarde() << endl
       << "\t" << setw(9) 
       << "Vrouwen:"<< mvObject.vrouwen.getWaarde() << endl;
   return out;
}
