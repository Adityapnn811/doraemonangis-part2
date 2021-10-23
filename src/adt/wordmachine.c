/**
 * File: matrix.c
 * Tanggal: 2021/09/29
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 *
 * wordmachine.c
 * 
 */
#include "charmachine.h"
#include "wordmachine.h"

char currentChar;
Word currentWord;
boolean endWord;

void ignoreBlank()
{
  /* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang 
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */

  /* ALGORITMA */
  while (currentChar == BLANK)
  {
    adv();
  }
}

void startWord()
{
  /* I.S. : currentChar sembarang 
    F.S. : endWord = true, dan currentChar = MARK; 
            atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

  /* ALGORITMA */
  start();
  ignoreBlank();

  if (currentChar == MARK)
  {
    endWord = true;
  }
  else
  {
    endWord = false;
    copyWord();
  }

  ignoreBlank();
}

void advWord()
{
  /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, endWord = true.		  
    Proses : Akuisisi kata menggunakan procedure copyWord */

  /* ALGORITMA */
  ignoreBlank();

  if (currentChar == MARK)
  {
    endWord = true;
  }
  else
  {
    copyWord();
  }

  ignoreBlank();
}

void copyWord()
{
  /* Mengakuisisi kata, menyimpan dalam currentWord
    I.S. : currentChar adalah karakter pertama dari kata
    F.S. : currentWord berisi kata yang sudah diakuisisi; 
            currentChar = BLANK atau currentChar = MARK; 
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
  /* KAMUS */
  int i;

  /* ALGORITMA */
  i = 0;
  do
  {
    currentWord.contents[i] = currentChar;
    adv();
    i++;
  } while (currentChar != MARK && currentChar != BLANK && i < CAPACITY);
  currentWord.length = i;
}
