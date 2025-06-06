#include <stdio.h>

int main()
{

    char *productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    float productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int size = 7;

    printf("Product list with adjacent Produtcs:\n\n");

    for (int i = 0; i < size - 1; i++)
    {
        printf("Product: %s, Price %.2f | adjacent Product: %s, Price: %.2f\n",
               productNames[i], productPrices[i], productNames[i + 1], productPrices[i + 1]);
    }

    return 0;
}