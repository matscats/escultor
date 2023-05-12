#include "Sculptor.h"
#include <iostream>

int main(void)
{
  Sculptor s(30,30,30);

  std::cout << "Teste" << std::endl;
  s.writeOFF("file.off");
  


  return 0;
}