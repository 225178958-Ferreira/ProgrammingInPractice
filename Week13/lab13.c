#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"

/* Global Variables */

Employee *employees = NULL;

int employeeCount = 0;
int employeeCapacity = 2;

/* Function Prototypes */

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void removeEmployee(void);
void shrinkToFit(void);

void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);

/* Main Function */

int main(void)
{
    int choice;

    employees = calloc(employeeCapacity,
                       sizeof(Employee));

    if(employees == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    do
    {
        printf("\n===== MFMS WEEK 13 =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee By ID\n");
        printf("4. Update Employee Salary\n");
        printf("5. Remove Employee\n");
        printf("6. Shrink To Fit\n");
        printf("0. Exit\n");

        printf("Enter Choice: ");
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
                searchEmployee();
                break;

            case 4:
            {
                int id;
                double salary;
                Employee *emp;

                printf("Enter Employee ID: ");
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
                    printf("Current Salary: %.2lf\n",
                           emp->salary);

                    printf("Enter New Salary: ");
                    scanf("%lf", &salary);

                    updateSalary(emp, salary);

                    printf("Salary updated successfully.\n");
                }

                break;
            }

            case 5:
                removeEmployee();
                break;

            case 6:
                shrinkToFit();
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 0);

    free(employees);
    employees = NULL;

    printf("Memory released successfully.\n");

    return 0;
}

/* Add Employee */

void addEmployee(void)
{
    Employee *bigger;

    if(employeeCount == employeeCapacity)
    {
        employeeCapacity *= 2;

        bigger = realloc(
                    employees,
                    employeeCapacity *
                    sizeof(Employee));

        if(bigger == NULL)
        {
            printf("Memory expansion failed.\n");
            return;
        }

        employees = bigger;

        printf("\nCapacity increased to %d employees.\n",
               employeeCapacity);
    }

    printf("Employee ID: ");
    scanf("%d",
          &employees[employeeCount].id);

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

    printf("Employee added successfully.\n");
}

/* Display Employees */

void displayEmployees(void)
{
    int i;

    if(employeeCount == 0)
    {
        printf("No employees found.\n");
        return;
    }

    printf("\nEmployees Stored: %d\n",
           employeeCount);

    printf("Current Capacity: %d\n\n",
           employeeCapacity);

    printf("%-8s %-20s %-15s %-12s\n",
           "ID",
           "NAME",
           "DEPARTMENT",
           "SALARY");

    printf("------------------------------------------------------------\n");

    for(i = 0; i < employeeCount; i++)
    {
        printf("%-8d %-20s %-15s %.2lf\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

/* Search Employee */

void searchEmployee(void)
{
    int id;
    int i;
    int found = 0;

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for(i = 0; i < employeeCount; i++)
    {
        if(employees[i].id == id)
        {
            printf("\nEmployee Found\n");

            printf("ID: %d\n",
                   employees[i].id);

            printf("Name: %s\n",
                   employees[i].name);

            printf("Department: %s\n",
                   employees[i].department);

            printf("Salary: %.2lf\n",
                   employees[i].salary);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Employee not found.\n");
    }
}

/* Remove Employee */

void removeEmployee(void)
{
    int id;
    int i;
    int position = -1;

    printf("Enter Employee ID to remove: ");
    scanf("%d", &id);

    for(i = 0; i < employeeCount; i++)
    {
        if(employees[i].id == id)
        {
            position = i;
            break;
        }
    }

    if(position == -1)
    {
        printf("Employee not found.\n");
        return;
    }

    for(i = position; i < employeeCount - 1; i++)
    {
        employees[i] = employees[i + 1];
    }

    employeeCount--;

    printf("Employee removed successfully.\n");
}

/* Shrink To Fit */

void shrinkToFit(void)
{
    Employee *smaller;

    if(employeeCount == employeeCapacity)
    {
        printf("Array already fits exactly.\n");
        return;
    }

    if(employeeCount == 0)
    {
        printf("No employees stored.\n");
        return;
    }

    smaller = realloc(
                employees,
                employeeCount *
                sizeof(Employee));

    if(smaller == NULL)
    {
        printf("Unable to shrink memory.\n");
        return;
    }

    employees = smaller;
    employeeCapacity = employeeCount;

    printf("Array shrunk successfully.\n");
    printf("New Capacity: %d\n",
           employeeCapacity);
}

/* Update Salary */

void updateSalary(Employee *e,
                  double newSalary)
{
    e->salary = newSalary;
}

/* Find Employee */

Employee *findEmployee(
        Employee list[],
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