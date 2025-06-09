#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[50];
    char grade[3];
};

void addstudent()
{

    FILE *file = fopen("students.txt", "a");
    struct Student s;

    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student grade: ");
    scanf("%s", s.grade);

    fprintf(file, "%d %s %s\n", s.id, s.name, s.grade);
    fclose(file);
    printf("Student added successfully.\n");
}

void displayStudents()
{
    FILE *file = fopen("students.txt", "r");
    struct Student s;

    printf("Student Records;\n");
    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        printf("ID: %d, Name: %s, Grade: %s\n", s.id, s.name, s.grade);
    }

    fclose(file);
}

int main()
{
    int choice;

    do
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display students\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addstudent();
        }
        else if (choice == 2)
        {
            displayStudents();
        }
        else if (choice == 3)
        {
            printf("Exiting program...\n");
        }
        else
        {
            printf("Invalid option. \n");
        }
    } while (choice != 3);

    return 0;
}
