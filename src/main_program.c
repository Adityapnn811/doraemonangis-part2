#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "wordmachine.c"

int main(){
    char opsi[1];
    printf("********* Selamat datang di game Mobilita! *********\n");
    printf("\n");
    /* menampilkan opsi yang mungkin dipilih oleh user */
    printf("Opsi yang tersedia: \n");
    printf("i. NEW GAME\n");
    printf("ii. LOAD GAME\n");
    printf("iii. EXIT\n");
    /* pengaturan kondisi pilihan user */
    scanf("Silahkan memilih Opsi yang tersedia: %s", &opsi[0]);
    printf("\n");
}