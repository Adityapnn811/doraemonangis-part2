#include <stdio.h>
#include "../game_header.h"

#include "cmd1.c" // command move, pickup, dropoff

#define enter printf("\n");
#define border printf("----------- END OF INFO CONFIG.TXT------------\n\n");

void startGame(Config newgame, boolean isNewGame) {

    // /* debug test load */
    // if (loadGame(filename, &newgame)) {
    //     printf("success");
    // } else {
    //     printf("fail");
    // }

    // enter;displayMatrix(newgame.adjMatrix);enter;
    // displayListPoint(newgame.bangunans);enter;
    // printf("length pesanan %d", lengthDftr(newgame.pesanans));enter;


    // printf("capcity bangunan %d (blom diassign di load)\n",newgame.bangunans.capacity);
    // displayMatrix(m);
    // /* end */

    /* INISIALISASI MAP */
    Matrix m;
    readCustomMatrix(&m,newgame.mapRows+2,newgame.mapCols+2);
    showMap(&m,newgame.bangunans);

    /* STATE NEW PLAYER */
    Player p;
    POINT loc;
    CreatePlayer(&p);    UANG(p) = 100000000;
    setPlayerLoc(&p, newgame.bangunans.buffer[0].position.X, newgame.bangunans.buffer[0].position.Y);

    /* Daftar pesanan temp untuk rujukan waktu time perish*/
    DaftarPesanan tempPsn = newgame.pesanans;

    /* STATE ABILITY SPEEDBOOST */
    boolean speedboost = false;
    int counterMove = 0;

    /* STATUS COUNTER HEAVY ITEM */
    int countHeavy = 0; // counter nya udah di move sekalian -fajar
    // ntar tinggal setWaktu(p, (WAKTU(*p)+1+countHeavy));

    /* START OF TEST */

    // /* DEBUG TEST DRIVER PLAYER */
    // printf("Uang player sebesar %d\n", UANG(p));
    // printf("Waktu player sebesar %d\n", WAKTU(p));
    // printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
    // printf("\n");

    // printf("Uang player sebesar %d\n", UANG(p));
    // printf("Waktu player sebesar %d\n", WAKTU(p));
    // printf("Lokaso player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));

    // border;

    /* TEST ADD ITEM TO TAS */
    Tas tas;
    CreateTas(&tas);
    Item item;
    // CreateItem(&item, 4, 'N', 'I', 'H', 8);
    // CreateTas(&tas);
    // addItem(&tas, item);
    /* END OF TEST */

    // Create Inventory
    Inventory invPlayer;
    CreateInv(&invPlayer);

    /* TEST TO DO LIST DARI PESANAN */
    TDList todo;
    Pesanan p1, p2;
    CreateListTD(&todo);
    //CreateTDfromPSN(&todo, &newgame.pesanans, WAKTU(p));
    // CreatePesanan(&p1, 10, 'D', 'G', 'h', 10);
    // CreatePesanan(&p2, 10, 'C', 'B', 'n', 10);
    // insertFirstTD(&todo, p1);
    // insertFirstTD(&todo, p2);
    /* END */

    // Test UANG
    //UANG(p) = 2000;

    /* Jika load game */
    if (!isNewGame) {
        loadGame(newgame, &p, &invPlayer, &tas, &todo);
    }

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
                
            }else if(inventory(currentWord.contents, currentWord.length)){
                DisplayGadget(&invPlayer,&UANG(p),&tas,todo,tempPsn,&p, newgame.bangunans);
            }else if (wordEquals(currentWord, "SAVE_GAME")) {
                saveGame(p, invPlayer, tas, todo);
            }
            else {
                printf("WRONG INPUT\n");
            }
            enter;displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter; // AUTO PRINT MAP BUAT DEBUG
        } else {
            ignoreWords();
        }
    }

    enter;
    printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
}

// int main(){
//     newgames();
// //     // char *filename = "config.txt";
// //     // FILE *fp = fopen(filename, "r");

// //     // if (fp == NULL)
// //     // {
// //     //     printf("Error: could not open file %s", filename);
// //     //     return 1;
// //     // }

// //     // // read one character at a time and
// //     // // display it to the output
// //     // char ch;
// //     // while ((ch = fgetc(fp)) != EOF)
// //     //     putchar(ch);

// //     // // close the file
// //     // fclose(fp);
// }



