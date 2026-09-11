#include <stdio.h>
#include <string.h>
#include "student.h"

int totalMarks(int marks[])
{
    int total = 0;

    for (int i = 0; i < SUBJECTS; i++)
    {
        total += marks[i];
    }

    return total;
}

float averageMarks(int marks[])
{
    return totalMarks(marks) / (float)SUBJECTS;
}

void addStudent(int roll[], char names[][50], int marks[][SUBJECTS], int *n)
{
    if (*n >= MAX_STUDENTS)
    {
        printf("Student limit reached.\n");
        return;
    }

    printf("\nEnter roll number: ");
    scanf("%d", &roll[*n]);

    printf("Enter name: ");
    scanf(" %49[^\n]", names[*n]);

    for (int j = 0; j < SUBJECTS; j++)
    {
        do
        {
            printf("Enter marks for subject %d (0-100): ", j + 1);
            scanf("%d", &marks[*n][j]);

            if (marks[*n][j] < 0 || marks[*n][j] > 100)
            {
                printf("Invalid marks. Enter a value from 0 to 100.\n");
            }

        } while (marks[*n][j] < 0 || marks[*n][j] > 100);
    }

    (*n)++;

    printf("Student added successfully!\n");
}

int searchStudent(int roll[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (roll[i] == target)
        {
            return i;
        }
    }

    return -1;
}

void showTopper(int roll[], char names[][50], int marks[][SUBJECTS], int n)
{
    if (n == 0)
    {
        printf("No students available.\n");
        return;
    }

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (totalMarks(marks[i]) > totalMarks(marks[index]))
        {
            index = i;
        }
    }

    printf("\n===== TOPPER =====\n");
    printf("Roll No : %d\n", roll[index]);
    printf("Name    : %s\n", names[index]);
    printf("Total   : %d / 300\n", totalMarks(marks[index]));
    printf("Average : %.2f\n", averageMarks(marks[index]));
}

void showLowest(int roll[], char names[][50], int marks[][SUBJECTS], int n)
{
    if (n == 0)
    {
        printf("No students available.\n");
        return;
    }

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (totalMarks(marks[i]) < totalMarks(marks[index]))
        {
            index = i;
        }
    }

    printf("\n===== LOWEST SCORE =====\n");
    printf("Roll No : %d\n", roll[index]);
    printf("Name    : %s\n", names[index]);
    printf("Total   : %d / 300\n", totalMarks(marks[index]));
    printf("Average : %.2f\n", averageMarks(marks[index]));
}

void sortByTotal(int roll[], char names[][50], int marks[][SUBJECTS], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (totalMarks(marks[j]) < totalMarks(marks[j + 1]))
            {
                int tempRoll = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = tempRoll;

                char tempName[50];

                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);

                for (int k = 0; k < SUBJECTS; k++)
                {
                    int tempMark = marks[j][k];

                    marks[j][k] = marks[j + 1][k];
                    marks[j + 1][k] = tempMark;
                }
            }
        }
    }

    printf("Students sorted by total marks.\n");
}

void showStatistics(int marks[][SUBJECTS], int n)
{
    if (n == 0)
    {
        printf("No students available.\n");
        return;
    }

    int totalAll = 0;
    int passed = 0;
    int failed = 0;

    for (int i = 0; i < n; i++)
    {
        int total = totalMarks(marks[i]);

        totalAll += total;

        int pass = 1;

        for (int j = 0; j < SUBJECTS; j++)
        {
            if (marks[i][j] < 35)
            {
                pass = 0;
                break;
            }
        }

        if (pass)
            passed++;
        else
            failed++;
    }

    printf("\n===== CLASS STATISTICS =====\n");
    printf("Students : %d\n", n);
    printf("Average  : %.2f\n",
           totalAll / (float)(n * SUBJECTS));
    printf("Passed   : %d\n", passed);
    printf("Failed   : %d\n", failed);
}
