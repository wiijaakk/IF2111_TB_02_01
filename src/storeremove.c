#include <stdio.h>
#include <stdlib.h>
#include "storeremove.h"

void storeremove(ArrayDin * barang){
    printf("Nama barang yang akan dihapus: ");
    STARTFRASA();
    int panjang = barang->Neff;
    boolean sama = false;
    for(int i = 0; i<panjang; i++){
        Barang curr = Get(*barang, i);
        int idx = 0;
        while(curr.name[idx]!='\0'){
            idx++;
        }
        if(cekstring(curr.name, CurrentFrasa.TabWord, idx, CurrentFrasa.Length)){
            DeleteAt(barang, i);
            sama = true;
            break;
        }
    }
    if (sama){
        int idx = 0;
        while(CurrentFrasa.TabWord[idx]!='\0'){
            printf("%c", CurrentFrasa.TabWord[idx]);
            idx++;
        }
        printf(" telah berhasil dihapus.\n");
    }
    else{
        printf("Toko tidak menjual ");
        int idx = 0;
        while(idx<CurrentFrasa.Length){
            printf("%c", CurrentFrasa.TabWord[idx]);
            idx++;
        }
        printf(".\n");
    }
}