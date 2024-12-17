#include <stdio.h>
#include "stack.h"

void history(Stack history, int N) {
    if (IsEmptyStack(history)) {
        printf("Kamu belum membeli barang apapun!\n");
    } else {
        printf("Riwayat pembelian barang:\n");

        // Iterasi dari elemen paling atas hingga N elemen atau sampai Stack habis
        int count = 0;
        for (int i = history.TOP; i >= 0 && count < N; i--, count++) {
            printf("%d. %s %d\n", count + 1, history.T[i].totalharga, history.T[i].name);
            count++;
        }

    }
}
