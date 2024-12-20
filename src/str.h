#ifndef __STR_H__
#define __STR_H__

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int stringlen(char str[]);

void copyStr(char *in, char *out);

void copyStr2(char *dest, const char *src);

int isIn(char c, char* s);

int check_str(char str1[], char str2[]);

int check_strV2(char str1[], char str2[]);

int check_strV3(char str1[], char str2[]);

void toupperstr(char str[]);

void removeFirstnString(char str[], int offset);

void removeLastWord(char str[]);

void keepLastWord(char str[]);

int stringToInteger(const char str[]);

#endif