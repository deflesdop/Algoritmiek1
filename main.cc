// Hoofdprogramma voor oplossing voor eerste programmeeropdracht Algoritmiek,
// voorjaar 2017: Stenen Leggen.
//
// Biedt de gebruiker een menustructuur om
// * het spel te spelen tegen een optimaal of random spelende computer;
//   bij elke zet krijgt de gebruiker een suggestie voor een winnende zet
//   of een goede zet
// * experimenten te doen
//
// Andrew Huang (s1913999)
// Micha de Jong (s1821784)
// 10-03-2017

#include <iostream>
#include "standaard.h"
#include "stand.h"
#include <ctime>
using namespace std;

//*************************************************************************

// Vraag de gebruiker wie er begint bij het spel:
// 1. gebruiker
// 2. optimale computer
// 3. random computer
int vraagbeginner ()
{ int keuze;

  do
  { cout << endl;
    cout << "Wie begint met spelen:" << endl;
    cout << "1. Gebruiker" << endl;
    cout << "2. Optimale computer" << endl;
    cout << "3. Random computer" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    
    if (keuze<1 || keuze>3)
    { cout << endl;
      cout << "Voer een goede keuze in!" << endl;
    }
  } while (keuze<1 || keuze>3);

  return keuze;

}  // hoofdmenu

//*************************************************************************

// Speel het spel vanaf stand s1.
// Hierbij krijgt de gebruiker herhaaldelijk de keuze om een zet tegen
// een optimaal of een random spelende computer in te voeren.
// Als dat een toegestane zet is, wordt die uitgevoerd,
// waarna het programma een (zo mogelijk) optimale of randomzet doet.
// Na iedere zet wordt de stand afgedrukt.
// Als de gebruiker aan de beurt is, doet het programma eerst nog
// * een suggestie voor een winnende zet (als die bestaat),
// * een suggestie voor een goede zet (als er geen winnende zet bestaat)
//
// Dit alles gaat door
// * totdat er een eindstand is bereikt
// * of totdat de gebruiker aangeeft dat hij wil stoppen met het spel
void doespel (Stand *s1)
{ int m, n,
      beginner,
      keuze,
      rij, kolom, steennr,
      wrij, wkolom, wsteennr,  // winnende zet
      grij, gkolom, gsteennr,  // goede zet
      aantal;  // aantal bekeken standen bij aanroep van winnend

  m = s1 -> getM ();
  n = s1 -> getN ();

  beginner = vraagbeginner ();  // 1: gebruiker, 2: optimale computer
                                // 3: random computer

  if (!s1->eindstand())
    if (beginner>=2)
    { cout << endl;
      cout << "De computer doet de eerste zet:" << endl;
      if (beginner==2)
      { s1 -> goedezet (grij, gkolom, gsteennr);
          // zo mogelijk een winnende zet
        s1->legsteenneer (grij, gkolom, gsteennr);
      }
      else // beginner = 3
        s1->doerandomzet ();

      s1 -> drukaf ();
    }  // beginner>=2

  keuze = 0;
  while (keuze!=3 && !s1->eindstand())
  {
    aantal = 0;
    cout << endl;
    if (s1->winnend(aantal, wrij, wkolom, wsteennr))
    { cout << "We hebben " << aantal << " standen bekeken." << endl;
      cout << "Een winnende zet is (" << wrij << "," << wkolom << ","
           << wsteennr << ")." << endl;
    }
    else
    { cout << "We hebben " << aantal << " standen bekeken." << endl;
      cout << "We vonden geen winnende zet." << endl;
      s1 -> goedezet (grij, gkolom, gsteennr);
      cout << "Een goede zet is (" << grij << "," << gkolom << ","
           << gsteennr << ")." << endl;
    }

    cout << endl;
    cout << "1. Een zet doen tegen een optimale computer" << endl;
    cout << "2. Een zet doen tegen een random computer" << endl;
    cout << "3. Stoppen met dit spel" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    switch (keuze)
    { case 1: ;
      case 2: cout << endl;
              cout << "Geef het nummer van een rij (0.." << m-1
                   << " vanaf boven): ";
              cin >> rij;
              cout << "Geef het nummer van een kolom (0.." << n-1
                   << " vanaf links): ";
              cin >> kolom;
              cout << "Geef het nummer van een steen: ";
              cin >> steennr;
              
              if (s1->legsteenneer (rij, kolom, steennr))
              { s1 -> drukaf ();
                if (!s1->eindstand())
                { cout << endl;
                  cout << "Nu doet de computer een zet:" << endl;
                  if (keuze==1)
                  { s1 -> goedezet (grij, gkolom, gsteennr);
                      // zo mogelijk een winnende zet
                    s1->legsteenneer (grij, gkolom, gsteennr);
                  }
                  else // keuze = 2
                    s1->doerandomzet ();

                  s1 -> drukaf ();
                }  // geen eindstand
              }
              else
              { cout << endl;
                cout << "De opgegeven zet was niet mogelijk." << endl;
              }
              break;
      case 3: break;
      default: cout << endl;
               cout << "Voer een goede keuze in!" << endl;
    }  // switch

  }  // while

  if (s1->eindstand())
  { cout << endl;
    cout << "De huidige stand is een eindstand.\n";
  }

}  // doespel

//*************************************************************************

// Voert de experimenten uit zoals beschreven op blz 4 van de opdracht.
void doeexperimenten (Stand *s1)
{
	clock_t t;
	bool win;
	int m(2), n(m), aantal(0), wrij, wkolom, wzetnr;
	float verhouding(-1);
	for(m = 2; m <= 5; m++){
		for(n = m; n <= 10; n++){
			s1 = new Stand(m,n);
			t = clock();
			win = s1->winnend(aantal, wrij ,wkolom ,wzetnr);
			t = clock() - t;
			if(win){
				cout << "Win op (" << m << "," << n << ") met " ;
				cout << aantal << " standen bekeken";
				cout << " met een duratie van: " ;
				cout << ((double) t / CLOCKS_PER_SEC) << " secondes,";
				cout << " winnende zet is (" << wrij << "," << wkolom; 
				cout << "," << wzetnr << ")" << endl;
				
				if((m==4 && n==7) || (m==5 && n==6)){ break;}
			}
			else{ 	
				wrij = 0;
				wkolom = 0;
				wzetnr = 0;
				s1 -> goedezetEX(wrij, wkolom, wzetnr, verhouding);
				cout << "Geen win op (" << m << "," << n << ") met "; 
				cout << aantal << " standen bekeken";
				cout << " met een duratie van: " ;
				cout << ((double) t / CLOCKS_PER_SEC) << " secondes,";
				cout << "  maar goede zet is (" << wrij << "," ;
				cout << wkolom << "," << wzetnr << ")";
				cout << "  met kans op winnen: " << verhouding << endl;
			}
			verhouding = -1;
			aantal = 0;
	  }
		if(m==5){break;}
  }
}

void infoblokje(){
    cout << "--------------------------------------------------------"<< endl;
    cout << "Andrew Huang(s1913999) & Micha de Jong(s1821784)." << endl;
    cout << "Studenten aan de Universiteit Leiden."<< endl;
    cout << "In dit programma kan je het spel stenen leggen spelen." << endl;
    cout << "Ook kan je diverse experimenten uitvoeren." << endl;
    cout << "--------------------------------------------------------"<< endl;
  }  

//*************************************************************************

void hoofdmenu ()
{ Stand *s1;  // pointer, om makkeijk nieuwe objecten te kunnen maken
              // en weer weg te gooien
  int keuze,
      m, n;
    infoblokje(); 
  do
  {
    cout << endl;
    cout << "1. Een spel spelen" << endl;
    cout << "2. Experimenten doen" << endl;
    cout << "3. Stoppen" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    switch (keuze)
    { case 1: cout << endl;
              cout << "Geef een waarde voor het aantal rijen van het bord (m): ";
              cin >> m;
              cout << "Geef een waarde voor het aantal kolommen van het bord (n): ";
              cin >> n;
              if (integerInBereik ("m", m, 1, Mmax)
                  && integerInBereik ("n", n, 1, Nmax))
              { s1 = new Stand (m, n);
                s1 -> drukaf ();

                doespel (s1);

                delete s1;  // netjes opruimen
              }
              break;
      case 2: doeexperimenten (s1);
              break;
      case 3: break;
      default: cout << endl;
               cout << "Voer een goede keuze in!" << endl;
    }
  } while (keuze!=3);
}  // hoofdmenu

//*************************************************************************
  
int main ()
{ 
  hoofdmenu ();

  return 0;

}
