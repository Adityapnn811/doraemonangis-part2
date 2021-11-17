#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

int main(){
    Item item1, item2, item3, item4, item5;
    Tas t;
    /* ALGORITMA */
    CreateTas(&t);
    printf("Kapasitas tas saat ini adalah %d\n", t.maxTas);
    t.maxTas += 1;
    printf("Kapasitas tas saat ini adalah %d\n", t.maxTas);
    CreateItem(&item1, 1, 'A', 'B', 'N', 2);
    CreateItem(&item2, 1, 'C', 'D', 'H', 5);
    CreateItem(&item3, 1, 'B', 'G', 'N', 4);
    CreateItem(&item4, 1, 'R', 'Z', 'H', 7);
    addItem(&t, item4);
    addItem(&t, item3);

    StackLinked St;
    createStackLinked(&St);
    print("is empty : %d\n",isEmpty(St));
    push(&St,item1);
    CreateInPrgsFromTas(&St,t);
    print("%d %c %c %c\n",STACKL_TOP(St).TimeIn,STACKL_TOP(St).PickUp,STACKL_TOP(St).DropOff,STACKL_TOP(St).ItemType);
    Item temp;
    pop(&St,&temp);
    print("%d %c %c %c\n",STACKL_TOP(St).TimeIn,STACKL_TOP(St).PickUp,STACKL_TOP(St).DropOff,STACKL_TOP(St).ItemType);
    DisplayInPrgs(t);
    



    return 0;
}