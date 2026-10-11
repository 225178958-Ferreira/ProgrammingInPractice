#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void generateReports(void) {
    printf("\n--- Reports ---\n");

    double totalSalary = 0;
    for (int i = 0; i < empCount; i++) totalSalary += employees[i].salary;
    printf("Total Employees: %d\n", empCount);
    printf("Total Salary Expense: %.2f\n", totalSalary);

    double totalBudget = 0;
    for (int i = 0; i < budgetCount; i++) totalBudget += budgets[i].amount;
    printf("Total Budget Items: %d\n", budgetCount);
    printf("Total Budget Amount: %.2f\n", totalBudget);
}
