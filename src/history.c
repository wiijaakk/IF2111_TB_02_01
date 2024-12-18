#include "history.h"

void history(Stack history, char arg[]) {
    keepLastWord(arg);
    // printf("%s\n", arg);
    int N = stringToInteger(arg);
    // printf("%d\n", arg);
    // printf("%d\n", N);
    if (IsEmptyStack(history)) {
        printf("Kamu belum membeli barang apapun!\n");
    } else {
        printf("Riwayat pembelian barang:\n");

        // Iterasi dari elemen paling atas hingga N elemen atau sampai Stack habis
        int count = 0;
        // printf("%d\n", history.TOP);
        if (N > history.TOP) {
            N = history.TOP+1;
        }
        for (int i = history.TOP; i > (history.TOP-N); i--) {
            count += 1;
            printf("%d. %s %d\n", count, history.T[i].name, history.T[i].totalharga);
        }

    }
}
