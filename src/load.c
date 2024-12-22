#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void load(Word filename, ArrayDin* arrayItems, TabInt* arrayUsers, boolean * SessionStatus) {
    int total = 0;
    int n_riwayat_pembelian = -1;
    int n_wishlist = -1;
    Barang currentBarang;
    User currentUser;
    boolean exists;
    boolean isIntBarang = true;
    boolean isIntUser = true;
    boolean riwayat_exist = true;
    boolean wishlist_exist = true;

    char filenameStr[50];
    char fullPath[200];
    for (int i = 0; i < filename.Length; i++) {
        filenameStr[i] = filename.TabWord[i];
    }
    filenameStr[filename.Length] = '\0';
    snprintf(fullPath, sizeof(fullPath), "%s%s", SAVE_FOLDER, filenameStr); // Menggabungkan folder (../save/) dengan filename input user

    if (isFileValid(fullPath)) {   
        // Membuka file
        StartFileWord(fullPath);
        if (!EndWord) {

            for(int i = 0; i < currentWord.Length; i++){
                if(currentWord.TabWord[i] < 48 || currentWord.TabWord[i] > 57){
                    isIntBarang = false;
                }
            }
            
            if(isIntBarang){
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
            }

            // Membaca total user yang tersimpan dalam file
            ADVFileWordNewLine();

            for(int i = 0; i < currentWord.Length; i++){
                if(currentWord.TabWord[i] < 48 || currentWord.TabWord[i] > 57){
                    isIntUser = false;
                }
            }

            if(!isIntBarang){
                isIntUser = false;
            }

            if(isIntUser){
                total = wordToInt(currentWord);

                // Memasukkan informasi user ke arrayUsers
                for (int i = 0; i < total; i++) {
                    currentUser.riwayat_pembelian = malloc(sizeof(Stack));
                    currentUser.wishlist = malloc(sizeof(List));
                    currentUser.keranjang = malloc(sizeof(Map));

                    CreateEmptyStack(currentUser.riwayat_pembelian);
                    CreateEmptyListLinier(currentUser.wishlist);
                    CreateEmptyMap(currentUser.keranjang);

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
                    for(int i = 0; i < currentWord.Length; i++){
                        if(currentWord.TabWord[i] == ' '){
                            riwayat_exist = false;
                            break;
                        }
                    }

                    if(!isIntBarang || !isIntUser){
                        riwayat_exist = false;
                    }

                    if(riwayat_exist){
                        n_riwayat_pembelian = wordToInt(currentWord);
                        for (int i = 0; i < n_riwayat_pembelian; i++) {
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
                    }

                    ADVFileWordNewLine();
                    for(int i = 0; i < currentWord.Length; i++){
                        if(currentWord.TabWord[i] == ' '){
                            wishlist_exist = false;
                            break;
                        }
                    }

                    if(!isIntBarang || !isIntUser){
                        wishlist_exist = false;
                    }

                    if(wishlist_exist){
                        n_wishlist = wordToInt(currentWord);
                        for (int i = 0; i < n_wishlist; i++) {
                            nama_barang X;

                            ADVFileWordNewLine();
                            for (int j = 0; j < currentWord.Length; j++) {
                                X[j] = currentWord.TabWord[j];
                            }
                            X[currentWord.Length] = '\0';
                            InsVLast(currentUser.wishlist, X);
                        }
                    }
                    SetEl(arrayUsers, i, currentUser);
                }
                arrayUsers->Neff = total;
            }
        }

        if (Length(*arrayItems) == 0 || NbElmt(*arrayUsers) == 0 || n_riwayat_pembelian == -1 || n_wishlist == -1) {
            printf("File tidak memuat data yang sesuai. PURRMART gagal dijalankan.\n");
        }
        else {
            *SessionStatus = true;
            printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        }
    }
    else {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
    }
}