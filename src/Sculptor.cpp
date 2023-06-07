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
    exit(1);
  }
}

Sculptor::~Sculptor()
{
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::writeOFF(const char* filename)
{
  int n_v, n_f = 0; /* número de vértices / número de arestas / número de elementos exibidos */
  float r, g, b, a; /* Tom RGB e transparência */
  int ni = 0; /* Iteration number */
  std::ofstream file(filename, std::ios::out);
  if (file.is_open())
  {
    file << "OFF" << std::endl;
    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
          if (v[xi][yi][zi].show)
          {
            n_f += 6;
            n_v += 8;
          }
        }
      }
    }
    file << n_v << " " << n_f << " " << 0 << std::endl;
    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
          if (v[xi][yi][zi].show)
          {
            file << xi - 0.5 << " " << yi + 0.5 << " " << zi - 0.5 << std::endl;
            file << xi - 0.5 << " " << yi - 0.5 << " " << zi - 0.5 << std::endl;
            file << xi + 0.5 << " " << yi - 0.5 << " " << zi - 0.5 << std::endl;
            file << xi + 0.5 << " " << yi + 0.5 << " " << zi - 0.5 << std::endl;
            file << xi - 0.5 << " " << yi + 0.5 << " " << zi + 0.5 << std::endl;
            file << xi - 0.5 << " " << yi - 0.5 << " " << zi + 0.5 << std::endl;
            file << xi + 0.5 << " " << yi - 0.5 << " " << zi + 0.5 << std::endl;
            file << xi + 0.5 << " " << yi + 0.5 << " " << zi + 0.5 << std::endl;
          }
        }
      }
    }
    for (int xi = 0; xi < nx; xi++) {
      for (int yi = 0; yi < ny; yi++) {
        for (int zi = 0; zi < nz; zi++) {
          if (v[xi][yi][zi].show)
          {
            r = v[xi][yi][zi].r;
            g = v[xi][yi][zi].g;
            b = v[xi][yi][zi].b;
            a = v[xi][yi][zi].a;
            file << 4 << " " << 0 + ni << " " << 3 + ni << " " << 2 + ni << " " << 1 + ni 
                 << " " << r << " " << g << " " << b << " " << a << std::endl;
            file << 4 << " " << 4 + ni << " " << 5 + ni << " " << 6 + ni << " " << 7 + ni 
                 << " " << r << " " << g << " " << b << " " << a << std::endl;
            file << 4 << " " << 0 + ni << " " << 1 + ni << " " << 5 + ni << " " << 4 + ni 
                 << " " << r << " " << g << " " << b << " " << a << std::endl;
            file << 4 << " " << 0 + ni << " " << 4 + ni << " " << 7 + ni << " " << 3 + ni 
                 << " " << r << " " << g << " " << b << " " << a << std::endl;
            file << 4 << " " << 3 + ni << " " << 7 + ni << " " << 6 + ni << " " << 2 + ni 
                 << " " << r << " " << g << " " << b << " " << a << std::endl;
            file << 4 << " " << 1 + ni << " " << 2 + ni << " " << 6 + ni << " " << 5 + ni 
                 << " " << r << " " << g << " " << b << " " << a << std::endl;
            ni += 8;
          }
        }
      }
    }
    std::cout << "Projeto gerado com sucesso!" << std::endl;
  }
  else
  {
    std::cerr << "Não foi possível abrir o arquivo" << std::endl;
  }
  file.close();
}