#include <stdio.h>

int main() {
    float salaries[50];
    float total = 0, average, highest, lowest;
    int i;

    
    printf("Enter the salaries of 50 employees (in NAD):\n");
    for (i = 0; i < 50; i++) {
        printf("Employee %d salary (NAD): ", i + 1);
        scanf("%f", &salaries[i]);
        total += salaries[i];  //total salary calculation
    }

    
    printf("\nTotal Salary: %.2f NAD\n", total);

    
    average = total / 50;
    printf("Average Salary: %.2f NAD\n", average);

   
    highest = salaries[0];
    lowest = salaries[0];
    for (i = 1; i < 50; i++) {
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }

    
    printf("Highest Salary: %.2f NAD\n", highest);
    printf("Lowest Salary: %.2f NAD\n", lowest);

    return 0;
}
