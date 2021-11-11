#include <stdio.h>
#include "../game_header.h"

#include "cmd1.c" // command move, pickup, dropoff

#define enter printf("\n");
#define border printf("----------- END OF INFO CONFIG.TXT------------\n\n");

void newgames(Config newgame, char*filename) {
    // Config newgame;
    // char *filename = "config.txt";

    /* MENAMPILKAN ISI LOAD CONFIG.TXT */
    if (loadGame(filename, &newgame)) {
        printf("success");
    } else {
        printf("fail");
    }

    enter;displayMatrix(newgame.adjMatrix);enter;
    displayListPoint(newgame.bangunans);enter;
    printf("length pesanan %d", lengthDftr(newgame.pesanans));enter;

    Matrix m;
    readCustomMatrix(&m,newgame.mapRows+2,newgame.mapCols+2);
    printf("capcity bangunan %d (blom diassign di load)\n",newgame.bangunans.capacity); // capacity blom diassign di load

    displayMatrix(m);
    /* END OF MENAMPILKAN ISI LOAD CONFIG.TXT */

    /* STATE NEW PLAYER */
    Player p;
    POINT loc;
    CreatePlayer(&p);

    /* STATE ABILITY SPEEDBOOST */
    boolean speedboost = false;
    int counterMove = 0;

    /* START OF TEST */
    /* TEST DRIVER PLAYER */
    printf("Uang player sebesar %d\n", UANG(p));
    printf("Waktu player sebesar %d\n", WAKTU(p));
    printf("Lokasi player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));
    printf("\n");
    setUang(&p, 1000);
    setWaktu(&p, 20);
    setPlayerLoc(&p, newgame.bangunans.buffer[0].position.X, newgame.bangunans.buffer[0].position.Y);
    printf("Uang player sebesar %d\n", UANG(p));
    printf("Waktu player sebesar %d\n", WAKTU(p));
    printf("Lokaso player di (%d, %d)\n", CUR_LOCX(p), CUR_LOCY(p));

    border;

    /* TEST ADD ITEM TO TAS */
    Tas tas;
    Item item;
    // CreateItem(&item, 4, 'N', 'I', 'H', 8);
    CreateTas(&tas);
    // addItem(&tas, item);
    /* END OF TEST */

    /* TEST TO DO LIST DARI PESANAN */
    TDList todo;
    Pesanan p1, p2;
    CreateListTD(&todo);
    CreateTDfromPSN(&todo, newgame.pesanans, WAKTU(p));
    // CreatePesanan(&p1, 10, 'D', 'G', 'h', 10);
    // CreatePesanan(&p2, 10, 'C', 'B', 'n', 10);
    // insertFirstTD(&todo, p1);
    // insertFirstTD(&todo, p2);
    /* END */

    showMap(&m,newgame.bangunans);
    displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter;

    /* COMMAND MOVE, PICK UP */
    printf("Waktu: %d\n", WAKTU(p));
    /* ini nanti dipanggil dari main program di command MOVE */
    while (true) {
        char input[30];
        printf("\nENTER COMMAND di newgame: ");
        fgets(input,30,stdin);
        if (strcmp(input, "MOVE\n") == 0) {
            movecmd(&p, newgame, &todo, &speedboost, &counterMove);
        } else if (strcmp(input, "PICK_UP\n") == 0) {
            pickupcmd(p, &newgame, &tas);
        } else if (strcmp(input, "DROP_OFF\n") == 0) {
            dropoffcmd(p, &newgame, &tas, &speedboost, &counterMove);
        } else if (strcmp(input, "IN_PROGRESS\n") == 0) {
            DisplayInPrgs(tas);
        } else if (strcmp(input, "TO_DO\n") == 0) {
            DisplayListToDo(newgame.pesanans,WAKTU(p));
        } 
        
        else {
            printf("RWONG INPUT\n");
        }
        // pickupcmd(p, newgame, tas);enter;

        printf("Waktu new game: %d", WAKTU(p));
        enter;enter;displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter;   
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



