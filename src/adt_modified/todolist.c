#include <stdio.h>
#include <stdlib.h>
#include "todolist.h"



void CreateListTD(TDList *l){
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}

boolean isEmptyTD(TDList l){
    return FIRST(l)==NULL && LAST(l)==NULL;
}

Address allocate(Pesanan val){
    Address p = (Address) malloc(sizeof(Node));
    if(p!=NULL){
        INFO(p)=val;
        NEXT(p)=NULL;
        PREV(p)=NULL;
        return p;
    }else{
        return NULL;
    }
}



Address search(TDList l, Pesanan val){
    Address p = FIRST(l);
    boolean flag = false;
    while(!flag && p!=NULL){
            if(CmpPesanan(INFO(p),val)){
                flag = true;
            }else{
                p = NEXT(p);
            }
    }
    if(flag){
        return p;
    }else{
        return NULL;
    }
}
void insertFirstTD(TDList *l, Pesanan val){
    Address p = allocate(val);
    Address loc = FIRST(*l);
    if(p!=NULL){
        NEXT(p) = loc;
        if(!isEmptyTD(*l)){
            PREV(loc) = p;
        }else{
            LAST(*l) = p;
        }

        FIRST(*l) = p;
    }
}
void insertLastTD(TDList *l, Pesanan val){
    Address p = allocate(val);
    Address loc = LAST(*l);
    if(p!=NULL){
        PREV(p) = loc;
        if(!isEmptyTD(*l)){
            NEXT(loc) = p;
        }else{
            FIRST(*l) = p;
        }

        LAST(*l) = p;
    }
}


void deleteFirstTD(TDList *l, Pesanan *val){
    Address p = FIRST(*l);
    *val = INFO(p);
    if(FIRST(*l)==LAST(*l)){
        LAST(*l) = NULL;
    }else{
        PREV(NEXT(FIRST(*l))) = NULL;
    }
    FIRST(*l) = NEXT(p);
    free(p);

}
void deleteLastTD(TDList *l, Pesanan *val){
    Address p = LAST(*l);
    *val = INFO(p);
    if(FIRST(*l)==LAST(*l)){
        FIRST(*l) = NULL;
    }else{
        NEXT(PREV(p)) = NULL;
    }
    LAST(*l) = PREV(p);
}
void deleteAtTD(TDList *l, Address Tp){
    Address loc = FIRST(*l);
    boolean flag = false;
    while(loc!=NULL && !flag){
        if(loc==Tp){
            if(NEXT(loc)==NULL){
            }else{
                NEXT(PREV(loc)) = NEXT(loc);
                PREV(NEXT(loc)) = PREV(loc);
            }
            flag = true;
        }else{
            loc = NEXT(loc);
        }
    }
    free(loc);

}

void CreateTDfromPSN(TDList *l,DaftarPesanan psn){
    DaftarPesanan pt = psn;
    while(!isEmptyDftr(pt)){
        Pesanan pt1;
        dequeuePsntoVal(&pt,&pt1);
        insertLastTD(l,pt1);
    }
}

void DisplayListToDo(DaftarPesanan psn){
    TDList l;
    CreateListTD(&l);
    CreateTDfromPSN(&l,psn);
    Address pt = FIRST(l);
    int a = 1;
    printf("Pesanan pada To Do List:\n");
    while(pt!=NULL){
        if(INFO(pt).done==false && a<10){
            printf("%d. ",a);
            printf("%c -> %c",INFO(pt).PickUp,INFO(pt).DropOff,INFO(pt).ItemType);
            if(INFO(pt).ItemType=='N'){
                printf(" (Normal Item)");
            }else if(INFO(pt).ItemType=='H'){
                printf(" (Heavy Item)");
            }else if(INFO(pt).ItemType=='P'){
                printf(" (Perishable Item)");
            }else{
                printf("VIP Item");
            }
            if(INFO(pt).ItemType!='P'){
                printf("\n");
            }else{
                printf(" %d\n",INFO(pt).TimePerish);
            }
            a++;
        }
        pt = NEXT(pt);
    }
}


