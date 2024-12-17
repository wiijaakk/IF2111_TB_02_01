#include <stdio.h>
#include "startv2.h"

void printBarang(ArrayDin arraydin){
    for(int i = 0; i < Length(arraydin); i++){
        printf("%d. %s - %d\n", (Get(arraydin, i)).price, (Get(arraydin, i)).name);
    }
}

void printUser (TabInt array){
    for (int i = GetFirstIdx(array); i <= GetLastIdx(array); i++) {
        printf("%d. Uang: %d - Username: %s - Password: %s\n", (GetElmt(array, i)).money, (GetElmt(array, i)).name, (GetElmt(array, i)).password);
    }
}

int main() {
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    
    startStore(&arrayItems, &arrayUsers);
    
    printf("Daftar Nama Barang dan Harga:\n");
    printBarang(arrayItems);
    
    printf("Daftar User:\n");
    printUser(arrayUsers);
}