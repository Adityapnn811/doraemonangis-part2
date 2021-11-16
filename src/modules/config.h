#ifndef CONFIG_H
#define CONFIG_H

#include "../game_header.h"

typedef struct config
{
  int mapCols, mapRows;
  ListPointDin bangunans;
  Matrix adjMatrix;
  DaftarPesanan pesanans;
} Config;

boolean loadConfig(char *filename, Config *conf);

#endif
