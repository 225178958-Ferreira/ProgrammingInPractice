#include <stdio.h>
#include <string.h>
#include "records.h"

/* Global Employee Array */

Employee employees[MAX_RECORDS];
int employeeCount = 0;

/* Function Prototypes */

void addEmployee();
void displayEmployees();

void swapSalaries(double *a, double *b);
void wrongSwap(double a, double b);

void displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
double calculateAverage(const double salaries[], int n);
void giveRaise(double salaries[], int n, double percent);

void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);

/* Main */

int main()
{
    int choice;

    do
    {
        printf("\n===== WEEK 12 MFMS =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee Salary\n");
        printf("4. Demonstrate Swap Salaries\n");
        printf("5. Demonstrate Array Functions\n");
        printf("0. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
            {
                int id;
                double newSalary;

                Employee *emp;

                printf("Employee ID: ");
                scanf("%d", &id);

                emp = findEmployee(
                        employees,
                        employeeCount,
                        id);

                if(emp == NULL)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    printf("New Salary: ");
                    scanf("%lf", &newSalary);

                    updateSalary(emp, newSalary);

                    printf("Employee updated successfully.\n");

                    printf("ID: %d\n", emp->id);
                    printf("Name: %s\n", emp->name);
                    printf("Department: %s\n", emp->department);
                    printf("Salary: %.2lf\n", emp->salary);
                }

                break;
            }

            case 4:
            {
                double s1 = 10000;
                double s2 = 20000;

                printf("\nCorrect Swap\n");
                printf("Before: %.2lf %.2lf\n", s1, s2);

                swapSalaries(&s1, &s2);

                printf("After: %.2lf %.2lf\n", s1, s2);

                s1 = 10000;
                s2 = 20000;

                printf("\nWrong Swap\n");
                printf("Before: %.2lf %.2lf\n", s1, s2);

                wrongSwap(s1, s2);

                printf("After: %.2lf %.2lf\n", s1, s2);

                break;
            }

            case 5:
            {
                double salaries[] =
                {
                    10000,
                    15000,
                    20000
                };

                int size = 3;

                printf("\nOriginal Salaries:\n");
                displaySalaries(salaries, size);

                printf("Highest Salary: %.2lf\n",
                       findHighest(salaries, size));

                printf("Average Salary: %.2lf\n",
                       calculateAverage(salaries, size));

                giveRaise(salaries, size, 10);

                printf("\nAfter 10%% Raise:\n");
                displaySalaries(salaries, size);

                break;
            }

            case 0:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 0);

    return 0;
}

/* Employee Functions */

void addEmployee()
{
    if(employeeCount >= MAX_RECORDS)
    {
        printf("Array full.\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &employees[employeeCount].id);

    printf("Name: ");
    scanf(" %29[^\n]",
          employees[employeeCount].name);

    printf("Department: ");
    scanf(" %19[^\n]",
          employees[employeeCount].department);

    printf("Salary: ");
    scanf("%lf",
          &employees[employeeCount].salary);

    employeeCount++;

    printf("Employee added.\n");
}

void displayEmployees()
{
    int i;

    if(employeeCount == 0)
    {
        printf("No employees.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("ID\tNAME\t\tDEPARTMENT\tSALARY\n");
    printf("-------------------------------------------------\n");

    for(i = 0; i < employeeCount; i++)
    {
        printf("%d\t%s\t\t%s\t\t%.2lf\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

/* Pointer Functions */

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void wrongSwap(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

/* Array Functions */

void displaySalaries(const double salaries[],
                     int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%.2lf ", salaries[i]);
    }

    printf("\n");
}

double findHighest(const double salaries[],
                   int n)
{
    int i;
    double highest = salaries[0];

    for(i = 1; i < n; i++)
    {
        if(salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }

    return highest;
}

double calculateAverage(const double salaries[],
                        int n)
{
    int i;
    double total = 0;

    for(i = 0; i < n; i++)
    {
        total += salaries[i];
    }

    return total / n;
}

void giveRaise(double salaries[],
               int n,
               double percent)
{
    int i;

    for(i = 0; i < n; i++)
    {
        salaries[i] +=
        salaries[i] * percent / 100.0;
    }
}

/* Employee Pointer Functions */

void updateSalary(Employee *e,
                  double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[],
                       int n,
                       int id)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(list[i].id == id)
        {
            return &list[i];
        }
    }

    return NULL;
}