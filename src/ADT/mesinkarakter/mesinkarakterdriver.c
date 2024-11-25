#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

int main(){
    printf("Selamat datang di Driver Mesin Karakter!\n");
    printf("Akan dibuka file config.txt\n");
    printf("\n");

    // Tes membaca file config.txt
    printf("Apakah file config.txt dapat dibaca: ");
    if(isFileValid("../../../save/config.txt")){
        printf("Ya!\n");
    }

    // Tes mendapatkan karakter dari file
    StartReadFile("../../../save/config.txt");
    printf("Karakter pertama di file config.txt adalah: %c\n", GetCC());
    // Menutup file
    while(!endOfFile){
        ADVFile();
    }
    printf("\n");

    // Tes mendapatkan karakter dari stdin
    printf("Masukkan satu karakter dan tekan ENTER: ");
    StartReadNewLine();
    printf("Kamu menulis: %c\n", GetCC());
    printf("\n");
    if(IsEOP){
        printf("Akhir dari Driver Mesin Kata\n");
    }
}