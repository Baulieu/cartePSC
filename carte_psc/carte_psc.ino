/*
il faudra créer des librairies qui se chargeront de tout le taff. -> merci de ce commentaire constructif. -> mais de rien, c'est un plaisir.
*/

#include <Comm1.h>


unsigned long time;
int duree_loop;
int led_alert = 13;
Comm1 communicator(100);

void setup()
{
  duree_loop = 100; //choisir ici la durée d'une loop !!!doit etre cohérent avec l'autre carte!!!
  pinMode (led_alert, OUTPUT);
}

void loop()
{
  // on utilise un timestamp pour permettre une synchronisation entre les deux cartes. + attendre un retour, pour etre sur de ne pas rater de tour.
  time = millis();
  
  //communication entre les cartes -> on teste en envoyant la valeur 100.
  communicator.envoi(100);
  
  // sert à gérer la durée d'une loop
  if (millis() - time < duree_loop) {
    delay(duree_loop - millis() + time);
    digitalWrite(led_alert, LOW); //la loop s'est éxecutée en un temps normal
  }
  else {
    digitalWrite(led_alert, HIGH); //la loop met trop de temps à s'éxecuter, la led 13 s'allume
  }
}
