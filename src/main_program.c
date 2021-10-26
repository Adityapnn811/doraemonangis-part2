#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;
/* nanti diinclude semua yang dibutuhin disini */

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
        printf("\n");
        printf("Silahkan input opsi yang di atas: ");
        while(!endWord){
            startWord();
                /* pengaturan kondisi pilihan user */
            if(currentWord.contents[0] == 'i' && endWord == true && currentWord.length == 1){
                    /* konfigurasi new game */
            }else if(currentWord.contents[0] == 'i' && currentWord.contents[1] == 'i' && currentWord.length == 2 && endWord == true){
                    /* fungsi load */
            }else if(currentWord.contents[0] == 'i' && currentWord.contents[1] == 'i' && currentWord.contents[2] == 'i' && endWord == true && currentWord.length == 3){
                valid = !valid;
                printf("Selamat bertemu kembali!\n");
                exit(0);
            }else if(endWord == true){
                /* ini masi infinity loop nanti mau dipikir ulang gimana caranya biar ga infinity loop */
                /* printf("Input salah. Silahkan ulangi input hingga sesuai.\n");
                endWord = !endWord;
                startWord(); */
                
            }
        }
    }
}
