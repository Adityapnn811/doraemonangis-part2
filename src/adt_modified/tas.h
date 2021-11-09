#ifndef TAS_H_INCLUDED
#define TAS_H_INCLUDED

#include "../adt/item.h"
#include "../models/boolean.h"

#define IDX_UNDEF -1
#define CAPACITY_TAS 100

typedef struct {
    Item daftar[CAPACITY_TAS];
    int idxTop;
    int maxTas;

} Tas;

#define IDX_TOP(s) (s).idxTop
#define TOP(s) (s).daftar[(s).idxTop]

int maxTas;
boolean useAbility;

void CreateTas(Tas *tas);
boolean isEmptyTas(Tas s);
void addItem(Tas *tas, Item val);
void dropItem(Tas *tas1);
void dropItemToVal(Tas *tas1,Item *val);
void DisplayInPrgs(Tas t);
// void setLengthTas(Tas *tas);


#endif // TAS_H_INCLUDED
