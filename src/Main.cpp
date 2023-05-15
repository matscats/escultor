#include "Sculptor.h"
#include <iostream>

int main(void)
{
  Sculptor s(100,100,100);
  s.setColor(0.9,0.1,0.1,0.9);
  s.putBox(1,10,10,18,10,18);
  s.setColor(0.1,0.9,0.1,0.5);
  s.putSphere(28,12,12,15);
  s.setColor(0.1,0.1,0.9,0.3);
  s.putEllipsoid(65,12,12,15,5,5);

  s.writeOFF("file.off");
  return 0;
}