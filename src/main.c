#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"

#include "start.h"
#include "login.h"
#include "logout.h"
#include "storelist.h"
#include "storeremove.h"
#include "storerequest.h"
#include "storesupply.h"
#include "str.h"
#include "save.h"
#include "register.h"
#include "quit.h"
#include "load.h"
#include "kebutuhanlog.h"
#include "help.h"
#include "bioweapon.h"
#include "boolean.h"
#include "work.h"
#include "workchallenge.h"


int main() {
    char username[PANJANG_UNAME_MAX];
    int username_idx = -1;
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    Queuebarang barang;
    CreateQueuebarang(&barang);
    boolean sessionStatus = false;
    boolean loginStatus = false;
    char filename[] = "config.txt";
    
    // startStore(&arrayItems, &arrayUsers);
    while (!sessionStatus && !loginStatus) {
        printf("Masukkan command: ");
        STARTWORD();
        printf("%s %d\n", currentWord.TabWord, EndWord);
        if (compareWordToString(currentWord, "START")) {
            startStore(&arrayItems, &arrayUsers);
            sessionStatus = true;
        } else if (compareWordToString(currentWord, "LOAD")) {
            STARTWORD();
            printf("%s\n", currentWord.TabWord);
            load(currentWord, &arrayItems, &arrayUsers, &sessionStatus);
        } else if (compareWordToString(currentWord, "HELP")) {
            help(sessionStatus, loginStatus);
        } else if (compareWordToString(currentWord, "QUIT")) {
            printf("Program berhasil dihentikan");
            break;
        } else {
            printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
        }
    }


    printf("==1\n");
    while (sessionStatus && !loginStatus) {
        printf("Masukkan command: ");
        STARTFRASA();
        printf("%s %d\n", CurrentFrasa.TabWord, EndWord);
        if (compareFrasaToString(CurrentFrasa, "REGISTER")) {
            Register_User(&arrayUsers);
        } else if (compareFrasaToString(CurrentFrasa, "LOGIN")) {
            Login_User(arrayUsers, &loginStatus, username, &username_idx);
        } else if (compareFrasaToString(CurrentFrasa, "HELP")) {
            help(sessionStatus, loginStatus);
        } else if (compareFrasaToString(CurrentFrasa, "QUIT")) {
            printf("Program berhasil dihentikan\n");
            break;
        } else {
            printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
        }
    }

    printf("==2\n");
    while (sessionStatus && loginStatus && !compareFrasaToString(CurrentFrasa, "QUIT")) {
        printf("Masukkan command: ");
        STARTFRASA();
        char forsave[50];
        copyStr(CurrentFrasa.TabWord, forsave);
        toupperstr(forsave);
        printf("%s\n", CurrentFrasa.TabWord);
        if (compareFrasaToString(CurrentFrasa, "WORK")) {
            work_(&arrayUsers, username_idx);
        } else if (compareFrasaToString(CurrentFrasa, "WORK CHALLENGE")) {
            workChallenge(&arrayUsers, username_idx);
        } else if (compareFrasaToString(CurrentFrasa, "STORE LIST")) {
            storelist(arrayItems);
        } else if (compareFrasaToString(CurrentFrasa, "STORE REQUEST")) {
            storerequest(arrayItems, &barang);
        } else if (compareFrasaToString(CurrentFrasa, "STORE REQUEST BIOWEAPON")) {
            bioweapon(&barang);
        } else if (compareFrasaToString(CurrentFrasa, "STORE SUPPLY")) {
            storesupply(&arrayItems, &barang);
        } else if (compareFrasaToString(CurrentFrasa, "STORE REMOVE")) {
            storeremove(&arrayItems);
        } else if (compareFrasaToString(CurrentFrasa, "LOGOUT")) {
            logout_User(username, &username_idx);
            loginStatus=false;
        } else if (check_str(forsave, "SAVE")) {
            removeFirstnString(CurrentFrasa.TabWord, 5);
            printf("%s\n", CurrentFrasa.TabWord);
            save(CurrentFrasa.TabWord, &arrayItems, &arrayUsers);
        } else if (compareFrasaToString(CurrentFrasa, "QUIT")) {
            quit(filename, &arrayItems, &arrayUsers);
        } else if (compareFrasaToString(CurrentFrasa, "LOGIN")){
            Login_User(arrayUsers, &loginStatus, username, &username_idx);
        } else if (compareFrasaToString(CurrentFrasa, "HELP")) {
            help(sessionStatus, loginStatus);
        } else {
            printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
        }
    }
}