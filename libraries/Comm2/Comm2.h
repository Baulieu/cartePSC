/*
 implémentation du système de communication entre les cartes - côté carte 2.
 */

#include "Arduino.h"


#ifndef Comm2_h
#define Comm2_h

class Comm2
{
  public:
    Comm2(int attenteMax);
    int reception(); //reçoit ce qu'envoit la carte 1. Si elle retourne -1, c'est que la carte 2 merde.
  private:
    int _attenteMax; //nombre max de fois que la carte attend une réponse de l'autre carte. à chaque boucle, on a attendu 10ms.
    int _pin_envoi;
    int _pin_reception;
    int _pin_alive;
    int _pin_valeur;
    int _i;
    int _valeur;
};

#endif