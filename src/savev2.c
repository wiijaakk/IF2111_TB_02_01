#include "save.h"

void save(char* fileName, ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command SAVE
    char fullPath[200];

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

            // Perlu pakai size agar bisa hitung jumlah elemen tanpa pop
            // karena save harus bisa digunakan tanpa quit
            int total = (GetElmt(*arrayUsers, i)).riwayat_pembelian->size;
            fprintf(file, "%d\n", total);

            barang_dibeli currentBarangDibeli;
            for(int i = 0; i < total; i++){
                barang_dibeli currentBarangDibeli;
                PopStack(arrayUsers->TI[i].riwayat_pembelian, &currentBarangDibeli);
                fprintf(file, "%d %s\n", currentBarangDibeli.totalharga, currentBarangDibeli.name);
            }

            total = 0;
            address currentAddress = First(*(arrayUsers->TI[i].wishlist));
            while(currentAddress != Nuh){
                total++;
                currentAddress = currentAddress->next;
            }

            currentAddress = First(*(arrayUsers->TI[i].wishlist));
            for(int i = 0; i < total; i++){
                fprintf(file, "%s\n", Info(currentAddress));
            }
        }

        fclose(file); // Menutup file .txt
        printf("File konfigurasi berhasil disimpan di %s\n", fullPath);
    }
}