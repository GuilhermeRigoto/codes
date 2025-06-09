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
    if (!file)
        return 0;

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
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d %s %s\n", id, name, grade);
    fclose(file);
    printf("Student added successfully.\n");
}

int loadStudents(struct Student students[])
{
    FILE *file = fopen("students.txt", "r");
    if (!file)
        return 0;

    int count = 0;
    while (fscanf(file, "%d %s %s", &students[count].id, students[count].name, students[count].grade) != EOF)
    {
        count++;
    }
    fclose(file);
    return count;
}

void displayStudents(struct Student students[], int count)
{
    printf("Student Records:\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Name: %s, Grade: %s\n", students[i].id, students[i].name, students[i].grade);
    }
}

void searchStudent(int id)
{
    FILE *file = fopen("students.txt", "r");
    if (!file)
    {
        printf("No records found.\n");
        return;
    }

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

int main()
{
    int choice, id;
    char name[50], grade[3];
    struct Student students[100];
    int count;

    do
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student ID: ");
            scanf("%d", &id);
            printf("Enter student name: ");
            scanf("%s", name);
            printf("Enter student grade: ");
            scanf("%s", grade);
            addStudent(id, name, grade);
            break;
        case 2:
            count = loadStudents(students);
            displayStudents(students, count);
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(id);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 4);

    return 0;
}