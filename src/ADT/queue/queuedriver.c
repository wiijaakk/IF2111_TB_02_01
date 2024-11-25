#include "queue.h"

int main() { // Driver mencoba fungsi ADT Queue
    Queue queue;
    char temp; // Variabel temporary untuk dequeue
    CreateQueue(&queue); // Membuat queue kosong
    printf("%d\n", isEmpty(queue)); // Seharusnya print 1 karena queue masih kosong
    printf("%d\n", isFull(queue)); // Seharusnya print 0 karena queue masih kosong

    enqueue(&queue, 'A'); // Mencoba enqueue 5 buah elemen
    enqueue(&queue, 'B');
    enqueue(&queue, 'C');
    enqueue(&queue, 'D');
    enqueue(&queue, 'E');

    displayQueue(queue); // Seharusnya menampilkan "[A,B,C,D,E]"

    printf("%d\n", length(queue)); // Seharusnya print 5

    dequeue(&queue, &temp); // Seharusnya 'A' keluar dari queue
    dequeue(&queue, &temp); // Seharusnya 'B' keluar dari queue

    displayQueue(queue); // Seharusnya menampilkan "[C,D,E]"
}