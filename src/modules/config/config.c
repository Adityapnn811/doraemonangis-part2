#include "../../game_header.h"

boolean loadConfig(char *filename, Config *conf)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
    return false;
  }

  /**
   * Tidak dilakukan validasi karena asumsi file konfigurasi valid
   */

  int x, y, n, i, j;

  // Ukuran map

  startWord(fp);
  wordToInt(currentWord, &(conf->mapRows));

  advWord();
  wordToInt(currentWord, &(conf->mapCols));

  // Koordinat HQ

  startWord(fp);
  wordToInt(currentWord, &x);

  advWord();
  wordToInt(currentWord, &y);

  Bangunan b;
  b.label = '8';
  b.position = MakePOINT(x, y); // sementara pake koordinat HQ (0,0)

  // Lokasi

  // Jumlah lokasi
  startWord(fp);
  wordToInt(currentWord, &n);

  // Insert HQ dulu
  CreateListPointDin(&(conf->bangunans), n);
  insertLastListPoint(&(conf->bangunans), b);

  // List lokasi
  for (i = 0; i < n; i++)
  {
    startWord(fp);
    b.label = currentWord.contents[0];

    advWord();
    wordToInt(currentWord, &x);

    advWord();
    wordToInt(currentWord, &y);

    b.position = MakePOINT(x, y);
    insertLastListPoint(&(conf->bangunans), b);
  }

  // Adjacency matrix

  int matSize = n + 1;
  Matrix matrix;
  CreateMatrix(matSize, matSize, &matrix);

  for (i = 0; i < matSize; i++)
  {
    startWord(fp);
    for (j = 0; j < matSize; j++)
    {
      wordToInt(currentWord, &x);
      ELMT(matrix, i, j) = x;
      advWord();
    }
  }

  conf->adjMatrix = matrix;

  // Pesanan

  // Jumlah pesanan
  startWord(fp);
  wordToInt(currentWord, &n);

  // List pesanan
  DaftarPesanan pesanans;
  CreateDaftar(&pesanans);
  for (i = 0; i < n; i++)
  {
    Pesanan p;
    int tIn, tPerish;
    char pickUp, dropOff, itemType;

    startWord(fp);
    wordToInt(currentWord, &tIn);

    advWord();
    pickUp = currentWord.contents[0];

    advWord();
    dropOff = currentWord.contents[0];

    advWord();
    itemType = currentWord.contents[0];

    if (itemType == 'P')
    {
      advWord();
      wordToInt(currentWord, &tPerish);
    }

    CreatePesanan(&p, tIn, pickUp, dropOff, itemType, tPerish);
    enqueuePsn(&pesanans, p);
  }

  conf->pesanans = pesanans;

  // fclose(fp);
  return true;
}
