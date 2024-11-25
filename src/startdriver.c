#include <stdio.h>
#include "start.h"

int main() { // Fungsi untuk mencoba fungsi START
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    
    printf("Masukkan command: ");
    StartWordNewLine();

    if (compareWordToString(currentWord, "START")) {
        startStore(&arrayItems, &arrayUsers);
        
        printf("Daftar Barang:\n");
        for (int i = 0; i < Length(arrayItems); i++) {
            printf("Barang %d - ", i+1);
            printf("Harga: %d, Nama: %s\n", (Get(arrayItems, i)).price, (Get(arrayItems, i)).name);
        }
        
        printf("Daftar User:\n");
        for (int i = GetFirstIdx(arrayUsers); i <= GetLastIdx(arrayUsers); i++) {
            printf("User %d - ", i);
            printf("Uang: %d, Username: %s, Password: %s\n", (GetElmt(arrayUsers, i)).money, (GetElmt(arrayUsers, i)).name, (GetElmt(arrayUsers, i)).password);
        }
    }
}