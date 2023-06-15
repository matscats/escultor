#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

#include "Sculptor.h"

/**
 * @brief Uma classe abstrata pura que servirá como base para as outras classes
 *        de figuras geométricas
 */
class FiguraGeometrica
{
  public:
    /**
     * @brief Realiza o desenho do sólido geométrico
     * 
     * @param t Objeto do tipo Sculptor
     */
    virtual void draw(Sculptor &t) = 0;
};

#endif
