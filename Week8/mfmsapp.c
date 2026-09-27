#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUPPLIERS 5   // maximum number of suppliers we can store
#define MAX_LEN 50        // maximum length for each string (name, email, etc.)

// ===== Function Prototypes =====
void displayWelcome();   // shows welcome message
void displayMenu();      // shows main menu
float calculateVAT(float amount);   // calculates VAT at 15%
float calculateSalary(float basic, float housing, float transport); // adds salary components
float calculateBudget(float revenue, float expenses); // revenue - expenses
int searchEmployee(int id, int ids[], int size); // searches employee ID

// Supplier Management
void addSupplier(char names[][MAX_LEN], char emails[][MAX_LEN],
                 char phones[][MAX_LEN], char towns[][MAX_LEN], int *count);
void displaySuppliers(char names[][MAX_LEN], char emails[][MAX_LEN],
                      char phones[][MAX_LEN], char towns[][MAX_LEN], int count);
void searchSupplier(char names[][MAX_LEN], char emails[][MAX_LEN],
                    char phones[][MAX_LEN], char towns[][MAX_LEN], int count);

// Helper
int isValidPhone(const char *phone); // checks if phone contains only digits

// ===== Function Implementations =====

// LAB TASK 1 — Welcome function
void displayWelcome() {
    printf("Welcome to the Municipal Financial Management System\n");
}

// LAB TASK 5 — Menu function
void displayMenu() {
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Employee Management (Search)\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

// LAB TASK 2 — VAT function
float calculateVAT(float amount) {
    return amount * 0.15f; // 15% VAT
}

// LAB TASK 3 — Salary function
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport; // gross salary
}

// LAB TASK 4 — Budget function
float calculateBudget(float revenue, float expenses) {
    float result = revenue - expenses;
    if (result > 0) {
        printf("SURPLUS\n");
    } else if (result < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
    return result;
}

// LAB TASK 6 — Employee search function
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) return i; // return position if found
    }
    return -1; // return -1 if not found
}

// ===== Supplier Management =====

// Add supplier details
void addSupplier(char names[][MAX_LEN], char emails[][MAX_LEN],
                 char phones[][MAX_LEN], char towns[][MAX_LEN], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier list is full!\n");
        return;
    }
    printf("Enter supplier details:\n");
    printf("Name: ");
    scanf(" %[^\n]", names[*count]);
    printf("Email: ");
    scanf(" %[^\n]", emails[*count]);

    // Validate phone input (digits only)
    while (1) {
        printf("Phone (digits only): ");
        scanf(" %[^\n]", phones[*count]);
        if (isValidPhone(phones[*count])) break;
        else printf("Invalid phone number! Try again.\n");
    }

    printf("Town: ");
    scanf(" %[^\n]", towns[*count]);
    (*count)++; // increase supplier count
}

// Display all suppliers
void displaySuppliers(char names[][MAX_LEN], char emails[][MAX_LEN],
                      char phones[][MAX_LEN], char towns[][MAX_LEN], int count) {
    if (count == 0) {
        printf("No suppliers available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("Name: %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town: %s\n", towns[i]);
    }
}

// Search supplier by name
void searchSupplier(char names[][MAX_LEN], char emails[][MAX_LEN],
                    char phones[][MAX_LEN], char towns[][MAX_LEN], int count) {
    char searchName[MAX_LEN];
    printf("Enter supplier name to search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("\nSupplier found!\n");
            printf("Name: %s\n", names[i]);
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town: %s\n", towns[i]);
            return;
        }
    }
    printf("Supplier not found.\n");
}

// Helper function to validate phone numbers
int isValidPhone(const char *phone) {
    int len = strlen(phone);
    if (len == 0) return 0; // empty string not valid
    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) return 0; // reject non-digit
    }
    return 1; // valid if all digits
}

// ===== Main Program =====
int main() {
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105}; // sample employee IDs
    int size = 5;

    // Arrays to store supplier info
    char names[MAX_SUPPLIERS][MAX_LEN];
    char emails[MAX_SUPPLIERS][MAX_LEN];
    char phones[MAX_SUPPLIERS][MAX_LEN];
    char towns[MAX_SUPPLIERS][MAX_LEN];
    int supplierCount = 0; // how many suppliers added

    displayWelcome(); // show welcome message

    // Main loop
    do {
        displayMenu(); // show menu
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // VAT
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            }
            case 2: { // Salary
                float basic, housing, transport;
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 3: { // Budget
                float revenue, expenses;
                printf("Revenue: ");
                scanf("%f", &revenue);
                printf("Expenses: ");
                scanf("%f", &expenses);
                printf("Result: %.2f\n", calculateBudget(revenue, expenses));
                break;
            }
            case 4: { // Employee search
                int id;
                printf("Enter employee ID: ");
                scanf("%d", &id);
                int pos = searchEmployee(id, employeeIDs, size);
                if (pos != -1)
                    printf("Employee found at position %d.\n", pos);
                else
                    printf("Employee not found.\n");
                break;
            }
            case 5: { // Supplier management submenu
                int subChoice;
                printf("\nSupplier Management\n");
                printf("1. Add Supplier\n");
                printf("2. Display Suppliers\n");
                printf("3. Search Supplier\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);

                if (subChoice == 1) addSupplier(names, emails, phones, towns, &supplierCount);
                else if (subChoice == 2) displaySuppliers(names, emails, phones, towns, supplierCount);
                else if (subChoice == 3) searchSupplier(names, emails, phones, towns, supplierCount);
                else printf("Invalid choice.\n");
                break;
            }
            case 6: // Exit
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6); // loop until user chooses Exit

    return 0;
}
