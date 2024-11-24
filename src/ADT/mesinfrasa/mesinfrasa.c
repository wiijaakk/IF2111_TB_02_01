#include <stdio.h>
#include "mesinfrasa.h"

boolean EndFrasa;
Frasa CurrentFrasa;

void IgnoreBlank(){
    while(GetCC()==BLANK){
        ADV();
    }
}

void STARTFRASA(){
    START();
    IgnoreBlanks();
    EndFrasa = GetCC() == NEWLINE;
    if (!EndFrasa) {
        ADVFRASA();
    }
}

void ADVFRASA(){
    IgnoreBlanks();
    EndFrasa = GetCC()==NEWLINE;
    if(!EndFrasa){
        CopyFrasa();
    }
}

void CopyFrasa(){
    int i = 0;
    while(GetCC()!=NEWLINE && i<Max){
        CurrentFrasa.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    CurrentFrasa.Length = i;
}
