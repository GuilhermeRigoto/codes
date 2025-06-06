#include <stdio.h>

int main()
{
    float groceries = 1040.25;
    float rent = 330.25;
    float utilities = 223.50;
    float total = groceries + rent + utilities;

    printf("The total of the apartment is £%.2f\n", total);

    return 0;
}