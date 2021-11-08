#ifndef TAS_H_INCLUDED
#define TAS_H_INCLUDED

#include "../adt/item.h"
#include "../models/boolean.h"

#define IDX_UNDEF -1
#define CAPACITY_TAS 100

typedef struct {
    Item daftar[CAPACITY_TAS];
    int idxTop;

} Tas;

#define IDX_TOP(s) (s).idxTop
#define TOP(s) (s).daftar[(s).idxTop]

int maxTas;
boolean useAbility;

void CreateTas(Tas *tas);
void addItem(Tas *tas, Item val);
void dropItem(Tas *tas1);


#endif // TAS_H_INCLUDED
