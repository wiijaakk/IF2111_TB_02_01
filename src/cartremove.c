#include "cartremove.h"

void cartremove(Map cart, Barang barang, int quantity) {
    if (!IsMember(cart, &barang)) {
        printf("Barang tidak ada di keranjang belanja!\n");
    } else {
        if (quantity > ValueMap(cart, &barang)) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", Value(cart,&barang), barang);
        } else {
            DeleteMap(&cart, &barang, quantity);
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, barang);
        }
    }
}