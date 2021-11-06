// #include "../modules/load.c"
// #include "boolean.h"
#include "config.h"
// #include "bangunan.h"
// #include "../adt/charmachine.c"
// #include "../adt/wordmachine.c"
// #include "../adt/point.c"
#include "../adt_modified/listpointdin.h"
#include <stdio.h>
// #include "../adt/matrix.c"
#define enter printf("\n");
#define border printf("---------------------------------\n");

#include "../adt/player.h"
#include "../adt_modified/pesanan.h"

void showMap(Matrix *m, ListPointDin l) {
    int i, j;
    for (i = 1; i <= ROWS(*m); i++)
    {
        for (j = 1; j <= COLS(*m); j++)
        {
            for(int k=0;k<=CAPACITY(l);k++) {
                if ((i==ELMTX(l,k)) && (j==ELMTY(l,k))) {
                    ELMT(*m, i, j) = ELMTLABEL(l,k);
                }
            }
        }
    }
}

void readCustomMatrix(Matrix *m, int nRow, int nCol)
{
  /* KAMUS */
  ElType el;
  int i, j;

  /* ALGORITMA */
  CreateMatrix(nRow, nCol, m);
  for (i = 0; i < nRow; i++)
  {
    for (j = 0; j < nCol; j++)
    {
        if ((i==0) || (j==0) || (i==getLastIdxRow(*m) || (j==getLastIdxCol(*m)))) {
            ELMT(*m, i, j) = 42; // isi dengan * sebagai border 
        }
        else {
            ELMT(*m, i, j) = 32; // isi dengan karakter kosong
        }
    }
  }
  ELMT(*m, 1, 1) = 178; // ini HQ nya
}

void readAdjacencyMatrix(Matrix *m) {
    ElType el;
    int i, j;
    CreateMatrix(4,4,m);
    for (i=0;i<4;i++) {
        for (j=0;j<4;j++) {
            ELMT(*m, i, j) = 0;
        }
    }
    ELMT(*m, 0, 2) = 1;
    ELMT(*m, 2, 0) = 1;
    ELMT(*m, 0, 3) = 1;
    ELMT(*m, 3, 0) = 1;
    ELMT(*m, 2, 3) = 1;
    ELMT(*m, 3, 2) = 1;
}

void showRelation(Matrix m, ListPointDin l, POINT p) {
    // CreateListDin(&r, 10);
    int counter = getIdxPoint(l, p);
    int nPos=0;
    for(int i=counter;i<COLS(m);i++) { // iterasi dimulai dari baris ke-index list
        if (ELMT(m,counter,i) == 1) {
            nPos += 1;
            // insertLast(&r, LISTELMT(l, i));
            // displayList(r);
            // printf("\nx y yg sama: %d %d\n",ELMTX(l,i), ELMTY(l,i));
            printf("%d. %c (%d,%d)\n", nPos % 27, ELMTLABEL(l,i), ELMTX(l,i), ELMTY(l,i));
        }
    } 
}

void getRelation(Matrix m, ListPointDin l, POINT p, int inputPos, Player plyr) {
    // CreateListDin(&r, 10);
    int counter = getIdxPoint(l, p);
    int nPos=0;
    for(int i=counter;i<COLS(m);i++) { // iterasi dimulai dari baris ke-index list
        if (ELMT(m,counter,i) == 1) {
            nPos += 1;
            // insertLast(&r, LISTELMT(l, i));
            // displayList(r);
            // printf("\nx y yg sama: %d %d\n",ELMTX(l,i), ELMTY(l,i));
            if (inputPos == (nPos % 27)) { // misal pilih pos 1
                // printf("npos %d\n", nPos);
                // CUR_LOC(plyr) = MakePOINT(ELMTX(l,i),ELMTY(l,i));
                printf("Mobita sekarang berada di titik %c (%d,%d)!\n", ELMTLABEL(l,i), ELMTX(l,i), ELMTY(l,i));
                break;
            }
            // printf("%d. %c (%d,%d)\n", nPos % 27, ELMTLABEL(l,i), ELMTX(l,i), ELMTY(l,i));
        }
    } 
}

char curLocLabel(Player p, Config newgame) {
    // get current loc label
    char CUR_LOCL;
    for(int i=0;i<20;i++) {
        if ((CUR_LOCX(p) == newgame.bangunans.buffer[i].position.X) && (CUR_LOCY(p) == newgame.bangunans.buffer[i].position.Y)) {
            CUR_LOCL = newgame.bangunans.buffer[i].label;
        }
    }
    return CUR_LOCL;
}

ListPointDin MakeRelationList(ListPointDin x) {

    
    Bangunan z;
    z.label = 'X';
    z.position.X = 2;
    z.position.Y = 3;
    insertLast(&x,z);
    return x;
}

// int xinputPos() {
//     printf("inputpos: \n");
//     int inputPost;
//     scanf(" %d", &inputPost);
//     printf("%d\n", inputPost);
//     return inputPost;
// }

void move(Player p, Config newgame) {
    printf("COMMAND MOVE\n");
    int inputPos;
    printf("*INFO* current label %c\n", curLocLabel(p, newgame));
    printf("Posisi yang dapat dicapai:\n");

    
    showRelation(newgame.adjMatrix, newgame.bangunans, p.currentLoc);
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    getRelation(newgame.adjMatrix, newgame.bangunans, p.currentLoc, 1, p); // misal ambil lokasi bangunan no. 1
    setWaktu(&p, (WAKTU(p)-1));
    printf("Waktu: %d\n", WAKTU(p));
}



void pickup(Player p, Config newgame) {
    printf("COMMAND PICK UP\n");
    // mengambil pesanan yang terdapat di current label
    // masih pakai dummy karena enter command blom work

    // printf("label %c", CUR_LOCL);

    for(int j=0;j<20;j++) {
        if (curLocLabel(p, newgame) == newgame.pesanans.daftar[j].PickUp) {
            char tipe_pesanan = newgame.pesanans.daftar[j].ItemType;
            if (tipe_pesanan = 'H') {
                printf("Pesanan berupa Heavy Item berhasil diambil!\n");
            }
            printf("Tujuan Pesanan: %c\n", newgame.pesanans.daftar[j].DropOff);
        }
    }
}