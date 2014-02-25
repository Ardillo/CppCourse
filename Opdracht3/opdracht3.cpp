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
   cout << "Programma" << endl;
   Teller count;
   cout << "counter: " << count.getWaarde() << endl;
   count.verhoog();
   cout << "counter: " << count.getWaarde() << endl;
   count.verlaag();
   cout << "counter: " << count.getWaarde() << endl;
   count.setWaarde(5);
   cout << "counter: " << count.getWaarde() << endl;
   count.verlaag();
   cout << "counter: " << count.getWaarde() << endl;
   
   MV statistiek;
   cout << "stats:" << endl << statistiek;
   statistiek.man(); statistiek.man();
   statistiek.vrouw();
   cout << "stats: na increment" << endl << statistiek;

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
