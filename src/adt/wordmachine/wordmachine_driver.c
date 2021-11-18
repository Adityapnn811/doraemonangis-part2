#include <stdio.h>
#include "../../game_header.h"

int main(void)
{
  printf("PENGHITUNG KATA\n");
  printf("Masukkan kata-kata: ");

  int i = 1;

  startWord(stdin);
  while (!endWord) {
    printf("%d) ", i);

    int j;
    for (j = 0; j < currentWord.length; j++)
    {
      printf("%c", currentWord.contents[j]);
    }
    printf("\n");

    i++;
    advWord();
  }
  printf("%d) ", i);

  int j;
  for (j = 0; j < currentWord.length; j++)
  {
    printf("%c", currentWord.contents[j]);
  }
  printf("\n");
  printf("Jumlah kata: %d\n", i);

  return 0;
}