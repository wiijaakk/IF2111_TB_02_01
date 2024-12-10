#include "../../boolean.h"

#ifndef stackt_H
#define stackt_H

#define Nil -1
#define MaxEl 100

typedef struct {
  char name[MaxEl];
  int totalharga;
} infotype;
typedef int address;

typedef struct { 
  infotype T[MaxEl]; 
  address TOP; 
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

void Push(Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void Pop(Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif