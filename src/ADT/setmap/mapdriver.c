#include <stdio.h>
#include "map.h"

int main(){
    Map yuh;
    CreateEmptyMap(&yuh); // Membuat Map kosong
    printf("%d\n", IsEmptyMap(yuh)); // Seharusnya print 1 karena Map masih kosong
    printf("%d\n", IsFullMap(yuh)); // Seharusnya print 0 karena Map masih kosong sehingga tidak penuh
    char coba[] = "Alstrukdat";
    infotype try;
    copyStringMap(try.Key, coba);
    printf("%s\n", try.Key); // Seharusnya try.Key = "Alstrukdat"
    printf("%d\n", compareStrings(coba, try.Key)); // Seharusnya print 0 karena try.Key = coba = "Alstrukdat", kalau beda print 1
    InsertMap(&yuh, coba, 10);
    printf("%d\n", ValueMap(yuh, coba)); // Seharusnya print 10 karena key "Alstrukdat" memiliki value 10
    printf("%d\n", IsMemberMap(yuh, coba)); // Seharusnya print 1 karena key "Alstrukdat" ada di Map
    printf("%d\n", IdxMemberMap(yuh,coba)); // Seharusnya print 0 karena itu letak indeks dari key "Alsstrukdat"
    DeleteMap(&yuh, coba, 9);
    printf("%d\n", ValueMap(yuh, coba)); // Seharusnya print 1 karena key "Alstrukdat" memiliki value 10 - 9 = 1
    DeleteMap(&yuh, coba, 1);
    printf("%d\n", IsMemberMap(yuh, coba)); // Seharusnya print 0 karena key "Alstrukdat telah dihapus"
}