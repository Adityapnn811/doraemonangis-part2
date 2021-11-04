#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include "../models/boolean.h"

/* Element Type */

typedef int StackLinkedElType;

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

#define STACKL_TOP(s) (s).top

/* Constructor */

void createStackLinked(StackLinked *s);

/* Basic test */

boolean isEmpty(StackLinked s);

/* Basic stack operation */

boolean push(StackLinked *s, StackLinkedElType value);
boolean pop(StackLinked *s, StackLinkedElType *value);

#endif
