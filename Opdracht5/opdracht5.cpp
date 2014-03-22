/*
 * naam: Jeroen van Prooijen
 * stud.nr: 1595111
 * 
 * datum: 22-03-2014
 * 
 * Bescrhijving:
 * Practicum opdracht 5
 * H12.13: opgave 1
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <ConsoleColorLinux.h>

#define DEBUG

class Node{
private:
   int getal;
   Node* p;
public:
   Node(int i = 0, Node* next = NULL)
   : getal(i), p(next){}
   
   const int getGetal() const{
      return getal;
   }
   
   Node* getNext() const{
      return p;
   }
   
   void setGetal(int x){
      getal = x;
   }
   
   void setNext(Node* ptr){
      p = ptr;
   }
      
   friend class Lijst;
};

class Container{
private:
   unsigned maxAantal;
   int aantal;
   Node* p; //fout in boek?, -> "int* p // pointer naar dynamische array"
public:
   Container( int max );
   ~Container();
   void voegtoe( int a );
   int tel ( int a )const;
   friend ostream& operator<< (ostream& out, const Container& cnt);
};

int main(){
   
   string tmp;
   cout << "Geef formaat van container (int): ";
   getline(cin, tmp);
   
   int size = atoi(tmp.c_str());
   Container container(size);
   
   cout << "Geef integers op: " << endl;
   for( int i=1; i<=size; ++i){
     cout << i << ") ";
     getline(cin, tmp);
     container.voegtoe(atoi(tmp.c_str()));           
   }
   
   cout << container << endl;
   
   cout << "Geef integer om te tellen: ";
   getline(cin, tmp);
   cout << "Er is/zijn " << container.tel(atoi(tmp.c_str()))
        << " element(en) met de waarde " << tmp << endl;
}

///--------------------------------------
// Class functions
///--------------------------------------
Container :: Container ( int max )
  : maxAantal(max), aantal(0), p(NULL){}

Container :: ~Container(){
   Node* ptr = p, *tmpNext;
   while( ptr != NULL){
      tmpNext = ptr -> getNext();
      #ifdef DEBUG
      cout << red << "Node @ " << ptr 
	   << " with value: "   << ptr -> getGetal()  
	   << " --> is getting destroyed NOW!" << reset << endl;
      #endif
      delete ptr;
      ptr = tmpNext;
   }
}

void Container :: voegtoe(int a){
   if( (aantal+1) > maxAantal){
      cout << "ERROR limit reached" << endl;
   } 
   else{      
      //toevoegen      
      p = new Node(a, p);
      aantal++;
      
      //sorteren
      Node *current = p;
      for(int i = 1 ; i < aantal; ++i){		 // i=0 als start is segfault
	 Node *next = current -> getNext();      
	 int currentVal = current -> getGetal(); // waarde huidige node
	 int nextVal = next -> getGetal();       // waarde van volgende node
	 if(currentVal > nextVal){               // als huidig > volgende
	    current -> setGetal(nextVal);        // wissel waarde van node
	    next -> setGetal(currentVal);
	    current = current -> getNext();      // increment pointer
	 }
      }
   }
}

int Container :: tel ( int a )const{
   Node *ptr = p;
   int count = 0;
   while( ptr != NULL){
      if(ptr -> getGetal() == a)
	 ++count;
      ptr = ptr -> getNext();
   }
   return count;
}

ostream& operator<< (ostream& out, const Container& cntr){
      Node* ptr = cntr.p;
      while( ptr!= NULL ){
	 #ifdef DEBUG
	 out << right << setfill(' ') 
	     << "-----------------------" << endl 
	     << "| address: "  << setw(10) << ptr << " |" << endl
    	     << "-----------------------" << endl   	     
	     << "| value: "    << setw(12) << ptr -> getGetal() << " |" << endl
	     << "| next ptr: " << setw(9) << ptr -> getNext() << " |" << endl
	     << "-----------------------" << endl
	     << setfill(' ')
	     << setw(11) <<  "|" << endl
	     << setw(12) << "\\|/" << endl
	     << setw(11) <<  "v" << endl;
	 #else
	 out << "|" << ptr -> getGetal();
	 #endif
	 ptr = ptr -> getNext();	 
      }
      #ifdef DEBUG
      out << "-----------------------" << endl
          << "|        NULL         |" << endl
          << "-----------------------" ;
      #else
      out << '|' << endl;
      #endif
	  
      return out;
   }