#include <stdio.h>
#include <string.h>

int main()
{
    char *productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    float productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = 7;

    printf("Before Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %.2f", productNames[i], productPrices[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    // Bubble Sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (productPrices[j] > productPrices[j + 1])
            {
                float tempPrice = productPrices[j];
                productPrices[j] = productPrices[j + 1];
                productPrices[j + 1] = tempPrice;

                char *tempName = productNames[j];
                productNames[j] = productNames[j + 1];
                productNames[j + 1] = tempName;
            }
        }
    }

    printf("After Price Sorting ( Ascending):\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %.2f", productNames[i], productPrices[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("\n");

    printf("\nBefore Name Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s", productNames[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    for (int i = 1; i < size; i++)
    {
        char *keyName = productNames[i];
        float keyPrice = productPrices[i];
        int j = i - 1;

        while (j >= 0 && strcmp(productNames[j], keyName) > 0)
        {

            productNames[j + 1] = productNames[j];
            productPrices[j + 1] = productPrices[j];
            j--;
        }
        productNames[j + 1] = keyName;
        productPrices[j + 1] = keyPrice;
    }

    printf("After Name Sorting (Alphabetical):\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %.2f", productNames[i], productPrices[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    return 0;
}