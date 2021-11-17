/* MODUL UNTUK TIPE DATA PLAYER */

#include "point.h"

#ifndef PLAYER_H
#define PLAYER_H

/***** DEFINISI ELEMEN DAN OBJEK *****/
typedef struct 
{
    int waktu; // Waktu player sekarang
    int uang; // Uang yang dimiliki player sekarang
    int PesananDone;
    POINT currentLoc;
    POINT prevLoc;
} Player;

/***** SELEKTOR *****/
#define WAKTU(p) (p).waktu
#define UANG(p) (p).uang
#define PESANAN_DONE(p) (p).PesananDone
#define CUR_LOCX(p) (p).currentLoc.X
#define CUR_LOCY(p) (p).currentLoc.Y
#define CUR_LOC(p) (p).currentLoc
#define PREV_LOCX(p) (p).prevLoc.X
#define PREV_LOCY(p) (p).prevLoc.Y
#define PREV_LOC(p) (p).prevLoc

/***** KONSTRUKTOR *****/
void CreatePlayer(Player *p);
/* I.S. Player p sembarang */
/* F.S. Player p memiliki waktu = 0, uang = 0, dan currentLoc = (0,0) */

/**** SETTER DAN GETTER ****/
void setWaktu(Player *p, int waktu);
/* I.S. Player p terdefinisi */
/* F.S. Player p memiliki waktu = waktu */

void setUang(Player *p, int uang);
/* I.S. Player p terdefinisi */
/* F.S. Player p memiliki uang = uang */

void setPlayerLoc(Player *p, float x, float y);
/* I.S. Player p terdefinisi */
/* F.S. Player p memiliki currentLoc = loc */

void setPlayerPrevLoc(Player *p, float x, float y);
/* I.S. Player p terdefinisi */
/* F.S. Player p memiliki prevLoc = sebelum currentLoc */

#endif