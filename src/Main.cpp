#include "Sculptor.h"
#include <iostream>

int main(void)
{
  Sculptor s(30,30,30);
  s.setColor(1.1,0.1,0.1,0.9);
  s.putSphere(20,20,20,10);
  s.writeOFF("file.off");
  return 0;
}