/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 13-02-2014
 * 
 * Beschrijving:
 * Practicum Opdracht 2 (coderen - decoderen) 
 *
 * Paragraaf 13.12 
 * Opdracht 5 decoderen
 * Opdracht 6 coderen
 * 
 * Voorwaarden:
 * Maak gebruik van:
 * 	stack
 * 	deque
 * 	memory
 * 
 ********** DECODEREN ************
 * Geen hoofdletters in string.
 * 
 **** FASE 1 ****
 * loop door de string teken voor teken
 * medeklinkers staan op de stack
 * Totdat klinker:
 *	Dan alle medeklinkers van stack naar deque.
 *	Plaats de klinker vervolgens op deque.
 * Ga verder met string
 * 
 **** FASE 2 ****
 * om en om tekens uit voorkant en achterkant deque halen
 * achter elkaar plakken
 * 
 * EOF
 *
 ********* CODEREN **************
 **** FASE 1 ****
 * haal chars teken voor teken uit string
 * 	1e in queue
 * 	2e op stack
 * 	3e in queue
 * 	4e ...
 * haal tekens van stack en voeg ze aan queue
 * 
 **** FASE 2 ****
 * haal tekens een voor een uit queue en plaats ze op stack
 * Totdat klinker:
 * 	Dan alle tekens uit stack naar string
 * 	plaats klinker achter de string
 * ga verder met queue
 * 
 * EOF	
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <deque>
#include <ConsoleColorLinux.h>

using namespace std;

const int ENCRYPT = 0;
const int DECRYPT = 1;

const bool DEBUG = true;

int main() {
   ///Startup
   string tekst = "";
   string command = "";
   cout << endl << "\t" << bg_red << black 
        << "=======================================" << reset << endl
        << "\t" << bg_red << black 
        << "|| Encryption and Decryption program ||" << reset << endl
        << "\t" << bg_red << black
        << "=======================================" << reset << endl << endl;
   cout << "Voer tekst in: ";
   getline( cin, tekst);
   
   //TODO
   cout << "Encrypt (" << blue << "E" << reset << ") "
        << "or Decrypt (" << blue << "D" << reset << "): " << blue;
   getline( cin, command);
   cout << reset;
   
   ///Decrypt
   const string klinkers = "aeiouy";
   string::iterator pos;
   stack<char> stk;
   deque<char> dqe;
   string output;
   //Fase 1
   cout << blue << setw(3) << right << "/|" << white << " Fase 1" << endl
        << blue << "//" << endl;
   for( pos = tekst.begin(); pos != tekst.end(); ++pos){
      if(klinkers.find(*pos) == string::npos){
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << setw(2) << left << *pos << "!klinker --> to stack" << endl;
	 }
	 stk.push(*pos); 
      }
      else {
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << setw(3) << left << *pos << "klinker --> all to deque"<<endl;
	 }
	 while(!stk.empty()){
	    dqe.push_back(stk.top());
	    stk.pop();
	 }	 
	 dqe.push_back(*pos);
      }
   }
   //end of string, make sure stack is empty as well
   while(!stk.empty()){ 
      dqe.push_back(stk.top());
      stk.pop();
   }
   
   if(DEBUG){
      cout << blue << "|| " << white << "result of Fase 1:" << endl
           << blue << "|| " << reset;
      deque<char>::iterator itr;
      for (itr = dqe.begin(); itr != dqe.end(); ++itr)
	 cout << *itr << " ";
      cout << endl << blue << "\\\\" << endl 
           << setw(3) << right << "\\|" << reset << endl;
   }

   //Fase 2
   cout << blue << setw(3) << right << "/|" << white << " Fase 2" << endl
   << blue << "//" << endl;
   int deque_size = dqe.size(); //hij wordt namelijk kleiner als je er mee werkt
   for(int i = 0; i < deque_size; ++i){
      if(i%2 == 1){
	 char x = dqe.back();
	 dqe.pop_back();	
	 cout << blue << "|| " << reset
	      << x << " from " << setw(6) << left 
	      << "back" << "--> to string" << endl;
	 output += x;
      }
      else {
	 char x = dqe.front();
	 dqe.pop_front();
	 cout << blue << "|| " << reset
	      << x << " from front --> to string" << endl;
	 output += x;      
      }      
   }
   if(DEBUG){
      cout << blue << "|| " << white << "result of Fase 2:" << endl
      << blue << "|| " << reset;
      string::iterator pos;
      for( pos = output.begin(); pos != output.end(); ++pos)
	 cout << *pos << " ";
      cout << endl << blue << "\\\\" << endl 
	   << setw(3) << right << "\\|" << reset << endl;
   }
    
   
   cout << green << left << setw(16) << "Plain text: " 
        << reset << tekst << endl;
   cout << red << left << setw(16) << "Encrypted text: " 
        << reset << output << endl;
   
   return 0;
}
