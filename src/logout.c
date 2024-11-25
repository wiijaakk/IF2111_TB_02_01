#include <stdio.h>
#include "logout.h"
void logout_User(char * username, int * username_idx){
    while(*username!='\0'){
        printf("%c", *username);
        *username = '\0';
        username++;
    }
    *username_idx = -1;
    printf(" telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n");
}