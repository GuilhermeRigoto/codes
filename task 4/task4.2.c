#include <stdio.h>

int main()
{
    char titles[5][100], authors[5][100], genres[5][50];
    int bookCount = 0;
    char choice;

    while (1)
    {
        printf("\nMenu\n");
        printf("a. Add a new book\n");
        printf("b. View all books\n");
        printf("y. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice); // space before %c to consume newline

        if (choice == 'a')
        {
            if (bookCount < 5)
            {
                printf("Enter the book's title: ");
                scanf(" %[^\n]", titles[bookCount]); // read full line including spaces

                printf("Enter the author's name: ");
                scanf(" %[^\n]", authors[bookCount]);

                printf("Enter the book's genre: ");
                scanf(" %[^\n]", genres[bookCount]);

                printf("Book added successfully!\n");
                bookCount++;
            }
            else
            {
                printf("You have reached the maximum number of books (5).\n");
            }
        }
        else if (choice == 'b')
        {
            if (bookCount > 0)
            {
                printf("\nBooks in the library:\n");
                for (int i = 0; i < bookCount; i++)
                {
                    printf("%d. Title: %s, Author: %s, Genre: %s\n", i + 1, titles[i], authors[i], genres[i]);
                }
            }
            else
            {
                printf("No books added yet.\n");
            }
        }
        else if (choice == 'y')
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}