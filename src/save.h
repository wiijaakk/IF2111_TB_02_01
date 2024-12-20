#ifndef __SAVE_H__
#define __SAVE_H__

#include <stdio.h>
#include <stdlib.h>

#include "ADT.h"

#define SAVE_FOLDER "../save/"

void save(char* fileName, ArrayDin* arrayItems, TabInt* arrayUsers, int length);

#endif