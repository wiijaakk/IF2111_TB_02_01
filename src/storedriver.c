#include <stdio.h>
#include "storelist.h"
#include "storerequest.h"
#include "storesupply.h"
#include "storeremove.h"

int main(){
    ArrayDin woohoo = MakeArrayDin();
    Barang meh;
    copyString(meh.name, "Toto Odol Item Amazing");
    meh.price = 100;
    InsertAt(&woohoo, meh, 0);
    storelist(woohoo);
    Queuebarang barang;
    CreateQueuebarang(&barang);
    storerequest(woohoo, &barang);
    storesupply(&woohoo, &barang);
    storeremove(&woohoo);
}