#ifndef __WORK_H__
#define __WORK_H__

#include <stdio.h>
#include <time.h>
#include "str.h"
#include "ADT.h"

#define work_count 5
//List Work
//             Name         Salary      Duration
#define work1 "work1",      10,         10
#define work2 "work2",      15,         15
#define work3 "work3",      20,         20
#define work4 "work4",      25,         25
#define work5 "work5",      30,         30

typedef struct {
  char name[50];
  int salary;
  int duration;
} work;

void work_();

#endif