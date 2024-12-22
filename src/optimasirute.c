#include <stdio.h>
#include "optimasirute.h"

int jarak_terkecil;
int *rute_terbaik;
int *rute;
int *kunjungi;

void cari_rute(int jarak, Din_matrix graf, int node_sekarang, int jumlah_node_didatangi, int node){
    if(jumlah_node_didatangi == node){
        if(jarak<jarak_terkecil || jarak_terkecil==-1){
            jarak_terkecil = jarak;
            for(int i = 0; i<node; i++){
                rute_terbaik[i] = rute[i];
            }
        }
        return;
    }
    for(int i = 0; i<node; i++){
        if(kunjungi[i]==0 && graf[node_sekarang][i]!=-1 && i!=node_sekarang){
            kunjungi[i] = 1;
            rute[jumlah_node_didatangi] = i;
            cari_rute(jarak+graf[node_sekarang][i], graf, i, jumlah_node_didatangi+1,node);
            kunjungi[i] = 0;
        }
    }
    return;
}

Din_matrix buatgraf(int node){
    Din_matrix adj = (int**)malloc(node*sizeof(int*));
    for(int i = 0; i<node; i++){
        adj[i] = (int*)malloc(node*sizeof(int));
        for (int j = 0; j < node; j++) {
            if(i==j){
                adj[i][j] = 0;
            }
            else{
                adj[i][j] = -1;
            }
        }
    }
    return adj;
}

void optimasirute(){
    printf("Masukkan jumlah lokasi pengiriman (node): ");
    STARTWORD();
    int idx = 0;
    int angka = 0;
    while(currentWord.TabWord[idx]!='\0'){
        if(currentWord.TabWord[idx]<'0' || currentWord.TabWord[idx]>'9'){
            printf("Jumlah yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            return;
        }
        else{
            angka++;
        }
        idx++;
    }
    if(angka==0){
        printf("Masukkan kamu kosong. Silakan coba lagi.\n");
        return;
    }
    int node = wordToInt(currentWord);
    if(node>MAX_NODE){
        printf("Jumlah lokasi pengiriman melebihi batas maksimal. Silakan coba lagi.\n");
        return;
    }
    else if(node<=0){
        printf("Jumlah lokasi pengiriman tidak valid. Silakan coba lagi.\n");
        return;
    }
    else if(node == 1){
        printf("Wah, lokasi pengiriman hanya ada 1. Tidak ada rutenya, dong:(\n");
        return;
    }
    printf("Masukkan jumlah rute (edge): ");
    STARTWORD();
    idx = 0;
    angka = 0;
    while(currentWord.TabWord[idx]!='\0'){
        if(currentWord.TabWord[idx]<'0' || currentWord.TabWord[idx]>'9'){
            printf("Jumlah yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            return;
        }
        else{
            angka++;
        }
        idx++;
    }
    if(angka==0){
        printf("Masukkan kamu kosong. Silakan coba lagi.\n");
        return;
    }
    int edge = wordToInt(currentWord);
    if(edge>((node*(node-1))/2)){
        printf("Jumlah rute melebihi batas. Silakan coba lagi. \n");
        return;
    }
    else if(edge<node-1){
        printf("Jumlah rute terlalu sedikit. Silakan coba lagi.\n");
        return;
    }
    Din_matrix adj = buatgraf(node);
    printf("Masukkan jarak antarlokasi (weight):\n");
    int i =0;
    while(i<edge){
        STARTWORD();
        idx = 0;
        angka = 0;
        int status = 1;
        int kosong = 0;
        while(currentWord.TabWord[idx]!='\0'){
            if(currentWord.TabWord[idx]<'0' || currentWord.TabWord[idx]>'9'){
                status = 0;
                break;
            }
            else{
                angka++;
            }
            idx++;
        }
        if(angka==0 && status==1){
            kosong = 1;
        }
        int asal = wordToInt(currentWord);
        STARTWORD();
        idx = 0;
        angka = 0;
        while(currentWord.TabWord[idx]!='\0'){
            if(currentWord.TabWord[idx]<'0' || currentWord.TabWord[idx]>'9'){
                status = 0;
                break;
            }
            else{
                angka++;
            }
            idx++;
        }
        if(angka==0 && status==1){
            kosong = 1;
        }
        int tujuan = wordToInt(currentWord);
        STARTWORD();
        idx = 0;
        angka = 0;
        while(currentWord.TabWord[idx]!='\0'){
            if(currentWord.TabWord[idx]<'0' || currentWord.TabWord[idx]>'9'){
                status = 0;
                break;
            }
            else{
                angka++;
            }
            idx++;
        }
        if(status == 0){
            printf("Jumlah yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            continue;
        }
        else if(angka==0 && status==1){
            printf("Masukkan kamu kosong. Silakan coba lagi.\n");
            continue;
        }
        if(kosong == 1){
            printf("Masukkan kamu kosong. Silakan coba lagi.\n");
            continue;
        }
        int jarak = wordToInt(currentWord);
        if((asal<0 || asal>=node) || (tujuan<0 || tujuan>=node)){
            printf("Node yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            continue;
        }
        if(asal==tujuan){
            printf("Kamu tidak bisa membuat jarak ke node yang sama. Silakan coba lagi.\n");
            continue;
        }
        if(jarak<=0){
            printf("Jarak yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            continue;
        }
        if(adj[asal][tujuan]!=-1 || adj[tujuan][asal]!=-1){
            printf("Anda sudah memasukkan jarak di antara kedua node ini. Silakan coba node lainnya.\n");
            continue;
        }
        else{
            adj[asal][tujuan] = jarak;
            adj[tujuan][asal] = jarak;
        }
        i++;
    }
    printf("\nData diterima, silakan tunggu.\n\n");
    rute_terbaik = (int*)malloc(node*sizeof(int));
    rute = (int*)malloc(node*sizeof(int));
    kunjungi = (int*)malloc(node*sizeof(int));
    for(int i = 0; i<node; i++){
        kunjungi[i] = 0;
    }
    rute[0] = 0;
    kunjungi[0] = 1;
    jarak_terkecil = -1;
    cari_rute(0, adj, 0, 1, node);
    if(jarak_terkecil==-1){
        printf("Tidak semua node dapat dikunjungi tepat sekali. Silakan coba lagi.\n");
    }
    else{
        printf("A-ha! Rute paling efektif adalah ");
        for(int i = 0; i<node-1; i++){
            printf("%d-", rute_terbaik[i]);
        }
        printf("%d dengan total jarak %d.\n", rute_terbaik[node-1], jarak_terkecil);
    }
}