/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;

static FILE *stream;
static int retval;

void start(FILE *tape)
{
  /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika EOF = false maka EOT akan padam (false)
          Jika EOF = true maka EOT akan menyala (true) */

  /* Algoritma */
  stream = tape;
  adv();
}

void adv()
{
  /* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, EOF = false
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin EOF
		      Jika EOF = true maka EOT akan menyala (true) */

  /* Algoritma */
  currentChar = fgetc(stream);

  eot = (feof(stream)) || currentChar == CHARMACHINE_MARK;
}
