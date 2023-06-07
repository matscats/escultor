#ifndef VOXEL_H
#define VOXEL_H

/**
 * @brief Struct para definir as propriedades de um voxel.
 */
struct Voxel
{
  float r; /*!< Tom de vermelho do voxel (RGB) */
  float g; /*!< Tom de verde do voxel (RGB) */
  float b; /*!< Tom de azul do voxel (RGB) */
  float a; /*!< Transparência do voxel [0,1] */
  bool show; /*!< Define se o voxel será exibido */
};

#endif