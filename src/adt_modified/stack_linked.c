#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

/* Constructor */

void createStackLinked(StackLinked *s)
{
  STACKL_ADDR(*s) = NULL;
}

/* Basic test */

boolean isEmpty(StackLinked s)
{
  return STACKL_ADDR(s) == NULL;
}

/* Basic stack operation */

boolean push(StackLinked *s, StackLinkedElType value)
{
  /* Kamus */
  StackAddress p;

  /* Algoritma */
  p = (StackAddress) malloc(sizeof(StackNode));
  if (p!=NULL)
  {
    STACKL_INFO(p) = value;
    STACKL_NEXT(p) = NULL;

  }

  STACKL_NEXT(p) = STACKL_ADDR(*s);
  STACKL_ADDR(*s) = p;

  return true;
}

boolean pop(StackLinked *s, StackLinkedElType *value)
{
  /* Kamus */
  StackAddress top;

  /* Algoritma */
  *value = STACKL_TOP(*s);
  top = STACKL_ADDR(*s);
  STACKL_ADDR(*s) = STACKL_NEXT(STACKL_ADDR(*s));
  STACKL_NEXT(top) = NULL;

  free(top);
  return true;
}

void CreateInPrgsFromTas(StackLinked *inPr, Tas t){
    Item b;
    Tas temp = t;
    Tas temp2;
    CreateTas(&temp2);
    temp2.maxTas = temp.maxTas;
    while(!isEmptyTas(temp)){
        dropItemToVal(&temp,&b);
        addItem(&temp2,b);
    }
    while(!isEmptyTas(temp2)){
        dropItemToVal(&temp2,&b);
        push(inPr,b);
    }

}

void DisplayInPrgs2(Tas t){
    StackLinked temp;
    createStackLinked(&temp);
    Item a;
    Tas tas2 = t;
    CreateInPrgsFromTas(&temp,tas2);
    int i = 1;
    if (isEmptyTas(tas2))
    {
      printf("Tidak ada pesanan yang sedang diantarkan.\n");
    }else{
      printf("Pesanan yang sedang diantarkan:\n");
      while(!isEmpty(temp)){
        pop(&temp,&a);
        printf("%d. ",i);
        if(a.ItemType=='N'){
            printf("Normal Item");
        } else if(a.ItemType=='H' || a.ItemType=='I'){
            printf("Heavy Item");
        } else if(a.ItemType=='P'){
            printf("Perishable Item %d",a.TimePerish);
        } else {
            printf("VIP Item");
        }
        printf(" (Tujuan: %c)\n",a.DropOff);
        
        i++;
      }
    }
    
    
} 