/*
il faudra créer des librairies qui se chargeront de tout le taff.
*/

unsigned long time;
int duree_loop;
int led_alerte = 13;

setup()
{
  duree_loop = 100; //choisir ici la durée d'une loop !!!doit etre cohérent avec l'autre carte!!!
  pinMode (led_alert, OUTPUT);
}

loop()
{
  // on utilise un timestamp pour permettre une synchronisation entre les deux cartes. + attendre un retour, pour etre sur de ne pas rater de tour.
  time = millis();
  // sert à gérer la durée d'une loop
  if (millis() - time < duree_loop) {
    delay(duree_loop - millis() + time);
    digitalWrite(led_alert, LOW); //la loop s'est éxecutée en un temps normal
  }
  else {
    digitalWrite(led_alert, HIGH); //la loop met trop de temps à s'éxecuter, la led 13 s'allume
  }
}
