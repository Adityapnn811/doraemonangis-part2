/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include <stdio.h>
#include "../modules/boolean.h"
#include "charmachine.h"

#define WORD_CAPACITY 50

typedef struct
{
   char contents[WORD_CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
extern boolean endWord;
extern Word currentWord;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau EOT = true */

void startWord(FILE *tape);
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan EOT = true; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika EOT = true, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau EOT = true; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void ignoreWords();
/* Menggerakkan file pointer hingga ke ujung tape,
   Dalam kata lain, mengabaikan setiap words dimulai dari titik ini. */

#endif
