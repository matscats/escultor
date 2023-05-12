#ifndef VOXEL_H
#define VOXEL_H

/**
 * @brief Struct para definir as propriedades de um voxel.
 */
struct Voxel
{
  float r, g, b; /* Cor do voxel (RGB) */
  float a; /* Transparência do voxel [0,1] */
  bool show; /* Define se o voxel será exibido */
};

#endif