#ifndef CONFIG_H
#define CONFIG_H

#include "bangunan.h"
#include "../adt_modified/listpointdin.h"
#include "../adt/matrix.h"

typedef struct config
{
  int mapCols, mapRows;
  Bangunan hq;
  ListPointDin bangunans;
  Matrix adjMatrix;
  int pesanans;
} Config;

#endif
