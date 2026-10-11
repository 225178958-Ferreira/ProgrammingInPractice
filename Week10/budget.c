// budget.c
#include <stdio.h>
#include "budget.h"

 Budget budgets[MAX_BUDGETS];
 int budgetCount = 0;

void manageBudget(void) {
    int choice;
    do {
        printf("\n--- Budget Menu ---\n");
        printf("1. Add Budget Item\n");
        printf("2. List Budget Items\n");
        printf("3. Average Budget\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1 && budgetCount < MAX_BUDGETS) {
            printf("Enter Category: ");
            scanf("%49s", budgets[budgetCount].category);
            printf("Enter Amount: ");
            scanf("%lf", &budgets[budgetCount].amount);
            budgetCount++;
        } else if (choice == 2) {
            for (int i = 0; i < budgetCount; i++) {
                printf("%s - %.2f\n", budgets[i].category, budgets[i].amount);
            }
        } else if (choice == 3 && budgetCount > 0) {
            double sum = 0;
            for (int i = 0; i < budgetCount; i++) sum += budgets[i].amount;
            printf("Average Budget: %.2f\n", sum / budgetCount);
        }
    } while (choice != 0);
}

/* --- NEW FUNCTIONS BELOW --- */

void saveBudgetsText() {
    FILE *fp = fopen("data/budgets.txt", "w");
    if (fp == NULL) { perror("data/budgets.txt"); return; }
    for (int i = 0; i < budgetCount; i++) {
        fprintf(fp, "%s|%.2f\n",
                budgets[i].category,
                budgets[i].amount);
    }
    fclose(fp);
}

void loadBudgetsText() {
    FILE *fp = fopen("data/budgets.txt", "r");
    if (fp == NULL) { perror("data/budgets.txt"); return; }
    budgetCount = 0;
    while (fscanf(fp, "%49[^|]|%lf\n",
                  budgets[budgetCount].category,
                  &budgets[budgetCount].amount) == 2) {
        budgetCount++;
    }
    fclose(fp);
}