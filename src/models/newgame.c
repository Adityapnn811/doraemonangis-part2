#include <stdio.h>
#include "../game_header.h"

#include "cmd1.c" // command move, pickup, dropoff

#define enter printf("\n");
#define border printf("----------- END OF INFO CONFIG.TXT------------\n\n");

void newgames(Config newgame, char*filename) {

    /* INISIALISASI MAP, TAS, INVENTORY, DAN PLAYER */
    Matrix m;
    Player p;
    POINT loc;
    DaftarPesanan tempPsn = newgame.pesanans; // Daftar pesanan temp untuk rujukan waktu time perish
    Tas tas;
    Item item;
    Inventory invPlayer;
    TDList todo;

    readCustomMatrix(&m,newgame.mapRows+2,newgame.mapCols+2);
    showMap(&m,newgame.bangunans);
    CreatePlayer(&p);    UANG(p) = 100000000;
    setPlayerLoc(&p, newgame.bangunans.buffer[0].position.X, newgame.bangunans.buffer[0].position.Y);
    CreateTas(&tas);
    CreateInv(&invPlayer);
    CreateListTD(&todo);

    /* STATE ABILITY SPEEDBOOST */
    boolean speedboost = false;
    int counterMove = 0;

    /* STATUS COUNTER HEAVY ITEM */
    int countHeavy = 0; // counter nya udah di move sekalian -fajar
    // ntar tinggal setWaktu(p, (WAKTU(*p)+1+countHeavy));

    /* COMMAND */
    printf("Waktu: %d\n", WAKTU(p));
    boolean isDone = false;
    while (!isDone) {
        printf("\nENTER COMMAND: ");
        startWord(stdin);
        if (endWord) {
            if (move(currentWord.contents, currentWord.length)) {
                movecmd(&p, &newgame, &todo, &tas, &speedboost, &counterMove);
                printf("Waktu: %d", WAKTU(p));
            } else if (map(currentWord.contents, currentWord.length)) {
                displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter;
            } else if (pick_up(currentWord.contents, currentWord.length)) {
                pickupcmd(p, &newgame, &tas, &todo, &speedboost, &counterMove);
            } else if (drop_off(currentWord.contents, currentWord.length)) {
                dropoffcmd(&p, &newgame, &tas, &speedboost, &counterMove, &todo);
            } else if (in_progress(currentWord.contents, currentWord.length)) {
                DisplayInPrgs(tas);
            } else if (to_do(currentWord.contents, currentWord.length)) {
                DisplayListToDo(todo,WAKTU(p));
            } else if(buy(currentWord.contents, currentWord.length)){
                if(CUR_LOCX(p)==newgame.bangunans.buffer[0].position.X && CUR_LOCY(p)==newgame.bangunans.buffer[0].position.Y){
                    BuyGadget(&invPlayer,&UANG(p));
                }else{
                    printf("Kamu tidak berada di HQ\n");	
                }
                
            } else if(inventory(currentWord.contents, currentWord.length)) {
                DisplayGadget(&invPlayer,&WAKTU(p),&tas,todo,tempPsn,&p, newgame.bangunans);
            } else if (help_in(currentWord.contents, currentWord.length)) {
                printf("\n");
                show_help();
            }
            else {
                printf("WRONG INPUT\n");
            }
            // enter;displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter; // AUTO PRINT MAP BUAT DEBUG       } else {
            while (!endWord) {
                advWord();
            }
        }
  
    }

    enter;
    printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
}