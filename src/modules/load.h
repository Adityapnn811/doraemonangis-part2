#ifndef LOAD_H
#define LOAD_H

#include "../game_header.h"

void saveGame(Player player, Inventory inv, Tas bag, TDList todo, Speedboost boost);
void loadGame(Config conf, Player *player, Inventory *inv, Tas *bag, TDList *todo, Speedboost *boost);

#endif
