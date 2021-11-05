#include "../modules/load.c"
#include "boolean.h"
#include "config.h"
#include "bangunan.h"
#include "../adt/charmachine.c"
#include "../adt/wordmachine.c"
#include "../adt/point.c"
#include "../adt_modified/listpointdin.c"
#include <stdio.h>
#include "../adt/matrix.c"
#define enter printf("\n");
#define border printf("---------------------------------\n");

#include "../adt/player.c"
#include "../adt_modified/pesanan.c"
// #include "../adt_modified/displaymap.c"

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

int main() {
    Config newgame;
    char *filename = "config.txt";
    if (loadGame(filename, &newgame)) {
        printf("success");
    } else {
        printf("fail");
    }
    // while (loadGame(filename, &newgame)) {
    //     printf("lenngth %d", lengthDftr(newgame.pesanans));
    //     printf("111");
    // }

    displayMatrix(newgame.adjMatrix);enter;
    displayList(newgame.bangunans);enter;
    printf("lenngth %d", lengthDftr(newgame.pesanans));enter;

    // ListPointDin l; // create hq
    // ListElType hqval;
    // CreateListDin(&l, 4); // create dummy list
    // LABEL(hqval) = 'Z';
    // KOORX(hqval) = 0;
    // KOORY(hqval) = 0;
    // insertLast(&newgame.bangunans, hqval);
    // displayList(newgame.bangunans);
    displayDaftarPesanan(newgame.pesanans);enter;
    Matrix m;
    readCustomMatrix(&m,13,18);
    printf("capcity bangunan %d\n",newgame.bangunans.capacity);
    showMap(&m,newgame.bangunans);
    displayMatrixLabel(m);enter;
////////////////////////
    Player p;
    POINT loc;
    CreatePlayer(&p);
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
    printf("\n");
    border;
    // command move
    printf("Waktu: %d\n", WAKTU(p));
    printf("Posisi yang dapat dicapai:\n");
    ListPointDin r;
    // CreateListDin(&r, 4);
    // displayList(r);
    showRelation(newgame.adjMatrix, newgame.bangunans, p.currentLoc);

    // list relasi

    
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    // misal pilih posisi 1

    // command pick up
    // jika current loc = loc di pesananan ,maka dipickup

    // get current loc label
    char CUR_LOCL;
    for(int i=0;i<20;i++) {
        if ((CUR_LOCX(p) == newgame.bangunans.buffer[i].position.X) && (CUR_LOCY(p) == newgame.bangunans.buffer[i].position.Y)) {
            CUR_LOCL = newgame.bangunans.buffer[i].label;
        }
    }
    // printf("label %c", CUR_LOCL);

    for(int j=0;j<20;j++) {
        if (CUR_LOCL == newgame.pesanans.daftar[j].PickUp) {
            char tipe_pesanan = newgame.pesanans.daftar[j].ItemType;
            if (tipe_pesanan = 'H') {
                printf("Pesanan berupa Heavy Item berhasil diambil!\n");
            }
            printf("Tujuan Pesanan: %c\n", newgame.pesanans.daftar[j].DropOff);
        }
    }




    

}


