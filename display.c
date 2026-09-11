#include <stdio.h>
#include "student.h"

void displayStudents(int roll[], char names[][50],
                     int marks[][SUBJECTS], int n)
{
    if (n == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    printf("\n========== STUDENT RESULTS ==========\n");

    for (int i = 0; i < n; i++)
    {
        int total = totalMarks(marks[i]);
        float average = averageMarks(marks[i]);

        int pass = 1;

        for (int j = 0; j < SUBJECTS; j++)
        {
            if (marks[i][j] < 35)
            {
                pass = 0;
                break;
            }
        }

        char grade;

        if (!pass)
            grade = 'F';
        else if (average >= 90)
            grade = 'A';
        else if (average >= 75)
            grade = 'B';
        else if (average >= 60)
            grade = 'C';
        else if (average >= 50)
            grade = 'D';
        else
            grade = 'E';

        printf("\nRoll No : %d", roll[i]);
        printf("\nName    : %s", names[i]);

        printf("\nSubject 1: %d", marks[i][0]);
        printf("\nSubject 2: %d", marks[i][1]);
        printf("\nSubject 3: %d", marks[i][2]);

        printf("\nTotal   : %d / 300", total);
        printf("\nAverage : %.2f", average);
        printf("\nStatus  : %s", pass ? "Pass" : "Fail");
        printf("\nGrade   : %c\n", grade);
    }
}
