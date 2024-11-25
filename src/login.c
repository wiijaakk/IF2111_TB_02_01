#include <stdio.h>
#include "login.h"

boolean apavalid(User users, char username[], char password[]){
    int idx = 0;
    while(users.name[idx]!='\0' && username[idx]!='\0' && users.name[idx]==username[idx]){
        idx++;
    }
    if(username[idx]!=users.name[idx]){
        return false;
    }
    idx = 0;
    while(users.password[idx]!='\0' && password[idx]!='\0' && users.password[idx]==password[idx]){
        idx++;
    }
    if(password[idx]!=users.password[idx]){
        return false;
    }
    return true;
}

void Login_User(TabInt arrayUsers, boolean * loginStatus, char username_sekarang[], int * username_idx){
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
    if(*loginStatus){
        printf("Anda masih tercatat sebagai ");
        int idx = 0;
        while(username_sekarang[idx]!='\0'){
            printf("%c", username_sekarang[idx]);
            idx++;
        }
        printf(". Silakan LOGOUT terlebih dahulu.\n");
    }
    else{
        for(int i = 0; i<arrayUsers.Neff; i++){
            int j = 0;
            *loginStatus = apavalid(arrayUsers.TI[i], username, password);
            if(*loginStatus){
                int idx = 0;
                while(username[idx]!='\0'){
                    username_sekarang[idx] = username[idx];
                    idx++;
                }
                *username_idx = i;
                break;
            }
        }
        if(*loginStatus){
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
        }
        else{
            printf("Username atau password salah.\n");
        }
    }
}