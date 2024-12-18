#include "profile.h"

void profile(TabInt arrayUsers, int user_idx) {
    /*
    // Menampilkan nama pengguna
    printf("Nama : %s\n", username_sekarang);

    // Menampilkan saldo pengguna
    printf("Saldo : %d\n", arruser->TI[useridx].money);
    */
    
    printf("Nama     : %s\n", arrayUsers.TI[user_idx].name);
    printf("Saldo    : %d\n", arrayUsers.TI[user_idx].money);
}