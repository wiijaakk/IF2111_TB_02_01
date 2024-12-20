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
    while(now!=Nuh && !inWL){ // Search barang input di wishlist
        char str[100];
        copyStr(now->info, str);
        toupperstr(str);
        if(check_strV2(in, str)){ // Case barang sudah di wishlist
            inWL = true;
        }
        now = now->next;
    }
    while(i < panjang && !found && !inWL){ // Search barang input di list barang
        Barang curr = Get(arrayItems, i);
        char str[100];
        copyStr(curr.name, str);
        toupperstr(str);
        if(check_strV2(in, str)){ // Case barang valid/ada di list barang
            InsVLast(&WL, curr.name);
            printf("Berhasil menambahkan %s ke wishlish!\n", curr.name);
            found = true;
        }
        i++;
    }
    if(!inWL && !found){ // Case barang tidak valid
        printf("Tidak ada barang dengan nama %s!\n", CurrentFrasa.TabWord);
    }else if (inWL){// Case barang sudah ada di wishlist
        printf("%s sudah ada di wishlist!\n", CurrentFrasa.TabWord);
    }
}

void WLswap(TabInt *arruser, int useridx,  int n1, int n2){
    if(NbElmtListLinier(WL) >= n2 && n2 > 0 && n1 > 0){ // Case input valid
        address p1 = First(WL);
        address p2 = First(WL);
        char v1[100];
        char v2[100];
        for (int i = 0; i < n1-1; i++){ // Ambil barang ke-n1
            p1 = p1->next;
        }
        for (int i = 0; i < n2-1; i++){// Ambil barang ke-n2
            p2 = p2->next;
        }
        copyStr(p1->info, v1);
        copyStr(p2->info, v2);
        InsertAfter(&WL, AlokasiListLinier(v1), p2); // Swaping
        InsertAfter(&WL, AlokasiListLinier(v2), p1);
        DelAddr(&WL, p1);
        DelAddr(&WL, p2);
        printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", v1, v2);
    }else if (NbElmtListLinier(WL) >= n1 && n1 > 0){ // Case salah satu input valid
        address p = First(WL);
        for (int i = 0; i < n1-1; i++){ // Ambin barang ke-n1
            p = p->next;
        }
        printf("Gagal menukar posisi %s!\n", p->info);
    }else{ // Case kedua input tidak valid atau salah satu negatif
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
    while(now!=Nuh && !inWL){ // Search barang input di wishlist
        char str[100];
        copyStr(now->info, str);
        toupperstr(str);
        if(check_strV2(in, str)){
            inWL = true;
        }else{
            now = now->next;
        }
    }
    if (inWL){ // Case barang ada di wishlist
        printf("%s berhasil dihapus dari WISHLIST!\n", now->info);
        DelAddr(&WL, now);
    }else{ // Case barang tidak ada di wishlist
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", CurrentFrasa.TabWord);
    }
}

void WLremovei(TabInt *arruser, int useridx, int n){
    if (n <= NbElmtListLinier(WL) && n > 0){ // Case input valid
        address p = First(WL);
        for (int i = 0; i < n-1; i++){ // Ambil barang ke-n
            p = p->next;
        }
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", n);
        DelAddr(&WL, p);
    }else if(IsEmptyListLinier(WL)){ // Case wishlist kososng
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    }else{ // Case input tidak valid
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", n);
    }
}

void WLshow(TabInt *arruser, int useridx){
    if(!IsEmptyListLinier(WL)){ // Case wishlist tidak kosong
        printf("Berikut adalah isi wishlist-mu:\n");
        address W = First(WL);
        int i = 1;
        while(W->next!=Nuh){ // Print setiap barang di wishlist
            printf("%d %s\n", i,  W->info);
            W = W->next;
            i++;
        }
        printf("%d %s\n", i,  W->info);
    }else{ // Case wishlist kosong
        printf("Wishlist kamu kosong!\n");
    }
}

void WLclear(TabInt *arruser, int useridx){
    while (!IsEmptyListLinier(WL)){ // Hapus barang di wishlist sampai kosong
        nama_barang x;
        DelVLast(&WL, &x);
    }   
    printf("Wishlist telah dikosongkan.\n");
}


void wishlist(TabInt *arruser, int useridx, ArrayDin arrayItems,  char arg[]){
    removeFirstnString(arg, 9); // Hapus string "WISHLIST" dari input
    if (check_strV2(arg, "ADD\0")){ // Cek input exact dengan "ADD"
        WLadd(arruser, useridx, arrayItems, arg);
    }else if (check_strV3(arg, "SWAP\0")){ // Cek input partial dengan "SWAP"
        char arg2[50];
        removeFirstnString(arg, 5); // Hapus string "SWAP" dari input
        copyStr(arg, arg2);
        removeLastWord(arg); // Ambil angka pertama
        keepLastWord(arg2); // Ambil angka kedua
        int n1 = stringToInteger(arg);
        int n2 = stringToInteger(arg2);
        if(n1 > n2){
            int t = n1;
            n1 = n2;
            n2 = t;
        }
        WLswap(arruser, useridx, n1, n2);
    }else if (check_strV3(arg, "REMOVE\0")){ // Cek input partial dengan "REMOVE"
        if (check_strV2(arg, "REMOVE\0")){ // Cek input exact dengan "REMOVE"
            WLremove(arruser, useridx);
        }else{ // Case input dengan parameter
            keepLastWord(arg); // Ambil angka
            int n = stringToInteger(arg);
            WLremovei(arruser, useridx, n);    
        }       
    }else if (check_strV2(arg, "CLEAR\0")){ // Cek input exact dengan "CLEAR"
        WLclear(arruser, useridx);
    }else if (check_strV2(arg, "SHOW\0")){ // Cek input exact dengan "SHOW"
        WLshow(arruser, useridx);
    }else{ // Case input tidak valid
        printf("Command Tidak Valid\n");
    }
}