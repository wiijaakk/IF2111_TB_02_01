#include <stdio.h>
#include "register.h"

void Register_User(TabInt * arrayUsers){
    char username[PANJANG_UNAME_MAX];
    char password[PANJANG_PASS_MAX];
    printf("Username: ");
    STARTWORD();
    for (int j = 0; j < currentWord.Length; j++) {
        username[j] = currentWord.TabWord[j];
    }
    username[currentWord.Length] = '\0';
    printf("Password: ");
    STARTWORD();
    for (int j = 0; j < currentWord.Length; j++) {
        password[j] = currentWord.TabWord[j];
    }
    password[currentWord.Length] = '\0';
    boolean exist = false;
    for(int i = 0; i<arrayUsers->Neff; i++){
        exist = apavalid(arrayUsers->TI[i], username, password);
        if(exist){
            break;
        }
    }
    if(exist){
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
    }
    else{
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
        arrayUsers->Neff++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    }
}