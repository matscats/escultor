#include <iostream>
#include "PutEllipsoid.h"
#include "math.h"

PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int rx, int ry, 
                           int rz, float r, float g, float b, float a)
{
  this->xc = xc;
  this->yc = yc;
  this->zc = zc;
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void PutEllipsoid::draw(Sculptor &t)
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
            t.v[xi][yi][zi].r = r;
            t.v[xi][yi][zi].g = g;
            t.v[xi][yi][zi].b = b;
            t.v[xi][yi][zi].a = a;
            t.v[xi][yi][zi].show = true;
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