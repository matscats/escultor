#ifndef PUT_BOX_H
#define PUT_BOX_H

#include "FiguraGeometrica.h"

class PutBox : public FiguraGeometrica
{
  private:
    int x0; /*!< Coordenada espacial x inicial */
    int x1; /*!< Coordenada espacial x final */
    int y0; /*!< Coordenada espacial y inicial */
    int y1; /*!< Coordenada espacial y final */
    int z0; /*!< Coordenada espacial z inicial */
    int z1; /*!< Coordenada espacial z final */
    float r; /*!< Tom de vermelho (RGB) */
    float g; /*!< Tom de verde (RGB) */
    float b; /*!< Tom de azul (RGB) */
    float a; /*!< Transparência [0,1] */
  public:
    /**
     * @brief Construtor da classe PutBox
     * 
     * @param x0 Coordenada x inicial
     * @param x1 Coordenada x final
     * @param y0 Coordenada y inicial
     * @param y1 Coordenada y final
     * @param z0 Coordenada z inicial
     * @param z1 Coordenada z final
     * @param r Tom de vermelho (RGB)
     * @param g Tom de verde (RGB)
     * @param b Tom de azul (RGB)
     * @param a Transparência [0,1]
     */
    explicit PutBox(int x0, int x1, int y0, int y1, int z0, int z1,
                    float r, float g, float b, float a);
    /**
     * @brief Desenha uma caixa na tela
     * @param t Objeto da classe Sculptor
     */
    void draw(Sculptor &t);
};

#endif