#include <stdio.h>
#include <stdlib.h>
#include "startv2.h"

void startStore(ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command START
    int total = 0; // representasi jumlah barang atau user yang tercatat
    int n_riwayat_pembelian, n_wishlist;
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

        InsertLastArrDin(arrayItems, currentBarang);
    }

    // Membaca total user yang tersimpan dalam file
    ADVFileWordNewLine();
    total = wordToInt(currentWord);

    // Memasukkan informasi user ke arrayUsers
    for (int i = 0; i < total; i++) {
        Stack riwayat;
        List wishlist;
        Map keranjang;
        CreateEmptyStack(&riwayat);
        CreateEmptyListLinier(&wishlist);
        CreateEmptyMap(&keranjang);

        currentUser.riwayat_pembelian = &riwayat;
        currentUser.keranjang = &keranjang;
        currentUser.wishlist = &wishlist;
        
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

        ADVFileWordNewLine();
        n_riwayat_pembelian = wordToInt(currentWord);
        for(int i = 0; i < n_riwayat_pembelian; i++){
            barang_dibeli X;

            ADVFileWordSpace();
            X.totalharga = wordToInt(currentWord);

            ADVFileWordNewLine();
            for (int j = 0; j < currentWord.Length; j++) {
                X.name[j] = currentWord.TabWord[j];
            }
            X.name[currentWord.Length] = '\0';
            PushStack(currentUser.riwayat_pembelian, X);
        }

        ADVFileWordNewLine();
        n_wishlist = wordToInt(currentWord);
        for(int i = 0; i < n_wishlist; i++){
            nama_barang X;

            ADVFileWordNewLine();
            for (int j = 0; j < currentWord.Length; j++) {
                X[j] = currentWord.TabWord[j];
            }
            X[currentWord.Length] = '\0';
            InsVLast(currentUser.wishlist, X);
        }

        printf("banyak riwayat 1: %d\n", currentUser.riwayat_pembelian->size);
        SetEl(arrayUsers, i, currentUser);
    }
    arrayUsers->Neff = total;

    printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}