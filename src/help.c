#include "help.h"

boolean sessionStatus = true;
boolean loginStatus = true;

void help(boolean sessionStatus, boolean loginStatus) {
    if (sessionStatus == false) { // Menampilkan menu untuk kondisi ketika program baru saja dimulai
        printf("================= [Selamat datang di PURRMART] ==================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. START\t\t\t\t\t\t\t|\n");
        printf("|       Untuk masuk sesi baru\t\t\t\t\t|\n");
        printf("|    2. LOAD <filename.txt>\t\t\t\t\t|\n");
        printf("|       Untuk memulai sesi berdasarkan suatu file konfigurasi\t|\n");
        printf("|    3. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    } else if (sessionStatus == true && loginStatus == false) { // Menampilkan menu ketika user sudah me-load file dan memulai sesi
        printf("================== [Login Menu Help PURRMART] ===================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. REGISTER\t\t\t\t\t\t|\n");
        printf("|       Untuk melakukan pendaftaran akun baru\t\t\t|\n");
        printf("|    2. LOGIN\t\t\t\t\t\t\t|\n");
        printf("|       Untuk masuk ke dalam akun dan memulai sesi\t\t|\n");
        printf("|    3. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    } else if (sessionStatus == true && loginStatus == true) { // Menampilkan menu ketika user sudah melakukan login/register
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
        printf("|    8. GLOBALALIGNMENT\t\t\t\t\t\t|\n");
        printf("|       Untuk mengecek kesamaan antara sekuens senjata\t\t|\n");
        printf("|       biologis dengan sekuens hasil metagenomik\t\t|\n");
        printf("|    9. OPTIMASIRUTE\t\t\t\t\t\t|\n");
        printf("|       Untuk mencari cara mengirim barang dengan rute\t\t|\n");
        printf("|       yang paling efisien\t\t\t\t\t|\n");
        printf("|    10. CART ADD <nama barang> <jumlah barang>\t\t\t|\n");
        printf("|       Untuk menambahkan barang ke dalam keranjang\t\t|\n");
        printf("|    11. CART REMOVE <nama barang> <jumlah barang>\t\t|\n");
        printf("|       Untuk mengurangi/menghapus barang dari keranjang\t|\n");
        printf("|    12. CART SHOW\t\t\t\t\t\t|\n");
        printf("|       Untuk menampilkan barang yang ada di keranjang\t\t|\n");
        printf("|    13. CART PAY\t\t\t\t\t\t|\n");
        printf("|       Untuk membeli barang yang ada di keranjang\t\t|\n");
        printf("|    14. WISHLIST ADD\t\t\t\t\t\t|\n");
        printf("|       Untuk menambahkan barang ke dalam wishlist\t\t|\n");
        printf("|    15. WISHLIST SWAP <i> <j>\t\t\t\t\t|\n");
        printf("|       Untuk menukar posisi dua barang pada wishlist\t\t|\n");
        printf("|    16. WISHLIST REMOVE <i>\t\t\t\t\t|\n");
        printf("|       Untuk menghapus sebuah barang pada wishlist\t\t|\n");
        printf("|       berdasarkan posisi barang di wishlist\t\t\t|\n");
        printf("|    17. WISHLIST REMOVE\t\t\t\t\t|\n");
        printf("|       Untuk menghapus sebuah barang pada wishlist\t\t|\n");
        printf("|       berdasarkan nama barang\t\t\t\t\t|\n");
        printf("|    18. WISHLIST CLEAR\t\t\t\t\t\t|\n");
        printf("|       Untuk menghapus semua barang pada wishlist\t\t|\n");
        printf("|    19. WISHLIST SHOW\t\t\t\t\t\t|\n");
        printf("|       Untuk melihat semua barang pada wishlist\t\t|\n");
        printf("|    20. HISTORY <n>\t\t\t\t\t\t|\n");
        printf("|       Untuk menampilkan n riwayat pembelian terakhir\t\t|\n");
        printf("|    21. PROFILE\t\t\t\t\t\t|\n");
        printf("|       Untuk menampilkan data diri user\t\t\t|\n");
        printf("|    22. LOGOUT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari sesi\t\t\t\t\t|\n");
        printf("|    23. SAVE <filename.txt>\t\t\t\t\t|\n");
        printf("|       Untuk menyimpan state ke dalam file\t\t\t|\n");
        printf("|    24. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    }
}

// int main() {
//     help();
// }