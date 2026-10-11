// employees.c
#include <stdio.h>
#include <string.h>
#include "employees.h"

 Employee employees[MAX_EMPLOYEES];
 int empCount = 0;

void manageEmployees(void) {
    int choice;
    do {
        printf("\n--- Employee Menu ---\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1 && empCount < MAX_EMPLOYEES) {
            printf("Enter ID: ");
            scanf("%d", &employees[empCount].id);
            printf("Enter Name: ");
            scanf("%49s", employees[empCount].name);
            printf("Enter Salary: ");
            scanf("%lf", &employees[empCount].salary);
            empCount++;
        } else if (choice == 2) {
            for (int i = 0; i < empCount; i++) {
                printf("%d: %s - %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            }
        }
    } while (choice != 0);
}
