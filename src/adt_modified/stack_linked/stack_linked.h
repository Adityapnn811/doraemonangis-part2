#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include "../../game_header.h"

/* Element Type */

typedef Item StackLinkedElType;

/* Node */

typedef struct stackNode *StackAddress;
typedef struct stackNode
{
  StackLinkedElType info;
  StackAddress next;
} StackNode;

/* Node accessor */

#define STACKL_INFO(n) (n)->info
#define STACKL_NEXT(n) (n)->next

/* Stack */

typedef struct stackLinked
{
  StackAddress top;
} StackLinked;

/* Stack accessor */
#define STACKL_ADDR(n) (n).top
#define STACKL_TOP(s) (s).top->info

/* Constructor */

void createStackLinked(StackLinked *s);

/* Basic test */

boolean isEmpty(StackLinked s);

/* Basic stack operation */

boolean push(StackLinked *s, StackLinkedElType value);
boolean pop(StackLinked *s, StackLinkedElType *value);
void CreateInPrgsFromTas(StackLinked *inPr, Tas t);
void DisplayInPrgs2(Tas t);

#endif
