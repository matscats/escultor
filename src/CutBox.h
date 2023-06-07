#ifndef CUT_BOX_H
#define CUT_BOX_H

#include "FiguraGeometrica.h"

class CutBox : public FiguraGeometrica
{
  private:
    int x0; /*!< Coordenada espacial x inicial */
    int x1; /*!< Coordenada espacial x final */
    int y0; /*!< Coordenada espacial y inicial */
    int y1; /*!< Coordenada espacial y final */
    int z0; /*!< Coordenada espacial z inicial */
    int z1; /*!< Coordenada espacial z final */

  public:
    /**
     * @brief Construtor da classe CutBox
     * 
     * @param x0 Coordenada espacial x inicial
     * @param x1 Coordenada espacial x final
     * @param y0 Coordenada espacial y inicial
     * @param y1 Coordenada espacial y final
     * @param z0 Coordenada espacial z inicial
     * @param z1 Coordenada espacial z final
     */
    explicit CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief Remove uma caixa da tela
     * 
     * @param t Objeto da classe Sculptor
     */
    void draw(Sculptor &t);
};

#endif