#include "workchallenge.h"

int RNG(int min, int max){
    srand(time(NULL));
    int v1 = rand();
    srand(v1);
    return (rand() * v1) % (max - min + 1) + min;
}

int countWords(char *filename, char wordlist[WordCount__][6]) {
    int count = 0;
    StartFileWord(filename);
    while (!endOfFile) {
        toupperstr(currentWord.TabWord);
        copyStr(currentWord.TabWord, wordlist[count]);
        ADVFileWordNewLine();
        //printf("%s\n", currentWord.TabWord);
        count++;
    }

    return count;
}

int isWord(char wordlist[WordCount__][6], char word[6], int count){
    int exist = 0;
    int i = 0;
    while (i < count && !exist)
    {
        if (check_strV2(wordlist[i], word))
        {
            exist = 1;
        }
        i++;
    }
    return exist;
}

void randomWord(char wordlist[WordCount__][6], int index, char *result) {
    copyStr(wordlist[index], result);
}

void tebakAngka(){
    int n = RNG(0, 100);
    //printf("%d\n", n);
    printf("Tebak Angka: ");
    
    int input = 0;
    STARTWORD();
    for (int i = 0; i < currentWord.Length; i++) {
        input = input * 10 + (currentWord.TabWord[i] - '0');
    }
    int i = 1;
    while (input != n && i < 10)
    {
        if (input < n)
        {
            printf("Tebakanmu lebih kecil!\n");
        }

        if (input > n)
        {
            printf("Tebakanmu lebih besar!\n");
        }

        printf("Tebak Angka: ");
    
        STARTWORD();
        input = 0;
        for (int i = 0; i < currentWord.Length; i++) {
            input = input * 10 + (currentWord.TabWord[i] - '0');
        }
        i++;
    }
    if (input == n)
    {
        printf("Tebakanmu benar!\n");
    }else{
        printf("Failed\n");
    }
}

void _printPast(char past[6][11], int count){
    int i = 0;
    while (i < count)
    {
        int j = 0;
        while (past[i][j] != '\0')
        {
            if (j != 0 && j % 2 == 0)
            {
                printf(" ");
            }
            
            if (past[i][j] != ' ')
            {
                printf("%c", past[i][j]);
            }
            j++;
        }
        printf("\n");
        i++;
    }    
}

void _printDash(int count){
    int i = 0;
    while (i < 5 - count)
    {
        printf("_ _ _ _ _\n");
        i++;
    }    
}

void wordl3(){
    char *filename = "../save/word.txt";
    char wordlist[WordCount__][6];
    char word[6];
    char past[6][11];
    char input[20];
    int count = 0;
    int found = 0;
    int wordnum = countWords(filename, wordlist);
    randomWord(wordlist, RNG(0, wordnum), word);
    //printf("%s %d %d\n", word, count, found);
    while (count < 6 && found < 5)
    {
        found = 0;
        int i = 0;
        int aword = 0;
        if (count > 0)
        {
            printf("Hasil:\n");
        }
        _printPast(past, count);
        _printDash(count);
        printf("\n");
        while (!aword)
        {
            printf("Masukan Kata Tebakan: ");
            STARTWORD();
            toupperstr(currentWord.TabWord);
            copyStr(currentWord.TabWord, input);
            aword = isWord(wordlist, input, wordnum);
            if (!aword)
            {
                printf("Tebakan Bukan Kata Valid\n");
            }
            
        }

        i = 0;
        while (i < 5)
        {
            if (input[i] == word[i])
            {
                //printf("%c ", input[i]);
                past[count][(i*2)] = input[i];
                past[count][(i*2)+1] = ' ';
                found++;
            }else if(isIn(input[i], word)){
                //printf("%c* ", input[i]);
                past[count][(i*2)] = input[i];
                past[count][(i*2)+1] = '*';
            }else{
                //printf("%c%% ", input[i]);
                past[count][(i*2)] = input[i];
                past[count][(i*2)+1] = '%';
            }
            i++;   
        }
        past[count][10] = '\0';
        count++;
    }
    printf("Hasil:\n");
    _printPast(past, count);
    _printDash(count);
    if (found == 5)
    {
        printf("Menang\n");
    }else{
        printf("Kalah\n");
        printf("Jawaban: %s\n", word);
    }
    
}


void workChallenge(){
    chal c[chal_count] = {{chal1}, {chal2}};
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < chal_count; i++)
    {
        printf("    %d. %s (biaya=%d)\n", i+1, c[i].name, c[i].biaya);
    }
    printf("Masukkan challenge yang dipilih: ");

    char input[50];
    STARTWORD();
    copyStr(currentWord.TabWord, input);

    int selected = -1;
    int i = 0;
    while (i < chal_count && selected == -1)
    {
        if (check_strV2(input, c[i].name))
        {
            selected = i;
        }
        if (input[0] - '0' - 1 == i)
        {
            selected = i;
        }
        i++;
    }
    switch (selected)
    {
    case 0:
        tebakAngka();
        break;
    case 1:
        wordl3();
        break;
    default:
        break;
    }
}
