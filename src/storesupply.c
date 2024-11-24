#include <stdio.h>
#include <stdlib.h>
#include "storesupply.h"

void storesupply(ArrayDin * barang, Queuebarang * request){
    Queuebarang temp;
    CreateQueuebarang(&temp);
    temp = *request;
    Barang depan;
    if(!isEmptybarang(temp)){
        dequeuebarang(&temp, &depan);
        printf("Apakah kamu ingin menambahkan barang ");
        int idx = 0;
        while(depan.name[idx]!='\0'){
            printf("%c", depan.name[idx]);
            idx++;
        }
        printf(": ");
        STARTWORD();
        if(cekstring(currentWord.TabWord, "Terima", currentWord.Length, 6)){
            printf("Harga barang: ");
            STARTWORD();
            int angka = 0;
            for(int i =0; i<currentWord.Length; i++){
                int digit = currentWord.TabWord[i] - '0';
                angka = angka*10 + digit;
            }
            depan.price = angka;
            int panjang = barang->Neff;
            InsertAt(barang, depan, panjang);
            Barang buang;
            dequeuebarang(request, &buang);
            idx = 0;
            while(depan.name[idx]!='\0'){
                printf("%c", depan.name[idx]);
                idx++;
            }
            printf(" dengan harga %d telah ditambahkan ke toko.\n", depan.price);
        }
        else if (cekstring(currentWord.TabWord, "Tunda", currentWord.Length, 5)){
            int idx = 0;
            while(depan.name[idx]!='\0'){
                printf("%c", depan.name[idx]);
                idx++;
            }
            printf(" dikembalikan ke antrian.\n");
        }
        else if (cekstring(currentWord.TabWord, "Tolak", currentWord.Length, 5)){
            Barang buang;
            dequeuebarang(request, &buang);
            int idx = 0;
            while(depan.name[idx]!='\0'){
                printf("%c", depan.name[idx]);
                idx++;
            }
            printf(" dihapuskan dari antrian.\n");
        }
        else{
            printf("Perintah tidak valid.\n");
        }
    }
    else{
        printf("Tidak ada barnag yang ada di antrian.\n");
    }
}