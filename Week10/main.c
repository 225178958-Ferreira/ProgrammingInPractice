#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
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
        printf("4. Manage Suppliers\n"); 
        printf("7. Save Data\n");
        printf("8. Load Data\n");
        printf("0. Exit\n");
        choice = getInt("Enter choice: ");

        switch(choice) {
            case 1: manageEmployees(); break;
            case 2: manageBudget(); break;
            case 3: generateReports(); break;
            case 4: manageSuppliers(); break;
            case 7: // Save Data
                saveEmployeesText();
                saveSuppliersText();
                saveBudgetsText();
                printf("Data saved successfully.\n");
                break;
            case 8: // Load Data
                loadEmployeesText();
                loadSuppliersText();
                loadBudgetsText();
                printf("Data loaded successfully.\n");
                break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}


