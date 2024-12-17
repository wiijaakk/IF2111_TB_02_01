#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmptyListLinier(List L){
    return First(L) == Nuh;
}

void CreateEmptyListLinier(List *L){
    L->First = Nuh;
}

address AlokasiListLinier(nama_barang X){
     address P = (address) malloc (sizeof(ElmtList));
     if (P!=NULL){
        copyString(P->info, X);
        P->next = Nuh;
        return P;
     }
     else{
        return Nuh;
     }
}

void DealokasiListLinier(address *P){
    free(*P);
}

address SearchListLinier(List L, nama_barang X){
    address now = First(L);
    while(now->next!=Nuh){
        if(now->info!=X){
            now = now->next;
        }
        else{
            return now;
        }
    }
    if(now->info==X){
        return now;
    }
    return Nuh;
}

void InsVFirst(List *L, nama_barang X){
    address P = AlokasiListLinier(X);
    if(P!=Nuh){
        if(IsEmptyListLinier(*L)){
            L->First = P;
        }
        else{
            P->next = L->First;
            L->First = P;
        }
    }
}

void InsVLast (List *L, nama_barang X){
    address P = AlokasiListLinier(X);
    if(P!=Nuh){
        InsertLast(L, P);
    }
}

void DelVFirst (List *L, nama_barang *X){
    address P;
    DelFirst(L, &P);
    copyString(*X, P->info);
    DealokasiListLinier (&P);
}

void DelVLast (List *L, nama_barang *X){
    address P;
    DelLast(L, &P);
    copyString(*X, P->info);
    DealokasiListLinier (&P);
}

void InsertFirst (List *L, address P){
    P->next = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
    P->next = Prec->next;
    Prec->next = P;
}

void InsertLast (List *L, address P){
    if(IsEmptyListLinier(*L)){
        InsertFirst(L, P);
    }
    else{
        address Prec = L->First;
        while(Prec->next!=Nuh){
            Prec = Prec->next;
        }
        InsertAfter(L, P, Prec);
    }
}

void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = First(*L)->next;
    (*P)->next = Nuh;
}

void DelP (List *L, nama_barang X){
    address P = SearchListLinier(*L, X);
    if(P!=Nuh){
        address now = First(*L);
        if(P == now){
            DelFirst(L, &P);
        }
        else{
            while(now->next!=P){
                now = now->next;
            }
            DelAfter(L, &P, now);
        }
    }
}

void DelAddr (List *L, address P){
    if(P!=Nuh){
        address now = First(*L);
        if(P == now){
            DelFirst(L, &P);
        }
        else{
            while(now->next!=P){
                now = now->next;
            }
            DelAfter(L, &P, now);
        }
    }
}

void DelLast (List *L, address *P){
	address last = First(*L);
	address prec = Nuh;

	while (Next(last) != Nuh){
		prec = last;
		last = Next(last);
	}

	*P = last;
	if (prec == Nuh){
		First(*L) = Nuh; 
	} else {
		Next(prec) = Nuh;
	}
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Prec->next;
    if(Prec->next!=Nuh){
        Prec->next = Prec->next->next;
        (*Pdel)->next = Nuh;
    }
}

void PrintInfoListLinier(List L){
    printf("[");
    if(!IsEmptyListLinier(L)){
        address W = First(L);
        while(W->next!=Nuh){
            printf("%d,", W->info);
            W = W->next;
        }
        printf("%d", W->info);
    }
    printf("]\n");
}

int NbElmtListLinier(List L){
    if(IsEmptyListLinier(L)){
        return 0;
    }
    else{
        int jum = 1;
        address W = First(L);
        while(W->next!=Nuh){
            jum++;
            W = W->next;
        }
        return jum;
    }
}

void InversListLinier(List *L){
   if(!IsEmptyListLinier(*L)){
        address W =First(*L);
        address sebelah = W->next;
        while(sebelah!=Nuh){
            address temp = sebelah;
            sebelah = sebelah->next;
            InsertFirst(L, temp);
            W->next = sebelah;
        }
   }
}

void KonkatListLinier(List *L1, List *L2, List *L3){
    CreateEmptyListLinier(L3);
    if(IsEmptyListLinier(*L1)){
        First(*L3) = First(*L2);
    }
    else{
        First(*L3) = First(*L1);
        address W = First(*L1);
        while(W->next!=Nuh){
            W = W->next;
        }
        W->next = First(*L2);
    }
    CreateEmptyListLinier(L2);
    CreateEmptyListLinier(L1);
}