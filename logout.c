#include "logout.h"

// Fungsi untuk memperbarui status pengguna menjadi "OFF"
void updatelogout_off(const char *username, const char *status_baru) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Menyimpan data sementara dalam array
    char file_username[PANJANG_UNAME_MAX];
    char file_password[PANJANG_PASS_MAX];
    char status[10];
    char data[1000];  // Array untuk menampung seluruh data pengguna
    data[0] = '\0';  // Pastikan data mulai kosong
    
    // Membaca seluruh file dan menyalin data ke array
    while (fscanf(file, "%s %s %s", file_username, file_password, status) != EOF) {
        if (strcmp(status, "ON") == 0) {
            // Jika ditemukan status "ON", ubah status menjadi "OFF"
            strcpy(status, status_baru);
        }
        
        // Menyusun data kembali menjadi satu string
        char line[100];
        sprintf(line, "%s %s %s\n", file_username, file_password, status);
        strcat(data, line);  // Gabungkan dengan data yang sudah ada
    }

    fclose(file);

    // Menulis data yang telah diperbarui kembali ke file
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }

    fputs(data, file);  // Tulis seluruh data kembali ke file
    fclose(file);
}

// Fungsi untuk logout pengguna
void logout_User() {
    // Membuka file untuk memeriksa pengguna yang sedang login
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char file_username[PANJANG_UNAME_MAX];
    char file_password[PANJANG_PASS_MAX];
    char status[10];
    int found = 0;

    // Mencari pengguna yang sedang login
    while (fscanf(file, "%s %s %s", file_username, file_password, status) != EOF) {
        if (strcmp(status, "ON") == 0) {
            found = 1;
            // Temukan pengguna yang sedang login
            // Perbarui status menjadi "OFF"
            updatelogout_off(file_username, "OFF");
            printf("\nAnda telah logout dari PURRMART sebagai %s.\n", file_username);
            break;
        }
    }

    fclose(file);

    if (!found) {
        // Tidak ada pengguna yang sedang login
        printf("\nTidak ada pengguna yang sedang login.\n");
    }
}

// int main() {
//     printf("==== LOGOUT PENGGUNA ====\n");

//     logout_User();

//     return 0;
// }