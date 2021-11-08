#include <stdio.h>
#include "listpointdin.h"
#include "../adt/matrix.h"
#include "../adt/point.h"
#include "displaymap.h"

void showMap(Matrix *m, ListPointDin l) {
    int i, j;
    for (i = 0; i < ROWS(*m); i++)
    {
        for (j = 0; j < COLS(*m); j++)
        {
            for(int k=0;k<CAPACITY(l);k++) {
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
    int n=0;
    int counter = getIdxPoint(l, p);
    for(int i=0;i<COLS(m);i++) { // iterasi dimulai dari baris ke-index list
            if ((ELMT(m,counter,i) == 1)) {
                n += 1;
                printf("%d. %c (%d,%d)\n", n, ELMTLABEL(l,i), ELMTX(l,i), ELMTY(l,i));
            }

    }
    // for(int j=counter;j<ROWS(m);j++) {
    //     if ((ELMT(m,counter,j) == 1)) {
    //         n += 1;
    //         printf("%d. %c (%d,%d)\n", n, ELMTLABEL(l,j), ELMTX(l,j), ELMTY(l,j));
    //     }
    // }  
}

ListPointDin mShowRelation(Matrix m, ListPointDin l, POINT p) {
    /* KAMUS LOKAL */
    ListPointDin l_adj;
    Bangunan B;
    /* ALGORITMA */
    CreateListPointDin(&l_adj, COLS(m));
    int counter = getIdxPoint(l, p);
    for(int i=counter;i<COLS(m);i++) { // iterasi dimulai dari baris ke-index list
        if (ELMT(m,counter,i) == 1) {
            B.label = ELMTLABEL(l,i);
            B.position = POINT(l, i);
            insertLastListPoint(&l_adj, B);
        }
    }
    return l_adj;
}

boolean pointInListPoint(float x, float y, ListPointDin l_adj) {
    /* KAMUS LOKAL */
    boolean found = false;
    int i = 0;
    POINT p;
    /* ALGORITMA */
    p = MakePOINT(x, y);
    while (!found && i < NEFF(l_adj)) {
        if (Absis(p) == ELMTX(l_adj, i) && Ordinat(p) == ELMTY(l_adj, i)) {
            found = true;
        } else {
            i += 1;
        }
    }
    return found;
}


// int main(){
//     Matrix m, adj;
//     ListPointDin l; // point di dalam list
//     ListElType val; // list
//     ListElType hqval;
//     int i;
//     Player cur_player;
    // Tas tas;
    // Item item;
//     DaftarPesanan daf_pes;
//     Pesanan pes;

    // CreateItem(&item, 4, 'B', 'B', 'h', 8);
    // CreateTas(&tas);
    // addItem(&tas, item);
//     CreatePlayer(&cur_player);
//     CreateDaftar(&daf_pes);
//     CreatePesanan(&pes, 3, 'A', 'A', 'n', 20);
//     enqueuePsn(&daf_pes, pes);
//     CreateListPointDin(&l, 4); // create dummy list
//     LABEL(hqval) = 'Z';
//     KOORX(hqval) = 0;
//     KOORY(hqval) = 0;
//     insertLastListPoint(&l, hqval);
//     for (i = 0; i < 3; i++){
//         LABEL(val) = 'A'+i;
//         KOORX(val) = i+2;
//         KOORY(val) = i+1;
//         insertLastListPoint(&l, val);
//     }
//     displayListPoint(l);
//     readCustomMatrix(&m,10,10); // fill matrix with border and blank space
//     // displayMatrix(m);
//     printf("\n");
//     showMap(&m,l,val); // menampilkan koordinat pada matriks
//     readAdjacencyMatrix(&adj);
//     displayMatrixLabel(m, adj, l, cur_player, tas, daf_pes);
//     printf("\n");
//     // Matrix adj;
//     // readMatrix(&adj, 4, 4);
//     // printf("printed adj:\n");
//     // displayMatrix(adj);

//     POINT hq = MakePOINT(0,0);
//     printf("sb x: %d\n", Absis(hq));
//     printf("sb y: %d\n", Ordinat(hq));

//     displayMatrix(adj);printf("\n");
//     printf("indeks point posisi move di listdin: %d", getIdxPoint(l, hq));printf("\n");
//     displayListPoint(mShowRelation(adj, l, hq));
    
    

//     return 0;
// }

