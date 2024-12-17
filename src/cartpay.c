#include "cartpay.h"


void cartpay(TabInt arrayUsers, int useridx, ArrayDin arrayItems, Map cart, Stack history) {
    if (isEmptyMap(cart)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("Kamu akan membeli barang-barang berikut:\n");
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
        printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalPrice);
        STARTFRASA();
        if (compareFrasaToString(CurrentFrasa, "Ya")) {
            if (arrayUsers.TI[useridx].money < totalPrice) {
                printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", arrayUsers.TI[useridx].money);
            } else {
                int maxprice = -1;
                Barang maxitem;
                boolean found = false;
                int idxBarang;
                for (int i=0 ; i < cart.Count ; i++) {
                    for (int j=0 ; j<arrayItems.Neff; j++) {
                        if (compareStrings(cart.Elements[i].Key, arrayItems.A[j].name)) {
                            found = true;
                            idxBarang = j;
                            break;
                        }
                    }
                    int harga = ((cart.Elements[i].Value)*arrayItems.A[idxBarang].price);
                    if (cart.Elements[i].Value > maxprice) {
                        copyStringMap(maxitem.name, cart.Elements[i].Key);
                        copyStringMap(maxitem.price, harga);
                        maxprice = harga;
                    }
                }
                Push(&history, maxitem); // Push barang dengan total harga paling mahal saja
                arrayUsers.TI[useridx].money = arrayUsers.TI[useridx].money - totalPrice;

                printf("\n");
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");
                // Beli barang, masuk histori pembelian
            }
        } else if (compareFrasaToString(CurrentFrasa, "Tidak")) {
        } else {
            printf("Input yang anda masukkan tidak valid!\n");
        }
    }
}