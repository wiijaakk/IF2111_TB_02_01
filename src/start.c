#include <stdio.h>
#include <stdlib.h>
#include "start.h"

void startStore(ArrayDin* arrayItems, TabInt* arrayUsers) {
    int total = 0; // representasi jumlah barang atau user yang tercatat
    Barang currentBarang; // menyimpan barang yg sedang diproses
    User currentUser; // menyimpan user yg sedang diproses

    // Membuka file konfigurasi
    StartFileWord("../save/config.txt");

     // Membaca total barang yang tersimpan dalam file
    total = wordToInt(currentWord);

    // Memasukkan informasi barang ke arrayItems
    for (int i = 0; i < total; i++) {
        ADVFileWordSpace();
        currentBarang.price = wordToInt(currentWord);

        ADVFileWordNewLine();
        for (int j = 0; j < currentWord.Length; j++) {
            currentBarang.name[j] = currentWord.TabWord[j];
        }
        currentBarang.name[currentWord.Length] = '\0';

        InsertLast(arrayItems, currentBarang);
    }

    // Membaca total user yang tersimpan dalam file
    ADVFileWordNewLine();
    total = wordToInt(currentWord);

    // Memasukkan informasi user ke arrayUsers
    for (int i = 0; i < total; i++) {
        ADVFileWordSpace();
        currentUser.money = wordToInt(currentWord);
        
        ADVFileWordSpace();
        for (int j = 0; j < currentWord.Length; j++) {
            currentUser.name[j] = currentWord.TabWord[j];
        }
        currentUser.name[currentWord.Length] = '\0';

        ADVFileWordNewLine();
        for (int j = 0; j < currentWord.Length; j++) {
            currentUser.password[j] = currentWord.TabWord[j];
        }
        currentUser.password[currentWord.Length] = '\0';

        SetEl(arrayUsers, i , currentUser);
    }
    arrayUsers->Neff = total;

    printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}