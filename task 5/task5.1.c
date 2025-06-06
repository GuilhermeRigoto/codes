#include <stdio.h>

#define MAX_STUDENTS 30

int main()
{
    int grades[MAX_STUDENTS];
    int studentIDs[MAX_STUDENTS];
    int numStudents;
    int option;
    int i;

    printf("Enter the number of students ( max 30): ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS || numStudents <= 0)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (i = 0; i < numStudents; i++)
    {
        printf("Enter ID for Student %d: ", i + 1);
        scanf("%d", &studentIDs[i]);

        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Show all student grades\n");
        printf("2. Calculate average grade\n");
        printf("3. Show highest and lowest grade\n");
        printf("4. Count students who passed (grade >= 50)\n");
        printf("5. count students who failed (grade < 50)\n");
        printf("6. Sort and display grades (ascending)\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("\nStudent Grades: \n");

            for (i = 0; i < numStudents; i++)
            {
                printf("ID %d: Grade %d\n", studentIDs[i], grades[i]);
            }
        }
        else if (option == 2)
        {
            int sum = 0;
            for (i = 0; i < numStudents; i++)
            {
                sum += grades[i];
            }
            float average = (float)sum / numStudents;
            printf("Average grade: %.2f\n", average);
        }

        else if (option == 3)
        {
            int max = grades[0];
            int min = grades[0];

            for (i = 1; i < numStudents; i++)
            {
                if (grades[i] > max)
                    max = grades[i];
                if (grades[i] < min)
                    min = grades[i];
            }
            printf("Highest grade: %d\n", max);
            printf("Lowest grade: %d\n", min);
        }

        else if (option == 4)
        {
            int passed = 0;
            for (i = 0; i < numStudents; i++)
            {
                if (grades[i] >= 50)
                    passed++;
            }

            printf("Number of students who passed: %d\n", passed);
        }

        else if (option == 5)
        {
            int failed = 0;
            for (i = 0; i < numStudents; i++)
            {
                if (grades[i] < 50)
                    failed++;
            }
            printf("Number of students who failed: %d\n", failed);
        }

        else if (option == 6)
        {
            int sortedGrades[MAX_STUDENTS];
            for (i = 0; i < numStudents; i++)
            {
                sortedGrades[i] = grades[i];
            }

            for (i = 0; i < numStudents - 1; i++)
            {
                for (int j = 0; j < numStudents - 1 - i; j++)
                {
                    if (sortedGrades[j] > sortedGrades[j + 1])
                    {
                        int temp = sortedGrades[j];
                        sortedGrades[j] = sortedGrades[j + 1];
                        sortedGrades[j + 1] = temp;
                    }
                }
            }
            printf("Grades in ascending order: \n");
            for (i = 0; i < numStudents; i++)
            {
                printf("%d ", sortedGrades[i]);
            }
            printf("\n");
        }

        else if (option == 7)
        {
            printf("Exiting the program...\n");
        }

        else
        {
            printf("Invalid option.\n");
        }

    } while (option != 7);

    return 0;
}
