#include <stdio.h>
#include <stdlib.h>
#include "storesupply.h"

void storesupply(ArrayDin * barang, Queuebarang * request){ // Fungsi untuk menambahkan sebuah item dari queue request ke store/toko
    Queuebarang temp;
    CreateQueuebarang(&temp);
    temp = *request;
    Barang depan;
    if(!isEmptybarang(temp)){
        dequeuebarang(&temp, &depan); // Mengambil barang di urutan pertama pada queue request
        printf("Apakah kamu ingin menambahkan barang ");
        int idx = 0;
        while(depan.name[idx]!='\0'){
            printf("%c", depan.name[idx]);
            idx++;
        }
        printf("(Terima/Tunda/Tolak): ");
        STARTWORD();
        if(cekstring(currentWord.TabWord, "Terima", currentWord.Length, 6)){ // Jika input user "Terima", akan diminta memasukkan harga, kemudian
            printf("Harga barang: ");                                        // item akan dimasukkan ke dalam store/toko
            STARTWORD();
            boolean isangka = true;
            for(int i=0; i<currentWord.Length; i++){
                if(currentWord.TabWord[i]<'0' || currentWord.TabWord[i]>'9'){
                    isangka = false;
                }
                if(!isangka){
                    printf("Angka yang kamu masukkan tidak valid.\n");
                    return;
                }
            }
            int angka = 0;
            for(int i =0; i<currentWord.Length; i++){
                int digit = currentWord.TabWord[i] - '0';
                angka = angka*10 + digit;
            }
            depan.price = angka;
            int panjang = barang->Neff;
            InsertAt(barang, depan, panjang); // Memasukkan item ke toko
            Barang buang;
            dequeuebarang(request, &buang);
            idx = 0;
            while(depan.name[idx]!='\0'){
                printf("%c", depan.name[idx]);
                idx++;
            }
            printf(" dengan harga %d telah ditambahkan ke toko.\n", depan.price);
        }
        else if (cekstring(currentWord.TabWord, "Tunda", currentWord.Length, 5)){ // Jika input user "Tunda", item akan dikembalikan ke queue request
            int idx = 0;
            while(depan.name[idx]!='\0'){
                printf("%c", depan.name[idx]);
                idx++;
            }
            Barang buang;
            dequeuebarang(request, &buang);
            enqueuebarang(request, buang);
            printf(" dikembalikan ke antrian.\n");
        }
        else if (cekstring(currentWord.TabWord, "Tolak", currentWord.Length, 5)){ // Jika input user "Tolak", item akan dihapus dari queue request
            Barang buang;
            dequeuebarang(request, &buang);
            int idx = 0;
            while(depan.name[idx]!='\0'){
                printf("%c", depan.name[idx]);
                idx++;
            }
            printf(" dihapuskan dari antrian.\n");
        }
        else{ // Untuk kasus ketika input user tidak valid
            printf("Perintah tidak valid.\n");
        }
    }
    else{ // Untuk kasus ketika tidak ada item di queue request
        printf("Tidak ada barang yang ada di antrian.\n");
    }
}