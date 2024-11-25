#include <stdio.h>
#include "loginwijak.h"

boolean apavalid(User users, char * username, char * password){
    int idx = 0;
    while(users.name[idx]!='\0' && *username!='\0' && users.name[idx]==*username){
        idx++;
        username++;
    }
    username--;
    if(*username!=users.name[idx]){
        return false;
    }
    idx = 0;
    while(users.password[idx]!='\0' && *password!='\0' && users.password[idx]==*password){
        idx++;
        password++;
    }
    password--;
    if(*password!=users.password[idx]){
        return false;
    }
    return true;
}

void Login_User(TabInt arrayUsers, boolean * loginStatus, char * username_sekarang){
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
        while(*username_sekarang!='\0'){
            printf("%c", username_sekarang);
            username_sekarang++;
        }
    }
    else{
        for(int i = 0; i<arrayUsers.Neff; i++){
            *loginStatus = apavalid(arrayUsers.TI[i], username, password);
            if(*loginStatus){
                int idx = 0;
                while(username[idx]!='\0'){
                    *username_sekarang = username[idx];
                    idx++;
                    username_sekarang++;
                }
                break;
            }
        }
        if(*loginStatus){
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
        }
        else{
            printf("Username atau password salah.");
        }
    }
}