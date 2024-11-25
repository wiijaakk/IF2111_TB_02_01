#include <stdio.h>
#include "arraydin.h"

int main(){
    ArrayDin A = MakeArrayDin();
    Barang B;
    printf("Empty?%d\n", IsEmpty(A));
    printf("Cap: %d\n", GetCapacity(A)); // Cek kapasitas
    for (int i = 0; i < 100; i++) // Menambah elemen melebihi kapasitas awal
    {
        InsertLast(&A, B);
    }
    printf("Cap: %d\n", GetCapacity(A)); // Cek kapasitas
    for (int i = 0; i < 1000; i++) // Menambah elemen melebihi kapasitas awal
    {
        InsertLast(&A, B);
    }
    printf("Cap: %d\n", GetCapacity(A)); // Cek kapasitas
    DeallocateArrayDin(&A); // Dealokasi

}