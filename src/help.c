#include "help.h"

boolean sessionStatus = true;
boolean loginStatus = true;

void help(boolean sessionStatus, boolean loginStatus) {
    if (sessionStatus == false) {
        printf("================= [Selamat datang di PURRMART] ==================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. START\t\t\t\t\t\t\t|\n");
        printf("|       Untuk masuk sesi baru\t\t\t\t\t|\n");
        printf("|    2. LOAD <filename.txt>\t\t\t\t\t|\n");
        printf("|       Untuk memulai sesi berdasarkan suatu file konfigurasi\t|\n");
        printf("|    3. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    } else if (sessionStatus == true && loginStatus == false) {
        printf("================== [Login Menu Help PURRMART] ===================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. REGISTER\t\t\t\t\t\t|\n");
        printf("|       Untuk melakukan pendaftaran akun baru\t\t\t|\n");
        printf("|    2. LOGIN\t\t\t\t\t\t\t|\n");
        printf("|       Untuk masuk ke dalam akun dan memulai sesi\t\t|\n");
        printf("|    3. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    } else if (sessionStatus == true && loginStatus == true) {
        printf("================== [Main Menu Help PURRMART] ====================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. WORK\t\t\t\t\t\t\t|\n");
        printf("|       Untuk bekerja\t\t\t\t\t\t|\n");
        printf("|    2. WORK CHALLENGE\t\t\t\t\t\t|\n");
        printf("|       Untuk mengerjakan challenge\t\t\t\t|\n");
        printf("|    3. STORE LIST\t\t\t\t\t\t|\n");
        printf("|       Untuk melihat barang-barang di toko\t\t\t|\n");
        printf("|    4. STORE REQUEST\t\t\t\t\t\t|\n");
        printf("|       Untuk meminta penambahan barang\t\t\t\t|\n");
        printf("|    5. STORE REQUEST BIOWEAPON\t\t\t\t\t|\n");
        printf("|       Untuk meminta penambahan senjata biologis\t\t|\n");
        printf("|    6. STORE SUPPLY\t\t\t\t\t\t|\n");
        printf("|       Untuk menambahkan barang dari permintaan\t\t|\n");
        printf("|    7. STORE REMOVE\t\t\t\t\t\t|\n");
        printf("|       Untuk menghapus barang\t\t\t\t\t|\n");
        printf("|    8. LOGOUT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari sesi\t\t\t\t\t|\n");
        printf("|    9. SAVE <filename.txt>\t\t\t\t\t|\n");
        printf("|       Untuk menyimpan state ke dalam file\t\t\t|\n");
        printf("|    10. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    }
}

// int main() {
//     help();
// }