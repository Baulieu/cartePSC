/*
 implémentation du système de communication entre les cartes - côté carte 1.
 */

#include "Arduino.h"
#include "Comm1.h"

Comm1::Comm1(int attenteMax)
{
  _attenteMax = attenteMax;
  _pin_envoi = 7; //pin d'émission
  pinMode(_pin_envoi, OUTPUT);
  _pin_reception = 8; //pin de réception
  pinMode(_pin_reception, INPUT);
  _pin_alive = 9; //pin d'émission
  pinMode(_pin_alive, OUTPUT);
  _pin_valeur = 10; //pin d'envoi de la valeur
  pinMode(_pin_valeur, OUTPUT);
}

bool Comm1::envoi (int valeur)
{
  //d'abord, on met la pin alive et la pin valeur à leurs valeurs respectives
  digitalWrite(_pin_alive, HIGH);
  analogWrite(_pin_valeur, valeur); //attention, on ne peut aller que jusqu'à 255!
  
  //ensuite on allume la led envoi pour signifier qu'on est prêt
  digitalWrite(_pin_envoi, HIGH);
  
  //on attend que l'autre carte réponde. Si elle tarde trop, on renvoie false
  _i = 0;
  while (digitalRead(_pin_reception) == LOW)
  {
    _i++;
    if (_i > _attenteMax)
      return false;
    delay(10);
  }
  
  //la pin reception a été mise à 1, on met le pin d'envoi à 0.
  digitalWrite(_pin_envoi, LOW);
  
  //RAS mon lieutenant. -> on attend également que la pin de la carte 2 repasse à 0 (la flemme pour l'instant)
  
  return true;
}