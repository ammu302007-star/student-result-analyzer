#include <stdio.h>
#include "student.h"

int main()
{
    int roll[MAX_STUDENTS];
    char names[MAX_STUDENTS][50];
    int marks[MAX_STUDENTS][SUBJECTS];

    int n = 0;
    int choice;
    int target;
    int index;

    do
    {
        printf("\n\n===== STUDENT RESULT ANALYZER =====\n");

        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Search student\n");
        printf("4. Show topper\n");
        printf("5. Show lowest scorer\n");
        printf("6. Sort by total marks\n");
        printf("7. Class statistics\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(roll, names, marks, &n);
                break;

            case 2:
                displayStudents(roll, names, marks, n);
                break;

            case 3:

                if (n == 0)
                {
                    printf("No students available.\n");
                    break;
                }

                printf("Enter roll number: ");
                scanf("%d", &target);

                index = searchStudent(roll, n, target);

                if (index == -1)
                {
                    printf("Student not found.\n");
                }
                else
                {
                    printf("\nStudent found!\n");
                    printf("Roll No : %d\n", roll[index]);
                    printf("Name    : %s\n", names[index]);
                    printf("Total   : %d / 300\n",
                           totalMarks(marks[index]));
                    printf("Average : %.2f\n",
                           averageMarks(marks[index]));
                }

                break;

            case 4:
                showTopper(roll, names, marks, n);
                break;

            case 5:
                showLowest(roll, names, marks, n);
                break;

            case 6:

                if (n == 0)
                {
                    printf("No students available.\n");
                }
                else
                {
                    sortByTotal(roll, names, marks, n);
                }

                break;

            case 7:
                showStatistics(marks, n);
                break;

            case 8:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 8);

    return 0;
}
