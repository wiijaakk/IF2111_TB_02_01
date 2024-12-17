#ifndef __WISHLISH_H__
#define __WISHLISH_H__

#include <stdio.h>
#include "str.h"
#include "ADT.h"

#define WL (*((arruser[useridx].TI)->wishlist))

typedef struct {
  char name[50];
  int salary;
  int duration;
} work;

void wishlist(TabInt *arruser, int useridx, ArrayDin arrayItems,  char arg[]);

#endif