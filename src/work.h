#ifndef __WORK_H__
#define __WORK_H__

#include <stdio.h>
#include <time.h>
#include "str.h"
#include "ADT.h"

#define work_count 5
//List Work
//             Name                          Salary    Duration
#define work1 "Evil Lab Assistant",          100,      14
#define work2 "OWCA Hiring Manager",         4200,     21
#define work3 "Cikapundunginator Caretaker", 7000,     30
#define work4 "Mewing Specialist",           1000,     22
#define work5 "Inator Connoisseur",          997,      15

typedef struct {
  char name[50];
  int salary;
  int duration;
} work;

void work_(TabInt *arruser, int useridx);

#endif