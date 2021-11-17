/**
 * File: wordmachine.c
 * Implementasi wordmachine
 */
#include <stdio.h>
#include "wordmachine.h"

char currentChar;
Word currentWord;
boolean endWord;

static boolean isBlank(char c)
{
  /* Menunjukkan apakah suatu karakter termasuk blank atau tidak */
  /* ALGORITMA */
  return c == ' ' || c == '\t' || c == '\v' || c == '\r';
}

void ignoreBlank()
{
  /* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang 
    F.S. : currentChar ≠ BLANK atau EOT = true */

  /* ALGORITMA */
  while (!eot && isBlank(currentChar))
  {
    adv();
  }

  endWord = eot;
}

void startWord(FILE *tape)
{
  /* I.S. : currentChar sembarang 
    F.S. : endWord = true, dan EOT = true; 
            atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

  /* ALGORITMA */
  start(tape);
  ignoreBlank();

  /* Reset currentWord */
  currentWord.length = 0;

  endWord = eot;
  if (!endWord)
  {
    copyWord();
  }

  ignoreBlank();
}

void advWord()
{
  /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika EOT = true, endWord = true.		  
    Proses : Akuisisi kata menggunakan procedure copyWord */

  /* ALGORITMA */
  ignoreBlank();

  endWord = eot;
  if (!endWord)
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
            currentChar = BLANK atau EOT = true; 
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
  /* KAMUS */
  int i;

  /* ALGORITMA */
  i = 0;
  while (!eot && !isBlank(currentChar) && i < WORD_CAPACITY)
  {
    currentWord.contents[i] = currentChar;
    adv();
    i++;
  }
  currentWord.length = i;
}

void ignoreWords()
{
  /* Menggerakkan file pointer hingga ke ujung tape,
     Dalam kata lain, mengabaikan setiap words dimulai dari titik ini. */
  while (!endWord)
  {
    advWord();
  }
}
