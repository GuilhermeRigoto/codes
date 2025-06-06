#include <stdio.h>

int main()
{
    char movieType;
    char ticketCategory;
    int ticketPrice;

    printf("Enter movie type (A for Action, C for Comedy, D for Drama): ");
    scanf(" %c", &movieType);

    printf("Enter ticket category (R for Regular, P for Premium): ");
    scanf(" %c", &ticketCategory);

    switch (movieType)
    {
    case 'A':
        if (ticketCategory == 'R')
            ticketPrice = 7;
        else if (ticketCategory == 'P')
            ticketPrice = 15;
        break;

    case 'C':
        if (ticketCategory == 'R')
            ticketPrice = 9;
        else if (ticketCategory == 'P')
            ticketPrice = 11;
        break;

    case 'D':
        if (ticketCategory == 'R')
            ticketPrice = 6;
        else if (ticketCategory == 'P')
            ticketPrice = 11;
        break;

    default:
        printf("Invalid movie type.\n");
        return 1;
    }

    if (movieType == 'A')
        printf("Movie Type: Action\n");
    else if (movieType == 'C')
        printf("Movie Type: Comedy\n");
    else if (movieType == 'D')
        printf("Movie Type: Drama\n");

    if (ticketCategory == 'R')
        printf("Ticket Category: Regular\n");
    else if (ticketCategory == 'P')
        printf("Ticket Category: Premium\n");

    printf("Total Ticket Price: £%d.00\n", ticketPrice);

    return 0;
}