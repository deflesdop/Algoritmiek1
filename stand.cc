// Implementatie van klasse Stand.

#include <iostream>
#include <iomanip>
#include "stand.h"
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
  cout << "Constructor is nog niet geimplementeerd." << endl;
  // TODO: implementeren

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
  cout << "Methode drukaf is nog niet geimplementeerd." << endl;
  // TODO: implementeren

}  // drukaf

//*************************************************************************

bool Stand::legsteenneer (int rij, int kolom, int steennr)
{
  cout << "Methode legsteenneer is nog niet geimplementeerd." << endl;
  // TODO: implementeren

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

