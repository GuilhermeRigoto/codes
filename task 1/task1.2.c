#include <stdio.h>

int main()
{
    float groceries, rent, utilities, total;
    float budgetLimit = 400.00;

    printf("Enter the value for groceries: ");
    scanf("%f", &groceries);

    printf("Enter the value for rent: ");
    scanf("%f", &rent);

    printf("Enter the value for utilities: ");
    scanf("%f", &utilities);

    total = groceries + rent + utilities;

    printf("Total expenses were: £%.2f\n", total);

    if (total <= budgetLimit)
    {
        printf("You are under your expenses.\n");
    }
    else
    {
        printf("You have exceeded your weekly budget.\n");
    }
}