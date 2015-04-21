/*
 implémentation du système de communication entre les cartes - côté carte 1.
 */

#include "Arduino.h"


#ifndef Comm1_h
#define Comm1_h

class Comm1
{
  public:
    Comm1();
    bool envoi(int valeur);
  private:
    int _attenteMax; //nombre max de fois que la carte attend une réponse de l'autre carte. à chaque boucle, on a attendu 10ms.
    int _pin_envoi;
    int _pin_reception;
    int _pin_alive;
    int _pin_valeur;
    int _i;
};

#endif