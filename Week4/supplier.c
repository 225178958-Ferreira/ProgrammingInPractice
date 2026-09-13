#include <stdio.h>
#include <string.h>

struct Supplier {
    char name[50];
    int price;             
    int registered;        // 1 = Yes, 0 = No
    int documentsComplete; // 1 = Yes, 0 = No
};

int main() {
    int n, budget;
    printf("Enter available budget (NAD): ");
    scanf("%d", &budget);

    printf("Enter number of suppliers: ");
    scanf("%d", &n);

    struct Supplier suppliers[n];
    int status[n]; // 0 = Disqualified, 1 = Qualified, 2 = Preferred

    // Input supplier details
    for (int i = 0; i < n; i++) {
        printf("\nEnter supplier %d name: ", i + 1);
        scanf("%s", suppliers[i].name);

        printf("Enter supplier %d price (NAD): ", i + 1);
        scanf("%d", &suppliers[i].price);

        // Validate registration input
        do {
            printf("Registration valid? (1=Yes, 0=No): ");
            scanf("%d", &suppliers[i].registered);
            if (suppliers[i].registered != 0 && suppliers[i].registered != 1) {
                printf("Invalid input! Please enter 1 or 0.\n");
            }
        } while (suppliers[i].registered != 0 && suppliers[i].registered != 1);

        // Validate documents input
        do {
            printf("Documents complete? (1=Yes, 0=No): ");
            scanf("%d", &suppliers[i].documentsComplete);
            if (suppliers[i].documentsComplete != 0 && suppliers[i].documentsComplete != 1) {
                printf("Invalid input! Please enter 1 or 0.\n");
            }
        } while (suppliers[i].documentsComplete != 0 && suppliers[i].documentsComplete != 1);

        // Qualification check using relational + logical operators
        if (suppliers[i].registered == 1 &&
            suppliers[i].documentsComplete == 1 &&
            suppliers[i].price <= budget) {
            status[i] = 1; // Qualified
        } else {
            status[i] = 0; // Disqualified
        }
    }

    // Find preferred supplier (lowest price among qualified)
    int preferredIndex = -1;
    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            if (preferredIndex == -1 || suppliers[i].price < suppliers[preferredIndex].price) {
                preferredIndex = i;
            }
        }
    }
    if (preferredIndex != -1) {
        status[preferredIndex] = 2; 
    }

    
    printf("\n--- Tender Evaluation Results ---\n");
    for (int i = 0; i < n; i++) {
        printf("Supplier: %s | Price: %d NAD | Status: ", suppliers[i].name, suppliers[i].price);
        if (status[i] == 0) {
            printf("Disqualified\n");
        } else if (status[i] == 1) {
            printf("Qualified\n");
        } else if (status[i] == 2) {
            printf("Preferred Supplier\n");
        } else {
            printf("Unknown\n");
        }
    }

    return 0;
}