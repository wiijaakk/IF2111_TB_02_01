#include "wishlist.h"


void WLadd(TabInt *arruser, int useridx, ArrayDin arrayItems,  char arg[]){
    boolean found = false;
    boolean inWL = false;
    printf("Masukkan nama barang: ");
    STARTFRASA();
    char in[100];
    copyStr(CurrentFrasa.TabWord, in);
    toupperstr(in);
    int panjang = arrayItems.Neff;
    int i = 0;
    address now = First(WL);
    while(now!=Nuh && !inWL){
        char str[100];
        copyStr(now->info, str);
        toupperstr(str);
        if(check_strV2(in, str)){
            inWL = true;
        }
        now = now->next;
    }
    while(i < panjang && !found && !inWL){
        Barang curr = Get(arrayItems, i);
        char str[100];
        copyStr(curr.name, str);
        toupperstr(str);
        if(check_strV2(in, str)){
            InsVLast(&WL, curr.name);
            printf("Berhasil menambahkan %s ke wishlish!\n", curr.name);
            found = true;
        }
        i++;
    }
    if(!inWL && !found){
        printf("Tidak ada barang dengan nama %s!\n", CurrentFrasa.TabWord);
    }else if (inWL){
        printf("%s sudah ada di wishlist!\n", CurrentFrasa.TabWord);
    }
}

void WLswap(TabInt *arruser, int useridx,  int n1, int n2){
    if(NbElmtListLinier(WL) >= n2 && n2 > 0 && n1 > 0){
        address p1 = First(WL);
        address p2 = First(WL);
        char v1[100];
        char v2[100];
        for (int i = 0; i < n1-1; i++){
            p1 = p1->next;
        }
        for (int i = 0; i < n2-1; i++){
            p2 = p2->next;
        }
        copyStr(p1->info, v1);
        copyStr(p2->info, v2);
        InsertAfter(&WL, AlokasiListLinier(v1), p2);
        InsertAfter(&WL, AlokasiListLinier(v2), p1);
        DelAddr(&WL, p1);
        DelAddr(&WL, p2);
        printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", v1, v2);
    }else if (NbElmtListLinier(WL) >= n1 && n1 > 0){
        address p = First(WL);
        for (int i = 0; i < n1-1; i++){
            p = p->next;
        }
        printf("Gagal menukar posisi %s!\n", p->info);
    }else{
        printf("Tidak ada barang pada posisi %d dan/atau %d\n", n1, n2);
    }
}

void WLremove(TabInt *arruser, int useridx){
    boolean inWL = false;
    printf("Masukkan nama barang yang akan dihapus: ");
    STARTFRASA();
    char in[100];
    copyStr(CurrentFrasa.TabWord, in);
    toupperstr(in);
    int i = 0;
    address now = First(WL);
    while(now!=Nuh && !inWL){
        char str[100];
        copyStr(now->info, str);
        toupperstr(str);
        if(check_strV2(in, str)){
            inWL = true;
        }else{
            now = now->next;
        }
    }
    if (inWL){
        printf("%s berhasil dihapus dari WISHLIST!\n", now->info);
        DelAddr(&WL, now);
    }else{
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", CurrentFrasa.TabWord);
    }
}

void WLremovei(TabInt *arruser, int useridx, int n){
    if (n <= NbElmtListLinier(WL) && n > 0){
        address p = First(WL);
        for (int i = 0; i < n-1; i++){
            p = p->next;
        }
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", n);
        DelAddr(&WL, p);
    }else if(IsEmptyListLinier(WL)){
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    }else{
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", n);
    }
}

void WLshow(TabInt *arruser, int useridx){
    if(!IsEmptyListLinier(WL)){
        printf("Berikut adalah isi wishlist-mu:\n");
        address W = First(WL);
        int i = 1;
        while(W->next!=Nuh){
            printf("%d %s\n", i,  W->info);
            W = W->next;
            i++;
        }
        printf("%d %s\n", i,  W->info);
    }else{
        printf("Wishlist kamu kosong!\n");
    }
}

void WLclear(TabInt *arruser, int useridx){
    while (!IsEmptyListLinier(WL)){
        nama_barang x;
        DelVLast(&WL, &x);
    }   
    printf("Wishlist telah dikosongkan.\n");
}


void wishlist(TabInt *arruser, int useridx, ArrayDin arrayItems,  char arg[]){
    removeFirstnString(arg, 9);
    if (check_strV2(arg, "ADD\0")){
        WLadd(arruser, useridx, arrayItems, arg);
    }else if (check_strV3(arg, "SWAP\0")){
        char arg2[50];
        removeFirstnString(arg, 5);
        copyStr(arg, arg2);
        removeLastWord(arg);
        keepLastWord(arg2);
        int n1 = stringToInteger(arg);
        int n2 = stringToInteger(arg2);
        if(n1 > n2){
            int t = n1;
            n1 = n2;
            n2 = t;
        }
        WLswap(arruser, useridx, n1, n2);
    }else if (check_strV3(arg, "REMOVE\0")){
        if (check_strV2(arg, "REMOVE\0")){
            WLremove(arruser, useridx);
        }else{
            keepLastWord(arg);
            int n = stringToInteger(arg);
            WLremovei(arruser, useridx, n);    
        }       
    }else if (check_strV2(arg, "CLEAR\0")){
        WLclear(arruser, useridx);
    }else if (check_strV2(arg, "SHOW\0")){
        WLshow(arruser, useridx);
    }else{
        printf("Command Tidak Valid\n");
    }
}