#include <stdio.h>
#include "register.h"

void Register_User(TabInt * arrayUsers){ // Fungsi untuk command REGISTER
    char username[PANJANG_UNAME_MAX];
    char password[PANJANG_PASS_MAX];
    printf("Username: ");
    STARTWORD(); // Menerima masukan Username
    for (int j = 0; j < currentWord.Length; j++) {
        username[j] = currentWord.TabWord[j];
    }
    username[currentWord.Length] = '\0';
    printf("Password: ");
    STARTWORD(); // Menerima masukan Password
    for (int j = 0; j < currentWord.Length; j++) {
        password[j] = currentWord.TabWord[j];
    }
    password[currentWord.Length] = '\0';
    boolean exist = false; // Boolean untuk pengecekan apakah username sudah ada pada array
    for(int i = 0; i<arrayUsers->Neff; i++){ // Mengecek apakah username sudah ada
        exist = apavalid(arrayUsers->TI[i], username, password);
        if(exist){
            break;
        }
    }
    if(exist){ // Kasus jika username sudah ada
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
    }
    else{ // Jika username belum dibuat
        int idx = 0;
        while(username[idx]!='\0'){
            arrayUsers->TI[arrayUsers->Neff].name[idx] = username[idx];
            idx++;
        }
        idx = 0;
        while(password[idx]!='\0'){
            arrayUsers->TI[arrayUsers->Neff].password[idx] = password[idx];
            idx++;
        }
        arrayUsers->TI[arrayUsers->Neff].money = 0;
        arrayUsers->TI[arrayUsers->Neff].riwayat_pembelian = malloc(sizeof(Stack));
        arrayUsers->TI[arrayUsers->Neff].wishlist = malloc(sizeof(List));
        arrayUsers->TI[arrayUsers->Neff].keranjang = malloc(sizeof(Map));

        CreateEmptyStack(arrayUsers->TI[arrayUsers->Neff].riwayat_pembelian);
        CreateEmptyListLinier(arrayUsers->TI[arrayUsers->Neff].wishlist);
        CreateEmptyMap(arrayUsers->TI[arrayUsers->Neff].keranjang);
        
        arrayUsers->Neff++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    }
}