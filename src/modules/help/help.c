#include "help.h"
#include <stdio.h>
#include <stdlib.h>

void show_help(){
    printf("****** PETUNJUK GAME MOBILITA ****** \n\n");
    printf("Daftar Command: \n");
    printf("1. MOVE: menunjukkan lokasi yang bisa disinggahi oleh mobilita, ketik 'MOVE' kapital\n");
    printf("2. PICK UP: mengambil pesanan pada lokasi yang dituju, ketik 'PICK_UP' kapital\n");
    printf("3. DROP OFF: mengantarkan pesanan ke lokasi Mobilita saat ini, ketik 'DROP_OFF' kapital\n");
    printf("4. MAP: menampilkan peta, ketik 'MAP' kapital\n");
    printf("5. TO DO: menampilkan pesanan yang harus dikerjakan Mobilita, ketik 'TO_DO' kapital\n");
    printf("6. IN PROGRESS: menampilkan pesanan yang sedang dikerjakan Mobilita , ketik 'IN_PROGRESS' kapital\n");
    printf("7. BUY: Hanya dapat digunakan di HQ, membeli gadget yang dibutuhkan. Ketik 'BUY' kapital\n");
    printf("8. INVENTORY: menunjukkan gadget yang dimiliki oleh pemain. Ketik 'INVENTORY' kapital\n");
    printf("9. NEW GAME: memulai permainan dengan mengambil data dari file config.txt yang sudah tersedia. Ketik 'NEW_GAME' kapital\n");
    printf("10. SAVE GAME: menyimpan kondisi player saat ini, hanya dapat dilakukan ketika permainan sedang berjalan. Ketik 'SAVE_GAME' kapital\n");
    printf("11. EXIT GAME: keluar dari permainan yang sedang berjalan. Ketik 'EXIT'\n");
}