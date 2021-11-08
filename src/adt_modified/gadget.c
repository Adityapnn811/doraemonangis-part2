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

void Buy(Inventory *inv, int *uang){
    //anggepan lokasi di HQ
    //uang nunggu main
    int a;
    printf("Uang Anda Sekarang: %d Yen\n",*uang);
    printf("Gadget yang tersedia:\n");
    for(int i=0;i<5;i++){
        printf("%d. %s (%d Yen)\n",i+1,DaftarGadget[i].nama,DaftarGadget[i].harga);
    }
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    scanf("%d",&a);
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
void DisplayGadget(Inventory *inv,int *waktu, Tas *tas){
    //inventory gadget
    int a;
    for(int i=0; i<5;i++){
        if(KEY(*inv,i)!='z'){
            printf("%d. %s\n",i+1,GADGET(*inv,i));
        }else{
            printf("%d. -\n",i+1);
        }
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    scanf("%d",&a);

    if(a>0){
        if(KEY(*inv,a-1)!='z'){
            printf("%s berhasil digunakan\n", GADGET(*inv,a-1));
            UseGadget((*inv).daftar[a-1],waktu,tas);

            deleteGadget(inv,a-1);
        }else{
            printf("Tidak ada Gadget yang dapat digunakan!\n");
        }
    }else{

    }


}

void deleteGadget(Inventory *inv, int i){
    GADGET(*inv,i)="UNDEF";
    HARGA(*inv,i)=-1;
    KEY(*inv,i)='z';
}

void UseGadget(NamaGadget gdg,int *waktu, Tas *tas){
    if(gdg.key=='a'){

    }else if(gdg.key=='b'){
        (*tas).maxTas*=2;
    }else if(gdg.key=='c'){

    }else if(gdg.key=='d'){
        (*waktu)-=50;
        if(*waktu<0){
            (*waktu)=0;
        }
    }else if(gdg.key=='e'){

    }
}
