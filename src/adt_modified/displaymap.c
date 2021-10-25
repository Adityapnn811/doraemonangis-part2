// #include <stdio.h>
// #include "listpointdin.c"
// #include "../adt/matrix.c"

// int main() {
//     ListPointDin l;
//     ElType val;
//     int i;
//     CreateListDin(&l, 5);
//     for (i = 0; i < 5; i++){
//         LABEL(val) = 'A';
//         KOORX(val) = i;
//         KOORY(val) = i;
//         insertLast(&l, val);
//     }
//     displayList(l);
//     printf("\n");
// }
#include <stdio.h>
#include "listpointdin.c"
#include "../adt/matrix.c"

void showMap(Matrix *m, ListPointDin l, ListElType val) {
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
}



int main(){
    Matrix m;
    ListPointDin l; // point di dalam list
    ListElType val; // list
    int i;
    CreateListDin(&l, 5); // create dummy list
    for (i = 0; i < 5; i++){
        LABEL(val) = 'A'+i;
        KOORX(val) = i;
        KOORY(val) = i+1;
        insertLast(&l, val);
    }
    readCustomMatrix(&m,10,10); // fill matrix with border and blank space
    displayMatrix(m);
    showMap(&m,l,val); // menampilkan koordinat pada matriks
    displayMatrix(m);
    return 0;
}

