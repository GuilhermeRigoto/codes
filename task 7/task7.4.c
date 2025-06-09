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
    fprintf(file, "%d %s %s\n", id, name, grade);
    fclose(file);
    printf("Student added successfully.\n");
}

void displayStudents()
{
    FILE *file = fopen("students.txt", "r");
    struct Student s;
    printf("\nStudent Records:\n");
    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        printf("ID: %d, Name: %s, Grade: %s\n", s.id, s.name, s.grade);
    }
    fclose(file);
}

void searchStudent(int id)
{
    FILE *file = fopen("students.txt", "r");
    struct Student s;
    int found = 0;
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
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateStudent(int id, char *newName, char *newGrade)
{
    FILE *file = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Student s;
    int found = 0;

    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        if (s.id == id)
        {
            fprintf(temp, "%d %s %s\n", id, newName, newGrade);
            found = 1;
        }
        else
        {
            fprintf(temp, "%d %s %s\n", s.id, s.name, s.grade);
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
    {
        printf("Student with ID %d updated successfully.\n", id);
    }
    else
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent(int id)
{
    FILE *file = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Student s;
    int found = 0;

    while (fscanf(file, "%d %s %s", &s.id, s.name, s.grade) != EOF)
    {
        if (s.id != id)
        {
            fprintf(temp, "%d %s %s\n", s.id, s.name, s.grade);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
    {
        printf("Student with ID %d deleted successfully.\n", id);
    }
    else
    {
        printf("Student with ID %d not found.\n", id);
    }
}

int main()
{
    int choice, id;
    char name[50], grade[3];

    do
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter ID, Name, and Grade: ");
            scanf("%d %s %s", &id, name, grade);
            addStudent(id, name, grade);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(id);
            break;
        case 4:
            printf("Enter ID, New Name, and New Grade: ");
            scanf("%d %s %s", &id, name, grade);
            updateStudent(id, name, grade);
            break;
        case 5:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 6);

    return 0;
}