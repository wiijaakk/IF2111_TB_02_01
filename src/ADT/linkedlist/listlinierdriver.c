#include <stdio.h>
#include "listlinier.h"

int main() {
    List myList;
    nama_barang item;
    address addr;

    // Membuat list kosong
    CreateEmptyListLinier(&myList);
    printf("%d\n", IsEmptyListLinier(myList)); // Seharusnya print 1 (list kosong)

    // Menambahkan elemen di awal (InsVFirst)
    nama_barang barang1 = "Barang1";
    InsVFirst(&myList, barang1);
    PrintInfoListLinier(myList); // Seharusnya print [Barang1]

    // Menambahkan elemen di akhir (InsVLast)
    nama_barang barang2 = "Barang2";
    InsVLast(&myList, barang2);
    PrintInfoListLinier(myList); // Seharusnya print [Barang1,Barang2]

    // Menghapus elemen pertama (DelVFirst)
    DelVFirst(&myList, &item);
    printf("Deleted: %s\n", item); // Seharusnya print Barang1
    PrintInfoListLinier(myList); // Seharusnya print [Barang2]

    // Menghapus elemen terakhir (DelVLast)
    DelVLast(&myList, &item);
    printf("Deleted: %s\n", item); // Seharusnya print Barang2
    PrintInfoListLinier(myList); // Seharusnya print []

    // Menambahkan beberapa elemen untuk tes lainnya
    InsVLast(&myList, barang1);
    InsVLast(&myList, barang2);
    nama_barang barang3 = "Barang3";
    InsVLast(&myList, barang3);
    PrintInfoListLinier(myList); // Seharusnya print [Barang1,Barang2,Barang3]

    // Menghitung jumlah elemen
    printf("Jumlah elemen: %d\n", NbElmtListLinier(myList)); // Seharusnya print 3

    // Membalik elemen list (InversListLinier)
    InversListLinier(&myList);
    PrintInfoListLinier(myList); // Seharusnya print [Barang3,Barang2,Barang1]

    // Menggabungkan dua list (KonkatListLinier)
    List list2, list3;
    CreateEmptyListLinier(&list2);
    InsVLast(&list2, "Barang4");
    KonkatListLinier(&myList, &list2, &list3);
    PrintInfoListLinier(list3); // Seharusnya print [Barang3,Barang2,Barang1,Barang4]
    PrintInfoListLinier(myList); // Seharusnya print []
    PrintInfoListLinier(list2); // Seharusnya print []

    return 0;
}
