#include <stdio.h>
#include "../game_header.h"
#include "cmd1.c" // command move, pickup, dropoff

#define enter printf("\n");
#define border printf("----------- END OF INFO CONFIG.TXT------------\n\n");

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
    displayListPoint(newgame.bangunans);enter;
    printf("length pesanan %d", lengthDftr(newgame.pesanans));enter;

    Matrix m;
    readCustomMatrix(&m,13,18);
    printf("capcity bangunan %d (blom diassign di load)\n",newgame.bangunans.capacity); // capacity blom diassign di load
    // showMap(&m,newgame.bangunans);
    // displayMatrixLabel(m);enter;
    displayMatrix(m);

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
    movecmd(p, newgame);enter;
    pickupcmd(p, newgame);enter;
    // displayMatrixLabel(m, newgame.adjMatrix, l, cur_player, tas);
}

// int main(){
//     newgame();
// }



