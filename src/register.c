#include <stdio.h>
#include "kebutuhanlog.h"
#include "register.h"

// Cek apakah username udah ada atau belom
int cek_User(const char* username) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return 0; // Jika file gaada, anggap username belum ada
    }

    char file_username[PANJANG_UNAME_MAX];
    char file_password[PANJANG_PASS_MAX];
    char status[10];

    while (fscanf(file, "%s %s %s", file_username, file_password, status) != EOF) {
        if (strcmp(file_username, username) == 0) {
            fclose(file);
            return 1; // Username sudah ada
        }
    }

    fclose(file);
    return 0; // Username belum ada
}

// Registrasi pengguna
void register_User() {
    char username[PANJANG_UNAME_MAX];
    char password[PANJANG_PASS_MAX];

    printf("Username: ");
    scanf("%s", username);

    // Cek apakah username sudah ada
    if (cek_User(username)) {
        printf("\nAkun dengan username %s gagal dibuat. Silakan gunakan username lain.\n", username);
        return;
    }

    printf("Password: ");
    scanf("%s", password);

    // Data pengguna baru yang masuk disimpang sebagai --> "OFF"
    // Untuk kebutuhan login, alias dia akan berstatus off kalau belum login
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    fprintf(file, "%s %s OFF\n", username, password); // Nambahin status OFF
    fclose(file);

    printf("\nAkun dengan username %s telah berhasil dibuat.\n", username);
}

// int main() {
//     printf("==== REGISTRASI PENGGUNA ====\n");

//     // Memanggil fungsi register untuk registrasi pengguna
//     register_User();

//     return 0;
// }