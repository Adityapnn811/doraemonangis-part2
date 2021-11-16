#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "game_header.h"
#include "./modules/newgame.c"

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
            if(help(currentWord.contents, currentWord.length)){
                printf("\n");
                show_help();
            }else if(new_game(currentWord.contents, currentWord.length)){
                /* new game */
                /* isi fungsi buat new game */
                Config newgame;
                char *filename = "config.txt";
                if (loadConfig(filename, &newgame)) {
                    printf("success");
                } else {
                    printf("fail");
                }
                newgames(newgame, filename);
            }else if(load_game(currentWord.contents, currentWord.length)){
                /* load game disini */


                /* isi fungsi buat load game */
            
            }else if(exit_2(currentWord.contents, currentWord.length)){
                printf("\nSelamat bertemu kembali!\n");
                isDone = true;
            }
        } else {
            while (!endWord) {
                advWord();
            }
        }
    }
    return 0;
}
