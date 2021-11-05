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
  if (fp == NULL) {
    printf("load gagal\n");
  } else {
    printf("load sukses\n");
  }

  int x, y, n, i, j;
  startWord(fp);

  // Ukuran map

  if (endWord || !wordToInt(currentWord, &(conf->mapRows)) ||
      conf->mapRows < 10 || conf->mapRows > 20)
  {
    return false;
  }
  advWord();

  if (endWord || !wordToInt(currentWord, &(conf->mapCols)) ||
      conf->mapCols < 10 || conf->mapCols > 30)
  {
    return false;
  }
  advWord();

  // Koordinat HQ

  if (endWord || !wordToInt(currentWord, &x))
  {
    return false;
  }
  advWord();

  if (endWord || !wordToInt(currentWord, &y))
  {
    return false;
  }
  advWord();

  CreateListDin(&(conf->bangunans), n);

  Bangunan b;
  b.label = 'Z';
  b.position = MakePOINT(0, 0); // sementara pake koordinat HQ (0,0)

  insertLast(&(conf->bangunans), b);

  // Lokasi

  // Jumlah lokasi
  if (endWord || !wordToInt(currentWord, &n))
  {
    return false;
  }
  advWord();

  // List lokasi
  for (i = 0; i < n; i++)
  {
    if (endWord || currentWord.length != 1)
    {
      return false;
    }

    b.label = currentWord.contents[0];

    advWord();

    if (endWord || !wordToInt(currentWord, &x))
    {
      return false;
    }
    advWord();

    if (endWord || !wordToInt(currentWord, &y))
    {
      return false;
    }
    advWord();

    b.position = MakePOINT(x, y);

    insertLast(&(conf->bangunans), b);
  }

  // Adjacency matrix

  int matSize = n + 1;
  CreateMatrix(matSize, matSize, &(conf->adjMatrix));

  for (i = 0; i < matSize; i++)
  {
    for (j = 0; j < matSize; j++)
    {
      if (endWord || !wordToInt(currentWord, &x))
      {
        return false;
      }
      advWord();

      ELMT(conf->adjMatrix, i, j) = x;
    }
  }

  if (!isSymmetric(conf->adjMatrix))
  {
    return false;
  }

  // Pesanan

  // Jumlah pesanan
  if (endWord || !wordToInt(currentWord, &n))
  {
    return false;
  }
  advWord();

  // List pesanan
  // printf("n pesanan %d", n); // cek n pesanan
  CreateDaftar(&(conf->pesanans));
  for (i = 0; i < n; i++)
  {
    Pesanan p;
    int tIn, tPerish;
    char pickUp, dropOff, itemType;

    if (endWord || !wordToInt(currentWord, &tIn))
    {
      return false;
    }
    advWord();

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    pickUp = currentWord.contents[0];
    advWord();

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    dropOff = currentWord.contents[0];
    advWord();

    if (endWord || currentWord.length != 1)
    {
      return false;
    }
    itemType = currentWord.contents[0];
    advWord();

    if (itemType == 'P')
    {
      if (endWord || !wordToInt(currentWord, &tIn))
      {
        return false;
      }
      advWord();
    }

    CreatePesanan(&p, tIn, pickUp, dropOff, itemType, tPerish);
    enqueuePsn(&(conf->pesanans), p);
  }

  if (!endWord)
  {
    return false;
  }
  // fclose(fp);
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