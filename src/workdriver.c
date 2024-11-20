#include "work.h"
#include "workchallenge.h"

int main(){
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        work_();
        break;
    case 2:
        workChallenge();
        break;
    default:
        break;
    }
}