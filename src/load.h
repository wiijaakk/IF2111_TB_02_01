#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdio.h>
#include <stdlib.h>

#include "ADT.h"
#define SAVE_FOLDER "../save/"

void load(Word filename, ArrayDin* arrayItems, TabInt* arrayUsers, boolean * SessionStatus);

#endif