#include <stdio.h>

int main(void) { 

    double basicSalary, housing, transport, tax;
    double grossSalary, netSalary;

    printf("Enter Basic Salary: ");
    scanf("%lf", &basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%lf", &housing);

    printf("Enter Transport Allowence: ");
    scanf("%lf", &transport);

    printf("Enter Tax: ");
    scanf("%lf", &tax);

    grossSalary = basicSalary + housing + transport; 

        if (grossSalary > 15000) {
        printf("\nGross Salary exceeds NAD 15,000. Applying tax\n");
        tax = tax + 0.15 * grossSalary;  

        }
    netSalary = grossSalary - tax; 

    

    printf("\n    Salary Summary \n");
    printf("Gross Salary: NAD %.2f\n", grossSalary);
    printf("Net Salary: NAD %.2f\n", netSalary);


    return 0;
}