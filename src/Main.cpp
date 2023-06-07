#include "Sculptor.h"
#include "PutBox.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"

int main(void)
{
  Sculptor *s = new Sculptor(100,100,100);
  PutBox *Terra = new PutBox(20, 40, 20, 40, 20, 40, 0.569, 0.286, 0.141, 0.9);
  PutBox *Grama = new PutBox(20, 40, 20, 40, 35, 40, 0.325, 0.89, 0.102, 0.9);
  PutBox *Tronco = new PutBox(29, 31, 29, 31, 41, 55, 0.729, 0.306, 0.09, 0.9);
  PutSphere *Folha = new PutSphere(30, 30, 58, 30, 0.106, 0.549, 0.039, 0.9);
  PutEllipsoid *Nuvem = new PutEllipsoid(30, 30, 80, 10, 7, 4, 0.9, 0.9, 0.9, 0.9);

  Terra->draw(*s);
  Grama->draw(*s);
  Tronco->draw(*s);
  Folha->draw(*s);
  Nuvem->draw(*s);

  s->writeOFF("file.off");

  delete s;
  delete Terra;
  delete Grama;
  delete Tronco;
  delete Folha;
  delete Nuvem;

  return 0;
}