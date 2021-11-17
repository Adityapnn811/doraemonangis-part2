#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "game_header.h"

boolean endWord;
Word currentWord;
/* jangan include header di sini, tapi include di game header */

int main(){
    boolean isDone = false;
    printf("********* Selamat datang di game Mobilita! *********\n");
    /* menampilkan opsi yang mungkin dipilih oleh user */
    while (!isDone){
        printf("\n");
        printf("Opsi yang tersedia: \n");
        printf("i. NEW GAME\n");
        printf("ii. LOAD GAME\n");
        printf("iii. EXIT\n");
        printf("iv. HELP\n");
        printf("\n");
        printf("Silahkan input opsi yang di atas: ");
        startWord(stdin);
        /* pengaturan kondisi pilihan user */
        if(endWord) {
            if(wordEquals(currentWord, "iv")){
                printf("\n");
                show_help();
            }else if(wordEquals(currentWord, "i") || wordEquals(currentWord, "ii")){
                /* new game */
                boolean isNewGame = wordEquals(currentWord, "i");
                Config newgame;

                printf("\n--- LOAD CONFIG FILE ---\n");
                char filename[WORD_CAPACITY + 1] = "config.txt"; // !!INI NANTI APUS
                inputFilename(filename);

                if (loadConfig(filename, &newgame)) {
                    startGame(newgame, isNewGame);
                } else {
                    printf("Gagal me-load file config.\n");
                }
            }else if(wordEquals(currentWord, "iii")){
                printf("\nSelamat bertemu kembali!\n");
                isDone = true;
            }
        } else {
            ignoreWords();
        }
    }
    return 0;
}
