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
    filenameStr[filename.Length+1] = '\0';

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
        ADV();

        // cek jumlah barang buat dimasukin ke current word, kondisi akhir currentChar ada di karakter new line
        for(int i = 0; currentChar != '\n'; i++){
            currentWord.TabWord[i] = currentChar;
            currentWord.Length = i+1;
            ADV();
        }
        
        // simpan angka representasi jumlah barang, dapet dari hasil tambah current word
        for(int i = 0; i < currentWord.Length; i++){
            total = total * 10 + (currentWord.TabWord[i] - '0');
        }

        // looping sebanyak jumlah barang (total) untuk masukin harga barang dan nama barang
        for (int i = 0 ; i < total ; i++){
            // pembacaan word dimulai
            // cari karakter selanjutnya (retval akan pindah ke karakter selanjutnya, termasuk yg ada di line baru)
            ADV();

            for(int i = 0; currentChar != ' '; i++){
                currentWord.TabWord[i] = currentChar;
                currentWord.Length = i+1;
                ADV();
            }

            int itemPrice = 0; // simpan angka representasi jumlah barang, dapet dari hasil tambah current word
            for(i = 0; i < currentWord.Length; i++){
                itemPrice = itemPrice * 10 + (currentWord.TabWord[i] - '0');
            }

            currentBarang.price = itemPrice;

            // cek kata selanjutnya
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

            for(int i = 0; currentChar != ' '; i++){
                currentWord.TabWord[i] = currentChar;
                currentWord.Length = i+1;
                ADV();
            }

            int userMoney = 0; // simpan angka representasi uang user, dapet dari hasil tambah current word
            for(i = 0; i < currentWord.Length; i++){
                userMoney = userMoney * 10 + (currentWord.TabWord[i] - '0');
            }

            // masukin uang ke user
            currentUser.money = userMoney;

            // cek kata selanjutnya
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

            // cek kata selanjutnya
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