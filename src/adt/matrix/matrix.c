#include <stdio.h>
#include "../../game_header.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
{
  /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
  /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
  /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
  /* ALGORITMA */
  ROWS(*m) = nRow;
  COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidMatrix(int i, int j)
{
  /* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
  /* ALGORITMA */
  return (i >= 0) && (j >= 0) && (i < ROW_CAP) && (j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
{
  /* Mengirimkan Index baris terbesar m */
  /* ALGORITMA */
  return ROWS(m) - 1;
}
Index getLastIdxCol(Matrix m)
{
  /* Mengirimkan Index kolom terbesar m */
  /* ALGORITMA */
  return COLS(m) - 1;
}
boolean isIdxEffMatrix(Matrix m, Index i, Index j)
{
  /* Mengirimkan true jika i, j adalah Index efektif bagi m */
  /* ALGORITMA */
  return isIdxValidMatrix(i, j) && (i <= getLastIdxRow(m)) && (j <= getLastIdxCol(m));
}

void displayMatrix(Matrix m)
{
  /* I.S. m terdefinisi */
  /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi */
  /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
  /* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
  1 2 3
  4 5 6
  8 9 10
  */
  /* KAMUS */
  int i, j, lastRow, lastCol;

  /* ALGORITMA */
  lastRow = getLastIdxRow(m);
  lastCol = getLastIdxCol(m);
  for (i = 0; i <= lastRow; i++)
  {
    for (j = 0; j <= lastCol; j++)
    {
      printf("%d%s", ELMT(m, i, j), (j == lastCol ? "" : " "));
    }
    printf("%s", (i == lastRow ? "" : "\n"));
  }
}

void displayMatrixLabel(Matrix m, Matrix m_adj, ListPointDin l_bangunan, Player p, Tas tas, TDList todoList)
{
  /* I.S. m terdefinisi */
  /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi */
  /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
  /* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
  1 2 3
  4 5 6
  8 9 10
  */
  /* KAMUS */
  int i, j, lastRow, lastCol;
  ListPointDin l_adj;

  /* ALGORITMA */
  l_adj = mShowRelation(m_adj, l_bangunan, CUR_LOC(p));
  lastRow = getLastIdxRow(m);
  lastCol = getLastIdxCol(m);
  for (i = 0; i <= lastRow; i++)
  {
    for (j = 0; j <= lastCol; j++)
    {
      // Cek Apakah i, j merupakan koordinat mobita
      if (CUR_LOCX(p) == i && CUR_LOCY(p) == j) {
        print_yellow((char) ELMT(m, i, j));
      } else if (TOP(tas).DropOff == (char) ELMT(m, i, j)) { // Lokasi drop off, 
        print_blue((char) ELMT(m, i, j));
      } else if (searchPickUpTD(todoList, (char) ELMT(m, i, j))) { // Lokasi pick up daftar pesanan
        print_red((char) ELMT(m, i, j));
      } else if (pointInListPoint(i, j, l_adj)) { // Cek adjacency dari player
        print_green((char) ELMT(m, i, j));
      } else {
        printf("%c", ELMT(m, i, j));
      }
      printf("%s", (j == lastCol ? "" : " "));
    }
    printf("%s", (i == lastRow ? "" : "\n"));
  }
}
