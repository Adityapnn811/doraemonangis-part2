/* MODUL UNTUK MEMBENTUK TIPE DATA ITEM */

#ifndef ITEM_H
#define ITEM_H

/* DEFINISI KONSTANTA */
#define TIME_UNDEF -1
/* Waktu tak terdefinisi */

/* DEFINISI ELEMEN DAN OBJEK */
typedef struct {
    int TimeIn; // Waktu masuk item
    char PickUp; // bangunan tempat pick up item
    char DropOff; // bangunan untuk drop off item
    char ItemType; // tipe item, h, n, dll
    int TimePerish; // waktu hingga item hangus, hanya untuk item P, selain item P bernilai TIME_UNDEF
} Item;

/* SELEKTOR */
#define TIMEIN(i) (i).TimeIn
#define PICKUP(i) (i).PickUp
#define DROPOFF(i) (i).DropOff
#define TYPE(i) (i).ItemType
#define TIMEPERISH(i) (i).TimePerish

/* KONSTRUKTOR */
void CreateItem(Item *i, int TimeIn, char PickUp, char DropOff, char ItemType, int TimePerish);
/* I.S. Item sembarang */
/* F.S. Item memiliki atribut sesuai input, untuk item selain P, parameter TimePerish tidak akan terpakai dan akan lgsg diisi TIME_UNDEF */

/* SETTER DAN GETTER PRIMITIF */
int getTimeIn(Item i);
/* Fungsi mengembalikan nilai TimeIn dari Item i */

char getPickUp(Item i);
/* Fungsi mengembalikan label bangunan tempat pickup item i */

char getDropOff(Item i);
/* Fungsi mengembalikan label bangunan tempat drop off item i */

char getItemType(Item i);
/* Fungsi mengembalikan tipe item i */

int getTimePerish(Item i);
/* Fungsi mengembalikan time perish item i */

void setTimePerish(Item *i, int TimePerish);
/* I.S. Item terdefinisi dan memiliki nlai TimePerish */
/* F.S. Nilai TimePerish dari item i = TimePerish */

#endif