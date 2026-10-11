// employees.h
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "config.h"

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

extern Employee employees[MAX_EMPLOYEES];
extern int empCount;

void manageEmployees(void);

#endif
