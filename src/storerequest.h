#ifndef STOREREQUEST_H
#define STOREREQUEST_H

#include "boolean.h"
#include "ADT.h"

void copyString(char *dest, const char *src);

boolean cekstring(char *a, char *b, int panjang_a, int panjang_b);

void storerequest(ArrayDin barang, Queuebarang * request);

#endif