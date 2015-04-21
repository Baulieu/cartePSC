/*
 implémentation du système de communication entre les cartes - côté carte 2.
 */

#include "Arduino.h"
#include "Comm2.h"

Comm2::Comm2(int attenteMax)
{
  _attenteMax = attenteMax;
  _pin_envoi = 7; //pin d'émission
  pinMode(_pin_envoi, OUTPUT);
  _pin_reception = 8; //pin de réception
  pinMode(_pin_reception, INPUT);
  _pin_alive = 9; //pin de reception
  pinMode(_pin_alive, INPUT);
  _pin_valeur = 10; //pin de reception de la valeur
  pinMode(_pin_valeur, INPUT);
  _valeur = 0;
}

int Comm2::reception ()
{
  //d'abord, on lit la pin alive. Si elle est à 0, on sort immédiatement, sinon on enclenche la procédure de synchronisation.
  if(digitalRead(_pin_alive) == LOW)
    return -1;
  
  _i = 0;
  while (digitalRead(_pin_reception) == LOW)
  {
    _i++;
    if (_i > _attenteMax)
      return -1;
    delay(10);
  }
  
  //la pin de réception a été mise à 1, on lit la valeur et on met le pin envoi à 1.
  _valeur = analogRead(_pin_valeur);
  digitalWrite(_pin_envoi, HIGH);
  
  // on attend que le pin de réception repasse à 0
  _i = 0;
  while(digitalRead(_pin_reception) == HIGH)
  {
    _i++;
    if (_i > _attenteMax)
      return -1;
    delay(10);
  }
  
  // on termine en remettant le pin d'envoi à 0.
  digitalWrite(_pin_envoi, LOW);
  
  //RAS mon lieutenant
  
  return _valeur;
}