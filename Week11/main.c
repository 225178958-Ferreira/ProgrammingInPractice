#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "records.h"

/* Arrays and Counters */

Employee employees[MAX_RECORDS];
int employeeCount = 0;

Supplier suppliers[MAX_RECORDS];
int supplierCount = 0;

Asset assets[MAX_RECORDS];
int assetCount = 0;

Budget budgets[MAX_RECORDS];
int budgetCount = 0;

Project projects[MAX_RECORDS];
int projectCount = 0;

/* Function Prototypes */

void addEmployee();
void displayEmployees();
void saveEmployees();
void loadEmployees();

void addSupplier();
void displaySuppliers();

void addAsset();
void displayAssets();

void addBudget();
void displayBudgets();

void addProject();
void displayProjects();

/* Main */

int main()
{
    int choice;

    loadEmployees();

    do
    {
        printf("\n===== MFMS WEEK 11 =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Add Supplier\n");
        printf("4. Display Suppliers\n");
        printf("5. Add Asset\n");
        printf("6. Display Assets\n");
        printf("7. Add Budget\n");
        printf("8. Display Budgets\n");
        printf("9. Add Project\n");
        printf("10. Display Projects\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
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
                addSupplier();
                break;

            case 4:
                displaySuppliers();
                break;

            case 5:
                addAsset();
                break;

            case 6:
                displayAssets();
                break;

            case 7:
                addBudget();
                break;

            case 8:
                displayBudgets();
                break;

            case 9:
                addProject();
                break;

            case 10:
                displayProjects();
                break;

            case 0:
                saveEmployees();
                printf("Data saved.\n");
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
        printf("Employee array full.\n");
        return;
    }

    printf("Employee ID: ");
    scanf("%d", &employees[employeeCount].id);

    printf("Name: ");
    scanf(" %29[^\n]", employees[employeeCount].name);

    printf("Department: ");
    scanf(" %19[^\n]", employees[employeeCount].department);

    printf("Salary: ");
    scanf("%lf", &employees[employeeCount].salary);

    employeeCount++;

    printf("Employee added.\n");
}

void displayEmployees()
{
    int i;

    if(employeeCount == 0)
    {
        printf("No employees found.\n");
        return;
    }

    printf("\n%-6s %-20s %-15s %-10s\n",
           "ID","NAME","DEPARTMENT","SALARY");

    for(i = 0; i < employeeCount; i++)
    {
        printf("%-6d %-20s %-15s %.2lf\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

void saveEmployees()
{
    FILE *fp = fopen("employees.dat", "wb");

    if(fp == NULL)
        return;

    fwrite(&employeeCount, sizeof(int), 1, fp);
    fwrite(employees, sizeof(Employee), employeeCount, fp);

    fclose(fp);
}

void loadEmployees()
{
    FILE *fp = fopen("employees.dat", "rb");

    if(fp == NULL)
        return;

    fread(&employeeCount, sizeof(int), 1, fp);
    fread(employees, sizeof(Employee), employeeCount, fp);

    fclose(fp);
}

/* Supplier Functions */

void addSupplier()
{
    if(supplierCount >= MAX_RECORDS)
    {
        printf("Supplier array full.\n");
        return;
    }

    printf("Supplier ID: ");
    scanf("%d", &suppliers[supplierCount].id);

    printf("Name: ");
    scanf(" %39[^\n]", suppliers[supplierCount].name);

    printf("Email: ");
    scanf(" %39s", suppliers[supplierCount].email);

    printf("Phone: ");
    scanf(" %14s", suppliers[supplierCount].phone);

    printf("Town: ");
    scanf(" %19s", suppliers[supplierCount].town);

    supplierCount++;

    printf("Supplier added.\n");
}

void displaySuppliers()
{
    int i;

    for(i = 0; i < supplierCount; i++)
    {
        printf("%d %s %s %s %s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
}

/* Asset Functions */

void addAsset()
{
    if(assetCount >= MAX_RECORDS)
    {
        printf("Asset array full.\n");
        return;
    }

    printf("Asset ID: ");
    scanf("%d", &assets[assetCount].id);

    printf("Description: ");
    scanf(" %39[^\n]", assets[assetCount].description);

    printf("Value: ");
    scanf("%lf", &assets[assetCount].value);

    printf("Acquired Day: ");
    scanf("%d", &assets[assetCount].acquired.day);

    printf("Acquired Month: ");
    scanf("%d", &assets[assetCount].acquired.month);

    printf("Acquired Year: ");
    scanf("%d", &assets[assetCount].acquired.year);

    assetCount++;
}

void displayAssets()
{
    int i;

    for(i = 0; i < assetCount; i++)
    {
        printf("%d %s %.2lf %02d/%02d/%04d\n",
               assets[i].id,
               assets[i].description,
               assets[i].value,
               assets[i].acquired.day,
               assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

/* Budget Functions */

void addBudget()
{
    if(budgetCount >= MAX_RECORDS)
    {
        printf("Budget array full.\n");
        return;
    }

    printf("Department: ");
    scanf(" %19[^\n]", budgets[budgetCount].department);

    printf("Allocated: ");
    scanf("%lf", &budgets[budgetCount].allocated);

    printf("Spent: ");
    scanf("%lf", &budgets[budgetCount].spent);

    budgetCount++;
}

void displayBudgets()
{
    int i;
    double balance;

    for(i = 0; i < budgetCount; i++)
    {
        balance = budgets[i].allocated -
                  budgets[i].spent;

        printf("%s Allocated: %.2lf Spent: %.2lf Balance: %.2lf\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].spent,
               balance);
    }
}

/* Project Functions */

void addProject()
{
    if(projectCount >= MAX_RECORDS)
    {
        printf("Project array full.\n");
        return;
    }

    printf("Project ID: ");
    scanf("%d", &projects[projectCount].id);

    printf("Title: ");
    scanf(" %39[^\n]", projects[projectCount].title);

    printf("Budget: ");
    scanf("%lf", &projects[projectCount].budget);

    printf("Start Day: ");
    scanf("%d", &projects[projectCount].startDate.day);

    printf("Start Month: ");
    scanf("%d", &projects[projectCount].startDate.month);

    printf("Start Year: ");
    scanf("%d", &projects[projectCount].startDate.year);

    printf("End Day: ");
    scanf("%d", &projects[projectCount].endDate.day);

    printf("End Month: ");
    scanf("%d", &projects[projectCount].endDate.month);

    printf("End Year: ");
    scanf("%d", &projects[projectCount].endDate.year);

    projectCount++;
}

void displayProjects()
{
    int i;

    for(i = 0; i < projectCount; i++)
    {
        printf("%d %s %.2lf\n",
               projects[i].id,
               projects[i].title,
               projects[i].budget);
    }
}