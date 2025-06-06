#include <stdio.h>

int main()
{
    char movieType;
    char ticketCategory;
    int ticketPrice = 0;
    int numTickets = 0;
    float totalprice = 0;
    char snacksChoice;
    int snacksCost = 0;
    float discount = 0.0;

    printf("Enter movie type (A for Action, C for Comedy, D for Drama): ");
    scanf(" %c", &movieType);

    printf("Enter ticket category (R for Regular, P for Premium): ");
    scanf(" %c", &ticketCategory);

    printf("Enter number of tickets: ");
    scanf("%d", &numTickets);

    switch (movieType)
    {
    case 'A':
        if (ticketCategory == 'R')
            ticketPrice = 10;
        else if (ticketCategory == 'P')
            ticketPrice = 15;
        break;

    case 'C':
        if (ticketCategory == 'R')
            ticketPrice = 8;
        else if (ticketCategory == 'P')
            ticketPrice = 12;
        break;

    case 'D':
        if (ticketCategory == 'R')
            ticketPrice = 7;
        else if (ticketCategory == 'P')
            ticketPrice = 10;
        break;

    default:
        printf("Invalid movie type.\n");
        return 1;
    }

    totalprice = ticketPrice * numTickets;

    if (numTickets > 5)
    {
        discount = totalprice * 0.10;
        totalprice -= discount;
    }

    printf("Do you want snacks for £5 per ticket? (y for yes, n for no): ");
    scanf(" %c", &snacksChoice);

    if (snacksChoice == 'y' || snacksChoice == 'Y')
    {
        snacksCost = 5 * numTickets;
        totalprice += snacksCost;
    }

    printf("\nMovie Type: ");
    if (movieType == 'A')
        printf("Action\n");
    else if (movieType == 'C')
        printf("Comedy\n");
    else if (movieType == 'D')
        printf("Drama\n");

    printf("Ticket Category: %s\n", (ticketCategory == 'R') ? "Regular" : "Premium");
    printf("Number of Tickets: %d\n", numTickets);
    printf("Total Cost Before Discount: £%.2f\n", (float)ticketPrice * numTickets);
    if (discount > 0)
        printf("Bulk Discount: £%.2f\n", discount);
    if (snacksCost > 0)
        printf("Snacks Cost: £%d.00\n", snacksCost);
    printf("Final Total Price: £%.2f\n", totalprice);

    return 0;
}