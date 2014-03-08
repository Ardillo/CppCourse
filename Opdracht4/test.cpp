/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 08-03-2014
 * 
 * Bescrhijving:
 * Practicum opdracht 4
 * H9.9: opg6
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Datum{
   private:
      
      int dag, maand, jaar;
      
   public:

      Datum(int dag, int maand, int jaar)
      :dag(dag), maand(maand), jaar(jaar){}
	    
      friend ostream& operator<< (ostream &out, const Datum &date){
	 return out << setw(2) << setfill('0') << date.dag << '-'
			       << setw(2)      << date.maand << '-'
			       << setw(4)      << date.jaar;
      }
};

class TentamenResultaat{
   private:
      
      string naam;
      double cijfer;
      Datum datum;
      
   public:
      
      TentamenResultaat(string naam, double cijfer, const Datum date)
      :naam(naam), cijfer(cijfer), datum(date){}
      
      friend ostream& operator<< (ostream &out, const TentamenResultaat &Tres){
	 return out << setfill(' ') << left
	            << setw(8) << "Vak: " << Tres.naam << endl
	            << setw(8) << "Datum: " << Tres.datum << endl
	            << setw(8) << "Cijfer: " << Tres.cijfer << endl;
      }
};

class Student{
   private:
 
      string voornaam, tussenvoegsel, achternaam;
      Datum gebDatum;
      vector<TentamenResultaat> resultaten;

   public:
      
      // constructor met tussenvoegsel
      Student(string voornaam, string tussenvoegsel, string achternaam,
	 const Datum gebDatum)
      :voornaam(voornaam), tussenvoegsel(tussenvoegsel),
       achternaam(achternaam), gebDatum(gebDatum){}
       
      //constructor zonder tussenvoegsel
      Student(string voornaam, string achternaam, const Datum gebDatum)
      :voornaam(voornaam), tussenvoegsel(),
       achternaam(achternaam), gebDatum(gebDatum){}
       
      friend ostream& operator<<(ostream &out, const Student &stud);
      void voegResultToe( const TentamenResultaat &result);
      void printResultaten();
             
};

int main(){
   Datum gebDatumJoop(1, 1, 1970);   
   Student st1("Joop", "Parkiet", gebDatumJoop);
   cout << st1 << endl;
   
   TentamenResultaat result("wiskunde", 7.5, Datum(1,3,2014));
   st1.voegResultToe(result);
   
   st1.voegResultToe(TentamenResultaat("biologie", 6, Datum(3,3,2014)));
   
   st1.printResultaten();
   cout << st1 << endl;
}

//functies uit student class

void Student::voegResultToe( const TentamenResultaat &result){
   resultaten.push_back(result);   
}

void Student::printResultaten(){
   vector<TentamenResultaat>::iterator pos, einde=resultaten.end();
   for(pos = resultaten.begin(); pos != einde; ++pos){
      cout << *pos << endl;
   }   
}

ostream& operator<< (ostream &out, const Student &stud){
   
   out << setw(12) << setfill(' ') << left 
       << "Naam: " << stud.voornaam;
   if (!stud.tussenvoegsel.empty()){
       out << ' ' << stud.tussenvoegsel;
   }
   out << ' ' << stud.achternaam << endl 
       << "Geb. datum: " << stud.gebDatum << endl << endl;
       
   return out;
}

/*
 * 
 * 
 * 
 * 
 * 
 * 
 *    //if (!stud.resultaten.empty()){
      vector<TentamenResultaat>::const_iterator pos,einde=stud.resultaten.end();
      cout << *pos << " -- " << *einde << endl;
      
      for(pos = stud.resultaten.begin(); pos != einde-1; ++pos){
	 cout << "std::cout " << *pos << endl;
	 out << *pos << endl << endl;	 
      }
   //}
 */