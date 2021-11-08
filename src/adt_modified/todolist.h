#ifndef TODOLIST_H_INCLUDED
#define TODOLIST_H_INCLUDED

#include "pesanan.h"


typedef struct node *Address;
typedef struct node {
	Pesanan info;
	Address next;
	Address prev;
} Node;
typedef struct {
	Address first;
	Address last;
} TDList;

/* Selektor */
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define PREV(P) (P)->prev
#define FIRST(L) ((L).first)
#define LAST(L) ((L).last)

void CreateTDfromPSN(TDList *l,DaftarPesanan psn);
void CreateListTD(TDList *l);
boolean isEmptyTD(TDList l);
Address allocate(Pesanan val);

Address search(TDList l, Pesanan val);
void insertFirstTD(TDList *l, Pesanan val);
void insertLastTD(TDList *l, Pesanan val);

void deleteFirstTD(TDList *l, Pesanan *val);
void deleteLastTD(TDList *l, Pesanan *val);
void deleteAtTD(TDList *l, Address Tp);

void DisplayListToDo(DaftarPesanan psn);

#endif // TODOLIST_H_INCLUDED
