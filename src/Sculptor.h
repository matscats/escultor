#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "Voxel.h"

/**
 * @brief Classe que contem métodos de manipulação de voxels e criação de figuras.
 */
class Sculptor
{
  private:
    Voxel ***v = nullptr; /* Matriz 3D do voxel */
    int nx, ny, nz; /* Dimensões */
    float r, g, b, a; /* Cores do desenho */
  public:
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
     * @brief Define a cor atual de desenho
     * 
     * @param r Tom de vermelho
     * @param g Tom de verde
     * @param b Tom de azul
     * @param a Transparência
     */
    void setColor(float r, float g, float b, float a);
    /**
     * @brief Ativa o voxel na posição (x,y,z) (fazendo show = true) e atribui ao 
     *        mesmo a cor atual de desenho
     * 
     * @param x Coordenada x
     * @param y Coordenada y
     * @param z Coordenada z
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief Desativa o voxel na posição (x,y,z) (fazendo show = false)
     * 
     * @param x Coordenada x
     * @param y Coordenada y
     * @param z Coordenada z
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] 
     *        e atribui aos mesmos a cor atual de desenho.
     * 
     * @param x0 Coordenada x inicial
     * @param x1 Coordenada x final
     * @param y0 Coordenada y inicial
     * @param y1 Coordenada y final
     * @param z0 Coordenada z inicial
     * @param z1 Coordenada z finak
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
     * 
     * @param x0 Coordenada x inicial
     * @param x1 Coordenada x final
     * @param y0 Coordenada y inicial
     * @param y1 Coordenada y final
     * @param z0 Coordenada z inicial
     * @param z1 Coordenada z finak
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief Ativa todos os voxels que satisfazem à equação da esfera e atribui 
     *        aos mesmos a cor atual de desenho (r,g,b,a)
     * 
     * @param xcenter Coordenada x do centro da esfera
     * @param ycenter Coordenada y do centro da esfera
     * @param zcenter Coordenada z do centro da esfera
     * @param radius  Tamanho do raio da esfera
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief Desativa todos os voxels que satisfazem à equação da esfera
     * 
     * @param xcenter Coordenada x do centro da esfera
     * @param ycenter Coordenada y do centro da esfera
     * @param zcenter Coordenada z do centro da esfera
     * @param radius  Tamanho do raio da esfera
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief Ativa todos os voxels que satisfazem à equação do elipsóide e atribui 
     *        aos mesmos a cor atual de desenho
     * 
     * @param xcenter Coordenada x do centro do elipsoide
     * @param ycenter Coordenada y do centro do elipsoide
     * @param zcenter Coordenada z do centro do elipsoide
     * @param rx Raio do elipsoide no eixo x
     * @param ry Raio do elipsoide no eixo y
     * @param rz Raio do elipsoide no eixo z
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief Desativa todos os voxels que satisfazem à equação do elipsóide
     * 
     * @param xcenter Coordenada x do centro do elipsoide
     * @param ycenter Coordenada y do centro do elipsoide
     * @param zcenter Coordenada z do centro do elipsoide
     * @param rx Raio do elipsoide no eixo x
     * @param ry Raio do elipsoide no eixo y
     * @param rz Raio do elipsoide no eixo z
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief Grava a escultura no formato OFF no arquivo filename
     * 
     * @param filename 
     */
    void writeOFF(const char* filename);
};

#endif