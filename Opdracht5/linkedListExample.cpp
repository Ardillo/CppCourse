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
#include <ConsoleColorLinux.h>

#define DEBUG

class Node{
private:
   int getal;
   Node* p;
public:
   Node(int i = 0, Node* next = NULL)
   : getal(i), p(next){}
   
   int getGetal() {
      return getal;
   }
   
   Node* getNext(){
      return p;
   }
   friend class Lijst;
};

class Lijst{
private:
   Node* kop;
public:
   Lijst()
   : kop(NULL){}
   
   ~Lijst(){
      Node* ptr = kop, *tmpNext;
      while(ptr!=NULL){
	 tmpNext = ptr -> getNext();
#ifdef DEBUG
	 cout << red << "Node @ " << ptr 
	      << " with value: "   << ptr -> getGetal() 
	      << " --> is getting destroyed NOW" << reset << endl;
#endif
	 delete ptr;
	 ptr = tmpNext;
      }
   }
   
   void voegtoe(int x){
      kop = new Node(x, kop);
   }
   
   friend ostream& operator<< (ostream& out, const Lijst& lijst){
      Node* ptr = lijst.kop;
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
	     out << "value " << ptr -> getGetal() << endl;
#endif
	 ptr = ptr -> getNext();	 
      }
#ifdef DEBUG
      out << "-----------------------" << endl
          << "|        NULL         |" << endl
          << "-----------------------" << endl;
#endif
      return out;
   }
  
};

int main(){

 Lijst lijst;
 lijst.voegtoe(2);
 lijst.voegtoe(7);
 lijst.voegtoe(1); 
 
 cout << lijst << endl;
}