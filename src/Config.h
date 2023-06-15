#ifndef CONFIG_H
#define CONFIG_H

#include "vector"

#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

class Config
{
  public:
    /**
     * @brief Construtor da classe Config
     * 
     */
    explicit Config() { };
    /**
     * @brief Lê o arquivo de configuração e armazena as figuras em um vector
     * 
     * @param file Nome do arquivo txt
     */
    void readConfigFile(const char* filename);
    /**
     * @brief Destrutor da classe config
     * 
     */
    ~Config();

    std::vector<FiguraGeometrica *> draws; /*!< Armazena todos os desenhos */
    
    int dim_x; /*<! Dimensão do desenho no eixo x */
    int dim_y; /*<! Dimensão do desenho no eixo y */
    int dim_z; /*<! Dimensão do desenho no eixo z */
};

#endif