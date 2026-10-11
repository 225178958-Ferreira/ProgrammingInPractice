// suppliers.c
#include <stdio.h>
#include "suppliers.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void manageSuppliers(void) {
    int choice;
    do {
        printf("\n--- Supplier Menu ---\n");
        printf("1. Add Supplier\n");
        printf("2. List Suppliers\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1 && supplierCount < MAX_SUPPLIERS) {
            printf("Enter ID: ");
            scanf("%d", &suppliers[supplierCount].id);
            printf("Enter Name: ");
            scanf("%49s", suppliers[supplierCount].name);
            printf("Enter Town: ");
            scanf("%49s", suppliers[supplierCount].town);
            supplierCount++;
        } else if (choice == 2) {
            for (int i = 0; i < supplierCount; i++) {
                printf("%d: %s (%s)\n", suppliers[i].id, suppliers[i].name, suppliers[i].town);
            }
        }
    } while (choice != 0);
}
