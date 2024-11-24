#include "quit.h"
#include "save.h"

void quit(Word filename, ArrayDin* arrayItems, TabInt* arrayUsers) {
    char input;

    do {
        printf("Apakah kamu ingin menyimpan data sesi kali ini (Y/N)? ");
        scanf(" %c", &input);
        if (input != 'Y' && input != 'N') {
            printf("Masukkan anda tidak valid!\n");
        }
    } while (input != 'Y' && input != 'N');

    if (input == 'Y') {
        save(filename.TabWord, arrayItems, arrayUsers);
        printf("Data sesi kali ini telah berhasil disimpan!\n\n");
    }

    printf("Anda telah keluar dari PURRMART\n");
    printf("Sampai jumpa! Semoga datang kembali ke PURRMART!\n");
}

// int main() {
//     quit();
// }