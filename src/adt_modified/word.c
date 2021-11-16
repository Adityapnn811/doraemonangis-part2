#include "../game_header.h"

boolean wordEquals(Word word, char *str)
{
  int i = 0;
  while (i < word.length && str[i] != '\0')
  {
    if (word.contents[i] != str[i])
    {
      return false;
    }

    i++;
  }

  return (i == (word.length - 1)) && (str[i] == '\0');
}

void wordToStr(Word word, char *value)
{
  int i;
  for (i = 0; i < word.length; i++)
  {
    value[i] = word.contents[i];
  }
  value[i] = '\0';
}

boolean wordToInt(Word word, int *value)
{
  boolean status = false;

  if (word.length > 0)
  {
    *value = 0;
    status = true;

    int i = 0;
    if (word.contents[0] == '-')
    {
      ++i;
    }

    if (word.contents[i] == '0' && (i + 1) < word.length)
    {
      status = false;
    }
    else
    {
      while (i < word.length && status)
      {
        if (word.contents[i] >= '0' && word.contents[i] <= '9')
        {
          *value *= 10;
          *value += (int)(word.contents[i] - '0');
          ++i;
        }
        else
        {
          status = false;
        }
      }

      if (word.contents[0] == '-')
      {
        *value *= -1;
      }
    }
  }

  return status;
}
