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
#include "queuebarang.h"
#include "load.h"
#include "kebutuhanlog.h"
#include "help.h"
#include "bioweapon.h"
#include "boolean.h"

int main() {
    ArrayDin arrayItems;
    TabInt arrayUsers;
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    Queuebarang barang;
    CreateQueuebarang(&barang);
    boolean sessionStatus = false;
    boolean loginStatus = false;
    char filename = "config.txt";
    
    printf("Masukkan command: ");
    StartWordNewLine();

    while (!sessionStatus && !loginStatus) {
        if (compareWordToString(currentWord, "START")) {
            startStore(&arrayItems, &arrayUsers);
            sessionStatus = true;
        } else if (compareWordToString(currentWord, "LOAD")) {
            load(currentWord, &arrayItems, &arrayUsers);
            sessionStatus = true;
        } else if (compareWordToString(currentWord, "HELP")) {
            help(sessionStatus, loginStatus);
        } else if (compareWordToString(currentWord, "QUIT")) {
            printf("Program berhasil dihentikan");
            break;
        } else {
            printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            printf("Masukkan command: ");
            StartWordNewLine();
        }
    }

    printf("Masukkan command: ");
    StartWordNewLine();
    while (sessionStatus && !loginStatus) {

        if (compareWordToString(currentWord, "REGISTER")) {
            register_User();
            loginStatus = true;
        } else if (compareWordToString(currentWord, "LOGIN")) {
            login_User();
            loginStatus = true;
        } else if (compareWordToString(currentWord, "HELP")) {
            help(sessionStatus, loginStatus);
        } else if (compareWordToString(currentWord, "QUIT")) {
            printf("Program berhasil dihentikan");
            break;
        } else {
            printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            printf("Masukkan command: ");
            StartWordNewLine();
        }
    }

    printf("Masukkan command: ");
    StartWordNewLine();
    while (sessionStatus && loginStatus && !compareWordToString(currentWord, "QUIT")) {
        if (compareWordToString(currentWord, "WORK")) {
            work_();
        } else if (compareWordToString(currentWord, "WORK CHALLENGE")) {
            workChallenge();
        } else if (compareWordToString(currentWord, "STORE LIST")) {
            storelist(arrayItems);
        } else if (compareWordToString(currentWord, "STORE REQUEST")) {
            storerequest(arrayItems, &barang);
        } else if (compareWordToString(currentWord, "STORE SUPPLY")) {
            storesupply(&arrayItems, &barang);
        } else if (compareWordToString(currentWord, "STORE REMOVE")) {
            storeremove(&arrayItems);
        } else if (compareWordToString(currentWord, "LOGOUT")) {
            logout_User();
        } else if (compareWordToString(currentWord, "SAVE")) {
            save(filename, &arrayItems, &arrayUsers);
        } else if (compareWordToString(currentWord, "QUIT")) {
            quit(&arrayItems, &arrayUsers);
        } else if (compareWordToString(currentWord, "HELP")) {
            help(sessionStatus, loginStatus);
        } else {
            printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            printf("Masukkan command: ");
            StartWordNewLine();
        }
    }
}