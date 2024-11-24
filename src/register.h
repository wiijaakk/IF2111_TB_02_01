#ifndef REGISTER_H
#define REGISTER_H

#define PANJANG_UNAME_MAX 50
#define PANJANG_PASS_MAX 50
#define FILE_NAME "users.txt"

// Deklarasi fungsi untuk registrasi pengguna
int cek_User(const char* username);
void register_User();

#endif