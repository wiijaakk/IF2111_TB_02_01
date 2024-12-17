#include <stdio.h>
#include "load.h"

int main() {
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    boolean SessionStatus;
    
    printf("Masukkan command: ");
    StartWordNewLine;
    load(currentWord, &arrayItems, &arrayUsers, &SessionStatus);

    printf("Daftar Nama Barang dan Harga:\n");
    for(int i = 0; i < Length(arrayItems); i++){
        printf("%d. %s - %d\n", (Get(arrayItems, i)).price, (Get(arrayItems, i)).name);
    }
    
    printf("Daftar User:\n");
    for (int i = GetFirstIdx(arrayUsers); i <= GetLastIdx(arrayUsers); i++) {
        printf("%d. Uang: %d - Username: %s - Password: %s\n", (GetElmt(arrayUsers, i)).money, (GetElmt(arrayUsers, i)).name, (GetElmt(arrayUsers, i)).password);
    }
}