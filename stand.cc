// Implementatie van klasse Stand.

#include "stand.h"
#include <iostream>
#include <iomanip>

#include "standaard.h"
using namespace std;

#define RB 12;

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

int Stand::getM ()
{
  return m;
}

//*************************************************************************

int Stand::getN ()
{
  return n;
}

int Stand::getZetnr ()
{
  return zetnr;
}

void Stand::setZetnr (int nr)
{
  zetnr = nr;
}

void Stand::incZetnr ()
{
  zetnr++;
}

//*************************************************************************

void Stand::drukaf ()
{
    for(int i = 0; i < getM(); i++){
        cout << " " << i << " "; 
    }
    cout << endl;
	for(int i = 0; i < getM(); i++){
		for(int t = 0; t < getM(); t++){
		cout << "---";
		}
		cout << endl;
		for(int j = 0; j < getN(); j++){
			if(bord[i][j] > 0){	cout << "|" << bord[i][j] << "|";}
			else{ cout << "|" << " " << "|";}
		}
		cout << " " << i << endl;
	}
	for(int t = 0; t < getM(); t++){
	cout << "---";
	}
	cout << endl;
}  // drukaf

//*************************************************************************
bool Stand::steenmogelijk(int rij, int kolom, int steennr)
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
        bord[rij+1][kolom] == 0 &&
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
        bord[rij][kolom+1] == 0 &&
        bord[rij+1][kolom+1] == 0){
        return true;
        }
    break;
    }
    return false;
}
bool Stand::legsteenneer (int rij, int kolom, int steennr)
{   
    if(steennr >= 0 && rij >=0 && kolom >= 0 && rij < getM()-1 && kolom < getN()-1 && steennr < 4 ){ 
        if(steenmogelijk(rij, kolom, steennr)){
            switch(steennr){
            case 0:
                bord[rij][kolom] = zetnr;
                bord[rij+1][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
            break;
            case 1:
                bord[rij][kolom] = zetnr;
                bord[rij+1][kolom] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            case 2:
                bord[rij+1][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            case 3:
                bord[rij][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            }
            incZetnr();
            return true;
        }
        cout << "zet niet mogelijk" << endl; 
        return false;
    }
    return false;
	
}  // legsteenneer

//*************************************************************************

bool Stand::eindstand ()
{
  for(int i = 0; i< getM()-1; i++){
    for(int j = 0; j< getN()-1; j++){
        for(int k = 0; k < 4; k++){
            if(steenmogelijk(i, j, k)){
            return false;
            }
        }
    }
  }
  return true;

}  // eindstand

//*************************************************************************
int Stand::aantalmogelijkeZetten(int temp[][3]){
    int counter = 0;
    for(int i = 0; i< getM()-1; i++){
        for(int j = 0; j< getN()-1; j++){
            for(int k = 0; k < 4; k++){
                if(steenmogelijk(i, j, k)){
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
void Stand::doerandomzet ()
{
  int mogelijkezet[1500][3];
  int aantalzet = aantalmogelijkeZetten(mogelijkezet);
  int random = randomGetal(0, aantalzet-1);
  legsteenneer(mogelijkezet[random][0], mogelijkezet[random][1], mogelijkezet[random][2]);
  

}  // doerandomzet

//*************************************************************************

int Stand::wAantalmogelijkeZetten(int temp[][3], int stand[][Nmax]){
    int counter = 0;
    for(int i = 0; i< getM()-1; i++){
        for(int j = 0; j< getN()-1; j++){
            for(int k = 0; k < 4; k++){
                if(wSteenmogelijk(i, j, k, stand)){
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

bool Stand::wEindstand (int stand[][Nmax])
{
  for(int i = 0; i< getM()-1; i++){
    for(int j = 0; j< getN()-1; j++){
        for(int k = 0; k < 4; k++){
            if(wSteenmogelijk(i, j, k, stand)){
            return false;
            }
        }
    }
  }
  return true;

}  // eindstand

bool Stand::wSteenmogelijk(int rij, int kolom, int steennr, int bord[][Nmax])
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
        bord[rij+1][kolom] == 0 &&
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
        bord[rij][kolom+1] == 0 &&
        bord[rij+1][kolom+1] == 0){
        return true;
        }
    break;
    }
    return false;
}

bool Stand::doeZet (int rij, int kolom, int steennr, int stand[][Nmax])
{   
    if(steennr >= 0 && rij >=0 && kolom >= 0 && rij < getM()-1 && kolom < getN()-1 && steennr < 4 ){ 
        if(wSteenmogelijk(rij, kolom, steennr, stand)){
            switch(steennr){
            case 0:
                bord[rij][kolom] = zetnr;
                bord[rij+1][kolom] = zetnr; 
                bord[rij][kolom+1] = zetnr;
            break;
            case 1:
                bord[rij][kolom] = zetnr;
                bord[rij+1][kolom] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            case 2:
                bord[rij+1][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
                bord[rij+1][kolom+1] = zetnr;
            break;
            case 3:
                bord[rij][kolom] = zetnr;
                bord[rij][kolom+1] = zetnr;
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

void Stand::copyBord(int a1[][Nmax], int a2[][Nmax]){
	for(int i = 0; i < getM(); i++){
		for(int j = 0; j < getN(); j++){
			a2[i][j] = a1[i][j];
		}
	}
	
}


bool Stand::win (int &aantal, int &wrij, int &wkolom, int &wsteennr, int stand[][Nmax], int mogelijkzet[][3], int kopie[][Nmax])
{
    if(wEindstand(stand)){
    	return false;
    }
    else{
    	for(int i = 0; i < wAantalmogelijkeZetten(mogelijkzet, stand); i++){
    		doeZet(mogelijkzet[i][0], mogelijkzet[i][1], mogelijkzet[i][2], stand);
    		drukaf();
    		if(!win(aantal, wrij, wkolom, wsteennr, stand, mogelijkzet, kopie)){
    			copyBord(kopie, stand);
    			wrij = mogelijkzet[i][0];
    			wkolom = mogelijkzet[i][1];
    			wsteennr = mogelijkzet[i][2];
    			return true;
    		}
    		else{
    			aantal++;
    			copyBord(kopie, stand);
    		}
    	}
    }
    return false;
}  // winnend

bool Stand::winnend (int &aantal, int &wrij, int &wkolom, int &wsteennr){
	int mogelijkzet[1500][3];
	int kopie[Mmax][Nmax];
	copyBord(bord,kopie);
	return win(aantal, wrij, wkolom, wsteennr, bord, mogelijkzet, kopie);	
}


//*************************************************************************

bool Stand::goedezet (int &grij, int &gkolom, int &gsteennr)
{
  cout << "Methode goedezet is nog niet geimplementeerd." << endl;
  // TODO: implementeren

  grij = 0;
  gkolom = 0;
  gsteennr = 0;
  return true;

}  // goedezet

void Stand::init_board(){
	for(int i = 0; i < getM(); i++){
		for(int j = 0; j < getN(); j++){
			bord[i][j] = 0;
		}
	}


}

