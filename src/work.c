#include "work.h"

// TODO:
// -Change input methode
void work_timer(int second){
    int ms = second * 1000;
    int i = 0;
    clock_t start = clock();
    while (i < second){
        clock_t cr = clock();
        printf("%d/%d\n", i, second);
        i++;
        while (clock() < start + (i * 1000));
    }
    printf("%d/%d out\n", i, second);
}

void work_(){
    work w[work_count] = {{work1}, {work2}, {work3}, {work4}, {work5}};
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < work_count; i++)
    {
        printf("    %d. %s (pendapatan=%d, durasi=%d)\n", i+1, w[i].name, w[i].salary, w[i].duration);
    }
    printf("Masukkan pekerjaan yang dipilih: ");

    char input[50];
    STARTWORD();
    copyStr(currentWord.TabWord, input);

    int selected = -1;
    int i = 0;
    while (i < work_count && selected == -1)
    {
        if (check_str(input, w[i].name))
        {
            selected = i;
        }
        if (input[0] - '0' - 1 == i)
        {
            selected = i;
        }
        i++;
    }
    printf("%d %d\n", selected, w[selected].duration);
    work_timer(w[selected].duration);
}
