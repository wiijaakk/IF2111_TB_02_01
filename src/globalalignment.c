#include <stdio.h>
#include "globalalignment.h"

int maksi(int a, int b, int c){
    if(a>=b && a>=c){
        return a;
    }
    else if(b>=a && b>=c){
        return b;
    }
    else{
        return c;
    }
}

int matchatautidak(char a, char b){
    if(a==b){
        return MATCH;
    }
    else{
        return MISMATCH;
    }
}

void globalalignment(){
    printf("Masukan sekuens referensi: ");
    char referensi[50], query[50];
    int needleman_wunsch[51][51];
    STARTFRASA();
    int i = 0;
    while(CurrentFrasa.TabWord[i]!='\0'){
        if(CurrentFrasa.TabWord[i]!='A' && CurrentFrasa.TabWord[i]!='G' && CurrentFrasa.TabWord[i]!='T' && CurrentFrasa.TabWord[i]!='C'){
            printf("Masukan sekuens tidak valid.\n");
            return;
        }
        else{
            referensi[i] = CurrentFrasa.TabWord[i];
            i++;
        }
    }
    int panjang_referensi = i;
    printf("Masukan sekuens query:     ");
    STARTFRASA();
    i = 0;
    while(CurrentFrasa.TabWord[i]!='\0'){
        if(CurrentFrasa.TabWord[i]!='A' && CurrentFrasa.TabWord[i]!='G' && CurrentFrasa.TabWord[i]!='T' && CurrentFrasa.TabWord[i]!='C'){
            printf("Masukan sekuens tidak valid.\n");
            return;
        }
        else{
            query[i] = CurrentFrasa.TabWord[i];
            i++;
        }
    }
    int panjang_query = i;
    // printf("%d, %d\n", panjang_referensi, panjang_query);
    for (int j = 0; j<=panjang_referensi; j++){
        needleman_wunsch[0][j] = 0 + j*GAP;
    }
    for (int j = 0; j<=panjang_query; j++){
        needleman_wunsch[j][0] = 0 + j*GAP;
    }
    for(int j = 1; j<=panjang_referensi; j++){
        for(int k = 1; k<=panjang_query; k++){
            needleman_wunsch[k][j] = maksi(needleman_wunsch[k-1][j] + GAP, needleman_wunsch[k][j-1] + GAP, needleman_wunsch[k-1][j-1] + matchatautidak(referensi[j-1], query[k-1]));
        }
    }
    // for(int k = 0; k<=panjang_query; k++){
    //     for(int j = 0; j<=panjang_referensi; j++){
    //         printf("%d ", needleman_wunsch[k][j]);
    //     }
    //     printf("\n");
    // }
    int panjang;
    if(panjang_referensi>panjang_query){
        panjang = panjang_referensi;
    }
    else{
        panjang = panjang_query;
    }
    int j = panjang_referensi;
    int k = panjang_query;
    int skor = needleman_wunsch[k][j];
    printf("\nSkor: %d\n", skor);
    int idx_r = panjang-1, idx_q = panjang-1;
    char aligned_r[51], aligned_q[51];
    while(j>0 && k>0){
        if(needleman_wunsch[k][j] == needleman_wunsch[k-1][j-1] + matchatautidak(referensi[j-1], query[k-1])){
            aligned_r[idx_r--] = referensi[j-1];
            aligned_q[idx_q--] = query[k-1];
            j--;
            k--;
        }
        else if(needleman_wunsch[k][j] == needleman_wunsch[k-1][j] + GAP){
            aligned_r[idx_r--] = '-';
            aligned_q[idx_q--] = query[k-1];
            k--;
        }
        else{
            aligned_r[idx_r--] = referensi[j-1];
            aligned_q[idx_q--] = '-';
            j--;
        }
    }
    while(j>0){
        aligned_r[idx_r--] = referensi[j-1];
        aligned_q[idx_q--] = '-';
        j--;
    }
    while(k>0){
        aligned_r[idx_r--] = '-';
        aligned_q[idx_q--] = query[k-1];
        k--;    
    }
    aligned_r[panjang] = '\0';
    aligned_q[panjang] = '\0';
    printf("Sekuens yang telah disejajarkan: \n");
    printf("%s\n", aligned_r);
    printf("%s\n\n", aligned_q);
    if(skor*100>80*panjang){
        printf("Oops, ada kebocoran :(\n");
    }
    else{
        printf("Yay! Tidak bocor :D\n");
    }
}