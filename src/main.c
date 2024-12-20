#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"

#include "startv2.h"
#include "login.h"
#include "logout.h"
#include "storelist.h"
#include "storeremove.h"
#include "storerequest.h"
#include "storesupply.h"
#include "cart.h"
#include "str.h"
#include "save.h"
#include "register.h"
#include "quit.h"
#include "load.h"
#include "kebutuhanlog.h"
#include "help.h"
#include "bioweapon.h"
#include "boolean.h"
#include "wishlist.h"
#include "work.h"
#include "workchallenge.h"
#include "history.h"
#include "profile.h"
#include "globalalignment.h"
#include "optimasirute.h"


int main() {
    char username[PANJANG_UNAME_MAX]; // Variabel menyimpan username yang sedang login di satu saat
    int username_idx = -1; // Variabel menyimpan index username yang sedang login di satu saat -> Agar dapat diakses uang dari user
    ArrayDin arrayItems; // Array dinamis untuk Barang
    TabInt arrayUsers; // Array statis untuk User
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    Queuebarang barang;
    CreateQueuebarang(&barang);
    boolean sessionStatus = false; // Variabel untuk mengecek apakah pengguna sudah START/LOAD
    boolean loginStatus = false; // Variabel untuk mengecek apakah pengguna sudah LOGIN
    
    printf("\n"); // Print banner judul ketika memulai program
    printf("                   -----------  W  E  L  C  O  M  E     T  O  ------------\n");
    printf("     __________                              _____       ____\n");
    printf("    /#|   ___  \\                            /$$|  \\     /    |\n");
    printf("   |##|  /   \\  |                           |$$|   \\   /     |\n");
    printf("   |##|  \\___/  |                           |$$|    \\_/      |                     __\n");
    printf("   |##|        / ___   __  __ ____  __ ____ |$$|  \\          | ______  __ ____  __|**|__\n");
    printf("   |##|   ----  |**|  |  |(# |  __)(# |  __)|$$|   \\___/|    ||___ **|(# |  __)(__ ***__)\n");
    printf("   |##|  |      |**|  |  ||#  .\"   |#  .\"   |$$|   |    |    |.---' *||#  .\"      | *| \n");
    printf("   |##|  |      |* '--'  ||# |     |# |     |$$|   |    |    || |##| ||# |        | *|\n");
    printf("   |##|__|      \".______.\"|__|     |__|     |$$|___|    |____|\".____.\"|__|        |__|\n");
    printf("\n");
    printf("                      y o u r   w a r   w e a p o n s   s o l u t i o n\n");
    printf("*******************************************************************************************\n");
    printf("             s e l e c t  << START >>  o r  << LOAD [file.txt] >>  o r  << HELP >>\n");
    while (!compareFrasaToString(CurrentFrasa, "QUIT")) // Program akan berjalan terus hingga user memasukkan input QUIT
    {
        while (!sessionStatus && !loginStatus) { // Loop untuk ketika pengguna belum memulai sesi (belum START atau LOAD)
            printf("Masukkan command: ");
            STARTWORD(); // Menerima masukan berupa satu kata
            if (compareWordToString(currentWord, "START")) {
                startStore(&arrayItems, &arrayUsers);
                sessionStatus = true;
            } else if (compareWordToString(currentWord, "LOAD")) {
                STARTWORD(); // Khusus untuk LOAD, jika masukan kata pertama berupa "LOAD", maka akan membaca masukan berikutnya yaitu filename
                load(currentWord, &arrayItems, &arrayUsers, &sessionStatus);
            } else if (compareWordToString(currentWord, "HELP")) {
                help(sessionStatus, loginStatus);
            } else if (compareWordToString(currentWord, "QUIT")) {
                printf("Program berhasil dihentikan.\n"); // Khusus QUIT pada fungsi ini tidak dapat melakukan SAVE, karena sesi belum dimulai
                exit(1);
            } else { // Untuk kasus input invalid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }


        //printf("==1\n");
        while (sessionStatus && !loginStatus) { // Loop untuk ketika pengguna sudah memulai sesi namun belum login
            printf("Masukkan command: ");
            STARTFRASA(); // Menerima masukan berupa semua kata pada input hingga bertemu newline
            if (compareFrasaToString(CurrentFrasa, "REGISTER")) {
                Register_User(&arrayUsers);
            } else if (compareFrasaToString(CurrentFrasa, "LOGIN")) {
                Login_User(arrayUsers, &loginStatus, username, &username_idx);
            } else if (compareFrasaToString(CurrentFrasa, "HELP")) {
                help(sessionStatus, loginStatus);
            } else if (compareFrasaToString(CurrentFrasa, "QUIT")) {
                quit(&arrayItems, &arrayUsers); // Meskipun belum login, pengguna dapat melakukan SAVE melalui QUIT, untuk menyimpan data user baru (jika ada)
                exit(1);
            } else { // Untuk kasus input invalid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }

        while (sessionStatus && loginStatus && !compareFrasaToString(CurrentFrasa, "QUIT")) { // Loop Main Menu (sudah memulai sesi dan sudah login)
            printf("Masukkan command: ");
            STARTFRASA(); // Menerima masukan berupa semua kata yang ada pada input hingga bertemu newline
            if (!check_str(CurrentFrasa.TabWord, "SAVE")) { // Khusus fungsi Cart tidak bisa dibuat kapital semua inputannya, kasus khusus
                toupperstr(CurrentFrasa.TabWord);
            }
            // PrintInfoListLinier(*arrayUsers.TI[username_idx].wishlist);
            if (compareFrasaToString(CurrentFrasa, "WORK")) {
                work_(&arrayUsers, username_idx);
            } else if (compareFrasaToString(CurrentFrasa, "WORK CHALLENGE")) {
                workChallenge(&arrayUsers, username_idx);
            } else if (compareFrasaToString(CurrentFrasa, "STORE LIST")) {
                storelist(arrayItems);
            } else if (compareFrasaToString(CurrentFrasa, "STORE REQUEST")) {
                storerequest(arrayItems, &barang);
            } else if (compareFrasaToString(CurrentFrasa, "STORE REQUEST BIOWEAPON")) {
                bioweapon(&barang, arrayItems);
            } else if (compareFrasaToString(CurrentFrasa, "STORE SUPPLY")) {
                storesupply(&arrayItems, &barang);
            } else if (compareFrasaToString(CurrentFrasa, "STORE REMOVE")) {
                storeremove(&arrayItems);
            } else if (compareFrasaToString(CurrentFrasa, "GLOBALALIGNMENT")) {
                globalalignment();
            } else if (compareFrasaToString(CurrentFrasa, "OPTIMASIRUTE")) {
                optimasirute();
            } else if (check_str(CurrentFrasa.TabWord, "WISHLIST")) {
                wishlist(&arrayUsers, username_idx, arrayItems, CurrentFrasa.TabWord);
            } else if (check_str(CurrentFrasa.TabWord, "CART")) {
                cartfunction(&arrayUsers, username_idx, arrayItems, CurrentFrasa.TabWord);
            } else if (check_str(CurrentFrasa.TabWord, "HISTORY")) {
                history(*arrayUsers.TI[username_idx].riwayat_pembelian, CurrentFrasa.TabWord);
            } else if(compareFrasaToString(CurrentFrasa, "PROFILE")) {
                profile(arrayUsers, username_idx);
            } else if (compareFrasaToString(CurrentFrasa, "LOGOUT")) {
                logout_User(username, &username_idx);
                loginStatus=false;
            } else if (check_str(CurrentFrasa.TabWord, "SAVE")) {
                removeFirstnString(CurrentFrasa.TabWord, 5); // Khusus untuk SAVE, perlu dilakukan pemisahan antara command "SAVE" dengan masukan "<filename.txt>"
                save(CurrentFrasa.TabWord, &arrayItems, &arrayUsers, CurrentFrasa.Length);
            } else if (compareFrasaToString(CurrentFrasa, "QUIT")) {
                quit(&arrayItems, &arrayUsers);
                exit(1);
            } else if (compareFrasaToString(CurrentFrasa, "LOGIN")){ // Ini dibuat untuk mengatasi kasus ketika pengguna sudah login, kemudian mencoba login lagi
                Login_User(arrayUsers, &loginStatus, username, &username_idx);
            } else if (compareFrasaToString(CurrentFrasa, "HELP")) {
                help(sessionStatus, loginStatus);
            } else { // Untuk kasus ketika input tidak valid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }
    }
}