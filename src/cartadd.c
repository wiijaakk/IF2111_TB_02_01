#include "cartadd.h"

void cartadd(ArrayDin arrayItems, Map cart, Barang barang, int quantity) {
    if (SearchArrayDin(arrayItems, barang) == -1) {
        printf("Barang tidak ada di toko!\n");
    } else {
        if (quantity == 0) {
            printf("Jumlah barang yang dimasukkan ke dalam cart tidak bisa 0!\n");
        } else if (quantity < 0) {
            printf("Barang yang dimasukkan ke dalam keranjang harus berjumlah positif!\n");
        } else {
            InsertMap(&cart, barang.name, quantity);
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, barang);
        }
    }
}