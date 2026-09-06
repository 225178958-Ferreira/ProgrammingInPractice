#include <stdio.h>

int main() {
    double revenue, expenses, balance;
    int departments;
    double payroll, procurement, assets;

    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);


    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter Payroll amount: ");
    scanf("%lf", &payroll);

    printf("Enter Procurement amount: ");
    scanf("%lf", &procurement);

    printf("Enter Assets value: ");
    scanf("%lf", &assets);


    balance = revenue - expenses;

    
    printf("\n--- Municipal Financial Summary ---\n");
    printf("Revenue:      %.2f\n", revenue);
    printf("Expenses:     %.2f\n", expenses);
    printf("Balance:      %.2f\n", balance);
    printf("Departments:  %d\n", departments);
    printf("Payroll:      %.2f\n", payroll);
    printf("Procurement:  %.2f\n", procurement);
    printf("Assets:       %.2f\n", assets);

    return 0;
}