#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"

NamaGadget DaftarGadget[5] = {Kain,Senter,Pintu,Mesin,Pengecil};



void CreateInv(Inventory *inv){
    for(int i=0;i<CAPACITY_INV;i++){
        GADGET(*inv,i)="UNDEF";
        HARGA(*inv,i)=-1;
        KEY(*inv,i)='z';
    }
}

void BuyGadget(Inventory *inv, int *uang){
    //anggepan lokasi di HQ
    //uang nunggu main
    int a;
    printf("Uang Anda Sekarang: %d Yen\n",*uang);
    printf("Gadget yang tersedia:\n");
    for(int i=0;i<5;i++){
        printf("%d. %s (%d Yen)\n",i+1,DaftarGadget[i].nama,DaftarGadget[i].harga);
    }
    printf("Gadget mana yang ingin kau beli? (jika input salah akan kembali ke halaman sebelumnya)\n");
    printf("ENTER COMMAND: ");
    startWord(stdin);
    wordToInt(currentWord, &a);
    if(a>0){
        if(!isFullInv(*inv)){
            if(((*uang)-(DaftarGadget[a-1].harga))>=0){
                (*uang) -= DaftarGadget[a-1].harga;
                printf("%s berhasil dibeli!\n",DaftarGadget[a-1].nama);
                printf("Uang anda sekarang: %d Yen\n",*uang);
                AddGadget(inv,DaftarGadget[a-1]);
            }else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
            }
        }else{
            printf("Inventory full!\n");
        }

    }



}

boolean isFullInv(Inventory inv){
    boolean flag = true;
    int ctr = 0;
    while(ctr<5 && flag){
        if(KEY(inv,ctr)=='z'){
            flag = false;
        }else{
            ctr++;
        }
    }
    if(ctr>4){
        flag = true;
    }else{
        flag = false;
    }
    return flag;

}

void AddGadget(Inventory *inv, NamaGadget gdg){
    boolean flag = false;
    int ctr = 0;
    while(ctr<5 && !flag){
        if(KEY(*inv,ctr)=='z'){
            flag = true;
        }else{
            ctr++;
        }
    }
    GADGET(*inv,ctr) = gdg.nama;
    HARGA(*inv,ctr) = gdg.harga;
    KEY(*inv,ctr) = gdg.key;

}

// Display gadget pada inventory
void DisplayGadget(Inventory *inv,int *waktu, Tas *tas,TDList todo,DaftarPesanan psn,Player *p,ListPointDin lb){
    //inventory gadget
    for(int i=0; i<5;i++){
        if(KEY(*inv,i)!='z'){
            printf("%d. %s\n",i+1,GADGET(*inv,i));
        }else{
            printf("%d. -\n",i+1);
        }
    }
    printf("Gadget mana yang ingin digunakan? (jika input salah akan kembali ke halaman sebelumnya)\n");
    printf("ENTER COMMAND: ");
    int a;
    startWord(stdin);
    wordToInt(currentWord, &a);

    if(a>0){
        if(KEY(*inv,a-1)!='z'){
            printf("%s berhasil digunakan\n", GADGET(*inv,a-1));
            UseGadget((*inv).daftar[a-1],waktu,tas,psn,p,lb);

            deleteGadget(inv,a-1);
        }else{
            printf("Tidak ada Gadget yang dapat digunakan!\n");
        }
    }
}

void deleteGadget(Inventory *inv, int i){
    GADGET(*inv,i)="UNDEF";
    HARGA(*inv,i)=-1;
    KEY(*inv,i)='z';
}

void UseGadget(NamaGadget gdg,int *waktu, Tas *tas,DaftarPesanan psn,Player *p,ListPointDin lb){
    DaftarPesanan temp2=psn;
    if(gdg.key=='a'){
        if(TOP(*tas).ItemType=='P'){
            while(HEADPSN(temp2).PickUp!=TOP(*tas).PickUp && HEADPSN(temp2).DropOff!=TOP(*tas).DropOff && HEADPSN(temp2).TimeIn!=TOP(*tas).TimeIn){
                dequeuePsn(&temp2);
            }
            TOP(*tas).TimePerish = HEADPSN(temp2).TimePerish;
        }else{
            printf("Nothing happened.\n");
        }
    }else if(gdg.key=='b'){
        (*tas).maxTas*=2;
        if((*tas).maxTas>100){
            (*tas).maxTas=100;
        }
    }else if(gdg.key=='c'){
        printf("Tempat yang dapat dicapai:\n");
        for(int i=0; i<lb.Neff; i++){
            printf("%d. %c (%d %d)\n",i+1,lb.buffer[i].label,lb.buffer[i].position.X,lb.buffer[i].position.Y);
        }
        printf("ENTER COMMAND: ");
        int a;
        startWord(stdin);
        wordToInt(currentWord, &a);
        a -= 1;
        setPlayerLoc(p,ELMTX(lb,a),ELMTY(lb,a));
        

    }else if(gdg.key=='d'){
        (*waktu)-=50;
        if(*waktu<0){
            (*waktu)=0;
        }
    }else if(gdg.key=='e'){
        if(TOP(*tas).ItemType=='H'){
            // Tanda heavy item efek hilang namun tetap berlabel heavy item
            TOP(*tas).ItemType='I'; 
        }else{
            printf("Nothing happened\n");
        }
    }
}
