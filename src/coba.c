#include "ADT.h"

int main(){
    int total = 0; // representasi jumlah barang atau user yang tercatat
    int n_riwayat_pembelian, n_wishlist;
    Barang currentBarang; // menyimpan barang yg sedang diproses
    User currentUser; // menyimpan user yg sedang diproses
    barang_dibeli currentBarangDibeli;
    barang_dibeli testBarangDibeli;
    nama_barang currentBarangWishlist;
    nama_barang testBarangWishlist;

    StartFileWord("../save/config.txt");
    total = wordToInt(currentWord);
    printf("total: %d\n", total);

    ADVFileWordSpace();
    currentBarang.price = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarang.name[j] = currentWord.TabWord[j];
    }
    currentBarang.name[currentWord.Length] = '\0';

    printf("nama barang: %s, harga: %d\n",currentBarang.name, currentBarang.price);

    ADVFileWordSpace();
    currentBarang.price = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarang.name[j] = currentWord.TabWord[j];
    }
    currentBarang.name[currentWord.Length] = '\0';

    printf("nama barang: %s, harga: %d\n",currentBarang.name, currentBarang.price);

    ADVFileWordSpace();
    currentBarang.price = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarang.name[j] = currentWord.TabWord[j];
    }
    currentBarang.name[currentWord.Length] = '\0';

    printf("nama barang: %s, harga: %d\n",currentBarang.name, currentBarang.price);

    ADVFileWordSpace();
    currentBarang.price = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarang.name[j] = currentWord.TabWord[j];
    }
    currentBarang.name[currentWord.Length] = '\0';

    printf("nama barang: %s, harga: %d\n",currentBarang.name, currentBarang.price);

    ADVFileWordNewLine();
    total = wordToInt(currentWord);
    printf("total: %d\n", total);

    ADVFileWordSpace();
    currentUser.money = wordToInt(currentWord);

    ADVFileWordSpace();
    for (int j = 0; j < currentWord.Length; j++) {
        currentUser.name[j] = currentWord.TabWord[j];
    }
    currentUser.name[currentWord.Length] = '\0';

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentUser.password[j] = currentWord.TabWord[j];
    }
    currentUser.password[currentWord.Length] = '\0';

    printf("nama user: %s, password: %s, uang: %d\n", currentUser.name, currentUser.password, currentUser.money);

    ADVFileWordNewLine();
    total = wordToInt(currentWord);
    printf("total: %d\n", total);

    CreateEmptyStack(&currentUser.riwayat_pembelian);
    CreateEmptyListLinier(&currentUser.wishlist);
    CreateEmptyMap(&currentUser.keranjang);

    ADVFileWordSpace();
    currentBarangDibeli.totalharga = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangDibeli.name[j] = currentWord.TabWord[j];
    }
    currentBarangDibeli.name[currentWord.Length] = '\0';

    PushStack(&currentUser.riwayat_pembelian, currentBarangDibeli);

    ADVFileWordSpace();
    currentBarangDibeli.totalharga = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangDibeli.name[j] = currentWord.TabWord[j];
    }
    currentBarangDibeli.name[currentWord.Length] = '\0';

    PushStack(&currentUser.riwayat_pembelian, currentBarangDibeli);

    ADVFileWordSpace();
    currentBarangDibeli.totalharga = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangDibeli.name[j] = currentWord.TabWord[j];
    }
    currentBarangDibeli.name[currentWord.Length] = '\0';

    PushStack(&currentUser.riwayat_pembelian, currentBarangDibeli);

    ADVFileWordSpace();
    currentBarangDibeli.totalharga = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangDibeli.name[j] = currentWord.TabWord[j];
    }
    currentBarangDibeli.name[currentWord.Length] = '\0';

    PushStack(&currentUser.riwayat_pembelian, currentBarangDibeli);

    ADVFileWordSpace();
    currentBarangDibeli.totalharga = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangDibeli.name[j] = currentWord.TabWord[j];
    }
    currentBarangDibeli.name[currentWord.Length] = '\0';

    PushStack(&currentUser.riwayat_pembelian, currentBarangDibeli);

    ADVFileWordSpace();
    currentBarangDibeli.totalharga = wordToInt(currentWord);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangDibeli.name[j] = currentWord.TabWord[j];
    }
    currentBarangDibeli.name[currentWord.Length] = '\0';

    PushStack(&currentUser.riwayat_pembelian, currentBarangDibeli);

    PopStack(&currentUser.riwayat_pembelian, &testBarangDibeli);
    printf("barang dibeli: %s, total harga: %d\n", testBarangDibeli.name, testBarangDibeli.totalharga);
    PopStack(&currentUser.riwayat_pembelian, &testBarangDibeli);
    printf("barang dibeli: %s, total harga: %d\n", testBarangDibeli.name, testBarangDibeli.totalharga);
    PopStack(&currentUser.riwayat_pembelian, &testBarangDibeli);
    printf("barang dibeli: %s, total harga: %d\n", testBarangDibeli.name, testBarangDibeli.totalharga);
    PopStack(&currentUser.riwayat_pembelian, &testBarangDibeli);
    printf("barang dibeli: %s, total harga: %d\n", testBarangDibeli.name, testBarangDibeli.totalharga);
    PopStack(&currentUser.riwayat_pembelian, &testBarangDibeli);
    printf("barang dibeli: %s, total harga: %d\n", testBarangDibeli.name, testBarangDibeli.totalharga);
    PopStack(&currentUser.riwayat_pembelian, &testBarangDibeli);
    printf("barang dibeli: %s, total harga: %d\n", testBarangDibeli.name, testBarangDibeli.totalharga);

    ADVFileWordNewLine();
    total = wordToInt(currentWord);
    printf("total: %d\n", total);

    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangWishlist[j] = currentWord.TabWord[j];
    }
    currentBarangWishlist[currentWord.Length] = '\0';
    InsVLast(&currentUser.wishlist, currentBarangWishlist);
    
    ADVFileWordNewLine();
    for (int j = 0; j < currentWord.Length; j++) {
        currentBarangWishlist[j] = currentWord.TabWord[j];
    }
    currentBarangWishlist[currentWord.Length] = '\0';
    InsVLast(&currentUser.wishlist, currentBarangWishlist);

    address currentAddress = First(currentUser.wishlist);
    while(currentAddress != Nuh){
        printf("barang wishlist: %s\n", Info(currentAddress));
        currentAddress = currentAddress->next;
    }
}