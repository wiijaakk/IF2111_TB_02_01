#ifndef REGISTER_H
#define REGISTER_H

#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/array/array.h"
#include "boolean.h"

#define PANJANG_UNAME_MAX 50
#define PANJANG_PASS_MAX 50
#define FILE_NAME "users.txt"

// Fungsi buat ngecek validasi data yang dimasukkan sudah sesuai atau beloom
boolean ngecek_login(char *username, char *password);

// Fungsi buat login pengguna
void login_User();

#endif 