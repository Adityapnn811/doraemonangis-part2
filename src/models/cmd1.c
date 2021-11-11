#include "../game_header.h"

boolean getRelation(Matrix m, ListPointDin l, POINT pt, Player *plyr) {
    int counter = getIdxPoint(l, pt);
    
    int nPos=0;
    char input[30];
    printf("\nENTER COMMAND: ");
    fgets(input,30,stdin);
    // printf("inputnya %s\n", input);
    // if (strcmp(input, "30")) {
    //     printf("if nya bisa\n");
    // }
    int inputInt = atoi(input);
    printf("nilai inputInt %d", inputInt);
    int i=0;
    boolean found = false;
    while((0<COLS(m) && !found)) {
        // iterasi setiap kolom matriks yang bernilai 1
        if (ELMT(m,counter,i) == 1) {
            nPos += 1;
            if (inputInt == (nPos % 27)) { 
                setPlayerPrevLoc(plyr,CUR_LOCX(*plyr),CUR_LOCX(*plyr));
                printf("\nMobita sekarang berada di titik %c (%d,%d)!\n", ELMTLABEL(l,i), ELMTX(l,i), ELMTY(l,i));
                setPlayerLoc(plyr,ELMTX(l,i),ELMTY(l,i));
                found = true;
                return true;
                break;
            } 
            else if (inputInt == 0) {
                found = false;
                return false;
                break;
            }
        }
        i += 1;
    }
    if (inputInt != 0) {
        if (found == false) {
            printf("Masukkan pilihan posisi yang benar!\n");
            return false;
        }
    }
}

char curLocLabel(Player p, Config newgame) 
// get current loc label
{
    char CUR_LOCL;
    for(int i=0;i<20;i++) {
        if ((CUR_LOCX(p) == newgame.bangunans.buffer[i].position.X) && (CUR_LOCY(p) == newgame.bangunans.buffer[i].position.Y)) {
            CUR_LOCL = newgame.bangunans.buffer[i].label;
        }
    }
    return CUR_LOCL;
}

ListPointDin MakeRelationList(ListPointDin x) {

    
    Bangunan z;
    z.label = 'X';
    z.position.X = 2;
    z.position.Y = 3;
    insertLastListPoint(&x,z);
    return x;
}

void movecmd(Player *p, Config newgame)
/* Mengatur current loc player ke lokasi yang baru */
{
    printf("-----COMMAND MOVE-----\n");
    int inputPos;
    // printf("*INFO* current label %c\n", curLocLabel(p, newgame));
    printf("Posisi yang dapat dicapai:\n");

    
    showRelation(newgame.adjMatrix, newgame.bangunans, CUR_LOC(*p));
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");

    if (getRelation(newgame.adjMatrix, newgame.bangunans, CUR_LOC(*p), p)) {
        setWaktu(p, (WAKTU(*p)-1));
    }
}

void dropoffcmd(Player p, Config *newgame, Tas *tas)
{
    Item droppeditem;
    int i;
    for(i=0;i<20;i++) {
        if (curLocLabel(p, *newgame) == (*newgame).pesanans.daftar[i].DropOff) {
            char tipe_pesanan = (*newgame).pesanans.daftar[i].ItemType;
            if (tipe_pesanan == 'H') {
                printf("Pesanan Heavy Item berhasil diantarkan\n");
            } else if (tipe_pesanan == 'N') {
                printf("Pesanan Normal Item berhasil diantarkan\n");
            } else if (tipe_pesanan == 'P') {
                printf("Pesanan Perish Item berhasil diantarkan\n");
            } else if (tipe_pesanan == 'V') {
                printf("Pesanan VIP Item berhasil diantarkan\n");
            }
        }
    }
    // dropItemToVal(tas,&droppeditem);
    
    printf("Uang yang didapatkan: ___\n");
}

void pickupcmd(Player p, Config *newgame, Tas *tas) 
/* Mengambil pesanan yang terdapat di current location */
{
    // // printf("label %c", CUR_LOCL);
    for(int j=0;j<20;j++) { // j = banyak pesanan
        if (curLocLabel(p, (*newgame)) == (*newgame).pesanans.daftar[j].PickUp) {
            char tipe_pesanan = (*newgame).pesanans.daftar[j].ItemType;
            if (tipe_pesanan == 'H') {
                printf("Pesanan berupa Heavy Item berhasil diambil!\n");
            } else if (tipe_pesanan == 'N') {
                printf("Pesanan berupa Normal Item berhasil diambil!\n");
            } else if (tipe_pesanan == 'P') {
                printf("Pesanan berupa Perish Item berhasil diambil!\n");
            } else if (tipe_pesanan == 'V') {
                printf("Pesanan berupa VIP Item berhasil diambil!\n");
            }
            printf("Tujuan Pesanan: %c\n", (*newgame).pesanans.daftar[j].DropOff);
            Item item;
            if ((*newgame).pesanans.daftar[j].ItemType != 'P') {
                CreateItem(&item, (*newgame).pesanans.daftar[j].TimeIn, (*newgame).pesanans.daftar[j].PickUp, (*newgame).pesanans.daftar[j].DropOff, (*newgame).pesanans.daftar[j].ItemType, IDX_UNDEF);
                addItem(tas, item);
                printf("pickup berhasil\n");
                printf("length tas %d\n", lengthTas(*tas));
                Pesanan p;
                CreatePesanan(&p, (*newgame).pesanans.daftar[j].TimeIn, (*newgame).pesanans.daftar[j].PickUp, (*newgame).pesanans.daftar[j].DropOff, (*newgame).pesanans.daftar[j].ItemType, IDX_UNDEF);
                PesananSelesai(&(*newgame).pesanans,p);
            } else {
                CreateItem(&item, (*newgame).pesanans.daftar[j].TimeIn, (*newgame).pesanans.daftar[j].PickUp, (*newgame).pesanans.daftar[j].DropOff, (*newgame).pesanans.daftar[j].ItemType, (*newgame).pesanans.daftar[j].TimePerish);
                addItem(tas, item);
                printf("pickup perish berhasil\n");
                printf("length tas %d\n", lengthTas(*tas));
                Pesanan p;
                CreatePesanan(&p, (*newgame).pesanans.daftar[j].TimeIn, (*newgame).pesanans.daftar[j].PickUp, (*newgame).pesanans.daftar[j].DropOff, (*newgame).pesanans.daftar[j].ItemType, (*newgame).pesanans.daftar[j].TimePerish);
                PesananSelesai(&(*newgame).pesanans,p);
            }

        }
        // else {
        //     printf("bukan lokasi pick up\n");
        // }
    }
    dequeuePsn(&(*newgame).pesanans);
}