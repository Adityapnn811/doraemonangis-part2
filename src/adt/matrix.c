#include <stdio.h>
#include "matrix.h"
#include "../models/boolean.h"

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
boolean isIdxValidMatrixMatrix(int i, int j)
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
ElType getElmtDiagonal(Matrix m, Index i)
{
  /* Mengirimkan elemen m(i,i) */
  /* ALGORITMA */
  return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
{
  /* Melakukan assignment MRes = MIn */
  /* ALGORITMA */
  *mRes = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
  /* I.S. isIdxValidMatrix(nRow,nCol) */
  /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
  /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
  /* Selanjutnya membaca nilai elemen per baris dan kolom */
  /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
  1 2 3
  4 5 6
  8 9 10 
  */
  /* KAMUS */
  ElType el;
  int i, j;

  /* ALGORITMA */
  CreateMatrix(nRow, nCol, m);
  for (i = 0; i < nRow; i++)
  {
    for (j = 0; j < nCol; j++)
    {
      scanf("%d", &el);
      ELMT(*m, i, j) = el;
    }
  }
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

void displayMatrixLabel(Matrix m)
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
      print_green((char) ELMT(m, i, j));
      printf("%s", (j == lastCol ? "" : " "));
    }
    printf("%s", (i == lastRow ? "" : "\n"));
  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
  /* Prekondisi : m1 berukuran sama dengan m2 */
  /* Mengirim hasil penjumlahan matriks: m1 + m2 */
  /* KAMUS */
  Matrix mRes;
  int i, j;

  /* ALGORITMA */
  CreateMatrix(ROWS(m1), COLS(m1), &mRes);
  for (i = 0; i <= getLastIdxRow(m1); i++)
  {
    for (j = 0; j <= getLastIdxCol(m1); j++)
    {
      ELMT(mRes, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
    }
  }

  return mRes;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
  /* Prekondisi : m1 berukuran sama dengan m2 */
  /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
  /* KAMUS */
  Matrix mRes;
  int i, j;

  /* ALGORITMA */
  CreateMatrix(ROWS(m1), COLS(m1), &mRes);
  for (i = 0; i <= getLastIdxRow(m1); i++)
  {
    for (j = 0; j <= getLastIdxCol(m1); j++)
    {
      ELMT(mRes, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
    }
  }

  return mRes;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
  /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
  /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
  /* KAMUS */
  Matrix mRes;
  int i, j, k;

  /* ALGORITMA */
  CreateMatrix(ROWS(m1), COLS(m2), &mRes);
  for (i = 0; i <= getLastIdxRow(m1); i++)
  {
    for (j = 0; j <= getLastIdxCol(m1); j++)
    {
      ELMT(mRes, i, j) = 0;
      for (k = 0; k <= getLastIdxRow(m2); k++)
      {
        ELMT(mRes, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
      }
    }
  }

  return mRes;
}
Matrix multiplyConst(Matrix m, ElType x)
{
  /* Mengirim hasil perkalian setiap elemen m dengan x */
  /* KAMUS */
  Matrix mRes;
  int i, j;

  /* ALGORITMA */
  CreateMatrix(ROWS(m), COLS(m), &mRes);
  for (i = 0; i <= getLastIdxRow(m); i++)
  {
    for (j = 0; j <= getLastIdxCol(m); j++)
    {
      ELMT(mRes, i, j) = x * ELMT(m, i, j);
    }
  }

  return mRes;
}
void pMultiplyConst(Matrix *m, ElType k)
{
  /* I.S. m terdefinisi, k terdefinisi */
  /* F.S. Mengalikan setiap elemen m dengan k */
  /* KAMUS */
  int i, j;

  /* ALGORITMA */
  for (i = 0; i <= getLastIdxRow(*m); i++)
  {
    for (j = 0; j <= getLastIdxCol(*m); j++)
    {
      ELMT(*m, i, j) = k * ELMT(*m, i, j);
    }
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMatrix(Matrix m1, Matrix m2)
{
  /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
  /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
  /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
  /* KAMUS */
  boolean flag;
  int i, j;

  /* ALGORITMA */
  flag = true;

  if (!isSizeEqualMatrix(m1, m2))
  {
    flag = false;
  }

  for (i = 0; i <= getLastIdxRow(m1) && flag; i++)
  {
    for (j = 0; j <= getLastIdxCol(m1) && flag; j++)
    {
      flag = ELMT(m1, i, j) == ELMT(m2, i, j);
    }
  }

  return flag;
}
boolean isNotEqualMatrix(Matrix m1, Matrix m2)
{
  /* Mengirimkan true jika m1 tidak sama dengan m2 */
  /* ALGORITMA */
  return !isEqualMatrix(m1, m2);
}
boolean isSizeEqualMatrixMatrix(Matrix m1, Matrix m2)
{
  /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
  /* ALGORITMA */
  return getLastIdxRow(m1) == getLastIdxRow(m2) && getLastIdxCol(m1) == getLastIdxCol(m2);
}

/* ********** Operasi lain ********** */
int countMatrix(Matrix m)
{
  /* Mengirimkan banyaknya elemen m */
  /* ALGORITMA */
  return ROWS(m) * COLS(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
  /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
  /* ALGORITMA */
  return ROWS(m) == COLS(m);
}
boolean isSymmetric(Matrix m)
{
  /* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
    dan untuk setiap elemen m, m(i,j)=m(j,i) */
  /* KAMUS */
  boolean flag;
  int i, j, lastIdx;

  /* ALGORITMA */
  flag = true;

  if (!isSquare(m))
  {
    flag = false;
  }

  lastIdx = getLastIdxRow(m);

  for (i = 0; i <= lastIdx && flag; i++)
  {
    for (j = 0; j <= lastIdx && flag; j++)
    {
      flag = ELMT(m, i, j) == ELMT(m, j, i);
    }
  }

  return flag;
}
boolean isIdentity(Matrix m)
{
  /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
    setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
  /* KAMUS */
  boolean flag;
  int i, j;

  /* ALGORITMA */
  flag = true;

  if (!isSquare(m))
  {
    flag = false;
  }

  for (i = 0; i <= getLastIdxRow(m) && flag; i++)
  {
    for (j = 0; j <= getLastIdxCol(m) && flag; j++)
    {
      if (i == j)
        flag = ELMT(m, i, j) == 1;
      else
        flag = ELMT(m, i, j) == 0;
    }
  }

  return flag;
}
boolean isSparse(Matrix m)
{
  /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
  /* KAMUS */
  int fillCount, maxFilled, i, j;
  boolean flag;

  /* ALGORITMA */
  flag = true;
  fillCount = 0;
  maxFilled = 0.05 * countMatrix(m);

  for (i = 0; i <= getLastIdxRow(m) && flag; i++)
  {
    for (j = 0; j <= getLastIdxCol(m) && flag; j++)
    {
      if (ELMT(m, i, j) != 0)
      {
        ++fillCount;
        flag = fillCount <= maxFilled;
      }
    }
  }

  return flag;
}
Matrix inverse1(Matrix m)
{
  /* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
  /* KAMUS */
  Matrix mRes;
  int i, j;

  /* ALGORITMA */
  CreateMatrix(ROWS(m), COLS(m), &mRes);
  for (i = 0; i <= getLastIdxRow(m); i++)
  {
    for (j = 0; j <= getLastIdxCol(m); j++)
    {
      ELMT(mRes, i, j) = -ELMT(m, i, j);
    }
  }

  return mRes;
}
void pInverse1(Matrix *m)
{
  /* I.S. m terdefinisi */
  /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
  /* KAMUS */
  int i, j;

  /* ALGORITMA */
  for (i = 0; i <= getLastIdxRow(*m); i++)
  {
    for (j = 0; j <= getLastIdxCol(*m); j++)
    {
      ELMT(*m, i, j) = -ELMT(*m, i, j);
    }
  }
}
float determinant(Matrix m)
{
  /* Prekondisi: isSquare(m) */
  /* Menghitung nilai determinan m */
  /* KAMUS */
  int col, i, j, lastIdx;
  float det, addend;
  Matrix cofactor;

  /* ALGORITMA */
  if (ROWS(m) == 2)
  {
    /* Basis: Matriks 2x2 */
    return (float)(ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0));
  }
  else
  {
    /* Rekurens: Matriks N x N */
    lastIdx = getLastIdxRow(m);
    det = 0.0;
    for (col = 0; col <= lastIdx; col++)
    {
      /* Baris acuan: Baris pertama */
      /* Buat kofaktor */
      CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &cofactor);
      for (i = 1; i <= lastIdx; i++)
      {
        for (j = 0; j <= lastIdx; j++)
        {
          if (j != col)
          {
            ELMT(cofactor, i - 1, (j < col ? j : j - 1)) = ELMT(m, i, j);
          }
        }
      }

      /* Hitung faktor penambah */
      addend = (float)ELMT(m, 0, col) * determinant(cofactor);
      if (col % 2 != 0)
      {
        addend = -addend;
      }

      /* Tambahkan ke determinan */
      det += addend;
    }
  }

  return det;
}
void transpose(Matrix *m)
{
  /* I.S. m terdefinisi dan isSquare(m) */
  /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
  /* KAMUS */
  int i, j;
  ElType tmp;

  /* ALGORITMA */
  for (i = 0; i <= getLastIdxRow(*m); i++)
  {
    for (j = i; j <= getLastIdxCol(*m); j++)
    {
      tmp = ELMT(*m, i, j);
      ELMT(*m, i, j) = ELMT(*m, j, i);
      ELMT(*m, j, i) = tmp;
    }
  }
}
