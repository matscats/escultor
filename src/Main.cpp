#include "Sculptor.h"
#include <iostream>

int main(void)
{
  Sculptor s(60,60,60);
  s.setColor(1.1,0.1,0.1,0.9);
  s.putEllipsoid(20,20,20,10,15,20);
  s.writeOFF("file.off");
  return 0;
}