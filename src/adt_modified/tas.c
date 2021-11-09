#include <stdio.h>
#include <stdlib.h>
#include "tas.h"

boolean useAbility = false;


void CreateTas(Tas *tas){
     IDX_TOP(*tas) = IDX_UNDEF;
     (*tas).maxTas = 20;
}

int lengthTas(Tas tas){
    return IDX_TOP(tas)+1;
}

boolean isEmptyTas(Tas s){
    return IDX_TOP(s) == IDX_UNDEF;
}

void addItem(Tas *tas, Item val){
    int a = lengthTas(*tas);
    if(a< tas->maxTas){
        IDX_TOP(*tas)++;
        TOP(*tas) = val;
    }else{
        printf("Tidak bisa mengambil item, tas penuh\n");
    }

}

void dropItem(Tas *tas1){

    if (IDX_TOP(*tas1) == 0)
    {
        IDX_TOP(*tas1) = IDX_UNDEF;
    }else{
        IDX_TOP(*tas1)--;
    }
}

void dropItemToVal(Tas *tas1,Item *val){
    *val = TOP(*tas1);
    if (IDX_TOP(*tas1) == 0)
    {
        IDX_TOP(*tas1) = IDX_UNDEF;
    }else{
        IDX_TOP(*tas1)--;
    }
}

void DisplayInPrgs(Tas t){
    Tas temp=t;
    Item a;
    int i = 1;

    if(isEmptyTas(temp)) {
        printf("Tidak ada pesanan yang sedang diantarkan.\n");
    } else {
        printf("Pesanan yang sedang diantarkan:\n");
        while(!isEmptyTas(temp)){
            printf("%d. ",i);
            dropItemToVal(&temp,&a);
            if(a.ItemType=='N'){
                printf("Normal Item");
            } else if(a.ItemType=='H'){
                printf("Heavy Item");
            } else if(a.ItemType=='P'){
                printf("Perishable Item");
            } else{
                printf("VIP Item");
            }
            printf(" (Tujuan: %c)\n",a.DropOff);
            i++;
        }
    }

}
