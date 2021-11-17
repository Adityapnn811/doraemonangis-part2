#ifndef TAS_H_INCLUDED
#define TAS_H_INCLUDED

#include "../../game_header.h"

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
int lengthTas(Tas tas);
void addItem(Tas *tas, Item val);
void dropItem(Tas *tas1);
void dropItemToVal(Tas *tas1,Item *val);
int CountHeavy(Tas tas);

void reduceAllPerishTime(Tas *t);
void cancelEfekPengecil(Tas *t);


#endif // TAS_H_INCLUDED
