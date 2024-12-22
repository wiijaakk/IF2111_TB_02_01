#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "start.h"

int main(){
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);

    startStore(&arrayItems, &arrayUsers);
    
    barang_dibeli newBarangDibeli;
    newBarangDibeli.totalharga = 50;
    newBarangDibeli.name[0] = 'M';
    newBarangDibeli.name[1] = 'o';
    newBarangDibeli.name[2] = 't';
    newBarangDibeli.name[3] = 'o';
    newBarangDibeli.name[4] = 'r';
    newBarangDibeli.name[5] = '\0';

    PushStack(arrayUsers.TI[0].riwayat_pembelian, newBarangDibeli);
    
    save("empty.txt", &arrayItems, &arrayUsers, 9);

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