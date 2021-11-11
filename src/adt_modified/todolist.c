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
            if(NEXTTD(loc)==NULL){
            }else{
                NEXTTD(PREVTD(loc)) = NEXTTD(loc);
                PREVTD(NEXTTD(loc)) = PREVTD(loc);
            }
            flag = true;
        }else{
            loc = NEXTTD(loc);
        }
    }
    free(loc);

}

void CreateTDfromPSN(TDList *l,DaftarPesanan psn,int waktu){
    DaftarPesanan pt = psn;
    boolean flag = false;
    while(!isEmptyDftr(pt) && !flag){
        Pesanan pt1;
        dequeuePsntoVal(&pt,&pt1);
        if(pt1.TimeIn<=waktu){
            insertLastTD(l,pt1);
        }else{
            flag = true;
        }
        
    }
}

void DisplayListToDo(DaftarPesanan psn,int waktu){
    TDList l;
    CreateListTD(&l);
    CreateTDfromPSN(&l,psn,waktu);
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


