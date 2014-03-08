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
      //constructor
      Datum(int dag, int maand, int jaar)
      :dag(dag), maand(maand), jaar(jaar){}
      //functies	    
      friend ostream& operator<< (ostream &out, const Datum &date){
	 return out << setw(2) << setfill('0') << date.dag << '-'
			       << setw(2)      << date.maand << '-'
			       << setw(4)      << date.jaar;
      }
      ///TODO overloaden van '==' operator
};

class TentamenResultaat{
   private:      
      string naam;
      double cijfer;
      Datum datum;      
   public:
      //constructor
      TentamenResultaat(string naam, double cijfer, const Datum date)
      :naam(naam), cijfer(cijfer), datum(date){}
      //functies
      friend ostream& operator<< (ostream &out, const TentamenResultaat &Tres){
	 return out << setfill(' ') << left
	            << setw(8) << "\tVak: " << Tres.naam << endl
	            << setw(8) << "\tDatum: " << Tres.datum << endl
	            << setw(8) << "\tCijfer: " << Tres.cijfer << endl;
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
      //functies 
      friend ostream& operator<<(ostream &out, const Student &stud);
      void addResult( const TentamenResultaat &result);
      void printResult();	///TODO
      void getVoornaam();	///TODO
      void getTussenvoegsel();	///TODO
      void getAchternaam();	///TODO
      void getGebDatum(); 	///TODO
};

class CijferAdmin{
   private:
      string naam;
      vector<Student> studenten; // blz 296
      
   public:
      
      CijferAdmin(const string naam):naam(naam){};
          
      void voegStudentToe(const Student &student);
      void voegCijferToe(const Student &student, const TentamenResultaat
			 &result);      
      void printStudent(const Student &student);
      void printAdministratie();
};

int main(){
   CijferAdmin administratie("cijfers");
   
   Student st1("Joop", "Parkiet", Datum(1, 1, 1970));
   Student st2("Kees", "de", "Beer", Datum(4,5,1983));
   Student st3("Annemarie", "Bezema", Datum(8,9,1982));
       
   st1.addResult(TentamenResultaat("wiskunde", 7.5, Datum(1,3,2014)));   
   st1.addResult(TentamenResultaat("biologie", 6, Datum(3,3,2014)));
   
   st2.addResult(TentamenResultaat("techniek", 8.3, Datum(2,3,2014)));
   
   st3.addResult(TentamenResultaat("frans", 4, Datum(2,1,2014)));
   st3.addResult(TentamenResultaat("engels", 6, Datum(7,7,2013)));
   st3.addResult(TentamenResultaat("biologie", 9, Datum(3,3,2014)));
  
   //cout << st2 << endl;
   
   administratie.voegStudentToe(st1);
   administratie.voegStudentToe(st2);
   administratie.voegStudentToe(st3);
   
   administratie.printStudent(st3);
}
//functies uit cijferAdmin class
void CijferAdmin::voegStudentToe(const Student &student){
   studenten.push_back(student);
}

void CijferAdmin::printStudent(const Student &student){
   vector<Student>::const_iterator pos, einde=studenten.end();
   for(pos = studenten.begin(); pos != einde; ++pos){
      ///TODO getters and setters.voor student.
      cout << *pos << endl;
   }  
}

//functies uit student class

void Student::addResult( const TentamenResultaat &result){
   resultaten.push_back(result);   
}

void Student::printResult(){
   vector<TentamenResultaat>::const_iterator pos, einde=resultaten.end();
   for(pos = resultaten.begin(); pos != einde; ++pos){
      cout << *pos << endl;
   }   
}

// vraag: Indien een object const is, zijn dan alle onderliggende objecten ook
//        const?
ostream& operator<< (ostream &out, const Student &stud){
   
   out << setw(12) << setfill(' ') << left 
       << "Naam: " << stud.voornaam;
   if (!stud.tussenvoegsel.empty()){
       out << ' ' << stud.tussenvoegsel;
   }
   out << ' ' << stud.achternaam << endl 
       << "Geb. datum: " << stud.gebDatum << endl << endl;
   
   // als er resultaten zijn dan lijst doorlopen.    
   if (!stud.resultaten.empty()){
      for(int i = 0; i<stud.resultaten.capacity(); ++i)
	 out << stud.resultaten.at(i) << endl;
   }
       
   return out;
}

/* 
 * Dit lijkt niet te werken --> Segmentation fault 
 
   if (!stud.resultaten.empty()){
     vector<TentamenResultaat>::const_iterator pos,einde=stud.resultaten.end();
     for(pos = stud.resultaten.begin(); pos != einde; ++pos){
	 cout << *pos << endl;
     }
   }
   
 */