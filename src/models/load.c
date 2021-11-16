#include "../game_header.h"

static boolean findGadget(char key, NamaGadget *g)
{
  int i;
  for (i = 0; i < 5; i++)
  {
    if (key == DaftarGadget[i].key)
    {
      *g = DaftarGadget[i];
      return true;
    }
  }

  return false;
}

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

boolean readFirstWord(FILE *tape)
{
  startWord(tape);

  if (endWord)
  {
    return false;
  }

  return true;
}

boolean readOneWord(FILE *tape)
{
  startWord(tape);

  if (!endWord)
  {
    while (!endWord)
    {
      advWord();
    }

    return false;
  }

  return true;
}

void saveGame(Player player, Inventory inv, Tas bag, TDList todo)
{
  char fname[WORD_CAPACITY + 1];

  printf("Nama file: ");
  readOneWord(stdin);
  wordToStr(currentWord, fname);

  FILE *fp;
  fp = fopen(fname, "w");
  if (fp == NULL)
  {
    printf("Error dalam membuka file.");
    return;
  }

  fprintf(fp, "[PLAYER]\n");
  fprintf(fp, "Time %d\n", WAKTU(player));
  fprintf(fp, "Money %d\n", UANG(player));
  fprintf(fp, "Current_Loc %d %d\n", CUR_LOCX(player), CUR_LOCY(player));
  fprintf(fp, "Prev_Loc %d %d\n", PREV_LOCX(player), PREV_LOCY(player));

  fprintf(fp, "\n[INVENTORY]\n");

  int i;
  for (i = 0; i < CAPACITY_INV; i++)
  {
    if (KEY(inv, i) != 'z')
    {
      fprintf(fp, "%c\n", KEY(inv, i));
    }
  }

  fprintf(fp, "\n[IN_PROGRESS]\n");

  Item item;
  while (!isEmptyTas(bag))
  {
    dropItemToVal(&bag, &item);
    fprintf(fp, "%d %c %c %c", item.TimeIn, item.PickUp, item.DropOff, item.ItemType);
    if (item.ItemType == 'P')
    {
      fprintf(fp, " %d", item.TimePerish);
    }
    fprintf(fp, "\n");
  }

  fprintf(fp, "\n[TODO]\n");

  AddressTD td = FIRSTTD(todo);
  while (td != NULL)
  {
    Pesanan pesanan = INFOTD(td);

    fprintf(fp, "%d %c %c %c", pesanan.TimeIn, pesanan.PickUp, pesanan.DropOff, pesanan.ItemType);
    if (pesanan.ItemType == 'P')
    {
      fprintf(fp, " %d", pesanan.TimePerish);
    }
    fprintf(fp, "\n");

    td = NEXTTD(td);
  }

  fclose(fp);

  if (ferror(fp))
  {
    printf("Error dalam menyimpan data.");
    return;
  }

  printf("Data game berhasil disimpan!");
}

enum LoadState
{
  LoadStart,
  LoadPlayer,
  LoadInventory,
  LoadInProgress,
  LoadTodo
};

#if 0
void load(Player *player, Inventory *inv, Tas *bag, TDList *todo)
{
  char str[WORD_CAPACITY + 1];

  printf("Nama file: ");
  readOneWord(stdin);
  wordToStr(currentWord, &str);

  FILE *fp;
  fp = fopen(str, "w");
  if (fp == NULL)
  {
    printf("Error dalam membuka file.");
    return;
  }

  CreatePlayer(player);
  CreateInv(inv);
  CreateTas(bag);
  CreateListTD(todo);

  boolean success = true;
  short int loadCounter = 0;
  short int playerCounter = 0;

  enum LoadState state = LoadStart;

  while (!feof(fp) && success)
  {
    startWord(fp);

    if (endWord && currentWord.contents[0] == '[')
    {
      /* Pergantian state */

      /* Pada state player, harus ada 4 item */
      if (state == LoadPlayer && playerCounter != 4)
      {
        success = false;
      }

      /* Ganti state */

      if (wordEquals(currentWord, "[PLAYER]"))
      {
        state = LoadPlayer;
        loadCounter++;
      }
      else if (wordEquals(currentWord, "[INVENTORY]"))
      {
        state = LoadInventory;
        loadCounter++;
      }
      else if (wordEquals(currentWord, "[IN_PROGRESS]"))
      {
        state = LoadInProgress;
        loadCounter++;
      }
      else if (wordEquals(currentWord, "[TODO]"))
      {
        state = LoadTodo;
        loadCounter++;
      }
      else
      {
        success = false;
      }
    }
    else if (state == LoadPlayer)
    {
      int x, y;

      if (wordEquals(currentWord, "Time"))
      {
        advWord();

        if (endWord || !wordToInt(currentWord, &x))
        {
          success = false;
        }
        else
        {
          setWaktu(player, x);
          playerCounter++;
        }
      }
      else if (wordEquals(currentWord, "Money"))
      {
        advWord();

        if (endWord || !wordToInt(currentWord, &x))
        {
          success = false;
        }
        else
        {
          setUang(player, x);
          playerCounter++;
        }
      }
      else if (wordEquals(currentWord, "Current_Loc"))
      {
        advWord();
        if (endWord || !wordToInt(currentWord, &x))
        {
          success = false;
        }

        advWord();
        if (endWord || !wordToInt(currentWord, &y))
        {
          return false;
        }

        setPlayerLoc(player, x, y);
        playerCounter++;
      }
      else if (wordEquals(currentWord, "Prev_Loc"))
      {
        advWord();
        if (endWord || !wordToInt(currentWord, &x))
        {
          return false;
        }

        advWord();
        if (endWord || !wordToInt(currentWord, &y))
        {
          return false;
        }

        setPlayerPrevLoc(player, x, y);
        playerCounter++;
      }
    }
    else if (state == LoadInventory)
    {
      if (!endWord || currentWord.length != 1)
      {
        success = false;
      }
      else
      {
        char key = currentWord.contents[0];
        NamaGadget gadget;
        if (!findGadget(key, &gadget))
        {
          success = false;
        }
        else
        {
          AddGadget(inv, gadget);
        }
      }
    }
  }
}
#endif
