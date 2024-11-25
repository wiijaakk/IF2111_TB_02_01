#ifndef LOGINWIJAK_H
#define LOGINWIJAK_H

#include "mesinkarakter.h"
#include "mesinkata.h"
#include "ADT.h"

#define PANJANG_UNAME_MAX 50
#define PANJANG_PASS_MAX 50

boolean apavalid(User users, char * username, char * password);

void Login_User(TabInt arrayUsers, boolean * loginStatus, char * username_sekarang);

#endif