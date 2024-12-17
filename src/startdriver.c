#include <stdio.h>
#include "startv2.h"

int main() {
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    
    startStore(&arrayItems, &arrayUsers);
    
    printf("Daftar Nama Barang dan Harga:\n");
    for(int i = 0; i < Length(arrayItems); i++){
        printf("%d. %s - %d\n", (Get(arrayItems, i)).price, (Get(arrayItems, i)).name);
    }
    
    printf("Daftar User:\n");
    for (int i = GetFirstIdx(arrayUsers); i <= GetLastIdx(arrayUsers); i++) {
        printf("%d. Uang: %d - Username: %s - Password: %s\n", (GetElmt(arrayUsers, i)).money, (GetElmt(arrayUsers, i)).name, (GetElmt(arrayUsers, i)).password);
    }

    for(int i = 0; i < NbElmt(arrayUsers); i++){
        printf("Daftar Riwayat Pembelian:\n");
        barang_dibeli currentBarangDibeli;
        
        while(!IsEmptyStack){
            PopStack(&arrayUsers.TI[i].riwayat_pembelian, &currentBarangDibeli);
            printf("Nama barang: %s, Total harga: %d\n", currentBarangDibeli.name, currentBarangDibeli.totalharga);
        }

        printf("Daftar Wishlist:\n");
        nama_barang currentBarangWishlist;

        address currentAddress = First(arrayUsers.TI[i].wishlist);
        while(currentAddress != Nuh){
            printf("Nama barang: %s\n", Info(currentAddress));
            currentAddress = currentAddress->next;
        }
    }
}