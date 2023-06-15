#include <iostream>
#include "CutBox.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  this->x0 = x0;
  this->x1 = x1;
  this->y0 = y0;
  this->y1 = y1;
  this->z0 = z0;
  this->z1 = z1;
}

void CutBox::draw(Sculptor &t)
{
  for (int xi = x0; xi <= x1; xi++) {
    for (int yi = y0; yi <=y1; yi++) {
      for (int zi = z0; zi <= z1; zi++) {
        if (xi >= 0 && xi < t.nx && yi >= 0 && yi < t.ny && zi>= 0 && zi < t.nz)
        {
          t.v[xi][yi][zi].show = false;
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