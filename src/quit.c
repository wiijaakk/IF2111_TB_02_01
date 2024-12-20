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
        printf("Masukkan nama save file: ");
        STARTFRASA();
        while (isTXT == false){
            if(CurrentFrasa.TabWord[CurrentFrasa.Length-1] == 't'){
                if(CurrentFrasa.TabWord[CurrentFrasa.Length-2] == 'x'){
                    if(CurrentFrasa.TabWord[CurrentFrasa.Length-3] == 't'){
                        if(CurrentFrasa.TabWord[CurrentFrasa.Length-4] == '.'){
                            save(CurrentFrasa.TabWord, arrayItems, arrayUsers);
                            printf("Data sesi kali ini telah berhasil disimpan!\n\n");
                            isTXT = true;
                        }
                        else{
                            printf("Nama file harus dengan format .txt\n");
                            printf("Masukkan nama file: ");
                            STARTFRASA();
                        }
                    }
                    else{
                        printf("Nama file harus dengan format .txt\n");
                        printf("Masukkan nama file: ");
                        STARTFRASA();
                    }
                }
                else{
                    printf("Nama file harus dengan format .txt\n");
                    printf("Masukkan nama file: ");
                    STARTFRASA();
                }
            }
            else{
                printf("Nama file harus dengan format .txt\n");
                printf("Masukkan nama file: ");
                STARTFRASA();
            }
        }
    }

    printf("Anda telah keluar dari PURRMART\n"); // Menampilkan pesan pengguna berhasil keluar dari program
    printf("Sampai jumpa! Semoga datang kembali ke PURRMART!\n");
}