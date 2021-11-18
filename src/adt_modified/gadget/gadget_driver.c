#include <stdio.h>
#include <stdlib.h>
#include "../../game_header.h"

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
    CreateTDfromPSN(&Td,&psn,10);
    Item a,b;
    CreateItem(&a,2,'A','B','N',-1);
    CreateItem(&b,3,'D','B','H',-1);
    Tas tas;
    CreateTas(&tas);
    addItem(&tas,a);
    addItem(&tas,b);
    Inventory inv1;
    CreateInv(&inv1);
    Player pl1;
    CreatePlayer(&pl1);
    UANG(pl1) = 10000;
    WAKTU(pl1) = 15;
    ListPointDin l;
    ListElType val; // list
    CreateListPointDin(&l, 5);
    for (int i = 0; i < 5; i++){
        LABEL(val) = 'A'+i;
        KOORX(val) = i;
        KOORY(val) = i+1;
        insertLastListPoint(&l, val);
    }

    printf("Is Full Inv: %c\n",isFullInv(inv1));
    BuyGadget(&inv1,&UANG(pl1));
    DisplayGadget(&inv1,&WAKTU(pl1),&tas,Td,psn,&pl1,l);
    AddGadget(&inv1,DaftarGadget[0]);
    DisplayGadget(&inv1,&WAKTU(pl1),&tas,Td,psn,&pl1,l);
    boolean flag = false;
    UseGadget(&flag,DaftarGadget[0],&WAKTU(pl1),&tas,psn,&pl1,l);
    AddGadget(&inv1,DaftarGadget[0]);
    DisplayGadget(&inv1,&WAKTU(pl1),&tas,Td,psn,&pl1,l);
    deleteGadget(&inv1, 0);
    DisplayGadget(&inv1,&WAKTU(pl1),&tas,Td,psn,&pl1,l);

    
    return 0;
}