#include "player.h"
#include <stdio.h>

int main() {
    Player p;
    CreatePlayer(&p);    UANG(p) = 100000000;
    setPlayerLoc(&p, 4, 2);
    printf("Uang player sebesar %d\n", UANG(p));
    printf("Waktu player sebesar %d\n", WAKTU(p));
    printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));    
}