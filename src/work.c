#include "work.h"

void work_timer(int second){
    int i = 0;
    clock_t start = clock();
    while (i < second){ // Menunggu selama second
        printf("%d/%d\n", i, second);
        i++;
        while (clock() < start + (i * 1000)); // Menunggu selama 1 detik untuk memperlihatkan progres
    }
    printf("%d/%d out\n", i, second);
}

void work_(TabInt *arruser, int useridx){
    work w[work_count] = {{work1}, {work2}, {work3}, {work4}, {work5}};
    printf("Daftar Pekerjaan:\n");
    for (int i = 0; i < work_count; i++) // Display semua work yang ada
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
        if (check_strV2(input, w[i].name)) // Cek input kata
        {
            selected = i;
        }
        if (input[0] - '0' - 1 == i) // Cek input angka
        {
            selected = i;
        }
        i++;
    }
    if (selected != -1)
    {
        printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", w[selected].name);
        work_timer(w[selected].duration); // Menunggu pekerjaan selesai
        arruser->TI[useridx].money += w[selected].salary; // Tambah uang user
        printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.(Uang Sekarang = %d)\n", w[selected].salary, arruser->TI[useridx].money);
    }else{
        printf("Pekerjaan Yang Dipilih Tidak Valid\n");
    }
    

}
