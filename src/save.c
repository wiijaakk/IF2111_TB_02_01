#include "save.h"

// typedef struct {
//   char name[100];
//   char password[100];
//   int money;
// } User;

// typedef struct {
//   char name[100];
//   int price;
// } Barang;

// User arrayUsers[100];
// Barang arrayItems[100];
// int itemCount;
// int userCount;

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
        fprintf(file, "%d %s\n", arrayItems[i].A->price, arrayItems[i].A->name);
    }

    fprintf(file, "%d\n", NbElmt(*arrayUsers)); // Memasukkan baris Total Users
    for (int i = 0; i < NbElmt(*arrayUsers); i++) { // Memasukkan baris-baris yang menjabarkan User-User yang terdaftar dari arrayUsers
        fprintf(file, "%d %s %s\n", arrayUsers[i].TI->money, arrayUsers[i].TI->name, arrayUsers[i].TI->password);
    }

    fclose(file); // Menutup file .txt
    printf("File konfigurasi berhasil disimpan di %s\n", fullPath);
}

// int main() {
//     loadConfiguration();
//     saveConfiguration();
// }