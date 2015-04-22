/**/

#include <Comm2.h>


unsigned long time;
int duree_loop;
int led_alert = 13;
int valeurRecue = 0;
int i = 0;
Comm2 receiver(1000);

void setup()
{
  duree_loop = 100; //choisir ici la durée d'une loop !!!doit etre cohérent avec l'autre carte!!!
  pinMode (led_alert, OUTPUT);
}

void loop()
{
  // on utilise un timestamp pour permettre la synchronisation des deux cartes.
  time = millis();
  
  //communication entre les cartes -> on teste en lisant la valeur 100.
  valeurRecue = receiver.reception();
  if (valeurRecue == -1)
  {
    for(i = 0; i < 20; i++)
    {
      digitalWrite(led_alert, LOW);
      delay(200);
      digitalWrite(led_alert, HIGH);
      delay(200);
    }
  }
  else// if (valeurRecue == 100)
  {
    for(i = 0; i < 5; i++)
    {
      digitalWrite(led_alert, LOW);
      delay(1000);
      digitalWrite(led_alert, HIGH);
      delay(1000);
    }
  }
  
  // sert à gérer la durée d'une loop
  if (millis() - time < duree_loop) {
    delay(duree_loop - millis() + time);
    digitalWrite(led_alert, LOW); //la loop s'est exécutée en un temps normal
  }
  else {
    digitalWrite(led_alert, HIGH); //la loop met trop de temps à s'éxecuter, la led 13 s'allume
  }
}
