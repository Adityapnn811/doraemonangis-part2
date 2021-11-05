#include <stdio.h>
#include <stdlib.h>
#include "tas.h"

int maxTas=3;
boolean useAbility = false;


void CreateTas(Tas *tas){
     IDX_TOP(*tas) = IDX_UNDEF;
}

int lengthTas(Tas tas){
    return IDX_TOP(tas)+1;
}

void addItem(Tas *tas, Item val){
    int a = lengthTas(*tas);
    if(a<maxTas){
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
