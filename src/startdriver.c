/* driver_config.c */
#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "array.h"
#include "arraydin.h"
#include "start.h"

void printBarang(Barang b) {
    printf("Harga: %d, Nama: %s\n", b.price, b.name);
}

void printUser(User u) {
    printf("Uang: %d, Username: %s, Password: %s\n", u.money, u.name, u.password);
}

int main() {
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    
    // Process config file
    printf("Membaca file config.txt...\n\n");
    startStore(&arrayItems, &arrayUsers);
    
    // Print all items
    printf("\nDaftar Barang:\n");
    printf("-------------\n");
    for(int i = 0; i < Length(arrayItems); i++) {
        printf("Barang %d: ", i+1);
        printBarang(Get(arrayItems, i));
    }
    
    // Print all users
    printf("\nDaftar User:\n");
    printf("-----------\n");
    for(int i = GetFirstIdx(arrayUsers); i <= GetLastIdx(arrayUsers); i++) {
        printf("User %d: ", i+1);
        printUser(GetElmt(arrayUsers, i));
    }
}