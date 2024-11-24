#include <stdio.h>
#include "boolean.h"
#include "dummylogin.h"

boolean ngecek_login(char *username, char *password) {
    User currentUser;
    boolean found = false;
    int total;

    StartFileWord("config.txt");
    total = wordToInt(currentWord);
    printf("total : %d\n", total);

    for (int i = 0; i < total; i++){
        ADVFileWordNewLine();
    }

    total = wordToInt(currentWord);
    printf("total : %d\n", total);

    for (int i = 0; i < total; i++){
        ADVFileWordSpace();
        for(int i = 0; i < currentWord.Length; i++){
            printf("%c\n", currentWord.TabWord[i]);
        }

        if(compareWordToString(currentWord, username)){
            ADVFileWordNewLine();
            if(compareWordToString(currentWord, password)){
                found = true;
                break;
            }
            else{
                ADVFileWordNewLine();
            }
        }
        else{
            ADVFileWordNewLine();
        }
    }
    return found;
}

void login_User() {
    char username[50];
    char password[50];

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

    if (ngecek_login(username, password)) {
        printf("\nAnda telah login ke PURRMART sebagai %s.\n", username);
    } else {
        printf("\nUsername atau password salah.\n");
    }
}