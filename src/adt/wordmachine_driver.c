#include <stdio.h>
#include "wordmachine.h"

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

  return 0;
}