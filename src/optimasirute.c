#include <stdio.h>
#include "optimasirute.h"

void optimasirute(){
    printf("Masukkan jumlah lokasi pengiriman (node): ");
    STARTWORD();
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
    int edge = wordToInt(currentWord);
    if(edge!=((node*(node-1))/2)){
        printf("Jumlah rute tidak menghubungkan tiap lokasi pengiriman tepat sekali. Silakan coba lagi.\n");
        return;
    }
    int adj_matrix[MAX_NODE+1][MAX_NODE+1];
    for(int i = 0; i<node; i++){
        for(int j = 0; j<node; j++){
            if(i==j){
                adj_matrix[i][j] = 0;
            }
            else{
                adj_matrix[i][j] = -1;
            }
        }
    }
    printf("Masukkan jarak antarlokasi (weight):\n");
    int i =0;
    while(i<edge){
        STARTWORD();
        int asal = wordToInt(currentWord);
        STARTWORD();
        int tujuan = wordToInt(currentWord);
        STARTWORD();
        int jarak = wordToInt(currentWord);
        if((asal<0 || asal>=node) || (tujuan<0 || tujuan>=node)){
            printf("Node yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            continue;
        }
        if(jarak<=0){
            printf("Jarak yang kamu masukkan tidak valid. Silakan coba lagi.\n");
            continue;
        }
        if(adj_matrix[asal][tujuan]!=-1 || adj_matrix[tujuan][asal]!=-1){
            printf("Anda sudah memasukkan jarak di antara kedua node ini. Silakan coba node lainnya.\n");
            continue;
        }
        else{
            adj_matrix[asal][tujuan] = jarak;
            adj_matrix[tujuan][asal] = jarak;
        }
        i++;
    }
    printf("\nData telah diterima. Silakan tunggu... :D\n\n");
    int kunjungi[MAX_NODE] = {0};
    int urutan[MAX_NODE];
    int total_jarak = 0;
    int node_sekarang = 0;
    urutan[0] = node_sekarang;
    kunjungi[node_sekarang] = 1;
    for(int j = 1; j<node; j++){
        int terdekat = -1;
        int jarak_antara = -1;
        for(int k = 0; k<node; k++){
            if((kunjungi[k]==0)&&adj_matrix[node_sekarang][k]!=0){
                if(jarak_antara==-1){
                    terdekat = k;
                    jarak_antara = adj_matrix[node_sekarang][k];
                }
                else{
                    if(jarak_antara>adj_matrix[node_sekarang][k]){
                        terdekat = k;
                        jarak_antara = adj_matrix[node_sekarang][k];
                    }
                }
            }
        }
        urutan[j] = terdekat;
        kunjungi[terdekat] = 1;
        total_jarak+=jarak_antara;
        node_sekarang = terdekat;
    }
    printf("Yay, ketemu! Rute paling efektif adalah ");
    for(int i = 0; i<node-1; i++){
        printf("%d-", urutan[i]);
    }
    printf("%d.\n", urutan[node-1]);
}