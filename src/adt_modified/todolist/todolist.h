#ifndef TODOLIST_H_INCLUDED
#define TODOLIST_H_INCLUDED

#include "../../game_header.h"

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

void CreateTDfromPSN(TDList *l,DaftarPesanan *psn,int waktu);
void CreateListTD(TDList *l);
boolean isEmptyTD(TDList l);
AddressTD allocate(Pesanan val);

AddressTD search(TDList l, Pesanan val);
boolean searchPickUpTD(TDList l, char pickup);
boolean searchDropOffTD(TDList l, char dropoff);
Pesanan searchPickUpTDLabel(TDList l, char pickup);
Pesanan searchDropOffTDLabel(TDList l, char dropofflabel);
void insertFirstTD(TDList *l, Pesanan val);
void insertLastTD(TDList *l, Pesanan val);

void deleteFirstTD(TDList *l, Pesanan *val);
void deleteLastTD(TDList *l, Pesanan *val);
void deleteAtTD(TDList *l, AddressTD Tp);

void DisplayListToDo(TDList l,int waktu);

#endif // TODOLIST_H_INCLUDED
