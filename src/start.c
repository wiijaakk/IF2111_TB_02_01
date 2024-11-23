/* start.c */
#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "array.h"
#include "arraydin.h"
#include "start.h"

static FILE *pita;
static int retval;

void startStore(ArrayDin* arrayItems, TabInt* arrayUsers) {
    int total = 0;
    Barang currentBarang;
    User currentUser;

    // Open and process config.txt
    pita = fopen("config.txt", "r");
    
    // Read number of items (first line)
    StartFileWord(pita);

    // Convert item count to integer
    for (int i = 0; i < currentWord.Length; i++) {
        total = total * 10 + (currentWord.TabWord[i] - '0');
    }

    // Process each item
    for (int itemIdx = 0; itemIdx < total; itemIdx++) {
        // Read next character (skip newline)
        ADVFileWordNewLine();

        // Convert price to integer
        int price = 0;
        for (int i = 0; i < currentWord.Length; i++) {
            price = price * 10 + (currentWord.TabWord[i] - '0');
        }
        currentBarang.price = price;

        // Read item name
        ADVFileWordNewLine();

        // Copy name from currentWord to currentBarang
        for (int i = 0; i < currentWord.Length; i++) {
            currentBarang.name[i] = currentWord.TabWord[i];
        }
        currentBarang.name[currentWord.Length] = '\0';

        // Add item to array
        InsertLast(arrayItems, currentBarang);
    }

    // Read number of users
    ADVFileWordNewLine();

    // Convert user count to integer
    total = 0;
    for (int i = 0; i < currentWord.Length; i++) {
        total = total * 10 + (currentWord.TabWord[i] - '0');
    }

    // Process each user
    for (int userIdx = 0; userIdx < total; userIdx++) {
        // Read next character (skip newline)
        ADVFileWordSpace();

        // Convert money to integer
        int money = 0;
        for (int i = 0; i < currentWord.Length; i++) {
            money = money * 10 + (currentWord.TabWord[i] - '0');
        }
        currentUser.money = money;
        
        // Read username
        ADVFileWordSpace();

        // Copy username from currentWord to currentUser
        for (int i = 0; i < currentWord.Length; i++) {
            currentUser.name[i] = currentWord.TabWord[i];
        }
        currentUser.name[currentWord.Length] = '\0';

        // Read password
        ADVFileWordNewLine();

        // Copy password from currentWord to currentUser
        for (int i = 0; i < currentWord.Length; i++) {
            currentUser.password[i] = currentWord.TabWord[i];
        }
        currentUser.password[currentWord.Length] = '\0';

        // Add user to array
        SetEl(arrayUsers, userIdx, currentUser);
    }

    fclose(pita);
    printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}