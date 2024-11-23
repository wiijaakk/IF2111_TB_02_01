#include <stdio.h>
#include <stdlib.h>
#include "load.h"

static FILE *pita;
static int retval;

void load(Word filename, ArrayDin* arrayItems, TabInt* arrayUsers) {
    int total = 0;
    Barang currentBarang;
    User currentUser;

    // ubah filename jadi string
    char filenameStr[filename.Length + 1];
    for(int i = 0; i < filename.Length; i++){
        filenameStr[i] = filename.TabWord[i];
    }
    filenameStr[filename.Length] = '\0';

    // cek apakah file ada dan bisa dibuka atau tidak
    boolean exist = true;
    FILE *file = fopen(filenameStr, "r");
    if(file){
        fclose(file);
    }
    else{
        exist = false;
    }

    // kondisi jika file bisa dibuka
    if(exist == true){
        // langkah seperti start
        pita = fopen(filenameStr, "r");
        
        // Membaca jumlah barang
        StartFileWord(pita);

        // Mengubah word menjadi integer
        for (int i = 0; i < currentWord.Length; i++) {
            total = total * 10 + (currentWord.TabWord[i] - '0');
        }

        // Memasukkan informasi barang ke arrayItems
        for (int itemIdx = 0; itemIdx < total; itemIdx++) {
            // Mulai membaca harga barang
            ADVFileWordSpace();

            // Mengubah harga menjadi integer
            int price = 0;
            for (int i = 0; i < currentWord.Length; i++) {
                price = price * 10 + (currentWord.TabWord[i] - '0');
            }
            currentBarang.price = price;

            // Mulai membaca nama barang
            ADVFileWordNewLine();

            // Mengubah nama menjadi string
            for (int i = 0; i < currentWord.Length; i++) {
                currentBarang.name[i] = currentWord.TabWord[i];
            }
            currentBarang.name[currentWord.Length] = '\0';

            // Memasukkan informasi barang ke arrayItems
            InsertLast(arrayItems, currentBarang);
        }

        // Membaca jumlah user
        ADVFileWordNewLine();

        // Mengubah word menjadi integer
        total = 0;
        for (int i = 0; i < currentWord.Length; i++) {
            total = total * 10 + (currentWord.TabWord[i] - '0');
        }

        // Memasukkan user ke arrayUsers
        for (int userIdx = 0; userIdx < total; userIdx++) {
            // Mulai membaca uang user
            ADVFileWordSpace();

            // Mengubah uang menjadi integer
            int money = 0;
            for (int i = 0; i < currentWord.Length; i++) {
                money = money * 10 + (currentWord.TabWord[i] - '0');
            }
            currentUser.money = money;
            
            // Mulai membaca nama user
            ADVFileWordSpace();

            // Mengubah nama menjadi string
            for (int i = 0; i < currentWord.Length; i++) {
                currentUser.name[i] = currentWord.TabWord[i];
            }
            currentUser.name[currentWord.Length] = '\0';

            // Mulai membaca password user
            ADVFileWordNewLine();

            // Mengubah password menjadi string
            for (int i = 0; i < currentWord.Length; i++) {
                currentUser.password[i] = currentWord.TabWord[i];
            }
            currentUser.password[currentWord.Length] = '\0';

            // Menambahkan user ke arrayUsers
            SetEl(arrayUsers, userIdx + 1, currentUser);
        }

        if(Length(*arrayItems) == 0 || NbElmt(*arrayUsers) == 0) {
            printf("File tidak memuat data yang sesuai. PURRMART gagal dijalankan\n");
        }
        else{
            printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        }
    }
    else{
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan\n");
    }
}