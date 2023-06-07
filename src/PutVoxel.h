#ifndef PUT_VOXEL_H
#define PUT_VOXEL_H

#include "FiguraGeometrica.h"

class PutVoxel : public FiguraGeometrica
{
  private:
    int x; /*!< Coordenada espacial x */
    int y; /*!< Coordenada espacial y */
    int z; /*!< Coordenada espacial z */
    float r; /*!< Tom de vermelho (RGB) */
    float g; /*!< Tom de verde (RGB) */
    float b; /*!< Tom de azul (RGB) */
    float a; /*!< Transparência [0,1] */

  public:
    /**
     * @brief Construtor da classe PutVoxel
     * 
     * @param x Coordenada espacial x
     * @param y Coordenada espacial y
     * @param z Coordenada espacial z
     * @param r Tom de vermelho (RGB)
     * @param g Tom de verde (RGB)
     * @param b Tom de azul (RGB)
     * @param a Transparência [0,1]
     */
    explicit PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    /**
     * @brief Desenha um voxel na tela
     * 
     * @param t Objeto do tipo Sculptor
     */
    virtual void draw(Sculptor &t);
};

#endif