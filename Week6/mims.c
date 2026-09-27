#include <stdio.h>
#include <string.h>

int main() {
    // --- Employee Salaries ---
    float salaries[50], salarySum = 0, salaryAverage, highest, lowest, searchSalary;
    int i, found = 0;

    printf("=== Employee Salaries ===\n");
    for (i = 0; i < 50; i++) {
        printf("Enter salary for Employee %d (NAD): ", i + 1);
        scanf("%f", &salaries[i]);
        salarySum += salaries[i];
    }

    printf("\n--- Salaries Entered ---\n");
    for (i = 0; i < 50; i++) {
        printf("Employee %d: %.2f NAD\n", i + 1, salaries[i]);
    }

    salaryAverage = salarySum / 50;
    highest = salaries[0];
    lowest = salaries[0];
    for (i = 1; i < 50; i++) {
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }

    printf("\nAverage Salary: %.2f NAD\n", salaryAverage);
    printf("Highest Salary: %.2f NAD\n", highest);
    printf("Lowest Salary: %.2f NAD\n", lowest);

    printf("\nEnter salary to search (NAD): ");
    scanf("%f", &searchSalary);
    for (i = 0; i < 50; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary %.2f NAD found at Employee %d\n", searchSalary, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Salary %.2f NAD not found.\n", searchSalary);
    }

    // --- Department Budgets ---
    float budgets[10], budgetSum = 0, budgetAverage, temp;
    int j;

    printf("\n\n=== Department Budgets ===\n");
    for (i = 0; i < 10; i++) {
        printf("Enter budget for Department %d (NAD): ", i + 1);
        scanf("%f", &budgets[i]);
        budgetSum += budgets[i];
    }

    printf("\n--- Budgets Entered ---\n");
    for (i = 0; i < 10; i++) {
        printf("Department %d: %.2f NAD\n", i + 1, budgets[i]);
    }

    budgetAverage = budgetSum / 10;
    printf("\nTotal Budget: %.2f NAD\n", budgetSum);
    printf("Average Budget: %.2f NAD\n", budgetAverage);

    // Sort budgets ascending
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (budgets[i] > budgets[j]) {
                temp = budgets[i];
                budgets[i] = budgets[j];
                budgets[j] = temp;
            }
        }
    }

    printf("\nBudgets sorted (lowest to highest):\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", budgets[i]);
    }
    printf("\n");

    // --- Vehicle Registrations ---
    char registrations[20][20], searchReg[20];
    found = 0;

    printf("\n\n=== Vehicle Registrations ===\n");
    for (i = 0; i < 20; i++) {
        printf("Enter registration number for Vehicle %d: ", i + 1);
        scanf("%s", registrations[i]);
    }

    printf("\n--- Registrations Entered ---\n");
    for (i = 0; i < 20; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter registration number to search: ");
    scanf("%s", searchReg);

    for (i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration %s found at Vehicle %d\n", searchReg, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Registration %s not found.\n", searchReg);
    }

    return 0;
}
