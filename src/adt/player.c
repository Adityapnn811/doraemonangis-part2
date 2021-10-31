/* IMPLEMENTASI PLAYER.H */

#include "player.h"
#include <stdio.h>

/***** KONSTRUKTOR *****/
void CreatePlayer(Player *p) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    WAKTU(*p) = 0;
    UANG(*p) = 0;
    CUR_LOCX(*p) = 0;
    CUR_LOCY(*p) = 0;
}

/**** SETTER DAN GETTER ****/
void setWaktu(Player *p, int waktu) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    WAKTU(*p) = waktu;
}

void setUang(Player *p, int uang) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    UANG(*p) = uang;
}

void setPlayerLoc(Player *p, float x, float y) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    CUR_LOC(*p) = MakePOINT(x, y);
}

// //driver
// int main(){
//     Player p;
//     POINT loc;
//     CreatePlayer(&p);
//     printf("Uang player sebesar %d\n", UANG(p));
//     printf("Waktu player sebesar %d\n", WAKTU(p));
//     printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
//     printf("\n");
//     setUang(&p, 1000);
//     setWaktu(&p, 20);
//     setPlayerLoc(&p, 3, 4);
//     printf("Uang player sebesar %d\n", UANG(p));
//     printf("Waktu player sebesar %d\n", WAKTU(p));
//     printf("Lokaso player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
//     printf("\n");
//     return 0;
// }