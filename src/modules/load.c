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
    printf("load gagal\n");
  }
  else
  {
    printf("load sukses\n");
  }

  int x, y, n, i, j;

  // Ukuran map

  startWord(fp);
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

  // Koordinat HQ

  startWord(fp);
  if (endWord || !wordToInt(currentWord, &x))
  {
    return false;
  }

  advWord();
  if (endWord || !wordToInt(currentWord, &y))
  {
    return false;
  }

  CreateListDin(&(conf->bangunans), n);

  Bangunan b;
  b.label = 'Z';
  b.position = MakePOINT(1, 1); // sementara pake koordinat HQ (1,1)

  insertLast(&(conf->bangunans), b);

  // Lokasi

  // Jumlah lokasi
  startWord(fp);
  if (endWord || !wordToInt(currentWord, &n))
  {
    return false;
  }

  // List lokasi
  for (i = 0; i < n; i++)
  {
    startWord(fp);
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

    b.position = MakePOINT(x, y);
    insertLast(&(conf->bangunans), b);
  }

  // Adjacency matrix

  int matSize = n + 1;
  CreateMatrix(matSize, matSize, &(conf->adjMatrix));

  for (i = 0; i < matSize; i++)
  {
    startWord(fp);
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
  startWord(fp);
  if (endWord || !wordToInt(currentWord, &n))
  {
    return false;
  }

  // List pesanan
  // printf("n pesanan %d", n); // cek n pesanan
  CreateDaftar(&(conf->pesanans));
  for (i = 0; i < n; i++)
  {
    Pesanan p;
    int tIn, tPerish;
    char pickUp, dropOff, itemType;

    startWord(fp);
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