#ifndef LOAD_H
#define LOAD_H

#include "../models/config.h"
#include "../adt/wordmachine.h"

boolean loadGame(char *filename, Config *conf);
boolean wordToStr(Word word, char *value);
boolean wordToInt(Word word, int *value);

#endif
