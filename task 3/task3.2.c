#include <stdio.h>

int main(void)
{
    float kilometers, miles;
    char choice = 'y';
    int count = 0;

    while (choice == 'y' || choice == 'Y')
    {
        // Ask for input in kilometers
        printf("Enter the distance in kilometers: ");
        scanf("%f", &kilometers);

        // Convert to miles
        miles = kilometers * 0.621371;
        printf("%.2f kilometers is equal to %.2f miles\n", kilometers, miles);

        count++; // Increase the conversion count

        // Ask if the user wants to continue
        printf("Do you want to convert another distance (y/n): ");
        getchar();
        scanf("%c", &choice);
    }

    printf("You performed a total of %d conversions.\n", count);
    return 0;
}