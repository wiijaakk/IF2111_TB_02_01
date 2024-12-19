#ifndef __WISHLISH_H__
#define __WISHLISH_H__

#include <stdio.h>
#include <stdlib.h>
#include "str.h"
#include "ADT.h"

#define WL (*arruser->TI[useridx].wishlist)

void wishlist(TabInt *arruser, int useridx, ArrayDin arrayItems,  char arg[]);

#endif