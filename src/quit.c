#include "quit.h"

void quit(ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command QUIT
    char input;
    boolean isTXT = false;
    
    do {
        printf("Apakah kamu ingin menyimpan data sesi kali ini (Y/N)? ");
        START(); // Menerima masukan dari pengguna
        input = currentChar;
        if ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')) { // Untuk kasus input invalid
            printf("Masukkan anda tidak valid!\n");
        }
    } while ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')); // Meminta masukan terus hingga input valid

    if (input == 'Y' || input == 'y') { // Jika pengguna menjawab yes, maka akan dilakukan SAVE pada config.txt
        while(!isTXT){
            printf("Masukkan nama save file: ");
            StartWordNewLine();
            currentWord.TabWord[currentWord.Length] = '\0';
            if(currentWord.TabWord[currentWord.Length-1] != 't' || currentWord.TabWord[currentWord.Length-2] != 'x' || currentWord.TabWord[currentWord.Length-3] != 't' || currentWord.TabWord[currentWord.Length-4] != '.'){ 
                printf("Nama save file harus dengan format .txt\n");
            }
            else{
                save(currentWord.TabWord, arrayItems, arrayUsers, currentWord.Length);
                printf("Data sesi kali ini telah berhasil disimpan!\n");
                isTXT = true;
                break;
            }
        }
    }

    printf("Anda telah keluar dari PURRMART\n"); // Menampilkan pesan pengguna berhasil keluar dari program
    printf("Sampai jumpa! Semoga datang kembali ke PURRMART!\n");
}