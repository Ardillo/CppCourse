#include <iostream>
#include <string>
#include <stdlib.h>
#include <ConsoleColorLinux.h>

using namespace std;

class Uitgave{
protected:
   string titel;
   double prijs;
public:
   Uitgave(string titel, double prijs)
    : titel(titel), prijs(prijs){}
   friend ostream& operator<<( ostream& out, const Uitgave utgv){
      return out << "Titel: " << utgv.titel << endl
                 << "Prijs: " << utgv.prijs << " euro";
   }
};

class Tijdschrift: public Uitgave{
private:
   int maand;
public:
   Tijdschrift(string titel, double prijs, int mnd)
    : Uitgave(titel, prijs), maand(mnd){}
   friend ostream& operator<< (ostream& out, const Tijdschrift tdscrft){
      return out << yellow << "Tijdschrift" << reset << endl
		 << Uitgave(tdscrft) << endl
                 << "Maand: " << tdscrft.maand << endl;
   }
};

class Boek: public Uitgave{
private:
   string auteur;
   int bladzijden;
public:
   Boek(string titel, double prijs, string auteur, int blz)
    : Uitgave(titel, prijs), auteur(auteur), bladzijden(blz){}
    friend ostream& operator<<( ostream &out, const Boek livre){
       return out << yellow << "Boek" << reset << endl
		  << Uitgave(livre) << endl
                  << "Auteur: " << livre.auteur << endl
                  << "Bladzijden: " << livre.bladzijden << endl;
    }
};

class CD: public Uitgave{
private:
   int minuten;
public:
   CD(string titel, double prijs, int minuten)
    : Uitgave(titel, prijs), minuten(minuten){}
    friend ostream& operator<<( ostream &out, const CD cd){
       return out << yellow << "CD" << reset << endl
		  << Uitgave(cd) << endl
                  << "Minuten: " << cd.minuten << endl;
    }
};

int main(){
   
   string naam, titel, auteur, tmp;
   double bedrag;
   int maand=1, bladzijden, minuten;
   string::size_type sz;
   
   cout << green << "Voer tijdschrift in" << reset << endl;
   cout << "Titel: "; 
   getline(cin, titel);
   cout << "Bedrag (0): "; 
   getline(cin, tmp);
   bedrag = atof(tmp.c_str());
   cout << "Maand (1): "; 
   getline(cin, tmp);
   maand = atoi(tmp.c_str());
   Tijdschrift tijdschrift(titel, bedrag, maand);
   cout << endl << red << "Zojuist toegevoegd: " << reset << endl 
        << tijdschrift << endl;
 
   cout << green << "Voer boek in" << reset << endl;
   cout << "Titel: ";
   getline(cin, titel);
   cout << "Bedrag (0): "; 
   getline(cin, tmp);
   bedrag = atof(tmp.c_str());
   cout << "Auteur: ";
   getline(cin, auteur);
   cout << "Aantal bladzijden: ";
   getline(cin, tmp);
   bladzijden = atoi(tmp.c_str());
   Boek boek(titel, bedrag, auteur, bladzijden);
   cout << endl << red << "Zojuist toegevoegd: " << reset << endl 
        << boek << endl;
   
   cout << green << "Voer cd in" << reset << endl;
   cout << "Titel: ";
   getline(cin, titel);
   cout << "Bedrag (0): "; 
   getline(cin, tmp);
   bedrag = atof(tmp.c_str());
   cout << "Minuten: ";
   getline(cin, tmp);
   minuten = atoi(tmp.c_str());
   CD cd(titel, bedrag, minuten);
   cout << endl << red << "Zojuist toegevoegd: " << reset << endl 
        << cd << endl;
  
}
