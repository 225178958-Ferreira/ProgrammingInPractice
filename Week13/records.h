#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct
{
    char department[20];
    double allocated;
    double spent;
} Budget;

#endif