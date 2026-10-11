#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 100

typedef struct {
    char category[50];
    double amount;
} Budget;

extern Budget budgets[MAX_BUDGETS];
extern int budgetCount;

void manageBudget(void);
void saveBudgetsText(void);
void loadBudgetsText(void);

#endif
