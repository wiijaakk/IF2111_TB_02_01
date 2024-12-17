#include <stdio.h>
#include "user.h"

void profile(User user) {
    /*
    // Menampilkan nama pengguna
    printf("Nama : %s\n", username_sekarang);

    // Menampilkan saldo pengguna
    printf("Saldo : %d\n", arruser->TI[useridx].money);
    */
    
    printf("Nama     : %s\n", user.name);
    printf("Saldo    : %d\n", user.money);
}