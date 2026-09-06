#include <stdio.h>

int main(void) {

    char supplierName[50]; 
    double price, budget; 
    int registered, documentsComplete;

    printf("Enter Supplier name: "); 
    scanf("%49s", supplierName); 
    printf("Enter tender price: "); 
    scanf("%lf", &price); 
    printf("Enter available budget: "); 
    scanf("%lf", &budget); 
    printf("Is supplier registered? (1=Yes, 0=No): "); 
    scanf("%d", &registered); 
    printf("Are all documents complete? (1=Yes, 0=No): "); 
    scanf("%d", &documentsComplete); 

    return 0;
 }