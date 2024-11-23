#include <stdio.h>
#include "kebutuhanlog.h"
#include "login.h"

int ngecek_login(const char *username, const char *password) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return 0; // Jika file tidak ditemukan
    }

    char file_username[PANJANG_UNAME_MAX];
    char file_password[PANJANG_PASS_MAX];
    char status[10];

    while (fscanf(file, "%s %s %s", file_username, file_password, status) != EOF) {
        if (strcmp(file_username, username) == 0) {
            if (strcmp(file_password, password) == 0 && strcmp(status, "OFF") == 0) {
                fclose(file);
                return 1; // Pengguna boleh login
            
            // Kasus kalau udah ada yg login
            } else if (strcmp(status, "ON") == 0) { //Status = ON artinya masih login
                fclose(file);
                return -1;
            }
        }
    }

    fclose(file);
    return 0; // Login gagal
}

void update_status(const char *username, const char *status_baru) {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    if (file == NULL || temp_file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char file_username[PANJANG_UNAME_MAX];
    char file_password[PANJANG_PASS_MAX];
    char status[10];

    while (fscanf(file, "%s %s %s", file_username, file_password, status) != EOF) {
        if (strcmp(file_username, username) == 0) { // 0 tuh kalau sama
            fprintf(temp_file, "%s %s %s\n", file_username, file_password, status_baru);
        } else {
            fprintf(temp_file, "%s %s %s\n", file_username, file_password, status);
        }
    }

    fclose(file);
    fclose(temp_file);

    // Ganti file asli dengan file sementara
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

// Fungsi untuk login pengguna
void login_User() {
    char username[PANJANG_UNAME_MAX];
    char password[PANJANG_PASS_MAX];

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    int login_status = ngecek_login(username, password);
    if (login_status == 1) {
        // Kasus karena login diperbolehkann
        update_status(username, "ON");
        printf("\nAnda telah login ke PURRMART sebagai %s.\n", username);
    // Kasus dimana pengguna uda login
    } else if (login_status == -1) {
        printf("\nPengguna dengan username %s sudah login dari perangkat lain. Silakan logout terlebih dahulu.\n", username);
    } else {
    // Kalau datanya salah / ga terdaftar --> lgsg aja buat uname password salah
        printf("\nUsername atau password salah.\n");
    }
}

// int main() {
//     printf("==== LOGIN PENGGUNA ====\n");

//     login_User();

//     return 0;
// }