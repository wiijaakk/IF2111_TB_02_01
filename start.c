#include <stdio.h>
#include <stdlib.h>

#include "start.h"

static FILE *pita;
static int retval;

void startStore(ArrayDin * arrayItems, TabInt* arrayUsers){
    int total = 0; // representasi jumlah barang atau user yang tercatat
    Barang currentBarang; // menyimpan barang yg sedang diproses
    User currentUser; // menyimpan user yg sedang diproses

    // buka file config.txt
    // baca line pertama
    pita = fopen("config.txt", "r");
    ADV();

    // cek jumlah barang buat dimasukin ke current word, kondisi akhir currentChar ada di karakter new line
    for(int i = 0; currentChar != '\n'; i++){
        currentWord.TabWord[i] = currentChar;
        currentWord.Length = i+1;
        ADV();
    }

    // simpan angka representasi jumlah barang
    for(int i = 0; i < currentWord.Length; i++){
        total = total * 10 + (currentWord.TabWord[i] - '0');
    }

    // looping sebanyak jumlah barang (total) untuk masukin harga barang dan nama barang
    for (int i = 0 ; i < total ; i++){
        // pembacaan word dimulai
        // cari karakter selanjutnya (retval akan pindah ke karakter selanjutnya, termasuk yg ada di line baru)
        ADV();

        // baca harga barang
        for(int i = 0; currentChar != ' '; i++){
            currentWord.TabWord[i] = currentChar;
            currentWord.Length = i+1;
            ADV();
        }

        // ubah harga barang ke int
        int itemPrice = 0;
        for(i = 0; i < currentWord.Length; i++){
            itemPrice = itemPrice * 10 + (currentWord.TabWord[i] - '0');
        }
        // masukkan harga barang
        currentBarang.price = itemPrice;

        // baca nama barang
        IgnoreBlanks();
        for(int i = 0; currentChar != '\n'; i++){
            currentWord.TabWord[i] = currentChar;
            currentWord.Length = i+1;
            ADV();
        }

        // masukin nama ke barang
        int length = currentWord.Length;
        for(int i = 0; i < length; i++){
            currentBarang.name[i] = currentWord.TabWord[i];
        }

        InsertLast(arrayItems, currentBarang);
    }

    // cek jumlah user buat dimasukin ke current word, kondisi akhir currentChar ada di karakter new line
    for(int i = 0; currentChar != '\n'; i++){
        currentWord.TabWord[i] = currentChar;
        currentWord.Length = i+1;
        ADV();
    }

    // simpan angka representasi jumlah user
    total = 0;
    for (int i = 0; i < currentWord.Length; i++){
        total = total * 10 + (currentWord.TabWord[i] - '0');
    }

    // looping sebanyak jumlah user (total) untuk masukin uang, nama, dan password user
    for(int i = 0 ; i < total ; i++){
        ADV();

        // baca uang user
        for(int i = 0; currentChar != ' '; i++){
            currentWord.TabWord[i] = currentChar;
            currentWord.Length = i+1;
            ADV();
        }

        // ubah uang ke int
        int userMoney = 0;
        for(i = 0; i < currentWord.Length; i++){
            userMoney = userMoney * 10 + (currentWord.TabWord[i] - '0');
        }

        // masukin uang ke user
        currentUser.money = userMoney;

        // baca nama user
        IgnoreBlanks();
        for(int i = 0; currentChar != ' '; i++){
            currentWord.TabWord[i] = currentChar;
            currentWord.Length = i+1;
            ADV();
        }

        // masukin nama ke user
        int length = currentWord.Length;
        for(int i = 0; i < length; i++){
            currentUser.name[i] = currentWord.TabWord[i];
        }

        // baca password user
        IgnoreBlanks();
        for(int i = 0; currentChar != '\n'; i++){
            currentWord.TabWord[i] = currentChar;
            currentWord.Length = i+1;
            ADV();
        }

        // masukin password ke user
        length = currentWord.Length;
        for(int i = 0; i < length; i++){
            currentUser.password[i] = currentWord.TabWord[i];
        }

        SetEl(arrayUsers, GetLastIdx(*arrayUsers), currentUser);
    }

    printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

