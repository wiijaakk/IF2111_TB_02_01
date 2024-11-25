#include "save.h"

void save(char* fileName, ArrayDin* arrayItems, TabInt* arrayUsers) {
    char fullPath[200];

    snprintf(fullPath, sizeof(fullPath), "%s%s", SAVE_FOLDER, fileName); // Menggabungkan folder (../save/) dengan filename input user

    FILE *file = fopen(fullPath, "w"); // Membuka file (jika sudah ada) untuk di-overwrite atau membuat file baru (jika file belum ada)
    if (!file) { // Ketika file gagal dibuka
        perror("Gagal membuka file untuk overwrite");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", Length(*arrayItems)); // Memasukkan baris pertama: Total Items
    for (int i = 0; i < Length(*arrayItems); i++) { // Memasukkan baris-baris yang menjabarkan Item yang ada dari arrayItems
        fprintf(file, "%d %s\n", arrayItems->A[i].price, arrayItems->A[i].name);
    }

    fprintf(file, "%d\n", NbElmt(*arrayUsers)); // Memasukkan baris Total Users
    for (int i = 0; i < NbElmt(*arrayUsers); i++) { // Memasukkan baris-baris yang menjabarkan User-User yang terdaftar dari arrayUsers
        fprintf(file, "%d %s %s\n", arrayUsers->TI[i].money, arrayUsers->TI[i].name, arrayUsers->TI[i].password);
    }

    fclose(file); // Menutup file .txt
    printf("File konfigurasi berhasil disimpan di %s\n", fullPath);
}