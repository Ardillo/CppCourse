#include <iostream>
#include <string>

using namespace std;

class Voertuig{
protected: 
   int aantalWielen;
public:
   Voertuig( int anw = 4);
   friend ostream& operator<< (ostream &out, const Voertuig vtg);
};

class Fiets : public Voertuig {
private:
   int framenummer;
public:
   Fiets( int framenummer = 0);
   friend ostream& operator<< (ostream &out, const Fiets fts);
};

int main(){
   Voertuig car;
   cout << car << endl;
   
   Fiets omafiets;
   Fiets mijnFiets(12345);
   cout << omafiets << endl << mijnFiets << endl;
   
}

//Constructor + lidfuncties van Voertuig
Voertuig :: Voertuig(int anw)
 : aantalWielen(anw){}

ostream& operator<< (ostream &out, const Voertuig vtg){
   return out << "Dit voertuig heeft " << vtg.aantalWielen << " wielen" << endl;
}
 
//Constructor + lidfuncties van Fiets
Fiets :: Fiets( int framenummer)
 : Voertuig(2), framenummer(framenummer){}
 
ostream& operator<< (ostream &out, const Fiets fts){
   return out << Voertuig(fts) << endl
              << "Framenummer: "     << fts.framenummer << endl;
}
   