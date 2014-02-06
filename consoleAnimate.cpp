#include <ConsoleColorLinux.h>
#include <iostream>
#include <unistd.h>
#include <chrono>

using namespace std;

typedef chrono::high_resolution_clock highc;

int main(){
   
   while(true){
      cout << "\033[2J\033[H";
      for (int loc = 0; loc<80; loc++){
	 for(int i=0; i<80; i++){
	    if (i == loc){
	       cout << "&";
	    }
	    else{
	       cout << "-";
	    }
	 }
	 auto start = highc::now();
         auto time = highc::now();
	 int adj = 0;
	 while( adj < 100){
	    time = highc::now();
	    auto timetaken = time - start;
	    adj = int (timetaken.count() / 100);
	    //cout << adj << endl;
	 }
	 cout << endl;
	 //cin.ignore();
	 cout << "\033[2K\033[H";
      }
      //cout << "\033[2J" ;
   }  
}