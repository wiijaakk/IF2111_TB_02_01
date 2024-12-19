#include "str.h"
#include <stdlib.h>
#include <stdio.h>

void copyStr(char *in, char *out) {
    int i = 0;
    while (in[i] != '\0') {
        out[i] = in[i];
        i++;
    }
    out[i] = '\0';
}

void copyStr2(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src; // Copy each character
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int isIn(char c, char* s){
    int i = 0;
    int found = 0;
    while (s[i] != '\0' && !found)
    {
        if (c == s[i])
        {
            found = 1;
        }
        i++;
    }
    return found;
}

int check_str(char str1[], char str2[]){
    int check = 1;
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && check)
    {
        if (str1[i] != str2[i])
        {
            check = 0;
        }
        i++;
    }
    return check;    
}

int check_strV2(char str1[], char str2[]){
    int check = 1;
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && check)
    {
        if (str1[i] != str2[i])
        {
            check = 0;
        }
        i++;
    }
    if (str1[i] != '\0' || str2[i] != '\0')
    {
        check = 0;
    }
    
    return check;    
}

int check_strV3(char str1[], char str2[]){
    int check = 1;
    int i = 0;
    while (str2[i] != '\0' && check)
    {
        if (str1[i] != str2[i])
        {
            check = 0;
        }
        i++;
    }
    return check;    
}

void toupperstr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }
}

void removeFirstnString(char str[], int offset){
    int i = 0;
    while (str[i+offset] != '\0')
    {
        str[i] = str[i+offset];
        i++;
    }
    str[i] = '\0';
}

void removeLastWord(char str[]) {
    int i = strlen(str) - 1; // Mulai dari akhir string

    // Loop mundur untuk mencari spasi terakhir
    while (i >= 0 && str[i] != ' ') {
        i--;
    }

    // Jika spasi ditemukan, tambahkan null terminator setelah spasi terakhir
    if (i >= 0) {
        str[i] = '\0';
    } else {
        // Jika tidak ada spasi, kosongkan string
        str[0] = '\0';
    }
}

void keepLastWord(char str[]) {
    int i = 0, lastSpaceIndex = -1;

    // Cari posisi spasi terakhir
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            lastSpaceIndex = i;
        }
        i++;
    }

    // Jika spasi ditemukan, geser kata terakhir ke awal string
    if (lastSpaceIndex >= 0) {
        int j = 0;
        i = lastSpaceIndex + 1; // Mulai dari karakter setelah spasi terakhir
        while (str[i] != '\0') {
            str[j++] = str[i++];
        }
        str[j] = '\0'; // Tambahkan null terminator di akhir
    } 
    // Jika tidak ada spasi, string sudah hanya satu kata, tidak diubah
}

int stringToInteger(const char str[]) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Check for a sign at the start of the string
    if (str[0] == '-') {
        sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }

    // Convert the remaining characters into an integer
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0'); // Accumulate the digit
        } else {
            // If a non-numeric character is found, return 0 (or handle as needed)
            return 0;
        }
        i++;
    }

    return result * sign;
}