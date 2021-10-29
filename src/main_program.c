#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "game_header.h"

boolean endWord;
Word currentWord;
/* jangan include header di sini, tapi include di game_header.h */

int main(){
    boolean start = true;
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
            startWord();
                /* pengaturan kondisi pilihan user */
            if(currentWord.contents[0] == 'i' && endWord == true && currentWord.length == 1){
                    /* konfigurasi new game */


                    /* fungsi */
            }else if(currentWord.contents[0] == 'i' && currentWord.contents[1] == 'i' && currentWord.length == 2 && endWord == true){
                    /* fungsi load */


                    /* fungsi */
            }else if(currentWord.contents[0] == 'i' && currentWord.contents[1] == 'i' && currentWord.contents[2] == 'i' && endWord == true && currentWord.length == 3){
                /* keluar */
                
                valid = !valid;
                printf("Selamat bertemu kembali!\n");
                exit(0);
            }else if(endWord){
                /* ini masi infinity loop nanti mau dipikir ulang gimana caranya biar ga infinity loop */
                /* printf("Input salah. Silahkan ulangi input hingga sesuai.\n");
                endWord = !endWord;
                startWord(); */
                if(currentWord.contents[0] == 'i' && currentWord.contents[1] == 'v' && currentWord.length == 2){
                    printf("\n");
                    show_help();
                    /* ini nantinya bakal ngulang inputnya sampe dia milih salah satu di atas. Tapi untuk sementara
                    diberentiin dulu krn ku masih make wordmachine yang lama (infinity loop) */
                    valid = !valid;
                }else{
                    endWord = !endWord;
                    startWord();
                }
            }
        }
    }

    return 0;
}