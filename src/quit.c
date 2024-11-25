#include "quit.h"

void quit(char* filename, ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command QUIT
    char input;
    
    do {
        printf("Apakah kamu ingin menyimpan data sesi kali ini (Y/N)? ");
        START(); // Menerima masukan dari pengguna
        input = currentChar;
        if ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')) { // Untuk kasus input invalid
            printf("Masukkan anda tidak valid!\n");
        }
    } while ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')); // Meminta masukan terus hingga input valid

    if (input == 'Y' || input == 'y') { // Jika pengguna menjawab yes, maka akan dilakukan SAVE pada config.txt
        save(filename, arrayItems, arrayUsers);
        printf("Data sesi kali ini telah berhasil disimpan!\n\n");
    }

    printf("Anda telah keluar dari PURRMART\n"); // Menampilkan pesan pengguna berhasil keluar dari program
    printf("Sampai jumpa! Semoga datang kembali ke PURRMART!\n");
}

// int main() {
//     quit();
// }