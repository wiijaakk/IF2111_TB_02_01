#ifndef OPTIMASIRUTE_H
#define OPTIMASIRUTE_H

#include "ADT.h"

#define MAX_NODE 50

typedef int** Din_matrix;

void cari_rute(int jarak, Din_matrix graf, int node_sekarang, int jumlah_node_didatangi, int edge);

Din_matrix buatgraf(int node);

void optimasirute();

#endif