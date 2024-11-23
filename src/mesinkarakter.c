#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
boolean endOfFile;

static FILE *pita;
static int retval;

void START() {
    // Mesin siap dioperasikan. Pita disiapkan.
    // Input diambil dari masukan pengguna lewat character stream di console
    pita = stdin;
    ADV();
}

void ADV() {
    // Pita dimajukan satu karakter.
    // Input diambil dari masukan pengguna lewat character stream di console
    // Pembacaan file dihentikan jika currentChar == MARK
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    // Mengirimkan currentChar
    return currentChar;
}

boolean IsEOP() {
    // Mengirimkan true jika currentChar = MARK
    return EOP;
}

void StartReadFile(char* input){
    // Mesin siap dioperasikan. Pita disiapkan.
    // Input diambil dari file txt sesuai masukan pengguna
    // Pembacaan file dihentikan jika file input tidak tersedia atau isinya kosong
    pita = fopen(input, "r");
    ADVFile();
}

void ADVFile() {
    // Pita dimajukan satu karakter.
    // Pembacaan file dihentikan jika telah mencapai karakter terakhir dalam file
    retval = fscanf(pita, "%c", &currentChar);
    if (retval == EOF){
        endOfFile = true;
    }
}

void StartReadNewLine() {
    // Mesin siap dioperasikan. Pita disiapkan.
    // Input diambil dari masukan pengguna lewat character stream di console
    pita = stdin;
    ADVNewLine();
}

void ADVNewLine(){
    // Pita dimajukan satu karakter
    // Membaca masukan hingga karakter NEWLINE
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == NEWLINE);
    if (EOP) {
        fclose(pita);
    }
}

boolean isFileValid(char* input){
    FILE *file = fopen(input, "r");
    if(file){
        fclose(file);
        return true;
    }
    else{
        return false;
    }
}