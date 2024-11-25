#include <stdio.h>
#include "mesinfrasa.h"

int main(){
    printf("Akan dibaca suatu frasa.\nMasukkan frasa yang ingin kamu ketikkan: ");
    STARTFRASA();
    //Pengecekan fungsi ADVFRASA() sudah termasuk dalam STARTFRASA()
    //Pengecekan fungsi CopyFrasa() sudah termasuk juga dalam STARTFRASA()
    printf("Kamu mengetikkan: %s\n", CurrentFrasa.TabWord);
    printf("Apabila kamu baru saja memasukkan satu kata saja, kita bisa coba cek apakah kata tersebut sama dengan suatu kata lain.\n");
    char cek[100];
    printf("Masukkan satu kata: ");
    STARTFRASA();
    if(compareFrasaToString(CurrentFrasa, cek)){
        printf("Kata yang baru saja kamu masukkan sama dengan frasa yang kamu masukkan di awal!\n");
    }
    else{
        printf("Kata yang baru saja kamu masukkan berbeda dengan frasa yang kamu masukkan di awal.\n");
    }
}