#ifndef COMMAND_H
#define COMMAND_H

#include "boolean.h"

/* berisi command-command yang akan digunakan */

boolean new_game(char current[], int length);

boolean load_game(char current[], int length);

boolean exit_2(char current[], int length);

boolean move(char current[], int length);

boolean pick_up(char current[], int length);

boolean drop_off(char current[], int length);

boolean map(char current[], int length);

boolean to_do(char current[], int length);

boolean in_progress(char current[], int length);

boolean buy(char current[], int length);

boolean inventory(char current[], int length);

#endif
