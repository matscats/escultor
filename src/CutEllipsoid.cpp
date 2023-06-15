#include <iostream>
#include "CutEllipsoid.h"
#include "math.h"

CutEllipsoid::CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz)
{
  this->xc = xc;
  this->yc = yc;
  this->zc = zc;
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
}

void CutEllipsoid::draw(Sculptor &t)
{
  for (int xi = xc - rx; xi <= xc + rx; xi++) {
    for (int yi = yc - ry; yi <= yc + ry; yi++) {
      for (int zi = zc - rz; zi <= zc + rz; zi++) {
        if (xi >= 0 && xi < t.nx && yi >= 0 && yi < t.ny && zi>= 0 && zi < t.nz)
        {
          if (pow(xi - xc, 2) / (float)pow(rx, 2) + 
              pow(yi - yc, 2) / (float)pow(ry, 2) + 
              pow(zi - zc, 2) / (float)pow(rz, 2) <= 1)
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