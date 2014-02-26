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
 ********** CODEREN ************
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
 ********* DECODEREN **************
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
#include <queue>
#include <ConsoleColorLinux.h>

using namespace std;

typedef enum {encrypt, decrypt} function;

void printHeader();
void functionQuestion(function &f);
string getText();
string codeer(string &input);
string decodeer(string &input);
void printResult(string &input, string &output, function &func);
void again();
void eop();

const bool DEBUG = true;
bool end = false;
function func;

//Main program
int main() {
   printHeader();
   while(!end){	        
      functionQuestion(func);
      string input = getText();
      string output;
      if(func == encrypt)	 
	 output = codeer(input);
      else if(func == decrypt)
	 output = decodeer(input);
      printResult(input, output, func);
      again();
   }
   eop();
   return 0;
}

//Just a intro header
void printHeader(){
   cout << endl << "\t" << bg_red << black 
        << "=======================================" << reset << endl
        << "\t" << bg_red << black 
        << "|| Encryption and Decryption program ||" << reset << endl
        << "\t" << bg_red << black
        << "=======================================" << reset << endl << endl;
}

//Question what the program should do, Encrypt or Decrypt
void functionQuestion(function &f){
   bool done = false;
   while(!done){
      string command = "";
      cout << "Encrypt (" << blue << "E" << reset << ") "
	 << "or Decrypt (" << blue << "D" << reset << "): " << blue;
      getline( cin, command); 
      cout << reset;
      
      if(command == "E"){
	 f = encrypt; 
	 done = true;
      }
      else if(command == "D"){
	 f = decrypt;
         done = true;
      }
      else
	 cout << red << "Error, not a valid option" << reset << endl;
   }
}

//Function for getting input text for algorithm
string getText(){
   string txt;
   cout << "Fill in text: " << endl;
   getline( cin, txt);
   return txt;
}

//Encrypting algorithm
string codeer(string &input){
   cout << blue << "    ENCRYPTING" << endl;
   const string klinkers = "aeiouy";
   string::iterator pos;
   stack<char> stk;
   deque<char> dqe;
   string output;
   //Fase 1
   if(DEBUG){
      cout << blue << setw(3) << right << "/|" << white << " Fase 1" << endl
	   << blue << "//" << endl;
   }
   for( pos = input.begin(); pos != input.end(); ++pos){
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
   if(DEBUG){
      cout << blue << setw(3) << right << "/|" << white << " Fase 2" << endl
	   << blue << "//" << endl;
   }
   int deque_size = dqe.size(); //hij wordt namelijk kleiner als je er mee werkt
   for(int i = 0; i < deque_size; ++i){
      if(i%2 == 1){
	 char x = dqe.back();
	 dqe.pop_back();	
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << x << " from " << setw(6) << left 
	         << "back" << "--> to string" << endl;
	 }
	 output += x;
      }
      else {
	 char x = dqe.front();
	 dqe.pop_front();
	 if(DEBUG){ 
	    cout << blue << "|| " << reset
	         << x << " from front --> to string" << endl;
	 }
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
   return output;
}

//Decrypting algorithm
string decodeer(string &input){
   cout << blue << "    DECRYPTING" << endl;
   const string klinkers = "aeiouy";
   string::iterator pos;
   queue<char> q;
   stack<char> s;
   string output, EOFase1;
   
   //Fase 1
   if(DEBUG){
      cout << blue << setw(3) << right << "/|" << white << " Fase 1" << endl
	   << blue << "//" << endl;
   }
  
   for(int i = 0; i <input.size(); ++i){
      if(i%2 == 0){
	 char x = input.at(i);
	 q.push(x);
	 EOFase1 = x + EOFase1;
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << x << " --> to queue" << endl;	 
	 }
      }
      else{
	 char x = input.at(i);
	 s.push(x);
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << x << " --> to stack" << endl;
	 }
      }
   }
   while(!s.empty()){
      q.push(s.top());
      EOFase1 = s.top() + EOFase1;
      s.pop();
   }
   
   if(DEBUG){
      cout << blue << "|| " << white << "result of Fase 1:" << endl
           << blue << "|| " << reset << "in--> ";
      for(pos = EOFase1.begin(); pos != EOFase1.end(); ++pos){
	 cout << *pos << " ";  
      }
      cout << "-->out";
      cout << endl << blue << "\\\\" << endl 
	   << setw(3) << right << "\\|" << reset << endl;
   }
   
   //Fase 2
   if(DEBUG){
      cout << blue << setw(3) << right << "/|" << white << " Fase 2" << endl
	   << blue << "//" << endl;
   }
   while(!q.empty()){
      char x = q.front();
      if(klinkers.find(x) == string::npos){
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << setw(2) << left << x << "!klinker --> to stack" << endl;
	 }
	 s.push(x);
         q.pop();
      }
      else{
	 if(DEBUG){
	    cout << blue << "|| " << reset
	         << setw(3) << left << x << "klinker --> all to string" << endl;
	 }
	 while(!s.empty()){
	    output += s.top();
	    s.pop();
	 }
	 output += x;
	 q.pop();	 
      }     
   }
   while(!s.empty()){
      output += s.top();
      s.pop();
   }
   
   if(DEBUG){
      cout << blue << "|| " << white << "result of Fase 2:" << endl
           << blue << "|| " << reset;
      for(pos = output.begin(); pos != output.end(); ++pos){
	 cout << *pos << " ";  
      }
      cout << endl << blue << "\\\\" << endl 
	   << setw(3) << right << "\\|" << reset << endl;	   
   }
   return output;
}

//Prints results depending if your are encrypting or decrypting
void printResult(string &input, string &output, function &func){
   cout << endl;
   if(func == encrypt){
      cout << green << left << setw(16) << "Plain text: " 
	   << reset << input << endl;
      cout << red << left << setw(16) << "Encrypted text: " 
	   << reset << output << endl << endl;
   }
   else{
      cout << green << left << setw(16) << "Encrypted text: " 
	   << reset << input << endl;
      cout << red << left << setw(16) << "Plain text: " 
	   << reset << output << endl << endl;
   }  
}

//Question for restart program
void again(){
   cout << "Restart again? (Y/n)";
   string answer;
   getline(cin, answer);
   if(answer == "n")
      end = true;
}  

//Finish program string
void eop(){
   cout << bg_black << red << "End of program" << reset << endl << endl;
}
