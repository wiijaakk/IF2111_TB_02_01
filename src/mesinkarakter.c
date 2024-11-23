#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
boolean endOfFile;

static FILE *pita;
static int retval;

void START() {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* DIGUNAKAN UNTUK MEMBACA DARI INPUT PENGGUNA */
    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* DIGUNAKAN UNTUK MEMBACA INPUT DARI PENGGUNA */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}

void StartReadFile(FILE* input){
    /* DIGUNAKAN UNTUK MEMBACA FILE */
    pita = input;
    ADVFile();
    if (endOfFile) {
        printf("File yang Anda ingin buka isinya kosong.\n");
        fclose(pita);
    }
}

void ADVFile() {
    /* Pita dimajukan satu karakter. ... */
    /* DIGUNAKAN UNTUK MEMBACA FILE */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    if (pita == NULL){
        printf("File yang Anda ingin buka tidak ditemukan dalam sistem.\n");
    }
    if (retval == EOF){
        endOfFile = true;
    }
}

void StartReadFilename() {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* DIGUNAKAN UNTUK MEMBACA DARI INPUT PENGGUNA */
    /* Algoritma */
    pita = stdin;
    ADVFilename();
}

void ADVFilename(){
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == NEWLINE);
    if (EOP) {
        fclose(pita);
    }
}