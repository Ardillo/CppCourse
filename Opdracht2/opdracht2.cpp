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
#include <ConsoleColorLinux.h>

using namespace std;

int main() {

   return 0;
}
