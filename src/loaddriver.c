#include <stdio.h>
#include "load.h"

int main() {
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    boolean SessionStatus;

    printf("Masukkan nama file:\n");
    StartWordNewLine();
    load(currentWord, &arrayItems, &arrayUsers, &SessionStatus);
    
    printf("Daftar Nama Barang dan Harga:\n");
    for (int i = 0; i < Length(arrayItems); i++) {
        printf("%d. Nama barang: %s, Harga: %d\n", i+1, (Get(arrayItems, i)).name), (Get(arrayItems, i)).price;
    }
    printf("\n");
    
    printf("Daftar User:\n");
    for (int i = GetFirstIdx(arrayUsers) - 1; i <= GetLastIdx(arrayUsers) - 1; i++) {
        printf("%d. Uang: %d - Username: %s - Password: %s\n", i+1, (GetElmt(arrayUsers, i)).money, (GetElmt(arrayUsers, i)).name, (GetElmt(arrayUsers, i)).password);
    }
    printf("\n");

    for (int i = 0; i < NbElmt(arrayUsers); i++) {
        printf("Daftar Riwayat Pembelian User %s:\n", arrayUsers.TI[i].name);
        barang_dibeli currentBarangDibeli;
        
        int a = 0;
        if(IsEmptyStack(*(arrayUsers.TI[i].riwayat_pembelian))){
            printf("Tidak ada riwayat pembelian.\n");
        }
        else{
            while (!IsEmptyStack(*(arrayUsers.TI[i].riwayat_pembelian))) {
                a++;
                PopStack(arrayUsers.TI[i].riwayat_pembelian, &currentBarangDibeli);
                printf("%d. Nama barang: %s, Total harga: %d\n", a, currentBarangDibeli.name, currentBarangDibeli.totalharga);
            }
        }
        printf("\n");

        printf("Daftar Wishlist User %s:\n", arrayUsers.TI[i].name);
        nama_barang currentBarangWishlist;
        address currentAddress = First(*(arrayUsers.TI[i].wishlist));

        int b = 0;
        if(currentAddress == Nuh){
            printf("Tidak ada wishlist\n");
        }
        else{
            while (currentAddress != Nuh) {
                b++;
                printf("%d. Nama barang: %s\n", b, Info(currentAddress));
                currentAddress = currentAddress->next;
            }
        }
        printf("\n");

    }

    for (int i = 0; i < NbElmt(arrayUsers); i++) {
        User *user = &(arrayUsers.TI[i]);
        free(user->riwayat_pembelian);
        free(user->wishlist);
        free(user->keranjang);
        user->riwayat_pembelian = NULL;
        user->keranjang = NULL;
        user->wishlist = NULL;
    }
}