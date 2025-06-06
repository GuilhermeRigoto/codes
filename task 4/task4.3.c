#include <stdio.h>
#include <string.h>

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
        printf("c. Search for a book\n");
        printf("y. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice); // consume newline with space

        if (choice == 'a')
        {
            if (bookCount < 5)
            {
                printf("Enter the book's title: ");
                scanf(" %[^\n]", titles[bookCount]);

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
        else if (choice == 'c')
        {
            if (bookCount > 0)
            {
                char searchTitle[100];
                int found = 0;

                printf("Enter the book title to search: ");
                scanf(" %[^\n]", searchTitle);

                for (int i = 0; i < bookCount; i++)
                {
                    if (strcmp(titles[i], searchTitle) == 0)
                    {
                        printf("\nBook found!\n");
                        printf("Title: %s\n", titles[i]);
                        printf("Author: %s\n", authors[i]);
                        printf("Genre: %s\n", genres[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("Book not found.\n");
                }
            }
            else
            {
                printf("No books to search.\n");
            }
        }
        else if (choice == 'y')
        {
            printf("Exiting program...\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}