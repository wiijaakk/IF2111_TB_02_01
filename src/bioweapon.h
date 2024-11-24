#ifndef BIOWEAPON_H
#define BIOWEAPON_H

#include "boolean.h"
#include "ADT.h"
#include "queuebarang.h"

boolean cek(char * a, char * b, int panjang_a, int panjang_b);

Queue protein(int awal, Queue * Q);

void torna(char * curr, int panjang);

void bioweapon(Queuebarang * request);

#endif