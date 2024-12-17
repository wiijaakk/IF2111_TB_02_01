#include "../ADT/stack/stack.h"
#include "../ADT/setmap/map.h"
#include "../ADT/linkedlist/listlinier.h"

#ifndef USER_H
#define USER_H

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
  Map *keranjang;
  Stack *riwayat_pembelian;
  List *wishlist;
} User;

#endif