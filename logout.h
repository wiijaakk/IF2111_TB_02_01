#ifndef LOGOUT_H
#define LOGOUT_H

#include <stdio.h>
#include "kebutuhanlog.h"

#define PANJANG_UNAME_MAX 50
#define PANJANG_PASS_MAX 50
#define FILE_NAME "users.txt"

// Fungsi buat logout pengguna
void logout_User();

// Fungsi buat perbarui status pengguna
// Logout --> status = OFF
void updatelogout_off(const char *username, const char *status_baru);

#endif
