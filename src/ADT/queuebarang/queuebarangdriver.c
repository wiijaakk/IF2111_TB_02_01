#include "queuebarang.h"

int main() { // Driver mencoba fungsi ADT Queue Barang
    Queuebarang queue;
    Barang temp; // Variabel temporary untuk dequeue
    Barang A; // Mendefinisikan Barang dummy
    Barang B;
    Barang C;
    Barang D;
    Barang E;

    CreateQueuebarang(&queue); // Membuat queue kosong
    printf("%d\n", isEmptybarang(queue)); // Seharusnya print 1 karena queue masih kosong
    printf("%d\n", isFullbarang(queue)); // Seharusnya print 0 karena queue masih kosong

    enqueuebarang(&queue, A); // Mencoba enqueuebarang 5 buah elemen
    enqueuebarang(&queue, B);
    enqueuebarang(&queue, C);
    enqueuebarang(&queue, D);
    enqueuebarang(&queue, E);
    printf("%d\n", lengthbarang(queue)); // Seharusnya print 5

    dequeuebarang(&queue, &temp); // Seharusnya 'A' keluar dari queue
    dequeuebarang(&queue, &temp); // Seharusnya 'B' keluar dari queue
    printf("%d\n", lengthbarang(queue)); // Seharusnya print 5
}