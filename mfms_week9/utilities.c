// utilities.c
#include <stdio.h>
#include "utilities.h"

int getInt(const char *prompt) {
    int val;
    printf("%s", prompt);
    scanf("%d", &val);
    return val;
}

double getDouble(const char *prompt) {
    double val;
    printf("%s", prompt);
    scanf("%lf", &val);
    return val;
}

void runUtilities(void) {
    printf("Utilities: input helpers available.\n");
}
