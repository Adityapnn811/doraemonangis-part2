#include <stdio.h>
#include <stdlib.h>
#include "tas.h"

boolean useAbility = false;


void CreateTas(Tas *tas){
     IDX_TOP(*tas) = IDX_UNDEF;
     (*tas).maxTas = 3;
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

void reduceAllPerishTime(Tas *t) {
    /* KAMUS LOKAL */
    Tas temp;
    Item val;
    /* ALGORITMA */
    CreateTas(&temp);
    temp.maxTas = t->maxTas + 1;
    while (!isEmptyTas(*t)) {
        if (TYPE(TOP(*t)) == 'P') {
            setTimePerish(&TOP(*t), (TIMEPERISH(TOP(*t)) - 1));
            if (TIMEPERISH(TOP(*t)) == 0) {
                //delete item
                printf("Yah, perishable item dengan tujuan %c sudah hilang :(\n", DROPOFF(TOP(*t)));
                dropItem(t);
            } else {
                // pindah top of stack ke temp
                dropItemToVal(t, &val);
                addItem(&temp, val);
            }
        } else {
            // pindah top of stack ke temp
            dropItemToVal(t, &val);
            addItem(&temp, val);
        }
    }
    
    // masukin semua stack dari item ke tas awal
    while (!isEmptyTas(temp)) {
        dropItemToVal(&temp, &val);
        addItem(t, val);
    }
}
