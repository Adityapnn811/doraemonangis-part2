#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"

int main(){
    Pesanan p1,p2,p3;
    CreatePesanan(&p1,1,'B','C','N',-1);
    CreatePesanan(&p2,3,'X','Z','H',-1);
    CreatePesanan(&p3,2,'A','D','H',-1);
    DaftarPesanan psn;
    CreateDaftar(&psn);
    enqueuePsn(&psn,p1);
    enqueuePsn(&psn,p2);
    enqueuePsn(&psn,p3);
    TDList Td;
    CreateListTD(&Td);
    CreateTDfromPSN(&Td,&psn,waktu);
    Item a,b;
    CreateItem(&a,2,'A','B','N',-1);
    CreateItem(&a,3,'D','B','H',-1);
    Tas tas;
    CreateTas(&tas);
    addItem(&tas,a);
    addItem(&tas,b);
    Inventory inv1;
    CreateInv(&inv1);
    Player p1;
    CreatePlayer(&p1);
    UANG(p1) = 10000;
    WAKTU(p1) = 15;
    ListPointDin l;
    ListElType val; // list
    CreateListDin(&l, 5);
    for (int i = 0; i < 5; i++){
        LABEL(val) = 'A'+i;
        KOORX(val) = i;
        KOORY(val) = i+1;
        insertLast(&l, val);
    }

    print("Is Full Inv: %c\n",isFullInv(inv1));
    BuyGadget(&inv1,&uang);
    DisplayGadget(&inv1,&WAKTU(p),&tas,&Td,psn,&p1,&l);
    AddGadget(&inv1,Mesin);
    DisplayGadget(&inv1,&WAKTU(p1),&tas,Td,psn,&p1,l);
    UseGadget(Mesin,&WAKTU(p1),&tas,psn,&p1,l);
    AddGadget(&inv1,Mesin);
    DisplayGadget(&inv1,&WAKTU(p1),&tas,Td,psn,&p1,l);
    deleteGadget(&inv1, 0);
    DisplayGadget(&inv1,&WAKTU(p1),&tas,Td,psn,&p1,l);

    
    return 0;
}