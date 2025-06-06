#include <stdio.h>

int main(void)
{
    int choice;
    float input, result;
    char continueChoice;
    int count = 0;

    do
    {
        // Display the conversion menu
        printf("\nChoose the type of conversion:\n");
        printf("1: Length (kilometers to miles)\n");
        printf("2: Weight (kilograms to pounds)\n");
        printf("3: Time (hours to minutes)\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        // Perform the selected conversion
        switch (choice)
        {
        case 1:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &input);
            result = input * 0.621371;
            printf("%.2f kilometers is equal to %.2f miles\n", input, result);
            count++;
            break;

        case 2:
            printf("Enter the weight in kilograms: ");
            scanf("%f", &input);
            result = input * 2.20462;
            printf("%.2f kilograms is equal to %.2f pounds\n", input, result);
            count++;
            break;

        case 3:
            printf("Enter the time in hours: ");
            scanf("%f", &input);
            result = input * 60;
            printf("%.2f hours is equal to %.2f minutes\n", input, result);
            count++;
            break;

        default:
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }

        // Prompt the user to continue or exit
        printf("Do you want to perform another conversion? (y/n): ");
        getchar(); // Consume the newline character left in the buffer
        scanf("%c", &continueChoice);

    } while (continueChoice == 'y' || continueChoice == 'Y');

    // Display the total number of conversions performed
    printf("\nYou performed a total of %d conversions.\n", count);
    return 0;
}