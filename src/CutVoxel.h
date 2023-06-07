#ifndef CUT_VOXEL_H
#define CUT_VOXEL_H

#include "FiguraGeometrica.h"

class CutVoxel : public FiguraGeometrica
{
  private:
    int x; /*!< Coordenada espacial x */
    int y; /*!< Coordenada espacial y */
    int z; /*!< Cpprdenada espacial z */

  public:
    /**
     * @brief Construtor da classe CutVoxel
     * 
     * @param x Coordenada espacial x
     * @param y Coordenada espacial y
     * @param z Coordenada espacial z
     */
    CutVoxel(int x, int y, int z);
    /**
     * @brief Remove um voxel da posição especificada no construtor
     * 
     * @param t Objeto do tipo Sculptor
     */
    void draw(Sculptor &t);
};

#endif