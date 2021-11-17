/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include <stdio.h>
#include "../../game_header.h"

#define CHARMACHINE_MARK '\n'

/* Char Engine State */
extern char currentChar;
extern boolean eot;

void start(FILE *tape);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika EOF = false maka EOT akan padam (false)
          Jika EOF = true maka EOT akan menyala (true) */

void adv();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, EOF = false
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin EOF
		      Jika EOF = true maka EOT akan menyala (true) */

#endif
