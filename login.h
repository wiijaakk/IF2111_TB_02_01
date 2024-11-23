#ifndef REGISTER_H
#define REGISTER_H

#define PANJANG_UNAME_MAX 50
#define PANJANG_PASS_MAX 50
#define FILE_NAME "users.txt"

// Fungsi buat login pengguna
void login_User();

// Fungsi buat ngecek validasi data yang dimasukkan sudah sesuai atau beloom
int ngecek_login(const char *username, const char *password);

// Fungsi buat memperbarui status pengguna dalam file
// Status login = ON
// Status ga login = OFF
void update_status(const char *username, const char *status_baru);

#endif 
