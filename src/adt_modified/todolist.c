#include <stdio.h>
#include <stdlib.h>
#include "todolist.h"



void CreateListTD(TDList *l){
    FIRSTTD(*l) = NULL;
    LASTTD(*l) = NULL;
}

boolean isEmptyTD(TDList l){
    return FIRSTTD(l)==NULL && LASTTD(l)==NULL;
}

AddressTD allocate(Pesanan val){
    AddressTD p = (AddressTD) malloc(sizeof(NodeTD));
    if(p!=NULL){
        INFOTD(p)=val;
        NEXTTD(p)=NULL;
        PREVTD(p)=NULL;
        return p;
    }else{
        return NULL;
    }
}



AddressTD search(TDList l, Pesanan val){
    AddressTD p = FIRSTTD(l);
    boolean flag = false;
    while(!flag && p!=NULL){
            if(CmpPesanan(INFOTD(p),val)){
                flag = true;
            }else{
                p = NEXTTD(p);
            }
    }
    if(flag){
        return p;
    }else{
        return NULL;
    }
}

Pesanan searchPickUpTDLabel(TDList l, char pickuplabel) {
/* searching to do list berdasarkan label */
    /* KAMUS LOKAL */
    AddressTD p;
    Pesanan label;
    boolean perish;
    boolean found;
    /* ALGORITMA */
    
    p = FIRSTTD(l);
    found = false;
    perish = false;
    while (p != NULL &&  !found) {
        if (PICKUP(INFOTD(p)) == pickuplabel) {
            found = true;
            label = p->info;
        } else {
            p = NEXTTD(p);
        }
    }
    return label;
    
}

Pesanan searchDropOffTDLabel(TDList l, char dropofflabel) {
/* searching to do list berdasarkan label */
    /* KAMUS LOKAL */
    AddressTD p;
    Pesanan label;
    boolean perish;
    boolean found;
    /* ALGORITMA */
    
    p = FIRSTTD(l);
    found = false;
    perish = false;
    while (p != NULL &&  !found) {
        if (PICKUP(INFOTD(p)) == dropofflabel) {
            found = true;
            label = p->info;
        } else {
            p = NEXTTD(p);
        }
    }
    return label;
    
}

boolean searchPickUpTD(TDList l, char pickup) {
    /* KAMUS LOKAL */
    AddressTD p;
    boolean found;
    /* ALGORITMA */
    if (isEmptyTD(l)) {
        return false;
    } else {
        p = FIRSTTD(l);
        found = false;
        while (p != NULL &&  !found) {
            if (PICKUP(INFOTD(p)) == pickup) {
                found = true;
            } else {
                p = NEXTTD(p);
            }
        }
        return found;
    }
    
}

boolean searchDropOffTD(TDList l, char dropoff) {
    /* KAMUS LOKAL */
    AddressTD p;
    boolean found;
    /* ALGORITMA */
    if (isEmptyTD(l)) {
        return false;
    } else {
        p = FIRSTTD(l);
        found = false;
        while (p != NULL &&  !found) {
            if (DROPOFF(INFOTD(p)) == dropoff) {
                found = true;
            } else {
                p = NEXTTD(p);
            }
        }
        return found;
    }
    
}

void insertFirstTD(TDList *l, Pesanan val){
    AddressTD p = allocate(val);
    AddressTD loc = FIRSTTD(*l);
    if(p!=NULL){
        NEXTTD(p) = loc;
        if(!isEmptyTD(*l)){
            PREVTD(loc) = p;
        }else{
            LASTTD(*l) = p;
        }

        FIRSTTD(*l) = p;
    }
}
void insertLastTD(TDList *l, Pesanan val){
    AddressTD p = allocate(val);
    AddressTD loc = LASTTD(*l);
    if(p!=NULL){
        PREVTD(p) = loc;
        if(!isEmptyTD(*l)){
            NEXTTD(loc) = p;
        }else{
            FIRSTTD(*l) = p;
        }

        LASTTD(*l) = p;
    }
}


void deleteFirstTD(TDList *l, Pesanan *val){
    AddressTD p = FIRSTTD(*l);
    *val = INFOTD(p);
    if(FIRSTTD(*l)==LASTTD(*l)){
        LASTTD(*l) = NULL;
    }else{
        PREVTD(NEXTTD(FIRSTTD(*l))) = NULL;
    }
    FIRSTTD(*l) = NEXTTD(p);
    free(p);

}
void deleteLastTD(TDList *l, Pesanan *val){
    AddressTD p = LASTTD(*l);
    *val = INFOTD(p);
    if(FIRSTTD(*l)==LASTTD(*l)){
        FIRSTTD(*l) = NULL;
    }else{
        NEXTTD(PREVTD(p)) = NULL;
    }
    LASTTD(*l) = PREVTD(p);
}
void deleteAtTD(TDList *l, AddressTD Tp){
    AddressTD loc = FIRSTTD(*l);
    boolean flag = false;
    while(loc!=NULL && !flag){
        if(loc==Tp){
            if (PREVTD(loc)==NULL) { // delete elemen pertama
                if(FIRSTTD(*l)==LASTTD(*l)){
                    LASTTD(*l) = NULL;
                }else{
                    PREVTD(NEXTTD(FIRSTTD(*l))) = NULL;
                }
                FIRSTTD(*l) = NEXTTD(loc); 
            } else {
                if(NEXTTD(loc)!=NULL){
                    NEXTTD(PREVTD(loc)) = NEXTTD(loc);
                    PREVTD(NEXTTD(loc)) = PREVTD(loc);
                }
            }

            flag = true;
        }else{
            loc = NEXTTD(loc);
        }
    }
    free(loc);

}

void CreateTDfromPSN(TDList *l,DaftarPesanan *psn,int waktu){
    boolean flag = false;
    while(!isEmptyDftr(*psn) && !flag){
        Pesanan pt1 = HEADPSN(*psn);
        if(pt1.TimeIn<=waktu){
            Pesanan pt2;
            dequeuePsntoVal(psn,&pt2);
            insertLastTD(l,pt2);
        }else{
            flag = true;
        }
    }
}

void DisplayListToDo(TDList l,int waktu){
    /*
    TDList l;
    CreateListTD(&l);
    CreateTDfromPSN(&l,psn,waktu);
    */
    
    int a = 1;
    printf("Pesanan pada To Do List:\n");
    if(isEmptyTD(l)){
        printf("Tidak ada pesanan yang akan dikerjakan.\n");
    }else{
        AddressTD pt = FIRSTTD(l);
        while(pt!=NULL){
            
            printf("%d. ",a);
            printf("%c -> %c",INFOTD(pt).PickUp,INFOTD(pt).DropOff);
            if(INFOTD(pt).ItemType=='N'){
                printf(" (Normal Item)");
            }else if(INFOTD(pt).ItemType=='H'){
                printf(" (Heavy Item)");
            }else if(INFOTD(pt).ItemType=='P'){
                printf(" (Perishable Item)");
            }else{
                printf(" (VIP Item)");
            }
            if(INFOTD(pt).ItemType!='P'){
                printf("\n");
            }else{
                printf(" %d\n",INFOTD(pt).TimePerish);
            }
            a++;
            pt = NEXTTD(pt);
        }
    }
    
}
/*
void DisplayListToDoOnly(DaftarPesanan psn, TDList l,int waktu) {
//ini sebenernya udh gue buat display yg dari to do, tapi kayak yg gue kirim ss di line, pesanan yg udh muncul, kalo command to do lagi bakal muncul lagi dia (jadi double)
    CreateTDfromPSN(&l,psn,waktu); // karena ini mungkin diakalin biar bikin to do nya engga double
    AddressTD pt = FIRSTTD(l);
    int a = 1;
    printf("Pesanan pada To Do List:\n");
    while(pt!=NULL){
        if(INFOTD(pt).done==false && a<10){
            printf("%d. ",a);
            printf("%c -> %c",INFOTD(pt).PickUp,INFOTD(pt).DropOff,INFOTD(pt).ItemType);
            if(INFOTD(pt).ItemType=='N'){
                printf(" (Normal Item)");
            }else if(INFOTD(pt).ItemType=='H'){
                printf(" (Heavy Item)");
            }else if(INFOTD(pt).ItemType=='P'){
                printf(" (Perishable Item)");
            }else{
                printf("VIP Item");
            }
            if(INFOTD(pt).ItemType!='P'){
                printf("\n");
            }else{
                printf(" %d\n",INFOTD(pt).TimePerish);
            }
            a++;
        }
        pt = NEXTTD(pt);
    }  
}
*/

