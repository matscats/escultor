#include "Sculptor.h"
#include <iostream>
#include "math.h"
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
  nx = _nx;
  ny = _ny;
  nz = _nz;
  try 
  {
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx * ny];
    v[0][0] = new Voxel[nx * ny * nz];
    for (int i = 1; i < nx; i++) {
      v[i] = v[i-1] + ny;
    }
    for (int i = 1; i < ny * nx; i++) {
      v[0][i] = v[0][i-1] + nz;
    }
    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
          v[xi][yi][zi].show = false;
        }
      }
    }
  } 
  catch (const std::exception &e) 
  {
    std::cerr << "Houve um erro na alocação de memória" << e.what();
  }
}

Sculptor::~Sculptor()
{
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a)
{
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z)
{
  if (x >= 0 && x < nx && y >= 0 && y < ny && z>= 0 && z < nz)
  {
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
  }
  else
  {
    std::cerr << "Voxel fora do grid" << std::endl;
    std::cout << "Digite um valor válido" << std::endl;
  }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
  if (x >= 0 && x < nx && y >= 0 && y < ny && z>= 0 && z < nz)
  {
    v[x][y][z].show = false;
  }
  else
  {
    std::cerr << "Voxel fora do grid" << std::endl;
    std::cout << "Digite um valor válido" << std::endl;
  }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  for (int xi = x0; xi <= x1; xi++) {
    for (int yi = y0; yi <=y1; yi++) {
      for (int zi = z0; zi <= z1; zi++) {
        v[xi][yi][zi].r = r;
        v[xi][yi][zi].g = g;
        v[xi][yi][zi].b = b;
        v[xi][yi][zi].a = a;
        v[xi][yi][zi].show = true;
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  for (int xi = x0; xi <= x1; xi++) {
    for (int yi = y0; yi <=y1; yi++) {
      for (int zi = z0; zi <= z1; zi++) {
        v[xi][yi][zi].show = false;
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  for (int xi = xcenter - radius; xi <= xcenter + radius; xi++) {
    for (int yi = ycenter - radius; yi <= ycenter + radius; yi++) {
      for (int zi = zcenter - radius; zi <= zcenter + radius; zi++) {
        if (pow(xi - xcenter, 2) + pow(yi - ycenter, 2) + pow(zi - zcenter, 2) <= radius)
        {
          putVoxel(xi, yi, zi);
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  for (int xi = xcenter - radius; xi <= xcenter + radius; xi++) {
    for (int yi = ycenter - radius; yi <= ycenter + radius; yi++) {
      for (int zi = zcenter - radius; zi <= zcenter + radius; zi++) {
        if (pow(xi - xcenter, 2) + pow(yi - ycenter, 2) + pow(zi - zcenter, 2) <= radius)
        {
          cutVoxel(xi, yi, zi);
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
  for (int xi = xcenter - rx; xi <= xcenter + rx; xi++) {
    for (int yi = ycenter - ry; yi <= ycenter + ry; yi++) {
      for (int zi = zcenter - rz; zi <= zcenter + rz; zi++) {
        if (pow(xi - xcenter, 2)/ pow(rx, 2) + pow(yi - ycenter, 2) / pow(r, 2) + pow(zi - zcenter, 2) / pow(rz, 2) <= 1)
        {
          putVoxel(xi, yi, zi);
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
  for (int xi = xcenter - rx; xi <= xcenter + rx; xi++) {
    for (int yi = ycenter - ry; yi <= ycenter + ry; yi++) {
      for (int zi = zcenter - rz; zi <= zcenter + rz; zi++) {
        if (pow(xi - xcenter, 2)/ (float)pow(rx, 2) + pow(yi - ycenter, 2) / (float)pow(r, 2) + pow(zi - zcenter, 2) / (float)pow(rz, 2) <= 1)
        {
          cutVoxel(xi, yi, zi);
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char* filename)
{
  std::ofstream file(filename, std::ios::out);
  if (file.is_open())
  {
    file << "OFF" << std::endl;
  }
  else
  {
    std::cerr << "Não foi possível abrir o arquivo" << std::endl;
  }
  file.close();
}