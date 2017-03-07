// Implementatie van klasse Stand.

#include "stand.h"
#include <iostream>
#include <iomanip>

#include "standaard.h"
using namespace std;

#define RL 12;

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

//*************************************************************************

void Stand::drukaf ()
{
	for(int i = 0; i < getM(); i++){
		for(int t = 0; t < getM(); t++){
		cout << "---";
		}
		cout << endl;
		for(int j = 0; j < getN(); j++){
			if(bord[i][j] > 0){	cout << "|" << bord[i][j] << "|";}
			else{ cout << "|" << " " << "|";}
		}
		cout << endl;
	}
	for(int t = 0; t < getM(); t++){
	cout << "---";
	}
	cout << endl;
}  // drukaf

//*************************************************************************

bool Stand::legsteenneer (int rij, int kolom, int steennr)
{

	return true;
}  // legsteenneer

//*************************************************************************

bool Stand::eindstand ()
{
  cout << "Methode eindstand is nog niet geimplementeerd." << endl;
  // TODO: implementeren

  return false;

}  // eindstand

//*************************************************************************

void Stand::doerandomzet ()
{
  cout << "Methode doerandomzet is nog niet geimplementeerd." << endl;
  // TODO: implementeren

}  // doerandomzet

//*************************************************************************

bool Stand::winnend (int &aantal, int &wrij, int &wkolom, int &wsteennr)
{
  cout << "Methode winnend is nog niet geimplementeerd." << endl;
  // TODO: implementeren

  wrij = 0;
  wkolom = 0;
  wsteennr = 0;
  return true;

}  // winnend

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

