#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUPPLIERS 5
#define MAX_LEN 50

// function to validate that a string contains only digits
int isValidPhone(const char *phone) {
    int len = strlen(phone);
    if (len == 0) return 0; // empty string not valid

    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) {
            return 0; // found a non-digit character
        }
    }
    return 1; // all digits
}

int main() {
    char names[MAX_SUPPLIERS][MAX_LEN];
    char emails[MAX_SUPPLIERS][MAX_LEN];
    char phones[MAX_SUPPLIERS][MAX_LEN];
    char towns[MAX_SUPPLIERS][MAX_LEN];

    char searchName[MAX_LEN];
    int i, found = 0;

    printf("Enter details for %d suppliers:\n", MAX_SUPPLIERS);

    for (i = 0; i < MAX_SUPPLIERS; i++) {
        printf("\nSupplier %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", names[i]);

        printf("Email: ");
        scanf(" %[^\n]", emails[i]);

        // Phon  e input with validation loop
        while (1) {
            printf("Phone (digits only): ");
            scanf(" %[^\n]", phones[i]);

            if (isValidPhone(phones[i])) {
                break; // valid input
            } else {
                printf("Invalid phone number! Please enter digits only.\n");
            }
        }

        printf("Town: ");
        scanf(" %[^\n]", towns[i]);
    }

    printf("\nEnter supplier name to search: ");
    scanf(" %[^\n]", searchName);

    for (i = 0; i < MAX_SUPPLIERS; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("\nSupplier found!\n");
            printf("Name: %s\n", names[i]);
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town: %s\n", towns[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nSupplier with name '%s' not found.\n", searchName);
    }

    return 0;
}
