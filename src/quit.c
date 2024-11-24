#include "quit.h"

void quit(char* filename, ArrayDin* arrayItems, TabInt* arrayUsers) {
    char input;
    
    do {
        printf("Apakah kamu ingin menyimpan data sesi kali ini (Y/N)? ");
        START();
        input = currentChar;
        if ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')) {
            printf("Masukkan anda tidak valid!\n");
        }
    } while ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n'));

    if (input == 'Y') {
        save(filename, arrayItems, arrayUsers);
        printf("Data sesi kali ini telah berhasil disimpan!\n\n");
    }

    printf("Anda telah keluar dari PURRMART\n");
    printf("Sampai jumpa! Semoga datang kembali ke PURRMART!\n");
}

// int main() {
//     quit();
// }