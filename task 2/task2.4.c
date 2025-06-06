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
    int choice;

    do
    {
        printf("\n--- Movie Ticket Booking System ---\n");
        printf("1. Book tickets\n");
        printf("2. View ticket prices\n");
        printf("3. Exit the program\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            do
            {
                printf("\nEnter movie type (A for Action, C for Comedy, D for Drama): ");
                scanf(" %c", &movieType);
            } while (movieType != 'A' && movieType != 'C' && movieType != 'D');

            do
            {
                printf("Enter Ticket category (R for Regular, P for Premium): ");
                scanf(" %c", &ticketCategory);
            } while (ticketCategory != 'R' && ticketCategory != 'P');

            do
            {
                printf("Enter number of tickets: ");
                scanf("%d", &numTickets);
                if (numTickets <= 0)
                {
                    printf("Number must be greater than 0.\n");
                }
            } while (numTickets <= 0);

            switch (movieType)
            {
            case 'A':
                ticketPrice = (ticketCategory == 'R') ? 10 : 15;
                break;
            case 'C':
                ticketPrice = (ticketCategory == 'R') ? 8 : 12;
                break;
            case 'D':
                ticketPrice = (ticketCategory == 'R') ? 7 : 10;
                break;
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

            printf("\n--- Booking Summary ---\n");
            printf("Movie Type: ");
            if (movieType == 'A')
                printf("Action\n");
            else if (movieType == 'C')
                printf("Comedy\n");
            else if (movieType == 'D')
                printf("Drama\n");

            printf("Ticket Category: %s\n", (ticketCategory == 'R') ? "Regular" : "Premium");
            printf("Number of tickets: %d\n", numTickets);
            printf("Ticket Price per unit: £%d\n", ticketPrice);
            printf("Total before discount/snacks: £%d\n", ticketPrice * numTickets);
            if (discount > 0)
                printf("Discount applied: -£%.2f\n", discount);
            if (snacksCost > 0)
                printf("Snacks added: +£%d\n", snacksCost);
            printf("Total Price: £%.2f\n", totalprice);
            break;

        case 2:
            printf("\n--- Ticket Prices ---\n");
            printf("Action Movie - Regular: £10 | Premium: £15\n");
            printf("Comedy Movie - Regular: £8  | Premium: £12\n");
            printf("Drama Movie  - Regular: £7  | Premium: £10\n");
            printf("Snacks (Optional): £5 per ticket\n");
            printf("Discount: 10%% if you buy more than 5 tickets\n");
            break;

        case 3:
            printf("Thank you for using the Movie Ticket Booking System. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            break;
        }

    } while (choice != 3);

    return 0;
}