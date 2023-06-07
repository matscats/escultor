#ifndef PUT_SPHERE_H
#define PUT_SPHERE_H

#include "FiguraGeometrica.h"

class PutSphere : public FiguraGeometrica
{
  private:
    int xc; /*!< Coordenada x do centro da esfera */
    int yc; /*!< Coordenada y do centro da esfera */
    int zc; /*!< Coordenada z do centro da esfera */
    int radius; /*!< Raio da esfera */
    float r; /*!< Tom de vermelho (RGB) */
    float g; /*!< Tom de verde (RGB) */
    float b; /*!< Tom de azul (RGB) */
    float a; /*!< Transparência [0,1] */

  public:
    /**
     * @brief Construtor da classe PutSphere
     * 
     * @param xc Coordenada x do centro da esfera 
     * @param yc Coordenada y do centro da esfera
     * @param zc Coordenada z do centro da esfera
     * @param radius Raio da esfera
     * @param r Tom de vermelho (RGB)
     * @param g Tom de verde (RGB)
     * @param b Tom de azul (RGB)
     * @param a Transparência [0,1]
     */
    explicit PutSphere(int xc, int yc, int zc, int radius, float r, float g,
                       float b, float a);
    /**
     * @brief Desenha uma esfera na tela
     * 
     * @param t Objeto da classe Sculptor
     */
    void draw(Sculptor &t);
};

#endif