#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================
// Struct Definitions
// =============================
typedef struct {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

typedef struct {
    char department[30];
    float allocatedBudget;
    float expenditure;
} Budget;

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
    char town[30];
} Supplier;

typedef struct {
    int id;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

// =============================
// Global Arrays
// =============================
Employee employees[50];
int employeeCount = 0;

Budget budgets[10];
int budgetCount = 0;

Supplier suppliers[20];
int supplierCount = 0;

Asset assets[20];
int assetCount = 0;

// =============================
// Function Prototypes
// =============================
void displayMenu();
void employeeManagement();
void budgetManagement();
void supplierManagement();
void assetManagement();
void reports();

// Employee functions
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateSalaryInfo();

// Budget functions
void addBudget();
void displayBudgets();
void checkBudgetStatus();

// Supplier functions
void addSupplier();
void displaySuppliers();
void searchSupplier();

// Asset functions
void addAsset();
void displayAssets();
void searchAsset();

// Report functions
void employeeReport();
void budgetReport();
void supplierReport();
void assetReport();

// =============================
// Main Function
// =============================
int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: employeeManagement(); break;
            case 2: budgetManagement(); break;
            case 3: supplierManagement(); break;
            case 4: assetManagement(); break;
            case 5: reports(); break;
            case 6: printf("Exiting system...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// =============================
// Menu Display
// =============================
void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}

// =============================
// Employee Management
// =============================
void employeeManagement() {
    int choice;
    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary Info\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalaryInfo(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 5);
}

void addEmployee() {
    if(employeeCount < 50) {
        Employee e;
        printf("Enter Employee ID: ");
        scanf("%d", &e.id);
        printf("Enter Name: ");
        scanf("%s", e.name);
        printf("Enter Department: ");
        scanf("%s", e.department);
        printf("Enter Basic Salary: ");
        scanf("%f", &e.basicSalary);
        printf("Enter Housing Allowance: ");
        scanf("%f", &e.housingAllowance);
        printf("Enter Transport Allowance: ");
        scanf("%f", &e.transportAllowance);

        // use strlen() to validate name
        if(strlen(e.name) == 0) {
            printf("Invalid name. Cannot be empty.\n");
            return;
        }

        if(e.basicSalary < 0) {
            printf("Invalid salary. Must be positive.\n");
            return;
        }

        // strcpy() to copy into global array
        employees[employeeCount] = e;
        strcpy(employees[employeeCount].name, e.name);
        strcpy(employees[employeeCount].department, e.department);

        employeeCount++;

        // use strcat() to build confirmation message
        char confirmMsg[100];
        strcpy(confirmMsg, "Employee ");
        strcat(confirmMsg, e.name);
        strcat(confirmMsg, " added successfully!");
        printf("%s\n", confirmMsg);
    } else {
        printf("Employee list full.\n");
    }
}

void displayEmployees() {
    for(int i=0; i<employeeCount; i++) {
        float totalSalary = employees[i].basicSalary + employees[i].housingAllowance + employees[i].transportAllowance;
        printf("ID: %d, Name: %s, Dept: %s, Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].department, totalSalary);
    }
}

void searchEmployee() {
    char searchName[50];
    printf("Enter Employee Name to search: ");
    scanf("%s", searchName);

    for(int i=0; i<employeeCount; i++) {
        // usedd strcmp() to compare names
        if(strcmp(employees[i].name, searchName) == 0) {
            printf("Found: %s in %s Dept\n", employees[i].name, employees[i].department);
            return;
        }
    }
    printf("Employee not found.\n");
}

void calculateSalaryInfo() {
    if(employeeCount == 0) {
        printf("No employees.\n");
        return;
    }
    float total = 0, max = 0, min = 999999;
    for(int i=0; i<employeeCount; i++) {
        float salary = employees[i].basicSalary + employees[i].housingAllowance + employees[i].transportAllowance;
        total += salary;
        if(salary > max) max = salary;
        if(salary < min) min = salary;
    }
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: %.2f\n", total/employeeCount);
    printf("Highest Salary: %.2f\n", max);
    printf("Lowest Salary: %.2f\n", min);
}
// =============================
// Budget Management
// =============================
void budgetManagement() {
    int choice;
    do {
        printf("\n--- Budget Management ---\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Check Budget Status\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBudget(); break;
            case 2: displayBudgets(); break;
            case 3: checkBudgetStatus(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 4);
}

void addBudget() {
    if(budgetCount < 10) {
        Budget b;
        printf("Enter Department: ");
        scanf("%s", b.department);
        printf("Enter Allocated Budget: ");
        scanf("%f", &b.allocatedBudget);
        printf("Enter Expenditure: ");
        scanf("%f", &b.expenditure);

        if(b.allocatedBudget < 0 || b.expenditure < 0) {
            printf("Invalid values.\n");
            return;
        }

        budgets[budgetCount++] = b;
        printf("Budget added successfully!\n");
    } else {
        printf("Budget list full.\n");
    }
}

void displayBudgets() {
    for(int i=0; i<budgetCount; i++) {
        float remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        printf("Dept: %s, Allocated: %.2f, Expenditure: %.2f, Remaining: %.2f\n",
               budgets[i].department, budgets[i].allocatedBudget, budgets[i].expenditure, remaining);
    }
}

void checkBudgetStatus() {
    for(int i=0; i<budgetCount; i++) {
        if(budgets[i].expenditure <= budgets[i].allocatedBudget)
            printf("%s: WITHIN BUDGET\n", budgets[i].department);
        else
            printf("%s: EXCEEDED BUDGET\n", budgets[i].department);
    }
}

// =============================
// Supplier Management
// =============================
void addSupplier() {
    if(supplierCount < 20) {
        Supplier s;
        printf("Enter Supplier ID: ");
        scanf("%d", &s.id);
        printf("Enter Name: ");
        scanf("%s", s.name);
        printf("Enter Email: ");
        scanf("%s", s.email);
        printf("Enter Phone: ");
        scanf("%s", s.phone);
        printf("Enter Town: ");
        scanf("%s", s.town);

        // Basic validation
        if(strlen(s.name) == 0 || s.id <= 0) {
            printf("Invalid supplier data.\n");
            return;
        }

        suppliers[supplierCount++] = s;
        printf("Supplier added successfully!\n");
    } else {
        printf("Supplier list full.\n");
    }
}

void supplierManagement() {
    int choice;
    do {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 4);
}

void displaySuppliers() {
    for(int i=0; i<supplierCount; i++) {
        printf("ID: %d, Name: %s, Email: %s, Phone: %s, Town: %s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email,
               suppliers[i].phone, suppliers[i].town);
    }
}

void searchSupplier() {
    char name[50];
    printf("Enter Supplier Name to search: ");
    scanf("%s", name);
    for(int i=0; i<supplierCount; i++) {
        if(strcmp(suppliers[i].name, name) == 0) {
            printf("Found Supplier: %s, Email: %s, Phone: %s, Town: %s\n",
                   suppliers[i].name, suppliers[i].email,
                   suppliers[i].phone, suppliers[i].town);
            return;
        }
    }
    printf("Supplier not found.\n");
}

// =============================
// Asset Management
// =============================
void assetManagement() {
    int choice;
    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 4);
}

void addAsset() {
    if(assetCount < 20) {
        Asset a;
        printf("Enter Asset ID: ");
        scanf("%d", &a.id);
        printf("Enter Asset Name: ");
        scanf("%s", a.name);
        printf("Enter Asset Type: ");
        scanf("%s", a.type);
        printf("Enter Purchase Value: ");
        scanf("%f", &a.purchaseValue);
        printf("Enter Department: ");
        scanf("%s", a.department);
        printf("Enter Condition: ");
        scanf("%s", a.condition);

        if(a.purchaseValue < 0) {
            printf("Invalid purchase value.\n");
            return;
        }

        assets[assetCount++] = a;
        printf("Asset added successfully!\n");
    } else {
        printf("Asset list full.\n");
    }
}

void displayAssets() {
    for(int i=0; i<assetCount; i++) {
        printf("ID: %d, Name: %s, Type: %s, Value: %.2f, Dept: %s, Condition: %s\n",
               assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset() {
    int id;
    printf("Enter Asset ID to search: ");
    scanf("%d", &id);
    for(int i=0; i<assetCount; i++) {
        if(assets[i].id == id) {
            printf("Found Asset: %s, Type: %s, Dept: %s, Condition: %s\n",
                   assets[i].name, assets[i].type,
                   assets[i].department, assets[i].condition);
            return;
        }
    }
    printf("Asset not found.\n");
}

// =============================
// Reports
// =============================
void reports() {
    int choice;
    do {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 5);
}

void employeeReport() {
    calculateSalaryInfo(); // reuse salary calculation
}

void budgetReport() {
    float totalAlloc = 0, totalExp = 0;
    for(int i=0; i<budgetCount; i++) {
        totalAlloc += budgets[i].allocatedBudget;
        totalExp += budgets[i].expenditure;
    }
    printf("Total Allocated Budget: %.2f\n", totalAlloc);
    printf("Total Expenditure: %.2f\n", totalExp);
    printf("Remaining Budget: %.2f\n", totalAlloc - totalExp);
    checkBudgetStatus();
}

void supplierReport() {
    displaySuppliers();
}

void assetReport() {
    displayAssets();
}