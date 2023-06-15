#include "Sculptor.h"
#include "PutBox.h"
#include "Config.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include <vector>

int main(void)
{
  Config *conf = new Config();
  conf->readConfigFile("project/commands.txt");

  Sculptor *s = new Sculptor(conf->dim_x, conf->dim_y, conf->dim_z);

  for (FiguraGeometrica* fig : conf->draws)
  {
    fig->draw(*s);
  }

  s->writeOFF("file.off");

  delete s;
  delete conf;

  return 0;
}