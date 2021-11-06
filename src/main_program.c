#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "game_header.h"

boolean endWord;
Word currentWord;
/* jangan include header di sini, tapi include di game header */
FILE *tape;

int main(){
    boolean valid = false;
    printf("********* Selamat datang di game Mobilita! *********\n");
    printf("\n");
    /* menampilkan opsi yang mungkin dipilih oleh user */
    while(!valid){
        printf("Opsi yang tersedia: \n");
        printf("i. NEW GAME\n");
        printf("ii. LOAD GAME\n");
        printf("iii. EXIT\n");
        printf("iv. HELP\n");
        printf("\n");
        printf("Silahkan input opsi yang di atas: ");
        while(!endWord){
            startWord(tape);
                /* pengaturan kondisi pilihan user */
            if(endWord){
                if(help(currentWord.contents, currentWord.length)){
                    printf("\n");
                    show_help();
                    /* ini nantinya bakal ngulang inputnya sampe dia milih salah satu di atas. Tapi untuk sementara
                    diberentiin dulu krn ku masih make wordmachine yang lama (infinity loop) */
                    valid = !valid;
                }else if(new_game(currentWord.contents, currentWord.length)){
                   /* new game */
                    newgame();
                   /* isi fungsi buat new game */
                
                }else if(load_game(currentWord.contents, currentWord.length)){
                    /* load game disini */


                    /* isi fungsi buat load game */
                
                }else if(exit_2(currentWord.contents, currentWord.length)){
                    valid = !valid;
                    printf("\nSelamat bertemu kembali!\n");
                    exit(0);
                }else{
                    endWord = !endWord;
                    startWord(tape);
                }
            }
        }
    }
    return 0;
}
