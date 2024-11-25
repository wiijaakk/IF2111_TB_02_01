#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

int main(){
    // Tes isFileValid(char *input);
    printf("Selamat datang di Driver Mesin Karakter!\n");
    printf("Akan dibuka file config.txt\n");
    printf("\n");

    printf("Apakah file config.txt dapat dibaca: ");
    if(isFileValid("../../../save/config.txt")){
        printf("Ya!\n");
    }

    // Tes GetCC(), StartReadFile(char *input), dan ADVFile()
    // *ADVFile digunakan dalam StartReadFile(char* input)
    StartReadFile("../../../save/config.txt");
    printf("Karakter pertama di file config.txt adalah: %c\n", GetCC());
    // Menutup file
    while(!endOfFile){
        ADVFile();
    }
    printf("\n");

    // Tes StartReadNewLine() dan ADVNewLine()
    // *ADVNewLine() digunakan dalam StartReadNewLine
    printf("Masukkan satu karakter dan tekan ENTER: ");
    StartReadNewLine();
    printf("Kamu menulis: %c\n", GetCC());
    printf("\n");

    printf("Akhir dari Driver Mesin Karakter\n");
}