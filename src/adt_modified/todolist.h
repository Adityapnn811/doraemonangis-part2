#ifndef TODOLIST_H_INCLUDED
#define TODOLIST_H_INCLUDED

#include "pesanan.h"


typedef struct nodeTD *AddressTD;
typedef struct nodeTD {
	Pesanan info;
	AddressTD next;
	AddressTD prev;
} NodeTD;
typedef struct {
	AddressTD first;
	AddressTD last;
} TDList;

/* Selektor */
#define INFOTD(P) (P)->info
#define NEXTTD(P) (P)->next
#define PREVTD(P) (P)->prev
#define FIRSTTD(L) ((L).first)
#define LASTTD(L) ((L).last)

void CreateTDfromPSN(TDList *l,DaftarPesanan psn);
void CreateListTD(TDList *l);
boolean isEmptyTD(TDList l);
AddressTD allocate(Pesanan val);

AddressTD search(TDList l, Pesanan val);
void insertFirstTD(TDList *l, Pesanan val);
void insertLastTD(TDList *l, Pesanan val);

void deleteFirstTD(TDList *l, Pesanan *val);
void deleteLastTD(TDList *l, Pesanan *val);
void deleteAtTD(TDList *l, AddressTD Tp);

void DisplayListToDo(DaftarPesanan psn);

#endif // TODOLIST_H_INCLUDED
