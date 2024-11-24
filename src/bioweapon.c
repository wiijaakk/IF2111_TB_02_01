#include <stdio.h>
#include "bioweapon.h"

boolean cek(char * a, char * b, int panjang_a, int panjang_b){
    boolean bool = false;
    int idx =0;
    while(idx<panjang_a){
        if(*a!=*b){
            a++;
            idx++;
        }
        else{
            char * amino = a;
            char * kode = b;
            int point = 0;
            while(*amino==*kode && point+idx<panjang_a && point<panjang_b){
                point++;
                amino++;
                kode++;
            }
            if(point==panjang_b){
                bool = true;
                break;
            }
            a++;
            idx++;
        }
    }
    return bool;
}
Queue protein(int awal, Queue * Q){
    Queue temp;
    CreateQueue(&temp);
    Queue yuh;
    CreateQueue(&yuh);
    yuh = *Q;
    while(awal>0){
        char woohoo;
        dequeue(&yuh, &woohoo);
        awal--;
    }
    char satu, dua, tiga;
    while(!isEmpty(yuh)&&length(yuh) >= 3){
        dequeue(&yuh, &satu);
        dequeue(&yuh, &dua);
        dequeue(&yuh, &tiga);
        if(satu=='U'){
            if(dua =='U'){
                if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'F');
                }
                else{
                    enqueue(&temp, 'L');
                }
            }
            else if(dua == 'C'){
                enqueue(&temp, 'S');
            }
            else if(dua == 'A'){
                if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'Y');
                }
            }
            else{
               if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'C');
                } 
                else if(tiga == 'G'){
                    enqueue(&temp, 'W');
                }
            }
        }
        else if(satu == 'C'){
            if(dua == 'U'){
                enqueue(&temp, 'L');
            }
            else if(dua =='C'){
                enqueue(&temp, 'P');
            }
            else if(dua == 'A'){
                if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'H');
                }
                else{
                    enqueue(&temp, 'Q');
                }
            }
            else{
                enqueue(&temp, 'R');
            }
        }
        else if(satu == 'A'){
            if(dua =='U'){
                if(tiga =='G'){
                    enqueue(&temp, 'M');
                }
                else{
                    enqueue(&temp, 'I');
                }
            }
            else if(dua =='C'){
                enqueue(&temp, 'T');
            }
            else if(dua =='A'){
                if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'N');
                }
                else{
                    enqueue(&temp, 'K');
                }
            }
            else{
                if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'S');
                }
                else{
                    enqueue(&temp, 'R');
                }
            }
        }
        else{
            if(dua == 'U'){
                enqueue(&temp, 'V');
            }
            else if(dua == 'C'){
                enqueue(&temp, 'A');
            }
            else if(dua == 'A'){
                if(tiga == 'U' || tiga == 'C'){
                    enqueue(&temp, 'D');
                }
                else{
                    enqueue(&temp, 'E');
                }
            }
            else{
                enqueue(&temp, 'G');
            }
        }
    }
    return temp;
}

void torna(char * curr, int panjang){
    int i =0;
    while(i<panjang){
        if(*curr == 'T'){
            *curr = 'A';
        }
        else if(*curr == 'A'){
            *curr = 'U';
        }
        else if(*curr == 'G'){
            *curr = 'C';
        }
        else{
            *curr = 'G';
        }
        curr++;
        i++;
    }
}

void bioweapon(Queuebarang * request){
    printf("Masukan nama senjata biologis: ");
    STARTFRASA();
    Barang senjata;
    for(int i = 0; i<CurrentFrasa.Length; i++){
        senjata.name[i] = CurrentFrasa.TabWord[i];
    }
    printf("Masukan sekuens DNA: ");
    STARTFRASA();
    char tampung[60];
    boolean valid = true;
    if(CurrentFrasa.Length<=60){
    }
    else{
        valid = false;
    }
    if(CurrentFrasa.Length>60){
        printf("Sekuens DNA yang kamu masukkan tidak valid. Pastikan sekuens DNA yang kamu masukkan memiliki panjang maksimal 60.\n");
    }
    else{
        for (int i = 0; i < CurrentFrasa.Length; i++) {
            tampung[i] = CurrentFrasa.TabWord[i];
        }       
        int panjang = CurrentFrasa.Length;
        torna(tampung, panjang);
        Queue rna;
        CreateQueue(&rna);
        for(int i =0; i<panjang; i++){
            enqueue(&rna, tampung[i]);
        }
        Queue hasil1, hasil2, hasil3;
        CreateQueue(&hasil1);
        CreateQueue(&hasil2);
        CreateQueue(&hasil3);
        if(panjang%3==0){
            hasil1 = protein(0, &rna);
        }
        else if(panjang%3==1){
            hasil1 = protein(0, &rna);
            hasil2 = protein(1, &rna);
        }
        else{
            hasil1 = protein(0, &rna);
            hasil2 = protein(1, &rna);
            hasil3 = protein(2, &rna);
        }
        char protein1[20];
        char protein2[20];
        char protein3[20];
        int idx1 =0;
        while(!isEmpty(hasil1)){
            dequeue(&hasil1, &protein1[idx1]);
            idx1++;
        }
        int idx2 = 0;
        while(!isEmpty(hasil2)){
            dequeue(&hasil2, &protein2[idx2]);
            idx2++;
        }
        int idx3 =0;
        while(!isEmpty(hasil3)){
            dequeue(&hasil3, &protein3[idx3]);
            idx3++;
        }
        printf("Masukan kode rahasia: ");
        STARTFRASA();
        boolean apakah_substring = false;
        apakah_substring = cek(protein1, CurrentFrasa.TabWord, idx1, CurrentFrasa.Length);
        if(!apakah_substring){
            apakah_substring = cek(protein2, CurrentFrasa.TabWord, idx2, CurrentFrasa.Length);
        }
        if(!apakah_substring){
            apakah_substring = cek(protein3, CurrentFrasa.TabWord, idx3, CurrentFrasa.Length);
        }
        if(apakah_substring){
            enqueuebarang(request, senjata);
            printf("Senjata biologis mengandung kode, barang akan ditambahkan ke dalam queue!");
        }
        else{
            printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!");
        }
    }
}