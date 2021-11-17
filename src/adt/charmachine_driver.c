#include <stdio.h>
#include "charmachine.h"

int main(void)
{
  printf("TAPE COPIER\n");
  printf("Masukkan tape: ");

  start(stdin);
  while (!eot)
  {
    printf("%c", currentChar);
    adv();
  }

  return 0;
}
