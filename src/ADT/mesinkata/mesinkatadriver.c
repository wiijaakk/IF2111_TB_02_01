#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

int main(){
    int total, price, money;

    printf("Selamat datang di Driver Mesin Kata!\n");
    printf("Akan dibuka file config.txt\n");
    printf("\n");

    // Membaca file config.txt
    printf("Akan dicetak jumlah barang yang tersedia dan harga barangnya\n");
    printf("dari file config.txt yang tersedia\n");
    StartFileWord("../../../save/config.txt");
    
    total = wordToInt(currentWord);
    printf("Angka terbaca: %d\n", total);

    for (int i = 0; i < total; i++) {
        ADVFileWordSpace();
        price = wordToInt(currentWord);
        printf("Harga barang %d: %d\n", i+1, price);

        ADVFileWordNewLine();
        printf("Nama barang %d: ", i+1);
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
    }

    ADVFileWordNewLine();
    total = wordToInt(currentWord);

    for (int i = 0; i < total; i++){
        ADVFileWordNewLine();
    }
    printf("\n");

    // Tes mengambil input dari stdin
    // Tes membandingkan kata (word) dengan string
    // Masukan tidak harus sama persis besar kecilnya
    printf("Masukkan kata untuk dibandingkan dengan kata TEST: ");
    StartWordNewLine();
    if (!isEndWord()) {
        if (compareWordToString(currentWord, "TEST")) {
            printf("Kata tersebut sama!\n");
        } else {
            printf("Kata tersebut tidak sama.\n");
        }
    }
    printf("\n");

    // Tes membaca masukan pengguna
    printf("Berapa banyak kata yang mau ditulis: ");
    StartWordNewLine();
    
    total = wordToInt(currentWord);

    printf("Kirimkan masukan untuk disalin di bawahnya : ");
    for(int i = 0; i < total - 1; i++){
        ADVWordSpace();
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf(" ");
    }

    // Tes membaca masukan pengguna
    ADVWordNewLine();
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n\n");

    printf("Masukkan 2 kata untuk disalin di bawahnya: ");
    STARTWORD();
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf(" ");

    ADVWORD();
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n\n");

    printf("Akhir dari Driver Mesin Kata\n");
}