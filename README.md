# PURRMART
## IF2111 Algoritma dan Struktur Data STI

Dibuat oleh Kelompok 1 - K02, yaitu :

1. Zaka Hanif Nabalah (18223006)
2. Rayhan Hidayatul Fikri (18223022)
3. Favian Rafi Laftiyanto (18223036)
4. Wijaksara Aptaluhung (18223088)
5. Seren Elizabeth Siahaan (18221160)

## Deskripsi Singkat Sistem
PURRMART adalah sebuah aplikasi yang dapat mensimulasikan aktivitas beli barang pada e-commerce dengan spesialisasi senjata perang. PURRMART memiliki beberapa fitur utama, yaitu:
1. Menampilkan barang toko
2. Meminta dan menyuplai barang baru ke toko
3. Menyimpan dan membeli barang dalam keranjang
4. Menampilkan barang yang sudah dibeli
5. Membuat dan menghapus wishlist
6. Bekerja untuk menghasilkan uang

Sistem yang akan dibangun adalah sebuah program berbasis command line interface (CLI) yang dibuat dalam bahasa C. Program ini akan menggunakan sejumlah abstract data type (ADT) yang telah dipelajari di mata kuliah ini.

## Cara Kompilasi Program
>    Make adalah tool command line interface untuk melakukan build executable code otomatis dan mampu mempermudah kompilasi program.
> 1. **Lakukan instalasi MinGW melalui** https://mingw-w64.org/
> 2. **Tambahkan path ke bin MinGW ke PATH sistem komputer Anda**
> 3. **Lakukan git clone atau unduh kode melalui zip**
> 3. **Masuk ke directory bin**
> 5. **Jalankan :**
>
>    ```powershell
>    make
>    ```
>    atau
>    ```powershell
>    mingw32-make
>    ```
>    atau
>    ```powershell
>    mingw32-make -f makefile
>    ```

## Cara Menjalankan Program
> **Masuk ke directory bin dan jalankan :**
>
> ```powershell
> ./output.exe
> ```

## Struktur Program
```
.
├── .gitginore
├── README.md
├── bin
│   └─── Makefile  
|
├── docs
│   ├─── IF2111_Form Asistensi Tugas Besar 01.pdf			    
│   ├─── IF2111_Form Asistensi Tugas Besar 02.pdf
│   ├─── IF2111_TB_02_01.pdf			    
│   ├─── IF2111_TB_02_02.pdf
│   ├─── Spesifikasi Tugas Besar 1 IF2111 2024_2025.pdf     
│   └─── Spesifikasi Tugas Besar 2 IF2111 2024_2025.pdf
|
├── save
│   ├─── config.txt 			    
│   ├─── dummyfile.txt
│   ├─── empty.txt 			     
│   ├─── invalid.txt				     
│   └─── word.txt                     
│ 
└── src
    ├─── boolean.h
    ├─── ADT
    │      ├─── array
    │      │       ├─── array.h
    │      │       ├─── array.c    
    │      │       └─── arraydriver.c
    │      │
    │      ├─── arraydin
    │      │       ├─── arraydin.h
    │      │       ├─── arraydin.c
    │      │       └─── arraydindriver.c
    │      │
    │      ├─── linkedlist
    │      │       ├─── listlinier.h
    │      │       ├─── listlinier.c
    │      │       └─── listlinierdriver.c
    │      │
    │      ├─── mesinfrasa
    │      │       ├─── mesinfrasa.h
    │      │       ├─── mesinfrasa.c
    │      │       └─── mesinfrasadriver.c
    │      │
    │      ├─── mesinkarakter
    │      │       ├─── mesinkarakter.h
    │      │       ├─── mesinkarakter.c
    │      │       └─── mesinkarakterdriver.c
    │      │
    │      ├─── mesinkata
    │      │       ├─── mesinkata.h
    │      │       ├─── mesinkata.c
    │      │       └─── mesinkatadriver.c
    │      │
    │      ├─── queue
    │      │       ├─── queue.h
    │      │       ├─── queue.c
    │      │       └─── queuedriver.c
    │      │
    │      ├─── queuebarang
    │      │       ├─── queuebarang.h
    │      │       ├─── queuebarang.c
    │      │       └─── queuebarangdriver.c
    │      │
    │      ├─── setmap
    │      │       ├─── map.h
    │      │       ├─── map.c
    │      │       └─── mapdriver.c
    │      │
    │      ├─── stack
    │      │       ├─── stack.h
    │      │       ├─── stack.c
    │      │       └─── stackdriver.c
    │      │
    │      └─── user.h
    │
    ├─── ADT.h
    ├─── Profile.c
    ├─── Profile.h
    ├─── banner.txt
    ├─── bioweapon.c
    ├─── bioweapon.h
    ├─── boolean.h
    ├─── cart.c
    ├─── cart.h
    ├─── ga_driver.c
    ├─── globalalignment.c
    ├─── globalalignment.h
    ├─── help.c
    ├─── help.h
    ├─── history.c
    ├─── history.h
    ├─── kebutuhanlog.c
    ├─── kebutuhanlog.h
    ├─── load.c
    ├─── load.h
    ├─── loaddriver.c
    ├─── login.c
    ├─── login.h
    ├─── logout.c
    ├─── logout.h
    ├─── main.c
    ├─── optimasirute.c
    ├─── optimasirute.h
    ├─── or_driver.c
    ├─── quit.c
    ├─── quit.h
    ├─── register.c
    ├─── register.h
    ├─── save.c
    ├─── save.h
    ├─── savedriver.c
    ├─── start.c
    ├─── start.h
    ├─── startdriver.c
    ├─── storedriver.c
    ├─── storelist.c
    ├─── storelist.h
    ├─── storeremove.c
    ├─── storeremove.h
    ├─── storerequest.c
    ├─── storerequest.h
    ├─── storesupply.c
    ├─── storesupply.h
    ├─── str.c
    ├─── str.h
    ├─── users.txt
    ├─── wishlist.c
    ├─── wishlist.h
    ├─── word.txt
    ├─── work.c
    ├─── work.h
    ├─── workchallenge.c
    ├─── workchallenge.h
    └─── workdriver.c
 ```