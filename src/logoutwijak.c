#include <stdio.h>
void logout_User(char * username){
    while(*username!='\0'){
        printf("%c", *username);
        *username = '\0';
        username++;
    }
    printf(" telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n");
}