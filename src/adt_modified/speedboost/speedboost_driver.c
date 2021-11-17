#include <stdio.h>
#include "speedboost.h"

int main(void)
{
  Speedboost sb;
  resetSpeedboost(&sb);

  boolean isDone = false;
  while (!isDone)
  {
    printf("\nSpeedboost ");
    if (SB_ISACTIVE(sb))
    {
      printf(" active, counter: %d\n", SB_COUNTER(sb));
    }
    else
    {
      printf("inactive\n");
    }

    printf("\n");
    printf("1. Use speedboost\n");
    printf("2. Reset speedboost\n");
    printf("3. Exit\n");

    printf("\nInput command: ");

    int x;
    scanf("%d", &x);

    if (x == 1)
    {
      SB_ISACTIVE(sb) = true;
      SB_COUNTER(sb)++;
    }
    else if (x == 2)
    {
      resetSpeedboost(&sb);
    }
    else if (x == 3)
    {
      isDone = true;
    }
  }

  return 0;
}
