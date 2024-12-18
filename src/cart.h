#ifndef CART_H
#define CART_H

#include <stdlib.h>
#include <stdio.h>
#include "str.h"
#include "ADT.h"
#include "boolean.h"

void cartadd(TabInt *arrayUsers, int useridx, ArrayDin arrayItems, Barang barang, int quantity);

void cartpay(TabInt *arrayUsers, int useridx, ArrayDin arrayItems);

void cartremove(TabInt *arrayUsers, int useridx, Barang barang, int quantity);

void cartshow(TabInt *arrayUsers, int useridx, ArrayDin arrayItems);

void cartfunction(TabInt *arrayUsers, int useridx, ArrayDin arrayItems, char arg[]);

#endif