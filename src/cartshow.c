#include "cartshow.h"

void cartshow(ArrayDin arrayItems, Map cart) {
    if (IsEmptyMap(cart)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("Berikut adalah isi keranjang belanjamu!\n");
        printf("Kuantitas\t| Nama\t\t| Total\n");
        int totalPrice = 0;
        for (int i=0 ; i<cart.Count ; i++) {
            boolean found = false;
            int idxBarang;
            for (int j=0 ; j<arrayItems.Neff; j++) {
                if (compareStrings(cart.Elements[i].Key, arrayItems.A[j].name)) {
                    found = true;
                    idxBarang = j;
                    break;
                }
            }
            int harga = ((cart.Elements[i].Value)*arrayItems.A[idxBarang].price);
            printf("%d\t| %s\t\t| %d\n", cart.Elements[i].Value, cart.Elements[i].Key, harga);
            totalPrice += harga;
        }
        printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalPrice);
    }
}