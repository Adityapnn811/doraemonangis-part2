#ifndef CONFIG_H
#define CONFIG_H

#include "bangunan.h"
#include "../adt_modified/listpointdin.h"
#include "../adt_modified/pesanan.h"
#include "../adt/matrix.h"

typedef struct config
{
  int mapCols, mapRows;
  ListPointDin bangunans;
  Matrix adjMatrix;
  DaftarPesanan pesanans;
} Config;

#endif
