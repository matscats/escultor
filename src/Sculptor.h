#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "Voxel.h"

/**
 * @brief Classe que contem métodos de manipulação de voxels e criação de figuras.
 */
class Sculptor
{
  public:
    Voxel ***v = nullptr; /*!< Matriz 3D do voxel */
    int nx; /*!< Tamanho do eixo x */
    int ny; /*!< Tamanho do eixo y */
    int nz; /*!< Tamanho do eixo z */
    /**
     * @brief Construtor da classe Sculptor
     * 
     * @param nx Dimensão em x
     * @param ny Dimensão em y
     * @param nz Dimensão em z
     */
    explicit Sculptor(int _nx, int _ny, int _nz);
    /**
     * @brief Destrutor da classe Sculptor
     */
    ~Sculptor();
    /**
     * @brief Grava a escultura no formato OFF no arquivo filename
     * 
     * @param filename Nome do arquivo a ser gravado
     */
    void writeOFF(const char* filename);
};

#endif