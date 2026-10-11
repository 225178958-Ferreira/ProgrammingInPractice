#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

extern Employee employees[MAX_EMPLOYEES];
extern int empCount;

void manageEmployees(void);
void saveEmployeesText(void);
void loadEmployeesText(void);

#endif
