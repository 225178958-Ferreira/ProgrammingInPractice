#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void) {
    int choice;
    do {
        printf("\n--- Municipal Financial Management System ---\n");
        printf("1. Manage Employees\n");
        printf("2. Manage Budget\n");
        printf("3. Reports\n");
        printf("0. Exit\n");
        choice = getInt("Enter choice: ");

        switch(choice) {
            case 1: manageEmployees(); break;
            case 2: manageBudget(); break;
            case 3: generateReports(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
