#ifndef SPEEDBOOST_H
#define SPEEDBOOST_H

#include "../game_header.h"

typedef struct speedboost {
  boolean isActive;
  int moveCounter;
} Speedboost;

#define SB_ISACTIVE(s) (s).isActive
#define SB_COUNTER(s) (s).moveCounter

void resetSpeedboost(Speedboost *s);

#endif
