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
> 1. **Instalasi Tool Make**
>
>    Make adalah tool command line interface untuk melakukan build executable code otomatis. Terdapat beberapa cara untuk melakukan instalasi, yakni:
>    1) **Chocolatey**
>       1. Buka command prompt
>       2. Install Chocolatey dengan menjalankan :
>
>          ```powershell
>          Set-ExecutionPolicy Bypass -Scope Process -Force;[System.Net.ServicePoint]::SecurityProtocol = [System.Net.ServicePoint]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
>          ```
>       3. Install Make dengan menjalankan :
>
>          ```powershell
>          choco install make
>          ```
>    2) **Windows Subsystem for Linux (WSL)**
>       1. Buka command prompt
>       2. Jalankan :
>
>          ```powershell
>          wsl -- install
>          ```
>    3) **MinGW**
>       1. Lakukan instalasi MinGW melalui https://mingw-w64.org/
>       2. Tambahkan path ke bin MinGW ke PATH sistem komputer Anda
> 2. **Lakukan git clone atau unduh kode melalui zip**
> 3. **Masuk ke directory bin**
> 4. **Jalankan :**
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
├── save
│   ├─── config.txt 			    
│   ├─── dummyfile.txt 			     
│   ├─── invalid.txt				     
│   └─── word.txt                     
│ 
└── src
    ├─── boolean.h
    ├─── ADT
    │      ├─── array
    │      │       ├─── array.h
    │      │       └─── array.c
    │      │
    │      ├─── arraydin
    │      │       ├─── arraydin.h
    │      │       └─── arraydin.c
    │      │
    │      ├─── mesinfrasa
    │      │       ├─── mesinfrasa.h
    │      │       └─── mesinfrasa.c
    │      │
    │      ├─── mesinkarakter
    │      │       ├─── mesinkarakter.h
    │      │       └─── mesinkarakter.c
    │      │
    │      ├─── mesinkata
    │      │       ├─── mesinkata.h
    │      │       └─── mesinkata.c
    │      │
    │      ├─── queue
    │      │       ├─── queue.h
    │      │       └─── queue.c
    │      │
    │      └─── queuebarang
    │              ├─── queuebarang.h
    │              └─── queuebarang.c
    │
    └─── ADT.h
           ├─── banner.txt
           ├─── users.txt
           ├─── word.txt
           ├─── bioweapon.c
           ├─── bioweapon.h
           ├─── help.c
           ├─── help.h
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
           ├─── queuebarang.c
           ├─── queuebarang.h
           ├─── quit.c
           ├─── quit.h
           ├─── register.c
           ├─── register.h
           ├─── save.c
           ├─── save.h
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
           ├─── work.c
           ├─── work.h
           ├─── workchallenge.c
           ├─── workchallenge.h
           └─── workdriver.c
 ```
> To Be Updated