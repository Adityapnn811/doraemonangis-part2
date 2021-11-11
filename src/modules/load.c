#include <stdio.h>
#include <ctype.h>
#include "load.h"
#include "../models/boolean.h"
#include "../models/config.h"
#include "../models/bangunan.h"
#include "../adt/wordmachine.h"
#include "../adt/point.h"
#include "../adt_modified/listpointdin.h"
#include "../adt_modified/pesanan.h"

boolean loadGame(char *filename, Config *conf)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
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

  fclose(fp);
  return true;
}

boolean wordToStr(Word word, char *value)
{
  int i;
  for (i = 0; i < word.length; i++)
  {
    value[i] = word.contents[i];
  }
  value[i] = '\0';
}

boolean wordToInt(Word word, int *value)
{
  boolean status = false;

  if (word.length > 0)
  {
    *value = 0;
    status = true;

    int i = 0;
    if (word.contents[0] == '-')
    {
      ++i;
    }

    if (word.contents[i] == '0' && (i + 1) < word.length)
    {
      status = false;
    }
    else
    {
      while (i < word.length && status)
      {
        if (isdigit(word.contents[i]))
        {
          *value *= 10;
          *value += (int)(word.contents[i] - '0');
          ++i;
        }
        else
        {
          status = false;
        }
      }

      if (word.contents[0] == '-')
      {
        *value *= -1;
      }
    }
  }

  return status;
}