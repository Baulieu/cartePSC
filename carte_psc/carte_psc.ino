/*
il faudra créer des librairies qui se chargeront de tout le taff. -> merci de ce commentaire constructif. -> mais de rien, c'est un plaisir.
*/

#include <Comm1.h>


unsigned long time;
int duree_loop;
int led_alert = 13;
boolean comm_success = true;
int i = 0;
Comm1 sender(1000);

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
  comm_success = sender.envoi(100);
  
  if (!comm_success)
  {
    for(i = 0; i < 20; i++)
    {
      digitalWrite(led_alert, LOW);
      delay(200);
      digitalWrite(led_alert, HIGH);
      delay(200);
    }
  }
  else
  {
    for(i = 0; i < 5; i++)
    {
      digitalWrite(led_alert, LOW);
      delay(1000);
      digitalWrite(led_alert, HIGH);
      delay(1000);
    }
    delay(2000);
  }
  
  // sert à gérer la durée d'une loop
  if (millis() - time < duree_loop) {
    delay(duree_loop - millis() + time);
    digitalWrite(led_alert, LOW); //la loop s'est éxecutée en un temps normal
  }
  else {
    digitalWrite(led_alert, HIGH); //la loop met trop de temps à s'éxecuter, la led 13 s'allume
  }
}
