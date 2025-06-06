#include <stdio.h>
#include <math.h>

int main()
{
    float rent, groceries, bills, apartment_cost, totalfirst, totalSecond;

    printf("Enter rent for first week: ");
    scanf("%f", &rent);
    printf("Enter groceries for first week: ");
    scanf("%f", &groceries);
    printf("Enter bills for first week: ");
    scanf("%f", &bills);
    printf("Enter other apartament costs for first week: ");
    scanf("%f", &apartment_cost);

    totalfirst = rent + groceries + bills + apartment_cost;
    printf("Your first week apartament costs are: £%.2f\n", totalfirst);

    printf("Enter rent for second week: ");
    scanf("%f", &rent);
    printf("Enter groceries for second week: ");
    scanf("%f", &groceries);
    printf("Enter bills for second week: ");
    scanf("%f", &bills);
    printf("Enter other apartament costs for second week: ");
    scanf("%f", &apartment_cost);

    totalSecond = rent + groceries + bills + apartment_cost;
    printf("Your first week apartament costs are: £%.2f\n", totalfirst);

    if (totalfirst > totalSecond)
    {
        printf("Your expenses decreased on the second week, congratuations");
    }
    else
    {
        printf("Your expenses increse from the first week, need attention");
    }
}