#include <stdio.h>

int main()
{
    char title[100];
    char author[100];
    char genre[50];
    char choice;

    printf("Library Management System\n");
    printf("a. Add a new book\n");
    printf("b. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'a')
    {
        printf("\nEnter the book's title: ");
        scanf(" %[^\n]", title);
        printf("Enter the author's name: ");
        scanf(" %[^\n]", author);
        printf("Enter the book's genre: ");
        scanf(" %[^\n]", genre);

        printf("\nBook added successfully!\n");
        printf("Book Details:\nTitle: %s\nAuthor: %s\nGenre: %s\n", title, author, genre);
    }
    else if (choice == 'b')
    {
        printf("Exiting the program...\n");
    }
    else
    {
        printf("Invalid choice. Exiting...\n");
    }

    return 0;
}