#include "PutBox.h"
#include <iostream>

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g,
               float b, float a)
{
  this->x0 = x0;
  this->x1 = x1;
  this->y0 = y0;
  this->y1 = y1;
  this->z0 = z0;
  this->z1 = z1;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void PutBox::draw(Sculptor &t)
{
  for (int xi = x0; xi <= x1; xi++) {
    for (int yi = y0; yi <= y1; yi++) {
      for (int zi = z0; zi <= z1; zi++) {
        if (xi >= 0 && xi < t.nx && yi >= 0 && yi < t.ny && zi>= 0 && zi < t.nz)
        {
          t.v[xi][yi][zi].r = r;
          t.v[xi][yi][zi].g = g;
          t.v[xi][yi][zi].b = b;
          t.v[xi][yi][zi].a = a;
          t.v[xi][yi][zi].show = true;
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