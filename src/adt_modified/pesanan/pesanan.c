#include <stdio.h>
#include <stdlib.h>
#include "pesanan.h"

void CreatePesanan(Pesanan *i, int TimeIn, char PickUp, char DropOff, char ItemType, int TimePerish){
    TIMEIN(*i) = TimeIn;
    PICKUP(*i) = PickUp;
    DROPOFF(*i) = DropOff;
    TYPE(*i) = ItemType;
    if (TYPE(*i) == 'P') {
        TIMEPERISH(*i) = TimePerish;
    } else {
        TIMEPERISH(*i) = IDX_UNDEF;
    }
    DONE(*i) = false;
}

void CreateDaftar(DaftarPesanan *dp){
  IDX_HEADPSN(*dp) = IDX_UNDEF;
  IDX_TAILPSN(*dp) = IDX_UNDEF;

}

boolean isEmptyDftr(DaftarPesanan p){
    return IDX_HEADPSN(p) == IDX_UNDEF && IDX_TAILPSN(p) == IDX_UNDEF;
}

boolean isFullDftr(DaftarPesanan p){
    return IDX_HEADPSN(p) == 0 && IDX_TAILPSN(p) == (CAPACITY_PSN - 1);
}

boolean CmpPesanan(Pesanan P1, Pesanan P2){
    boolean flag = false;
    if(P1.DropOff==P2.DropOff && P1.TimeIn==P2.TimeIn && P1.PickUp==P2.PickUp && P1.ItemType==P2.ItemType){
        flag = true;
    }else{
        flag = false;
    }

    return flag;

}

int lengthDftr(DaftarPesanan q)
{
  if (isEmptyDftr(q))
  {
    return 0;
  }

  return IDX_TAILPSN(q) - IDX_HEADPSN(q) + 1;
}


void enqueuePsn(DaftarPesanan *dft, Pesanan pt){
    int HEADPSN;
    if (isEmptyDftr(*dft))
    {
        IDX_HEADPSN(*dft) = 0;
        IDX_TAILPSN(*dft) = 0;
        HEADPSN(*dft) = pt;
    }
    else
    {
        if (IDX_TAILPSN(*dft) == (CAPACITY_PSN - 1))
        {
          HEADPSN = IDX_HEADPSN(*dft);
          while (IDX_HEADPSN(*dft) <= IDX_TAILPSN(*dft))
          {
            Pesanan tmp = HEADPSN(*dft);
            IDX_HEADPSN(*dft) -= HEADPSN;
            HEADPSN(*dft) = tmp;
            IDX_HEADPSN(*dft) += HEADPSN;
            ++IDX_HEADPSN(*dft);
          }
          IDX_HEADPSN(*dft) = 0;
          IDX_TAILPSN(*dft) -= HEADPSN;
        }

        IDX_TAILPSN(*dft)++;
        TAILPSN(*dft) = pt;
        int i = IDX_TAILPSN(*dft);
        Pesanan temp2;
        while((*dft).daftar[i].TimeIn <= (*dft).daftar[i-1].TimeIn && i>=0){
                temp2 = (*dft).daftar[i];
                (*dft).daftar[i] = (*dft).daftar[i-1];
                (*dft).daftar[i-1] = temp2;
            i--;
        }
    }
}


void dequeuePsn(DaftarPesanan *dft){
    if(IDX_HEADPSN(*dft)==IDX_TAILPSN(*dft)){
        IDX_HEADPSN(*dft) = IDX_UNDEF;
        IDX_TAILPSN(*dft) = IDX_UNDEF;
    }else{
        IDX_HEADPSN(*dft)++;
    }
}

void dequeuePsntoVal(DaftarPesanan *dft,Pesanan *pt){
    *pt = HEADPSN(*dft);
    if(IDX_HEADPSN(*dft)==IDX_TAILPSN(*dft)){
        IDX_HEADPSN(*dft) = IDX_UNDEF;
        IDX_TAILPSN(*dft) = IDX_UNDEF;
    }else{
        IDX_HEADPSN(*dft)++;
    }
}

void PesananSelesai(DaftarPesanan *pt,Pesanan ps){
    int i = 0;
    while(!CmpPesanan((*pt).daftar[i],ps)){
        i++;
    }
    DONE((*pt).daftar[i])=true;

}


