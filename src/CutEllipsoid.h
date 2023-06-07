#ifndef CUT_ELLIPSOID_H
#define CUT_ELLIPSOID_H

#include "FiguraGeometrica.h"

class CutEllipsoid : public FiguraGeometrica
{
  private:
    int xc; /*!< Coordenada x do centro do elipsoide */
    int yc; /*!< Coordenada y do centro do elipsoide */
    int zc; /*!< Coordenada z do centro do elipsoide */
    int rx; /*!< Raio do elipsoide no eixo x */
    int ry; /*!< Raio do elipsoide no eixo y */
    int rz; /*!< Raio do elipsoide no eixo z */
    
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
     */
    explicit CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);
    /**
     * @brief Remove um elipsoide na tela
     * 
     * @param t Objeto de classe Sculptor
     */
    void draw(Sculptor &t);
};

#endif