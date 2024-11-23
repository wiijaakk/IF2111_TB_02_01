#ifndef __WORKCHALLENGE_H__
#define __WORKCHALLENGE_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "str.h"
#include "mesinkata.h"

#define chal_count 2
//List Chal
//             Name             Biaya
#define chal1 "Tebak Angka",    200
#define chal2 "WORDL3",         500

typedef struct {
  char name[50];
  int biaya;
} chal;

void workChallenge();

#endif