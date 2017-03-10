// Implementatie van klasse Stand.

#include "stand.h"
#include <iostream>
#include <iomanip>

#include "standaard.h"
using namespace std;

//*************************************************************************

Stand::Stand()
{
  // eventueel TODO: implementeren

}

//*************************************************************************

Stand::Stand (int waardeM, int waardeN)
{
	m = waardeM;
	n = waardeN;
	zetnr = 1;
	init_board();
}

//*************************************************************************

Stand::~Stand ()
{ 
  // eventueel TODO: implementeren

}  // ~Stand

//*************************************************************************


/**
Initialiseert het bord naar 0.
**/
void Stand::init_board(){
	for(int i = 0; i < getM(); i++){
		for(int j = 0; j < getN(); j++){
			bord[i][j] = 0;
		}
	}
}

//*************************************************************************
//Return M.
int Stand::getM ()
{
  return m;
}

//*************************************************************************
//Return N.
int Stand::getN ()
{
  return n;
}
//Return zetnr.
int Stand::getZetnr ()
{
  return zetnr;
}

//Verandert de waar van zetnr. 
void Stand::setZetnr (int nr)
{
  zetnr = nr;
}

//Incrementeert zetnr met 1.
void Stand::incZetnr ()
{
  zetnr++;
}

//*************************************************************************

//Druk het bord af van grootte m bij n.
void Stand::drukaf ()
{
    for(int i = 0; i < getN(); i++){
        cout << " " << i << " "; 
    }
    cout << endl;
	for(int i = 0; i < getM(); i++){
		for(int t = 0; t < getN(); t++){
		cout << "---";
		}
		cout << endl;
		for(int j = 0; j < getN(); j++){
			if(bord[i][j] > 0){	cout << "|" << bord[i][j] << "|";}
			else{ cout << "|" << " " << "|";}
		}
		cout << " " << i << endl;
	}
	for(int t = 0; t < getN(); t++){
	cout << "---";
	}
	cout << endl;
}  // drukaf

//*************************************************************************
//Returns true wanneer het mogelijk is om een steen op het bord te leggen
//op een bepaalde positie gespecificeerd bij rij, kolom en steennr op een 
//bepaalde stand bord[][].
//PARAMS
//int rij, index van de rij van het bord.
//int kolom, index van de kolom van het bord.
//int steennr, de rotatie van een steen.
//int bord[][], de huidige stand van het bord.
bool Stand::steenmogelijk(int rij, int kolom, int steennr, int bord[][Nmax])
{
    switch(steennr){
    case 0:
        if(bord[rij][kolom] == 0&&
        bord[rij+1][kolom] == 0 &&
        bord[rij][kolom+1] == 0){
        return true;
        }
    break;
    case 1:
        if(bord[rij][kolom] == 0&&
        bord[rij][kolom+1] == 0 &&
        bord[rij+1][kolom+1] == 0){
        return true;
        }
    break;
    case 2:
        if(bord[rij+1][kolom] == 0&&
        bord[rij][kolom+1] == 0 &&
        bord[rij+1][kolom+1] == 0){
        return true;
        }
    break;
    case 3:
        if(bord[rij][kolom] == 0&&
        bord[rij+1][kolom] == 0 &&
        bord[rij+1][kolom+1] == 0){
        return true;
        }
    break;
    }
    return false;
}

/**
Returns true wanneer een steen is geplaatst op een bord.
PARAMS
int rij, index van de rij van het bord.
int kolom, index van de kolom van het bord.
int steennr, de rotatie van een steen.
int bord[][], de huidige stand van het bord.
int zetnr, het nummer van de steen die wordt geplaatst.
**/
bool Stand::doeZet (int rij, int kolom, int steennr, int bord[][Nmax], int zetnr)
{   
    if(steennr >= 0 && rij >=0 && kolom >= 0 && rij < getM()-1 && kolom < getN()-1 && steennr < 4 ){ 
        if(steenmogelijk(rij, kolom, steennr, bord) || zetnr == 0){
            switch(steennr){
            case 0:
                bord[rij][kolom] = zetnr;
                bord[rij+1][kolom] = zetnr; 
                bord[rij][kolom+1] = zetnr;
            break;
            case 1:
                bord[rij][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            case 2:
                bord[rij+1][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            case 3:
                bord[rij][kolom] = zetnr;
                bord[rij+1][kolom] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            }
            incZetnr();
            return true;
        } 
        return false;
    }
    return false;
	
}  // legsteenneer

/**
Returns true wanneer een steen is geplaatst op een bord.
PARAMS
int rij, index van de rij van het bord.
int kolom, index van de kolom van het bord.
int steennr, de rotatie van een steen.
int bord[][], de huidige stand van het bord.
**/
bool Stand::legsteenneer (int rij, int kolom, int steennr)
{   
   return doeZet(rij, kolom, steennr, bord, getZetnr());
	
}  // legsteenneer

//*************************************************************************
/**
Returns true wanneer een bepaalde stand de eindstand is.
PARAMS
int stand[][], de huidige stand van het bord.
**/
bool Stand::huidigeEindstand (int stand[][Nmax])
{
  for(int i = 0; i< getM()-1; i++){
    for(int j = 0; j< getN()-1; j++){
        for(int k = 0; k < 4; k++){
            if(steenmogelijk(i, j, k, stand)){
            return false;
            }
        }
    }
  }
  return true;

}  // eindstand

/**
Returns true wanneer de stand van het bord de eindstand is.
**/
bool Stand::eindstand ()
{
  return huidigeEindstand(bord);

}  // eindstand

//*************************************************************************
/**
Returns het aantal mogelijke zetten vanuit een gegeven stand.
PARAMS
int temp[][], een array waarin alle mogelijke zetten worden opgeslagen
int stand[][], de huidige stand van het bord.
**/
int Stand::aantalmogelijkeZetten(int temp[][3], int stand[][Nmax]){
    int counter = 0;
    for(int i = 0; i< getM()-1; i++){
        for(int j = 0; j< getN()-1; j++){
            for(int k = 0; k < 4; k++){
                if(steenmogelijk(i, j, k, stand)){
                temp[counter][0] = i;
                temp[counter][1] = j;
                temp[counter][2] = k;
                counter++;
                }
            }
        }
  }
  
  return counter;
}

/**
Legt een steen neer op een random mogelijke lokatie.
**/
void Stand::doerandomzet ()
{
  int mogelijkezet[1500][3];
  int aantalzet = aantalmogelijkeZetten(mogelijkezet, bord);
  int random = randomGetal(0, aantalzet-1);
  legsteenneer(mogelijkezet[random][0], mogelijkezet[random][1], mogelijkezet[random][2]);
  

}  // doerandomzet

//*************************************************************************
/**
Zet de waardes van een neergelegde steen weer op 0
PARAMS
int rij, index van de rij van het bord.
int kolom, index van de kolom van het bord.
int steennr, de rotatie van een steen.
int bord[][], de huidige stand van het bord.
**/
void Stand::undoZet(int rij, int kolom, int steennr, int stand[][Nmax]){
	doeZet(rij, kolom, steennr, bord, 0);
}

/**
Returns true wanneer een huidige stand winnend is voor de speler.
PARAMS
int aantal, het aantal bekeken standen.
int wrij, index van de rij van het bord die een winnend stand geeft.
int wkolom, index van de kolom van het bord die een winnend stand geeft.
int wsteennr, de rotatie van een steen die een winnend stand geeft.
int stand[][], de huidige stand van het bord.
**/
bool Stand::win (int &aantal, int &wrij, int &wkolom, int &wsteennr, int stand[][Nmax])
{
	int mogelijkzet[1500][3];
    if(huidigeEindstand(stand)){
    	return false;
    }
    else{
    	for(int i = 0; i < aantalmogelijkeZetten(mogelijkzet, stand); i++){
    		doeZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], stand, getZetnr());
    		aantal++;
    		if(!win(aantal, wrij, wkolom, wsteennr, stand)){
    			undoZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord);
    			wrij = mogelijkzet[i][0];
    			wkolom = mogelijkzet[i][1];
    			wsteennr = mogelijkzet[i][2];
    			return true;	
    		}
    		else{
    			undoZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord);
    		}
    	}
    	return false;
    }
}  // winnend

/**
Returns true wanneer een huidige stand winnend is voor de speler.
PARAMS
int aantal, het aantal bekeken standen.
int wrij, index van de rij van het bord die een winnend stand geeft.
int wkolom, index van de kolom van het bord die een winnend stand geeft.
int wsteennr, de rotatie van een steen die een winnend stand geeft.
**/
bool Stand::winnend (int &aantal, int &wrij, int &wkolom, int &wsteennr){
	int zetnr = getZetnr();
	bool winnend = win(aantal, wrij, wkolom, wsteennr, bord);
	setZetnr(zetnr);
	return winnend;	
}


//*************************************************************************
/**
Returns Telt het totale aantal standen waarin de speler wint of verliest.
PARAMS
float totaal, het totaal aantal standen waarin een spel is afgelopen.
float gewonnen, het totaal aantal gewonnen standen.
bool aanzet, true als speler aan de beurt is.
**/
void Stand::telwinnend(float & totaal, float & gewonnen, bool aanzet){
	
	int mogelijkzet[1500][3];
	if(eindstand()){
		totaal = 1;
		gewonnen = aanzet ? 1 : 0;
	}
	else{
		for(int i = 0; i < aantalmogelijkeZetten(mogelijkzet, bord); i++){
			doeZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord, getZetnr());
			
			float temptotaal, tempgewonnen;
			telwinnend(temptotaal, tempgewonnen, !aanzet);

			totaal += temptotaal;
			gewonnen += tempgewonnen;
			undoZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord);
		}		
	}
}

/**
Bepaalt de goede zet als een winnende zet niet bestaat
De goede zet heeft het hoogste kans tot het
leiden naar een winnende zet.
PARAMS
int grij, de index van een rij van een goede zet
int gkolom, de index van een kolom van een goede zet 
int gsteennr, de rotatie van een steen an een goede zet
**/
bool Stand::goedezet(int &grij, int &gkolom, int &gsteennr)
{	float totaal, gewonnen;
	int zetnum = getZetnr();

	float verhouding, hoogste;
	int mogelijkzet[1500][3]
						  ;
	for(int i = 0; i < aantalmogelijkeZetten(mogelijkzet, bord); i++){
			doeZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord, getZetnr());
			totaal = 0;
			gewonnen = 0;
			telwinnend(totaal, gewonnen, true);
			undoZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord);
						
			verhouding = (float)gewonnen / (float)totaal;
			
			if(verhouding > hoogste){
				hoogste = verhouding;
				grij = mogelijkzet[i][0];
				gkolom = mogelijkzet[i][1];
				gsteennr = mogelijkzet[i][2];	
			}
			if(verhouding == 0){
				grij = 0;
				gkolom = 0;
				gsteennr = 0;
			}
	}
	setZetnr(zetnum);
	return false;
}  // goedezetint


/**
Bepaalt de goede zet als een winnende zet niet bestaat
De goede zet heeft het hoogste kans tot het
leiden naar een winnende zet.
PARAMS
int grij, de index van een rij van een goede zet
int gkolom, de index van een kolom van een goede zet 
int gsteennr, de rotatie van een steen an een goede zet
float hoogste, de kans dat de positie van de steen leidt tot 
een winnende stand. 
**/
void Stand::goedezetEX(int &grij, int &gkolom, int &gsteennr, float &hoogste){
	float totaal, gewonnen;
	int zetnum = getZetnr();
		float verhouding;
		int mogelijkzet[1500][3]
							  ;
		for(int i = 0; i < aantalmogelijkeZetten(mogelijkzet, bord); i++){
				doeZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord, getZetnr());
				totaal = 0;
				gewonnen = 0;
				telwinnend(totaal, gewonnen, true);
				undoZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], bord);
							
				verhouding = (float)gewonnen / (float)totaal;

				if(verhouding > hoogste){
					hoogste = verhouding;
					grij = mogelijkzet[i][0];
					gkolom = mogelijkzet[i][1];
					gsteennr = mogelijkzet[i][2];
				}
				if(verhouding == 0){
					grij = 0;
					gkolom = 0;
					gsteennr = 0;
				}
		}
		setZetnr(zetnum);
}
