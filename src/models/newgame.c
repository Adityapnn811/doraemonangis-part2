#include "boolean.h"
#include "config.h"
#include "bangunan.h"
#include "../modules/load.h"
#include "../adt/player.h"
#include "../adt_modified/pesanan.h"
#include "../adt/charmachine.h"
#include "../adt/wordmachine.h"
#include "../adt/point.h"
#include "../adt_modified/listpointdin.h"
#include "../adt/matrix.h"
#include <stdio.h>
#include "cmd1.c" // command move, pickup, dropoff

#define enter printf("\n");
#define border printf("----------- END OF INFO CONFIG.TXT------------\n\n");

/* dont delete, for compiler */
// #include "../modules/load.c"
// #include "../adt/player.c"
// #include "../adt_modified/pesanan.c"
// #include "../adt/charmachine.c"
// #include "../adt/wordmachine.c"
// #include "../adt/point.c"
// #include "../adt_modified/listpointdin.c"
// #include "../adt/matrix.c"
// #include "bangunan.c"

void newgame() {
    Config newgame;
    char *filename = "config.txt";

    /* MENAMPILKAN ISI LOAD CONFIG.TXT */
    if (loadGame(filename, &newgame)) {
        printf("success");
    } else {
        printf("fail");
    }

    enter;displayMatrix(newgame.adjMatrix);enter;
    displayList(newgame.bangunans);enter;
    printf("length pesanan %d", lengthDftr(newgame.pesanans));enter;

    Matrix m;
    readCustomMatrix(&m,13,18);
    printf("capcity bangunan %d (blom diassign di load)\n",newgame.bangunans.capacity); // capacity blom diassign di load
    showMap(&m,newgame.bangunans);
    displayMatrixLabel(m);enter;

    /* STATE NEW PLAYER */
    Player p;
    POINT loc;
    CreatePlayer(&p);
    /* TEST DRIVER PLAYER */
    printf("Uang player sebesar %d\n", UANG(p));
    printf("Waktu player sebesar %d\n", WAKTU(p));
    printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
    printf("\n");
    setUang(&p, 1000);
    setWaktu(&p, 20);
    setPlayerLoc(&p, 1, 15);
    printf("Uang player sebesar %d\n", UANG(p));
    printf("Waktu player sebesar %d\n", WAKTU(p));
    printf("Lokaso player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
    border;

    /* COMMAND MOVE, PICK UP */
    printf("Waktu: %d\n", WAKTU(p));
    move(p, newgame);enter;
    pickup(p, newgame);enter;
}


