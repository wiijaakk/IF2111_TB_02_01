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

void save(Word fileName, ArrayDin* arrayItems, TabInt* arrayUsers) {
    char fullPath[200];

    snprintf(fullPath, sizeof(fullPath), "%s%s", SAVE_FOLDER, fileName);

    FILE *file = fopen(fullPath, "w");
    if (!file) {
        perror("Gagal membuka file untuk overwrite");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", Length(*arrayItems));
    for (int i = 0; i < Length(*arrayItems); i++) {
        fprintf(file, "%d %s\n", arrayItems[i].A->price, arrayItems[i].A->name);
    }

    fprintf(file, "%d\n", NbElmt(*arrayUsers));
    for (int i = 0; i < NbElmt(*arrayUsers); i++) {
        fprintf(file, "%d %s %s\n", arrayUsers[i].TI->money, arrayUsers[i].TI->name, arrayUsers[i].TI->password);
    }

    fclose(file);
    printf("File konfigurasi berhasil disimpan di %s\n", fullPath);
}

// int main() {
//     loadConfiguration();
//     saveConfiguration();
// }