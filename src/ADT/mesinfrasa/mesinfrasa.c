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
    IgnoreBlank();
    EndFrasa = GetCC() == NEWLINE;
    if (!EndFrasa) {
        ADVFRASA();
    }
}

void ADVFRASA(){
    IgnoreBlank();
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
    CurrentFrasa.TabWord[i] = '\0';
    CurrentFrasa.Length = i;
}

boolean compareFrasaToString(Frasa word, char* string) {
    int stringLength = 0;
    char temp[50];

    for (int i = 0; string[i] != '\0'; i++){
        stringLength++;
    }

    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] != '\n'){    
            if (word.TabWord[i] >= 'a' && word.TabWord[i] <= 'z'){
                temp[i] = word.TabWord[i] - 32;
            }else {
            temp[i] = word.TabWord[i];
            }
        }
        
    }

    if (word.Length == stringLength) {
        for (int i = 0; i < word.Length; i++){
            if(temp[i] != string[i]){
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}
