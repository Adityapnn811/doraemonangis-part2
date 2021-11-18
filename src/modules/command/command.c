#include "../../game_header.h"

boolean getRelation(Matrix m, ListPointDin l, POINT pt, Player *plyr, Config newgame) {
    int counter = getIdxPoint(l, pt);
    
    int nPos=0;
    int inputInt;

    int i=0;
    boolean found = false;

    showRelation((newgame).adjMatrix, (newgame).bangunans, CUR_LOC(*plyr));

    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    startWord(stdin);
    wordToInt(currentWord, &inputInt);
    if (inputInt == 0) {
        found = false;
        return false;
    } else {
        int n=0;
        int counter = getIdxPoint(l, CUR_LOC(*plyr));
        for(int i=0;i<COLS(m);i++) {
                if ((ELMT(m,counter,i) == 1)) {
                    n += 1;
                    if (n == inputInt)
                    {
                        setPlayerPrevLoc(plyr,CUR_LOCX(*plyr),CUR_LOCX(*plyr));
                        printf("\nMobita sekarang berada di titik %c (%d,%d)!\n", ELMTLABEL(l,i), ELMTX(l,i), ELMTY(l,i));
                        setPlayerLoc(plyr,ELMTX(l,i),ELMTY(l,i));
                        return true;
                    }
                }
        }
        printf("Masukkan pilihan posisi yang benar!\n");
        return false;
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

void movecmd(Player *p, Config *newgame, TDList *todo, Tas *t, Speedboost *sb)
/* Mengatur current loc player ke lokasi yang baru */
{
    int inputPos;
    // printf("*INFO* current label %c\n", curLocLabel(p, newgame));
    printf("Posisi yang dapat dicapai:\n");

    // Heavy item di tas
    int sumH = CountHeavy(*t);

    if (getRelation((*newgame).adjMatrix, (*newgame).bangunans, CUR_LOC(*p), p, *newgame)) {
        // Cek apakah speedboost aktif
        if (SB_ISACTIVE(*sb) == true) {
            printf("speedboost aktif\n");
            if (SB_COUNTER(*sb) == 10) { // klo udah move 10 kali, berarti speedboostnya ilang
                resetSpeedboost(sb);
                setWaktu(p, (WAKTU(*p)+1));
                reduceAllPerishTime(t);
            } else if (SB_COUNTER(*sb) != 0 && SB_COUNTER(*sb) % 2 == 0) {
                setWaktu(p, (WAKTU(*p)+1));
                SB_COUNTER(*sb) += 1;
                reduceAllPerishTime(t);
            } else {
                SB_COUNTER(*sb) += 1;
            }
        } else {
            if(sumH>0){
                int moveH = 1 + sumH;
                setWaktu(p, (WAKTU(*p)+moveH));
                reduceAllPerishTime(t);
            }else{
                setWaktu(p, (WAKTU(*p)+1));
                reduceAllPerishTime(t);
            }
            
        }
        
    }
    // tiap nambah waktu, panggil fungsi createTDfromPSN biar pesanan masuk ke to do list
    CreateTDfromPSN(todo, &((*newgame).pesanans), WAKTU(*p));
}

void dropoffcmd(Player *p, Config *newgame, Tas *tas, Speedboost *sb, TDList *todo)
{
    Item droppeditem = TOP(*tas);
    // dropItemToVal(tas,&droppeditem);
    if (droppeditem.DropOff == curLocLabel(*p, (*newgame))) {
        cancelEfekPengecil(tas);
        PESANAN_DONE(*p)+=1;
        char tipe_pesanan = droppeditem.ItemType;
        printf("TIPE PESANAN %c\n",tipe_pesanan);
        if (tipe_pesanan == 'H' || tipe_pesanan=='I') {
            printf("Pesanan Heavy Item berhasil diantarkan\n");
            UANG(*p) += 400;
            printf("Uang yang didapatkan: %d\n",400);
        } else if (tipe_pesanan == 'N') {
            printf("Pesanan Normal Item berhasil diantarkan\n");
            UANG(*p) += 200;
            printf("Uang yang didapatkan: %d\n",200);
        } else if (tipe_pesanan == 'P') {
            (*tas).maxTas += 1;
            printf("Pesanan Perish Item berhasil diantarkan\n");
            UANG(*p) += 400;
            printf("Uang yang didapatkan: %d\n",400);
            printf("Kapasitas tas Mobita bertambah 1!\n");
        } else if (tipe_pesanan == 'V') {
            printf("Pesanan VIP Item berhasil diantarkan\n");
            UANG(*p) += 600;
            printf("Uang yang didapatkan: %d\n",600);
        } else {
            printf("bp1\n");
        }
        dropItem(tas);
        if (CountHeavy(*tas) == 0 && tipe_pesanan == 'H') {
            SB_ISACTIVE(*sb) = true;
            SB_COUNTER(*sb) = 1;
            printf("Yeay, kamu mendapatkan speedboost untuk sepuluh move!\n");
        }
    } else if (isEmptyTas(*tas)) {
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    } else if (droppeditem.DropOff != curLocLabel(*p, (*newgame))) {
        printf("Tempat drop off salah! Harusnya di %c\n", droppeditem.DropOff);
    }
}

void pickupcmd(Player p, Config *newgame, Tas *tas, TDList *todo, Speedboost *sb) 
/* Mengambil pesanan yang terdapat di current location */
{
    if (lengthTas(*tas) != (*tas).maxTas) {
        if (searchPickUpTD(*todo,curLocLabel(p, (*newgame))) == true) {
            Pesanan pickuppsn;
            CreatePesanan(&pickuppsn, (searchPickUpTDLabel(*todo,curLocLabel(p, (*newgame)))).TimeIn, (searchPickUpTDLabel(*todo,curLocLabel(p, (*newgame)))).PickUp, (searchPickUpTDLabel(*todo,curLocLabel(p, (*newgame)))).DropOff, (searchPickUpTDLabel(*todo,curLocLabel(p, (*newgame)))).ItemType, (searchPickUpTDLabel(*todo,curLocLabel(p, (*newgame)))).TimePerish);
            char tipe_pesanan = pickuppsn.ItemType;
            if (tipe_pesanan == 'H') {
                printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                // speedboost lgsg digagalin
                resetSpeedboost(sb);
            } else if (tipe_pesanan == 'N') {
                printf("Pesanan berupa Normal Item berhasil diambil!\n");
            } else if (tipe_pesanan == 'P') {
                printf("Pesanan berupa Perish Item berhasil diambil!\n");
            } else if (tipe_pesanan == 'V') {
                printf("Pesanan berupa VIP Item berhasil diambil!\n");
            }
            printf("Tujuan Pesanan: %c\n", pickuppsn.DropOff);
            Item item;

            if (pickuppsn.ItemType != 'P') {
                CreateItem(&item, pickuppsn.TimeIn, pickuppsn.PickUp, pickuppsn.DropOff, pickuppsn.ItemType, IDX_UNDEF);
                addItem(tas, item);
                // printf("pickup berhasil\n");
                // printf("length tas %d\n", lengthTas(*tas));
                deleteAtTD(todo, search(*todo,pickuppsn));
            } else {
                CreateItem(&item, pickuppsn.TimeIn, pickuppsn.PickUp, pickuppsn.DropOff, pickuppsn.ItemType, pickuppsn.TimePerish);
                addItem(tas, item);
                // printf("pickup perish berhasil\n");
                // printf("length tas %d\n", lengthTas(*tas));
                deleteAtTD(todo, search(*todo,pickuppsn));
            }

        }
        else {
            printf("Pesanan tidak ditemukan!\n");
        }
    } else {
        printf("Tas udah penuh!!\n");
    }
}

boolean isDone (TDList todo, Tas tas, DaftarPesanan psn, Player p, ListPointDin bangunan) {
    return (isEmptyTD(todo) && (isEmptyDftr(psn) && (isEmptyTas(tas)) && CUR_LOCX(p)==bangunan.buffer[0].position.X && CUR_LOCY(p)==bangunan.buffer[0].position.Y));
}
