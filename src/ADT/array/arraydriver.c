#include <stdio.h>
#include "array.h"

int main(){
    TabInt T;
    User arruser[100];
    MakeEmpty(&T);
    printf("Empty? %d\n", IsEmptyArr(T));
    for (int i = IdxMin; i < 100; i++)
    {
        arruser[i].money = i;
    }
    
    printf("%d\n", IsEmptyArr(T));
    for (int i = IdxMin; i < 100; i++) // Mengisi array
    {
        SetEl(&T, i, arruser[i]);
    }
    
    for (int i = IdxMin; i < 100; i++) // Mengecek isi array
    {
        printf("%d\n", GetElmt(T, i).money);
    }
    
}