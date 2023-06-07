#ifndef CUT_SPHERE_H
#define CUT_SPHERE_H

#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica
{
  private:
    int xc; /*!< Coordenada x do centro da esfera */
    int yc; /*!< Coordenada y do centro da esfera */
    int zc; /*!< Coordenada z do centro da esfera */
    int radius; /*!< Raio da esfera */

  public:
    /**
     * @brief Construtor da classe CutSphere
     * 
     * @param xc Coordenada x do centro da esfera 
     * @param yc Coordenada y do centro da esfera
     * @param zc Coordenada z do centro da esfera
     * @param radius Raio da esfera
     */
    explicit CutSphere(int xc, int yc, int zc, int radius);
    /**
     * @brief Remove uma esfera na tela
     * 
     * @param t Objeto da classe Sculptor
     */
    void draw(Sculptor &t);
};

#endif