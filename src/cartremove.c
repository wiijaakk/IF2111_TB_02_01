#include "cartremove.h"

void cartremove(Map cart, Barang barang, int quantity) {
    if (!IsMemberMap(cart, barang.name)) {
        printf("Barang tidak ada di keranjang belanja!\n");
    } else {
        if (quantity > ValueMap(cart, barang.name)) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", ValueMap(cart,barang.name), barang);
        } else {
            DeleteMap(&cart, barang.name, quantity);
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, barang);
        }
    }
}