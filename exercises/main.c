#include <stdio.h>

#define VAT_RATE 0.15

int main(void) {
    int choice;
    int quantity;
    float price, subtotal = 0.0, vat, total;

    do {
     
        printf("\n===== SAFE POINT MENU =====\n");
        printf("1. Notebook   - 10.00 NAD\n");
        printf("2. Pen        - 2.50 NAD\n");
        printf("3. Backpack   - 35.00 NAD\n");
        printf("4. Checkout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            switch (choice) {
                case 1: price = 10.00; break;
                case 2: price = 2.50; break;
                case 3: price = 35.00; break;
            }

            subtotal += price * quantity;
            printf("Item added! Current subtotal: %.2f NAD\n", subtotal);
        } else if (choice == 4) {
            printf("\nProceeding to checkout...\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    // VAT calculation
    vat = subtotal * VAT_RATE;
    total = subtotal + vat;

    // Invoice display
    printf("\n===== FINAL INVOICE =====\n");
    printf("Subtotal : %.2f NAD\n", subtotal);
    printf("VAT (15%%): %.2f NAD\n", vat);
    printf("Total    : %.2f NAD\n", total);
    printf("=========================\n");

    return 0;
}
