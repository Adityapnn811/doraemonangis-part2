/* MODUL DISPLAY MAP */
#ifndef DISPLAYMAP_H
#define DISPLAYMAP_H

#include "../../game_header.h"

void showMap(Matrix *m, ListPointDin l);
/* I.S. Elemen matrix m sembarang */
/* F.S. Elemen matrix m berisi label dari list */

void readCustomMatrix(Matrix *m, int nRow, int nCol);
/* I.S. Matrix m sembarang */
/* F.S. Matrix m berisi border dan karakter kosong */

void readAdjacencyMatrix(Matrix *m);
/* I.S. Matrix m sembarang */
/* F.S. Matrix m berisi adjacency dari bangunan */

void showRelation(Matrix m, ListPointDin l, POINT p);
/* I.S. Matrix m, List l, dan Point p terdefinisi */
/* F.S. Menampilkan adjacency dari point p berdasarkan data l dan m */

ListPointDin mShowRelation(Matrix m, ListPointDin l, POINT p);
/* FUNGSI mengembalikan adjacency dari Point p (Posisi Player) */

boolean pointInListPoint(float x, float y, ListPointDin l_adj);
/* Fungsi mengembalikan true jika titik (x,y) ada di list */
#endif