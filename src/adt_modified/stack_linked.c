#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

/* Constructor */

void createStackLinked(StackLinked *s)
{
  STACKL_TOP(*s) = NULL;
}

/* Basic test */

boolean isEmpty(StackLinked s)
{
  return STACKL_TOP(s) == NULL;
}

/* Basic stack operation */

boolean push(StackLinked *s, StackLinkedElType value)
{
  /* Kamus */
  StackAddress p;

  /* Algoritma */
  p = malloc(sizeof(StackNode));
  if (!p)
  {
    return false;
  }

  STACKL_NEXT(p) = STACKL_TOP(*s);
  STACKL_TOP(*s) = p;

  return true;
}

boolean pop(StackLinked *s, StackLinkedElType *value)
{
  /* Kamus */
  StackAddress top;

  /* Algoritma */
  if (isEmpty(*s))
  {
    return false;
  }

  top = STACKL_TOP(*s);
  *value = STACKL_INFO(top);
  STACKL_TOP(*s) = STACKL_NEXT(top);

  free(top);
  return true;
}
