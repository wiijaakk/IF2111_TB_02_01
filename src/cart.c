#include "cart.h"

void cartadd(TabInt *arrayUsers, int useridx, ArrayDin arrayItems, Barang barang, int quantity) { // Fungsi CART ADD
    boolean found = false;
    Barang curr2;
    for (int i=0 ; i<arrayItems.Neff ; i++) {       // For loop mengecek apakah barang ada pada toko
        Barang curr = Get(arrayItems, i);
        char str[50];
        char in[50];
        copyStr2(str, curr.name);
        copyStr2(in, barang.name);
        toupperstr(str);
        toupperstr(in);
        if (check_strV2(str, in)) {
            found = true;
            copyStr2(curr2.name, curr.name);
        }
    }
    if (quantity == 0) { // Kasus jika masukan angka nol atau kosong
        printf("Masukan angka tidak boleh kosong!\n");
    } else if (!found) { // Jika barang tidak ada di toko
        printf("Barang tidak ada di toko!\n");
    } else { // Jika barang ada di toko
        if (quantity < 0) { // Kasus quantity bilangan negatif
            printf("Barang yang dimasukkan ke dalam keranjang harus berjumlah positif!\n");
        } else { // Kasus normal (quantity positif)
            InsertMap(arrayUsers->TI[useridx].keranjang, curr2.name, quantity);

            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, curr2.name);
        }
    }
}

void cartpay(TabInt *arrayUsers, int useridx, ArrayDin arrayItems) { // Fungsi CART PAY
    if (IsEmptyMap(*arrayUsers->TI[useridx].keranjang)) { // Kasus keranjang kosong
        printf("Keranjang kamu kosong!\n");
    } else { // Kasus normal (ada barang di keranjang)
        printf("Kamu akan membeli barang-barang berikut:\n");
        printf("Kuantitas\t| Nama\t\t\t\t| Total\n");
        int totalPrice = 0; // Variabel untuk total harga semua barang di keranjang
        for (int i=0 ; i< arrayUsers->TI[useridx].keranjang->Count ; i++) { // For loop untuk iterasi setiap barang di keranjang
            boolean found = false;
            int idxBarang;
            for (int j=0 ; j<arrayItems.Neff; j++) { // For loop untuk mencari barang pada arrayItems (supaya dapat diakses harganya)
                if (compareStrings(arrayUsers->TI[useridx].keranjang->Elements[i].Key, arrayItems.A[j].name) == 0) {
                    found = true;
                    idxBarang = j;
                    break;
                }
            }
            int harga = ((arrayUsers->TI[useridx].keranjang->Elements[i].Value)*arrayItems.A[idxBarang].price); // Menghitung harga barang yang dibeli
            if (stringlen(arrayUsers->TI[useridx].keranjang->Elements[i].Key) <= 5) { // Jika nama barang kurang dari sama dengan 5 karakter
                printf("%d\t\t| %s\t\t\t\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            } else if (stringlen(arrayUsers->TI[useridx].keranjang->Elements[i].Key) <= 11) { // Jika nama barang kurang dari sama dengan 11 karakter
                printf("%d\t\t| %s\t\t\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            } else if (stringlen(arrayUsers->TI[useridx].keranjang->Elements[i].Key) <= 21) { // Jika nama barang kurang dari sama dengan 21 karakter
                printf("%d\t\t| %s\t\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            } else { // Jika nama barang lebih dari 21 karakter
                printf("%d\t\t| %s\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            }
            totalPrice += harga;
        }
        printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalPrice);
        STARTFRASA(); // Menerima input pengguna
        if (check_strV2(CurrentFrasa.TabWord, "Ya")) { // Jika "Ya"
            if (arrayUsers->TI[useridx].money < totalPrice) { // Kasus uang pengguna kurang dari harga total di keranjang
                printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", arrayUsers->TI[useridx].money);
            } else { // Kasus normal (uang cukup)
                int maxprice = -1; // Variabel untuk mencari barang dengan harga termahal di keranjang
                barang_dibeli maxitem; // Variabel barang yang memiliki harga tertinggi/termahal
                int idx_maxitem;
                boolean found = false;
                int idxBarang;
                for (int i=0 ; i < arrayUsers->TI[useridx].keranjang->Count ; i++) { // For loop untuk iterasi setiap barang di keranjang
                    for (int j=0 ; j<arrayItems.Neff; j++) { // For loop untuk mencari barang di toko (supaya dapat mengakses harga barang)
                        if (compareStrings(arrayUsers->TI[useridx].keranjang->Elements[i].Key, arrayItems.A[j].name) == 0) {
                            found = true;
                            idxBarang = j;
                            break;
                        }
                    }
                    int harga = ((arrayUsers->TI[useridx].keranjang->Elements[i].Value)*arrayItems.A[idxBarang].price); // Menghitung harga barang
                    if (harga > maxprice) { // Jika menemukan barang dengan harga lebih tinggi
                        copyStr2(maxitem.name, arrayUsers->TI[useridx].keranjang->Elements[i].Key);
                        maxprice = harga;
                        idx_maxitem = i;
                    } else if (harga == maxprice) { // Kasus jika total harga dua buah barang sama
                        int iteration = 0; // Variabel untuk iterasi perbandingan huruf per huruf
                        char currMaxItem[50];
                        char currItem[50];
                        copyStr2(currMaxItem, maxitem.name);
                        copyStr2(currItem, arrayUsers->TI[useridx].keranjang->Elements[i].Key);
                        toupperstr(currMaxItem); // Dua barang dibuat kapital
                        toupperstr(currItem);

                        while (currMaxItem[iteration] == currItem[iteration]) { // Loop hingga menemukan huruf yang berbeda pada kedua barang
                            iteration++;
                        }
                        if (currItem[iteration] > currMaxItem[iteration]) { // Jika lexical order barang pada indeks i lebih besar dari barang yang ada di maxItem
                            copyStringMap(maxitem.name, arrayUsers->TI[useridx].keranjang->Elements[i].Key); // maxitem berubah ke barang di indeks i
                            idx_maxitem = i; // indeks max item juga berubah ke barang di indeks i
                        }
                    }
                }
                maxitem.totalharga = totalPrice; // Harga yang dimasukkan ke riwayat pembelian adalah total harga pada pembelian keranjang tersebut
                PushStack(arrayUsers->TI[useridx].riwayat_pembelian, maxitem); // Push barang dengan total harga paling mahal saja
                arrayUsers->TI[useridx].money = arrayUsers->TI[useridx].money - totalPrice; // Mengurangi uang pengguna

                while(!IsEmptyMap(*arrayUsers->TI[useridx].keranjang)) {
                    DeleteMap(arrayUsers->TI[useridx].keranjang, arrayUsers->TI[useridx].keranjang->Elements[0].Key, arrayUsers->TI[useridx].keranjang->Elements[0].Value);
                }

                printf("\n");
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            }
        } else if (check_strV2(CurrentFrasa.TabWord, "Tidak")) { // Jika "Tidak"
            printf("Proses pembelian dibatalkan.\n");
        } else { // Jika input tidak valid (selain "Ya" dan "Tidak")
            printf("Input yang anda masukkan tidak valid!\n");
        }
    }
}

void cartremove(TabInt *arrayUsers, int useridx, Barang barang, int quantity) { // Fungsi utama CART REMOVE
    boolean found = false;
    Barang curr;
    for (int i=0; i<arrayUsers->TI[useridx].keranjang->Count; i++) { // For loop mencari barang di keranjang
        char str[50];
        char in[50];
        copyStr2(str, arrayUsers->TI[useridx].keranjang->Elements[i].Key);
        copyStr2(in, barang.name);
        toupperstr(str);
        toupperstr(in);
        if (check_str(str, in)) {
            found = true;
            copyStr2(curr.name, arrayUsers->TI[useridx].keranjang->Elements[i].Key);
        }
    }
    if (!found) { // Kasus barang tidak ada di keranjang
        printf("Barang tidak ada di keranjang belanja!\n");
    } else { // Kasus normal (barang ada di keranjang)
        if (quantity <= 0) { // Kasus input quantity 0 atau bilangan negatif
            printf("Tidak berhasil mengurangi, masukan angka harus positif!\n");
        } else if (quantity > ValueMap(*arrayUsers->TI[useridx].keranjang, curr.name)) { // Kasus input quantity melebihi banyak barangnya di keranjang
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", ValueMap(*arrayUsers->TI[useridx].keranjang, barang.name), curr.name);
        } else { // Kasus normal (input quantity positif dan tidak melebihi banyak barangnya yang ada di keranjang)
            DeleteMap(arrayUsers->TI[useridx].keranjang, curr.name, quantity);
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, curr.name);
        }
    }
}

void cartshow(TabInt *arrayUsers, int useridx, ArrayDin arrayItems) { // Fungsi CART SHOW
    if (IsEmptyMap(*arrayUsers->TI[useridx].keranjang)) { // Kasus keranjang kosong
        printf("Keranjang kamu kosong!\n");
    } else { // Kasus normal (ada barang di keranjang)
        printf("Berikut adalah isi keranjang belanjamu!\n");
        printf("Kuantitas\t| Nama\t\t\t\t| Total\n");
        int totalPrice = 0; // Variabel total harga semua barang yang ada di keranjang
        for (int i=0 ; i<arrayUsers->TI[useridx].keranjang->Count ; i++) { // For loop iterasi semua barang di keranjang
            boolean found = false;
            int idxBarang;
            for (int j=0 ; j<arrayItems.Neff; j++) { // For loop untuk mencari barang di toko (supaya dapat mengakses harga barang)
                if (compareStrings(arrayUsers->TI[useridx].keranjang->Elements[i].Key, arrayItems.A[j].name) == 0) {
                    found = true;
                    idxBarang = j;
                    break;
                }
            }
            int harga = ((arrayUsers->TI[useridx].keranjang->Elements[i].Value)*arrayItems.A[idxBarang].price); // Menghitung harga barang
            if (stringlen(arrayUsers->TI[useridx].keranjang->Elements[i].Key) <= 5) { // Jika nama barang kurang dari sama dengan 5 karakter
                printf("%d\t\t| %s\t\t\t\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            } else if (stringlen(arrayUsers->TI[useridx].keranjang->Elements[i].Key) <= 11) { // Jika nama barang kurang dari sama dengan 11 karakter
                printf("%d\t\t| %s\t\t\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            } else if (stringlen(arrayUsers->TI[useridx].keranjang->Elements[i].Key) <= 21) { // Jika nama barang kurang dari sama dengan 21 karakter
                printf("%d\t\t| %s\t\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            } else { // Jika nama barang lebih dari 21 karakter
                printf("%d\t\t| %s\t| %d\n", arrayUsers->TI[useridx].keranjang->Elements[i].Value, arrayUsers->TI[useridx].keranjang->Elements[i].Key, harga);
            }
            totalPrice += harga;
        }
        printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalPrice);
    }
}

void cartfunction(TabInt *arrayUsers, int useridx, ArrayDin arrayItems, char arg[]) { // Fungsi utama untuk menu CART
    removeFirstnString(arg, 5);         // Memotong "CART " dari frasa
    if (check_str(arg, "ADD\0")) {      // Apabila pada frasa mengandung "ADD", maka masuk ke fungsi CART ADD
        Barang barang;
        removeFirstnString(arg, 4);     // Memotong "ADD " dari frasa
        char arg2[100];
        copyStr2(arg2, arg);            // Menduplikat frasa
        removeLastWord(arg);            // Frasa 1: dihapus digit angka setelah nama barangnya
        copyStr2(barang.name, arg);     // Mengisi barang.nama dengan Frasa 1
        keepLastWord(arg2);             // Frasa 2: dihapus semua kata yang ada sebelum digit angka
        int quantity = stringToInteger(arg2); // Konversi string ke integer untuk quantity
        cartadd(arrayUsers, useridx, arrayItems, barang, quantity); // Memanggil fungsi CART ADD
    } else if (check_str(arg, "REMOVE\0")) { // Apabila frasa mengandung "REMOVE", maka masuk ke fungsi CART REMOVE
        Barang barang;
        removeFirstnString(arg, 7);     // Memotong "REMOVE " dari frasa
        char arg2[100];
        copyStr2(arg2, arg);            // Menduplikat frasa
        removeLastWord(arg);            // Frasa 1: dihapus digit angka setelah nama barangnya
        copyStr2(barang.name, arg);     // Mengisi barang.nama dengan frasa 1
        keepLastWord(arg2);             // Frasa 2: dihapus semua kata yang ada sebelum digit angka
        int quantity = stringToInteger(arg2); // Konversi string ke integer untuk quantity
        cartremove(arrayUsers, useridx, barang, quantity); // Memanggil fungsi CART REMOVE
    } else if (check_strV2(arg, "SHOW\0")) {        // Apabila keseluruhan frasa sama dengan "SHOW", maka masuk fungsi CART SHOW
        cartshow(arrayUsers, useridx, arrayItems);  // Memanggil fungsi CART SHOW
    } else if (check_strV2(arg, "PAY\0")) {         // Apabila keseluruhan frasa sama dengan "PAY", maka masuk fungsi CART PAY
        cartpay(arrayUsers, useridx, arrayItems);   // Memanggil fungsi CART PAY
    } else {    // Kasus input/command tidak valid
        printf("Perintah yang anda masukkan tidak valid!\n");
    }
}