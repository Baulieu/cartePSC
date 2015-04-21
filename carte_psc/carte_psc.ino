/*
il faudra créer des librairies qui se chargeront de tout le taff.
*/

unsigned long time;

setup()
{
}

loop()
{
  // on utilise un timestamp pour permettre une synchronisation entre les deux cartes. + attendre un retour, pour etre sur de ne pas rater de tour.
  time = millis();
  // à supprimer
  delay(1000);
}
