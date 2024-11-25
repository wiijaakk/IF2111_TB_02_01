#include "work.h"

void work_timer(int second){
    int i = 0;
    clock_t start = clock();
    while (i < second){
        printf("%d/%d\n", i, second);
        i++;
        while (clock() < start + (i * 1000));
    }
    printf("%d/%d out\n", i, second);
}

void work_(TabInt *arruser, int useridx){
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
    toupperstr(input);

    int selected = -1;
    int i = 0;
    while (i < work_count && selected == -1)
    {
        toupperstr(w[i].name);
        if (check_strV2(input, w[i].name))
        {
            selected = i;
        }
        if (input[0] - '0' - 1 == i)
        {
            selected = i;
        }
        i++;
    }
    if (selected != -1)
    {
        //printf("%d %d\n", selected, w[selected].duration);
        printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", w[selected].name);
        work_timer(w[selected].duration);
        arruser->TI[useridx].money += w[selected].salary;
        printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.(Uang Sekarang = %d)\n", w[selected].salary, arruser->TI[useridx].money);
        //tambah uang user
    }else{
        printf("Pekerjaan Yang Dipilih Tidak Valid\n");
    }
    

}
