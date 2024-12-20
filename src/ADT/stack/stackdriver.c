#include <stdio.h>
#include "stack.h"

int main() {
    Stack myStack;
    barang_dibeli item, poppedItem;

    // Membuat Stack kosong
    CreateEmptyStack(&myStack);
    printf("%d\n", IsEmptyStack(myStack)); // Seharusnya print 1 karena Stack masih kosong
    printf("%d\n", IsFullStack(myStack)); // Seharusnya print 0 karena Stack tidak penuh

    // Menambahkan elemen pertama (Push)
    barang_dibeli item1 = {"Barang1", 50000};
    PushStack(&myStack, item1);
    printf("%d\n", IsEmptyStack(myStack)); // Seharusnya print 0 karena Stack tidak kosong
    printf("Top: %s, Total Harga: %d\n", InfoTop(myStack).name, InfoTop(myStack).totalharga); // Seharusnya print "Barang1, 50000"

    // Menambahkan elemen kedua
    barang_dibeli item2 = {"Barang2", 100000};
    PushStack(&myStack, item2);
    printf("Top: %s, Total Harga: %d\n", InfoTop(myStack).name, InfoTop(myStack).totalharga); // Seharusnya print "Barang2, 100000"

    // Menghapus elemen dari Stack (Pop)
    PopStack(&myStack, &poppedItem);
    printf("Popped: %s, Total Harga: %d\n", poppedItem.name, poppedItem.totalharga); // Seharusnya print "Barang2, 100000"
    printf("Top: %s, Total Harga: %d\n", InfoTop(myStack).name, InfoTop(myStack).totalharga); // Seharusnya print "Barang1, 50000"

    // Menghapus elemen terakhir
    PopStack(&myStack, &poppedItem);
    printf("Popped: %s, Total Harga: %d\n", poppedItem.name, poppedItem.totalharga); // Seharusnya print "Barang1, 50000"
    printf("%d\n", IsEmptyStack(myStack)); // Seharusnya print 1 karena Stack kembali kosong

    return 0;
}
