#ifndef PUT_ELLIPSOID_H
#define PUT_ELLIPSOID_H

#include "FiguraGeometrica.h"

class PutEllipsoid : public FiguraGeometrica
{
  private:
    int xc; /*!< Coordenada x do centro do elipsoide */
    int yc; /*!< Coordenada y do centro do elipsoide */
    int zc; /*!< Coordenada z do centro do elipsoide */
    int rx; /*!< Raio do elipsoide no eixo x */
    int ry; /*!< Raio do elipsoide no eixo y */
    int rz; /*!< Raio do elipsoide no eixo z */
    float r; /*!< Tom de vermelho (RGB) */
    float g; /*!< Tom de verde (RGB) */
    float b; /*!< Tom de azul (RGB) */
    float a; /*!< Transparência [0,1] */
    
  public:
    /**
     * @brief Construtor da classe PutEllipsoid
     * 
     * @param xc Coordenada x do centro do elipsoide
     * @param yc Coordenada y do centro do elipsoide
     * @param zc Coordenada z do centro do elipsoide
     * @param rx Raio do elipsoide no eixo x
     * @param ry Raio do elipsoide no eixo y
     * @param rz Raio do elipsoide no eixo z
     * @param r Tom de vermelho (RGB)
     * @param g Tom de verde (RGB)
     * @param b Tom de azul (RGB)
     * @param a Transparência [0,1]
     */
    explicit PutEllipsoid(int xc, int yc, int zc, int rx, int ry, 
                          int rz, float r, float g, float b, float a);
    /**
     * @brief Desenha um elipsoide na tela
     * 
     * @param t Objeto de classe Sculptor
     */
    void draw(Sculptor &t);
};

#endif