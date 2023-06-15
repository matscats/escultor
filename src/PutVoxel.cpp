#include "PutVoxel.h"
#include <iostream>

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a)
{
  this->x = x;
  this->y = y;
  this->z = z;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void PutVoxel::draw(Sculptor &t)
{
  if (x >= 0 && x < t.nx && y >= 0 && y < t.ny && z>= 0 && z < t.nz)
  {
    t.v[x][y][z].r = r;
    t.v[x][y][z].g = g;
    t.v[x][y][z].b = b;
    t.v[x][y][z].a = a;
    t.v[x][y][z].show = true;
  }
  else
  {
    std::cerr << "Voxel fora do grid" << std::endl;
    std::cout << "Digite um valor válido" << std::endl;
    return;
  }
}