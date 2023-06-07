#include "CutVoxel.h"
#include <iostream>

CutVoxel::CutVoxel(int x, int y, int z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

void CutVoxel::draw(Sculptor &t)
{
  if (x >= 0 && x < t.nx && y >= 0 && y < t.ny && z>= 0 && z < t.nz)
  {
    t.v[x][y][z].show = false;
  }
  else
  {
    std::cerr << "Voxel fora do grid" << std::endl;
    std::cout << "Digite um valor válido" << std::endl;
  }
}