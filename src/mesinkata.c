#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == NEWLINE)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != EOP)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return EndWord;
}

void StartFileWord(FILE* input){
    StartReadFile(input);
    IgnoreBlanks();
    if (currentChar == BLANK || currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFileNewLine();
    }
}

void ADVFileWordSpace()
{
    IgnoreBlanks();
    for(int i = 0; i < currentWord.Length; i++){
        currentWord.TabWord[i] = ' ';
    }
    currentWord.Length = 0;

    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFileSpace();
    }
}

void ADVFileWordNewLine()
{
    IgnoreBlanks();
    for(int i = 0; i < currentWord.Length; i++){
        currentWord.TabWord[i] = ' ';
    }
    currentWord.Length = 0;

    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFileNewLine();
    }
}

void CopyWordFileSpace()
{
    currentWord.Length = 0;
    while (currentChar != BLANK && !endOfFile)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVFile();
        }
        else
            break;
    }
}

void CopyWordFileNewLine()
{
    currentWord.Length = 0;
    while (currentChar != NEWLINE && !endOfFile)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVFile();
        }
        else {
            break;
        }
    }
}

Word StartFilenameWord(){
    StartReadFilename();
    IgnoreBlanks();
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFilename();
    }

    return currentWord;
}

void CopyWordFilename()
{
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != NEWLINE)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVFilename();
        }
        else
            break;
    }
}