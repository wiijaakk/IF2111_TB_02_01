#include <stdio.h>
#include <stdlib.h>
#include "storelist.h"

void storelist(ArrayDin barang){ // Fungsi menampilkan semua item yang terdapat pada arrayItems
    if(IsEmpty(barang)){ // Jika array kosong
        printf("TOKO KOSONG\n");
    }
    else{ // Jika array memiliki isi
        int panjang = barang.Neff;
        printf("List barang yang ada di toko :\n");
        for(int i = 0; i<panjang; i++){
            Barang curr = Get(barang, i);
            printf("- ");
            int idx = 0;
            while(curr.name[idx]!='\0'){
                printf("%c", curr.name[idx]);
                idx++;
            }
            printf("\n");
        }
    }
}