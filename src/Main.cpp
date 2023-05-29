#include "Sculptor.h"
#include <iostream>

int main(void)
{
  Sculptor s(100,100,100);
  s.setColor(0.569,0.286,0.141,0.9);
  s.putBox(20,40,20,40,20,40);
  s.setColor(0.325,0.89,0.102,0.9);
  s.putBox(20,40,20,40,35,40);
  s.setColor(0.729,0.306,0.09,0.9);
  s.putBox(29,31,29,31,41,55);
  s.setColor(0.106,0.549,0.039,0.9);
  s.putSphere(30,30,58,30);
  s.setColor(0.9,0.9,0.9,0.9);
  s.putEllipsoid(30,30,80,10,7,4);

  s.writeOFF("file.off");
  return 0;
}