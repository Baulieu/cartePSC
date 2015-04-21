/**/

#include <Comm2.h>


unsigned long time;
int duree_loop;
int led_alert = 13;

void setup()
{
  duree_loop = 100; //choisir ici la durée d'une loop !!!doit etre cohérent avec l'autre carte!!!
  pinMode(led_alert, OUTPUT);
}

void loop()
{
  // on utilise un timestamp pour permettre la synchronisation des deux cartes.
  time = millis();
  // sert à gérer la durée d'une loop
  if (millis() - time < duree_loop) {
    delay(duree_loop - millis() + time);
    digitalWrite(led_alert, LOW); //la loop s'est exécutée en un temps normal
  }
  else {
    digitalWrite(led_alert, HIGH); //la loop met trop de temps à s'éxecuter, la led 13 s'allume
  }
}
