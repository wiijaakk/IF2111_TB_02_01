#include <stdio.h>
#include <stdlib.h>
#include "storerequest.h"

void copyString(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src; // Copy each character
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

boolean cekstring(char *a, char *b, int panjang_a, int panjang_b){
    while((*a != '\0')&&(*b != '\0')){
        if(*a!=*b){
            break;
        }
        else{
            a++;
            b++;
        }
    }
    return (((*a == '\0')||(*b == '\0'))&&(panjang_a==panjang_b)); //apakah kedua string sama

}

void storerequest(ArrayDin barang, Queuebarang * request){
    printf("Nama barang yang diminta: ");
    STARTWORD();
    if(IsEmpty(barang)){
        if(isEmptybarang(*request)){
            Barang baru;
            copyString(baru.name, currentWord.TabWord);
            baru.price = 0;
            enqueuebarang(request, baru);
        }
        else{
            Queuebarang temp = *request;
            boolean sama = false;
            while(!isEmptybarang(temp)){
                Barang wait;
                dequeuebarang(&temp, &wait);
                int idx = 0;
                while(wait.name[idx]!='\0'){
                    idx++;
                }
                if(cekstring(wait.name, currentWord.TabWord, idx, currentWord.Length)){
                    sama = true;
                    printf("Barang dengan nama yang sama sudah ada di antrian!\n");
                    break;
                }
            }
            if (sama == false){
                Barang baru;
                copyString(baru.name, currentWord.TabWord);
                baru.price = 0;
                enqueuebarang (request, baru);
                printf("Barang telah berhasil dimasukkan ke dalam antrian.\n");
            }
        }
    }
    else{
        int panjang = barang.Neff;
        boolean same = false;
        for(int i = 0; i<panjang; i++){
            Barang curr = Get(barang, i);
            int idx = 0;
            while(curr.name[idx]!='\0'){
                idx++;
            }
            if(cekstring(curr.name,currentWord.TabWord, idx, currentWord.Length)){
                same = true;
                printf("Barang dengan nama yang sama sudah ada di toko!\n");
                break;
            }
        }
        if(same == false){
            Queuebarang temp = *request;
            boolean sama = false;
            while(!isEmptybarang(temp)){
                Barang wait;
                dequeuebarang(&temp, &wait);
                int idx = 0;
                while(wait.name[idx]!='\0'){
                    idx++;
                }
                if(cekstring(wait.name, currentWord.TabWord, idx, currentWord.Length)){
                    sama = true;
                    printf("Barang dengan nama yang sama sudah ada di antrian!\n");
                    break;
                }
            }
            if (sama == false){
                Barang baru;
                copyString(baru.name, currentWord.TabWord);
                baru.price = 0;
                enqueuebarang(request, baru);
                printf("Barang telah berhasil dimasukkan ke dalam antrian.\n");
            }
        }
    }
}


