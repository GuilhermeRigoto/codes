#include <stdio.h>

int main()
{

    char *productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    float productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = 7;

    printf("Before Sorting:\n");

    for (int i = 0; i < size - 1; i++)
    {
        printf(" %s -  %.2f", productNames[i], productPrices[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    for (int i = 0; i < size - 1; i++)
    {
        if (productPrices[i] > productPrices[i + 1])
        {
            float tempPrice = productPrices[i];
            productPrices[i] = productPrices[i + 1];
            productPrices[i + 1] = tempPrice;

            char *tempName = productNames[i];
            productNames[i] = productNames[i + 1];
            productNames[i + 1] = tempName;
        }
    }

    printf("After Single Pass:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %.2f", productNames[i], productPrices[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("\n");

    return 0;

    return 0;
}