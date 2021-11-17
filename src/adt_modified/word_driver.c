#include <stdio.h>
#include "word.h"

int main(void)
{
  printf("Masukkan kata-kata: ");

  startWord(stdin);
  while (!endWord)
  {
    if (wordEquals(currentWord, "MOBITA"))
    {
      printf("Mobita ditemukan!\n");
    }

    char string[WORD_CAPACITY + 1];
    int integer;

    if (wordToInt(currentWord, &integer))
    {
      printf("Ditemukan integer: %d\n", integer);
    }
    else
    {
      wordToStr(currentWord, string);
      printf("Ditemukan non-integer: %s\n", string);
    }

    advWord();
  }

  return 0;
}
