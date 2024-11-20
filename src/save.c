#include <stdio.h>
#include <stdlib.h>

#define SAVE_FOLDER "save/"

// typedef struct {
//   char name[100];
//   char password[100];
//   int money;
// } User;

// typedef struct {
//   char name[100];
//   int price;
// } Barang;

// User users[100];
// Barang items[100];
// int itemCount;
// int userCount;

void save(char fileName) {
    char fullPath[200];

    snprintf(fullPath, sizeof(fullPath), "%s%s", SAVE_FOLDER, fileName);

    FILE *file = fopen(fullPath, "w");
    if (!file) {
        perror("Failed to open configuration file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", itemCount);
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d %s\n", items[i].price, items[i].name);
    }

    fprintf(file, "%d\n", userCount);
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d %s %s\n", users[i].money, users[i].name, users[i].password);
    }

    fclose(file);
    printf("Configuration saved successfully to %s\n", fullPath);
}

// int main() {
//     loadConfiguration();
//     saveConfiguration();
// }