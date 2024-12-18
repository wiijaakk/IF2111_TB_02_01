#include "save.h"

void save(char* fileName, ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command SAVE
    char fullPath[200];
    Stack tempStack;
    CreateEmptyStack(&tempStack);

    snprintf(fullPath, sizeof(fullPath), "%s%s", SAVE_FOLDER, fileName); // Menggabungkan folder (../save/) dengan filename input user

    FILE *file = fopen(fullPath, "w"); // Membuka file (jika sudah ada) untuk di-overwrite atau membuat file baru (jika file belum ada)
    if (!file) { // Ketika file gagal dibuka
        // printf("Gagal membuka file untuk overwrite\n");
        perror("Gagal membuka file untuk write/overwrite");
        // exit(EXIT_FAILURE);
    } else {
        fprintf(file, "%d\n", Length(*arrayItems)); // Memasukkan baris pertama: Total Items
        for (int i = 0; i < Length(*arrayItems); i++) { // Memasukkan baris-baris yang menjabarkan Item yang ada dari arrayItems
            fprintf(file, "%d %s\n", arrayItems->A[i].price, arrayItems->A[i].name);
        }

        fprintf(file, "%d\n", NbElmt(*arrayUsers)); // Memasukkan baris Total Users
        for(int i = 0; i < NbElmt(*arrayUsers); i++){
            fprintf(file, "%d %s %s\n", arrayUsers->TI[i].money, arrayUsers->TI[i].name, arrayUsers->TI[i].password);

            // Perlu atribut size untuk hitung jumlah elemen
            int total = (GetElmt(*arrayUsers, i)).riwayat_pembelian->size;
            fprintf(file, "%d\n", total);
            
            // Memasukkan riwayat_pembelian user ke tempStack dahulu
            // untuk menjaga urutan penulisan barang_dibeli yang terbalik
            barang_dibeli currentBarangDibeli;
            while(!IsEmptyStack(*arrayUsers->TI[i].riwayat_pembelian)){
                PopStack(arrayUsers->TI[i].riwayat_pembelian, &currentBarangDibeli);
                PushStack(&tempStack, currentBarangDibeli);
            }

            // Memasukkan barang_dibeli ke file
            // dan memasukkannya kembali ke stack riwayat_pembelian
            // jika user tidak quit setelah save
            while(!IsEmptyStack(tempStack)){
                PopStack(&tempStack, &currentBarangDibeli);
                fprintf(file, "%d %s\n", currentBarangDibeli.totalharga, currentBarangDibeli.name);
                PushStack(arrayUsers->TI[i].riwayat_pembelian, currentBarangDibeli);
            }

            // Menghitung jumlah barang wishlist dan memasukkannya ke file
            total = 0;
            address currentAddress = First(*(arrayUsers->TI[i].wishlist));
            while(currentAddress != Nuh){
                total++;
                currentAddress = currentAddress->next;
            }
            fprintf(file, "%d\n", total);

            // Memasukkan baris nama barang di wishlist
            currentAddress = First(*(arrayUsers->TI[i].wishlist));
            for(int i = 0; i < total; i++){
                fprintf(file, "%s\n", Info(currentAddress));
                currentAddress = currentAddress->next;
            }
        }

        fclose(file); // Menutup file .txt
        printf("File konfigurasi berhasil disimpan di %s\n", fullPath);
    }
}