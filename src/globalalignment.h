#ifndef GLOBALALIGNMENT_H
#define GLOBALALIGNMENT_H

#include "ADT.h"

#define MATCH 1      // Match score
#define MISMATCH 0   // Mismatch score
#define GAP -1       // Gap penalty

int maksi(int a, int b, int c);

int matchatautidak(char a, char b);

void globalalignment();

#endif