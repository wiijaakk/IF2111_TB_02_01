#include <stdio.h>
#include "map.h"
#include "boolean.h"

void copyString(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int compareStrings(const char *key1, const char *key2) {
    int i = 0;
    while (key1[i] != '\0' && key2[i] != '\0') {
        if (key1[i] != key2[i]) {
            return key1[i] - key2[i];
        }
        i++;
    }
    return key1[i] - key2[i];
}


void CreateEmpty(Map *M){
    M->Count = Nil;
}

boolean IsEmpty(Map M){
    return (M.Count == Nil);
}

boolean IsFull(Map M){
    return (M.Count == MaxEl);
}

valuetype Value(Map M, keytype k){
    if(IsMember(M, k)){
        for(int i = 0; i<M.Count; i++){
        if(M.Elements[i].Key == k){
            return M.Elements[i].Value;
            break;
        }
    }
    }
    else{
        return Undefined;
    }
}

void Insert(Map *M, keytype k, valuetype v){
    if(!IsMember(*M,k)){
        if(IsEmpty(*M)){
            M->Count = 1;
            copyString(M->Elements[0].Key, k);
            M->Elements[0].Value = v;
        }
        else{
            int idx = M->Count;
            M->Count++;
            copyString(M->Elements[idx].Key, k);
            M->Elements[idx].Value = v;
        }
    }
    else{
        int idx = IdxMember(*M, k);
        M->Elements[idx].Value+=v;
    }
}

void Delete(Map *M, keytype k, valuetype v){
    if(IsMember(*M, k)){
        int idx = IdxMember(*M, k);
        if(M->Elements[idx].Value-v<=0){
            M->Elements[idx].Value = 0;
            if(M->Count==1){
                M->Count = Nil;
            }
            else{
                for(int i = idx+1; i<M->Count; i++){
                    M->Elements[i-1] = M->Elements[i];
                }
                M->Count--;
            }
        }
        else{
            M->Elements[idx].Value-=v;
        }
    }
}

boolean IsMember(Map M, keytype k){
    boolean ada = false;
    for(int i = 0; i<M.Count; i++){
        if(compareStrings(M.Elements[i].Key, k)==0){
            ada = true;
            break;
        }
    }
    return ada;
}

int IdxMember(Map M, keytype k){
    if(IsMember(M, k)){
        for(int i = 0; i<M.Count; i++){
            if(compareStrings(M.Elements[i].Key, k)==0){
                return i;
            }
        }
    }
}