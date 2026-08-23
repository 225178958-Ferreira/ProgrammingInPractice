#include <stdio.h>

int main()
{
    char municipality[50];
    char mayor[50];
    int population;

    printf("Enter Municipality Name: ");
    scanf("%49s", municipality);

    printf("Enter Mayor: ");
    scanf("%49s", mayor);

    printf("Enter Population: ");
    scanf("%d", &population);

    printf("--------------------------------\n");
    printf("Municipality: %s\n", municipality);
    printf("Mayor: %s\n", mayor);
    printf("Population: %d\n", population);

    // to pause so the window doesnt close immediately
    printf("\nPress Enter to exit...");
    getchar(); 
    getchar(); // wait for Enter

    return 0;
}
