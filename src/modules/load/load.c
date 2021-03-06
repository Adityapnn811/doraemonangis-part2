#include "../../game_header.h"

/**
 * HELPER FUNCTIONS
 */

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

static boolean readFirstWord(FILE *tape)
{
  startWord(tape);

  if (endWord)
  {
    return false;
  }

  return true;
}

static boolean readOneWord(FILE *tape)
{
  startWord(tape);

  if (!endWord)
  {
    ignoreWords();
    return false;
  }

  return true;
}

static boolean readPoint(POINT *point)
{
  int x, y;

  if (!wordToInt(currentWord, &x) || endWord)
  {
    return false;
  }

  advWord();
  if (!wordToInt(currentWord, &y))
  {
    return false;
  }

  *point = MakePOINT(x, y);
  return true;
}

static boolean readPesanan(int *timeIn, char *pickUp, char *dropOff, char *type, int *timePerish)
{
  if (!wordToInt(currentWord, timeIn) || endWord)
  {
    return false;
  }

  advWord();
  if (currentWord.length != 1 || endWord)
  {
    return false;
  }
  *pickUp = currentWord.contents[0];

  advWord();
  if (currentWord.length != 1 || endWord)
  {
    return false;
  }
  *dropOff = currentWord.contents[0];

  advWord();
  if (currentWord.length != 1)
  {
    return false;
  }
  *type = currentWord.contents[0];

  if (*type == 'P')
  {
    if (endWord)
    {
      return false;
    }

    advWord();
    if (!wordToInt(currentWord, timePerish))
    {
      return false;
    }
  }

  return true;
}

/**
 * EXTERNAL HELPER FUNCTION
 */
void inputFilename(char *filename)
{
  printf("Input path file: ");
  readOneWord(stdin);
  wordToStr(currentWord, filename);
}

/**
 * MAIN FUNCTION
 */

void saveGame(Player player, Inventory inv, Tas bag, TDList todo, Speedboost boost)
{
  char fname[WORD_CAPACITY + 1];
  inputFilename(fname);

  FILE *fp;
  fp = fopen(fname, "w");
  if (fp == NULL)
  {
    printf("Error dalam membuka file.\n");
    return;
  }

  fprintf(fp, "[PLAYER]\n");
  fprintf(fp, "Time %d\n", WAKTU(player));
  fprintf(fp, "Money %d\n", UANG(player));
  fprintf(fp, "Current_Loc %d %d\n", CUR_LOCX(player), CUR_LOCY(player));
  fprintf(fp, "Prev_Loc %d %d\n", PREV_LOCX(player), PREV_LOCY(player));
  fprintf(fp, "Bag_Max %d\n", bag.maxTas);
  fprintf(fp, "Done_Count %d\n", PESANAN_DONE(player));

  /* Speed boost */
  fprintf(fp, "Speed_Boost ");
  if (SB_ISACTIVE(boost))
  {
    fprintf(fp, "T %d\n", SB_COUNTER(boost));
  }
  else
  {
    fprintf(fp, "F\n");
  }

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

  Item items[CAPACITY_TAS];

  int bagLen = lengthTas(bag);
  i = bagLen - 1;
  while (!isEmptyTas(bag))
  {
    Item item;
    dropItemToVal(&bag, &item);
    items[i] = item;
    i--;
  }

  for (i = 0; i < bagLen; i++)
  {
    Item item = items[i];

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
    printf("Error dalam menyimpan data.\n");
    return;
  }

  printf("Data game berhasil disimpan!\n");
}

boolean loadGame(DaftarPesanan *pesanans, Player *player, Inventory *inv, Tas *bag, TDList *todo, Speedboost *boost)
{
  char str[WORD_CAPACITY + 1];
  inputFilename(str);

  FILE *fp;
  fp = fopen(str, "r");
  if (fp == NULL)
  {
    printf("Error dalam membuka file.\n");
    return false;
  }

  CreatePlayer(player);
  CreateInv(inv);
  CreateTas(bag);
  CreateListTD(todo);

  /* Todo menggunakan queue terlebih dahulu */
  DaftarPesanan todoQueue;
  CreateDaftar(&todoQueue);

  boolean success = true;
  short int loadCounter = 0;
  short int playerCounter = 0;

  enum LoadState
  {
    LoadStart,
    LoadPlayer,
    LoadInventory,
    LoadInProgress,
    LoadTodo
  } state;

  state = LoadStart;
  while (!feof(fp) && success)
  {
    startWord(fp);

    if (endWord && currentWord.length == 0)
    {
      continue;
    }

    if (endWord && currentWord.contents[0] == '[')
    {
      /* Pergantian state */

      /* Pada state player, harus ada ... */
      if (state == LoadPlayer && playerCounter != 7)
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
        if (endWord)
        {
          success = false;
        }
        else
        {
          advWord();

          if (!endWord || !wordToInt(currentWord, &x))
          {
            success = false;
          }
          else
          {
            setWaktu(player, x);
            playerCounter++;
          }
        }
      }
      else if (wordEquals(currentWord, "Money"))
      {
        if (endWord)
        {
          success = false;
        }
        else
        {
          advWord();

          if (!endWord || !wordToInt(currentWord, &x))
          {
            success = false;
          }
          else
          {
            setUang(player, x);
            playerCounter++;
          }
        }
      }
      else if (wordEquals(currentWord, "Current_Loc"))
      {
        if (endWord)
        {
          success = false;
        }
        else
        {
          POINT p;

          advWord();
          if (!readPoint(&p) || !endWord)
          {
            success = false;
          }
          else
          {
            setPlayerLoc(player, Absis(p), Ordinat(p));
            playerCounter++;
          }
        }
      }
      else if (wordEquals(currentWord, "Prev_Loc"))
      {
        if (endWord)
        {
          success = false;
        }
        else
        {
          POINT p;

          advWord();
          if (!readPoint(&p) || !endWord)
          {
            success = false;
          }
          else
          {
            setPlayerPrevLoc(player, Absis(p), Ordinat(p));
            playerCounter++;
          }
        }
      }
      else if (wordEquals(currentWord, "Bag_Max"))
      {
        if (endWord)
        {
          success = false;
        }
        else
        {
          advWord();

          if (!endWord || !wordToInt(currentWord, &x))
          {
            success = false;
          }
          else
          {
            bag->maxTas = x;
            playerCounter++;
          }
        }
      }
      else if (wordEquals(currentWord, "Done_Count"))
      {
        if (endWord)
        {
          success = false;
        }
        else
        {
          advWord();
          if (!endWord || !wordToInt(currentWord, &x))
          {
            success = false;
          }
          else
          {
            PESANAN_DONE(*player) = x;
            playerCounter++;
          }
        }
      }
      else if (wordEquals(currentWord, "Speed_Boost"))
      {
        if (endWord)
        {
          success = false;
        }
        else
        {
          advWord();

          if (wordEquals(currentWord, "F"))
          {
            if (!endWord)
            {
              success = false;
            }
            else
            {
              resetSpeedboost(boost);
              playerCounter++;
            }
          }
          else if (wordEquals(currentWord, "T"))
          {
            if (endWord)
            {
              success = false;
            }
            else
            {
              advWord();

              if (!endWord || !wordToInt(currentWord, &x))
              {
                success = false;
              }
              else
              {
                SB_ISACTIVE(*boost) = true;
                SB_COUNTER(*boost) = x;
                playerCounter++;
              }
            }
          }
          else
          {
            success = false;
          }
        }
      }
    }
    else if (state == LoadInventory)
    {
      if (!endWord || currentWord.length > 1)
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
    else if (state == LoadInProgress)
    {
      int timeIn, timePerish;
      char pickUp, dropOff, itemType;

      if (!readPesanan(&timeIn, &pickUp, &dropOff, &itemType, &timePerish))
      {
        success = false;
      }

      Item item;
      item.TimeIn = timeIn;
      item.PickUp = pickUp;
      item.DropOff = dropOff;
      item.ItemType = itemType;
      item.TimePerish = timePerish;

      addItem(bag, item);
    }
    else if (state == LoadTodo)
    {
      int timeIn, timePerish;
      char pickUp, dropOff, itemType;

      if (!readPesanan(&timeIn, &pickUp, &dropOff, &itemType, &timePerish))
      {
        success = false;
      }

      Pesanan pesanan;
      CreatePesanan(&pesanan, timeIn, pickUp, dropOff, itemType, timePerish);
      enqueuePsn(&todoQueue, pesanan);
    }
  }

  if (success)
  {
    /* Bisa saja ada order fiktif di dalam IN_PROGRESS atau TODO */
    /* Buat referensi berdasarkan konfigurasi */
    TDList allTodo;
    CreateTDfromPSN(&allTodo, pesanans, WAKTU(*player));

    /* Periksa in progress list */
    Tas tmpBag = *bag;
    while (!isEmptyTas(tmpBag))
    {
      Item item;
      dropItemToVal(&tmpBag, &item);

      if (item.TimeIn > WAKTU(*player))
      {
        success = false;
      }
      else
      {
        Pesanan pesanan;
        CreatePesanan(&pesanan, item.TimeIn, item.PickUp, item.DropOff, item.ItemType, item.TimePerish);

        AddressTD found = search(allTodo, pesanan);
        if (found == NULL || (item.ItemType == 'P' && item.TimePerish > INFOTD(found).TimePerish))
        {
          success = false;
        }
      }
    }

    /* Periksa todolist */
    while (!isEmptyDftr(todoQueue) && success)
    {
      Pesanan pesanan = HEADPSN(todoQueue);
      dequeuePsn(&todoQueue);

      if (pesanan.TimeIn > WAKTU(*player))
      {
        success = false;
      }
      else
      {
        AddressTD found = search(allTodo, pesanan);
        if (found == NULL || (pesanan.ItemType == 'P' && pesanan.TimePerish != INFOTD(found).TimePerish))
        {
          success = false;
        }
        else
        {
          insertLastTD(todo, pesanan);
        }
      }
    }
  }

  fclose(fp);

  if (!success)
  {
    printf("Gagal load game. File tidak valid.\n");
    return false;
  }

  printf("Game berhasil di-load.\n");
  return true;
}
