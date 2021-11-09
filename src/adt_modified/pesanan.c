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
  IDX_HEAD(*dp) = IDX_UNDEF;
  IDX_TAIL(*dp) = IDX_UNDEF;

}

boolean isEmptyDftr(DaftarPesanan p){
    return IDX_HEAD(p) == IDX_UNDEF && IDX_TAIL(p) == IDX_UNDEF;
}

boolean isFullDftr(DaftarPesanan p){
    return IDX_HEAD(p) == 0 && IDX_TAIL(p) == (CAPACITY_PSN - 1);
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

  return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}


void enqueuePsn(DaftarPesanan *dft, Pesanan pt){
    int head;
    if (isEmptyDftr(*dft))
    {
        IDX_HEAD(*dft) = 0;
        IDX_TAIL(*dft) = 0;
        HEAD(*dft) = pt;
    }
    else
    {
        if (IDX_TAIL(*dft) == (CAPACITY_PSN - 1))
        {
          head = IDX_HEAD(*dft);
          while (IDX_HEAD(*dft) <= IDX_TAIL(*dft))
          {
            Pesanan tmp = HEAD(*dft);
            IDX_HEAD(*dft) -= head;
            HEAD(*dft) = tmp;
            IDX_HEAD(*dft) += head;
            ++IDX_HEAD(*dft);
          }
          IDX_HEAD(*dft) = 0;
          IDX_TAIL(*dft) -= head;
        }

        IDX_TAIL(*dft)++;
        TAIL(*dft) = pt;
        int i = IDX_TAIL(*dft);
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
    if(IDX_HEAD(*dft)==IDX_TAIL(*dft)){
        IDX_HEAD(*dft) = IDX_UNDEF;
        IDX_TAIL(*dft) = IDX_UNDEF;
    }else{
        IDX_HEAD(*dft)++;
    }
}




