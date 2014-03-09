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
#include <ConsoleColorLinux.h>

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
	 return out << setfill('0') << right 
	                       << setw(2) << date.dag << '-'
			       << setw(2) << date.maand << '-'
			       << setw(4) << date.jaar;
      }
      bool operator== ( Datum &eq) const{
	 return dag == eq.dag && maand == eq.maand && jaar == eq.jaar;
      }
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
      void addResult( const TentamenResultaat &result){
	 resultaten.push_back(result); 
      }
      string getVoornaam() const { return voornaam; }      
      string getTussenvoegsel() const { return tussenvoegsel; }
      string getAchternaam() const { return achternaam; }
      Datum getGebDatum() const { return gebDatum; }
      void printResult();
      
      friend ostream& operator<<(ostream &out, const Student &stud);

};

class CijferAdmin{
   private:
      string naam;
      vector<Student> studenten; // blz 296
      
   public:
      
      CijferAdmin(const string naam):naam(naam){};
          
      void voegStudentToe(Student &student);
      void voegCijferToe(Student &student, const TentamenResultaat &result);
      Student* getStudent(const Student &student);
      void printStudent(const Student &student);
      void print();

      friend ostream& operator<<(ostream &out, const CijferAdmin &admin);
};

int main(){
   CijferAdmin administratie("cijfers Q11B02");
   
   Student st1("Joop", "Parkiet", Datum(1, 1, 1970));
   Student st2("Kees", "de", "Beer", Datum(4,5,1983));
   Student st3("Annemarie", "Bezema", Datum(8,9,1982));
         
   administratie.voegStudentToe(st1);
   administratie.voegStudentToe(st2);
   administratie.voegStudentToe(st3);
   Student* stu;
   
   stu = administratie.getStudent(st1);
   TentamenResultaat wiskundeJoop("wiskunde", 7.5, Datum(1,3,2014));
   TentamenResultaat biologieJoop("biologie", 6, Datum(3,3,2014));
   TentamenResultaat techniekJoop("techniek", 5.9, Datum(2,3,2014));
   administratie.voegCijferToe(*stu, wiskundeJoop);
   administratie.voegCijferToe(*stu, biologieJoop);
   administratie.voegCijferToe(*stu, techniekJoop);
   
   stu = administratie.getStudent(st2);
   TentamenResultaat techniekKees("techniek", 8.3, Datum(2,3,2014));
   administratie.voegCijferToe(*stu, techniekKees);

   stu = administratie.getStudent(st3);
   TentamenResultaat fransAnnemarie("frans", 4, Datum(2,1,2014));
   TentamenResultaat engelsAnnemarie("engels", 6, Datum(7,7,2013));
   TentamenResultaat biologieAnnemarie("biologie", 9, Datum(3,3,2014)); 
   administratie.voegCijferToe(*stu, fransAnnemarie);
   administratie.voegCijferToe(*stu, engelsAnnemarie);
   administratie.voegCijferToe(*stu, biologieAnnemarie);

   administratie.printStudent(st2);
   cout << administratie << endl;
}
///functies uit cijferAdmin class
void CijferAdmin::voegStudentToe(Student &student){
   studenten.push_back(student);
}

void CijferAdmin::voegCijferToe(Student &student, const TentamenResultaat &rsl){
   student.addResult(rsl);   
}

//returned een pointer naar de student.
Student* CijferAdmin::getStudent(const Student &student){
      Datum gebDatum = student.getGebDatum();
   for(int i = 0; i<studenten.size(); ++i){
      Student tmp = studenten.at(i);     
      if( tmp.getAchternaam() == student.getAchternaam() &&
	  tmp.getTussenvoegsel() == student.getTussenvoegsel() &&
	  tmp.getVoornaam() == student.getVoornaam() && 
	  tmp.getGebDatum() == gebDatum ){
	 return &studenten.at(i);
      }
   }
}

void CijferAdmin::printStudent(const Student &student){ 
   Datum gebDatum = student.getGebDatum();
   for(int i = 0; i<studenten.size(); ++i){
      Student tmp = studenten.at(i);     
      if( tmp.getAchternaam() == student.getAchternaam() &&
	  tmp.getTussenvoegsel() == student.getTussenvoegsel() &&
	  tmp.getVoornaam() == student.getVoornaam() && 
	  tmp.getGebDatum() == gebDatum ){
	 cout << tmp << endl;
      }
   }
}

void CijferAdmin::print(){
   cout << *this << endl;  
}

ostream& operator<< (ostream &out, const CijferAdmin &admin){
   out << bg_green << black << "Cijfer administratie" << reset << endl
       << bg_red << admin.naam << reset << endl;
   vector<Student>::const_iterator pos, einde=admin.studenten.end();
   for(pos=admin.studenten.begin(); pos != einde; ++pos){
      out << *pos << endl;
   }
   out << bg_red << "End of: " << admin.naam << reset << endl;
   
}


///functies uit student class
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
      for(int i = 0; i<stud.resultaten.size(); ++i)
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