#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    char grade[3];
};

int studentExists(int id)
{
    FILE *file = fopen("students.txt", "r");
    struct Student s;
    if (!file)
        return 0;

    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        if (s.id == id)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void addStudent(int id, char *name, char *grade)
{
    if (studentExists(id))
    {
        printf("Student with ID %d already exists.\n", id);
        return;
    }

    FILE *file = fopen("students.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d %s %s\n", id, name, grade);
    fclose(file);
    printf("Student added successfully.\n");
}

void searchStudent(int id)
{
    FILE *file = fopen("students.txt", "r");
    struct Student s;
    int found = 0;

    if (!file)
    {
        printf("No records found.\n");
        return;
    }

    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        if (s.id == id)
        {
            printf("Student found: ID: %d, Name: %s, Grade: %s\n", s.id, s.name, s.grade);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found)
        printf("Student with ID %d not found.\n", id);
}

void updateStudent(int id)
{
    FILE *file = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Student s;
    int found = 0;

    if (!file || !temp)
    {
        printf("Error opening files.\n");
        return;
    }

    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        if (s.id == id)
        {
            found = 1;
            printf("Enter new name for ID %d: ", id);
            scanf("%s", s.name);
            printf("Enter new grade for ID %d: ", id);
            scanf("%s", s.grade);
        }
        fprintf(temp, "%d %s %s\n", s.id, s.name, s.grade);
    }

    fclose(file);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student updated successfully.\n");
    else
        printf("Student with ID %d not found.\n", id);
}

void displayAllStudents()
{
    FILE *file = fopen("students.txt", "r");
    struct Student s;

    if (!file)
    {
        printf("No records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        printf("ID: %d, Name: %s, Grade: %s\n", s.id, s.name, s.grade);
    }

    fclose(file);
}

int main()
{
    int choice, id;
    char name[50], grade[3];

    do
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Update Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Grade: ");
            scanf("%s", grade);
            addStudent(id, name, grade);
            break;
        case 2:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(id);
            break;
        case 3:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            updateStudent(id);
            break;
        case 4:
            displayAllStudents();
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}