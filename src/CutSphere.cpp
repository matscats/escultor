#include <iostream>
#include "CutSphere.h"
#include "math.h"

CutSphere::CutSphere(int xc, int yc, int zc, int radius)
{
  this->xc = xc;
  this->yc = yc;
  this->zc = zc;
  this->radius = radius;
}

void CutSphere::draw(Sculptor &t)
{
  for (int xi = xc - radius; xi <= xc+ radius; xi++) {
    for (int yi = yc- radius; yi <= yc+ radius; yi++) {
      for (int zi = zc - radius; zi <= zc + radius; zi++) {
        if (xi >= 0 && xi < t.nx && yi >= 0 && yi < t.ny && zi>= 0 && zi < t.nz)
        {
          if (pow(xi - xc, 2) + pow(yi - yc, 2) + pow(zi - zc, 2) <= radius)
          {
            t.v[xi][yi][zi].show = false;
          }
        }
        else
        {
          std::cerr << "Voxel fora do grid" << std::endl;
          std::cout << "Digite um valor válido" << std::endl;
          return;
        }
      }
    }
  }
}