#define STUDENT_H

#define MAX_STUDENTS 100
#define SUBJECTS 3

void addStudent(int roll[], char names[][50], int marks[][SUBJECTS], int *n);

void displayStudents(int roll[], char names[][50], int marks[][SUBJECTS], int n);

int searchStudent(int roll[], int n, int target);

int totalMarks(int marks[]);

float averageMarks(int marks[]);

void showTopper(int roll[], char names[][50], int marks[][SUBJECTS], int n);

void showLowest(int roll[], char names[][50], int marks[][SUBJECTS], int n);

void sortByTotal(int roll[], char names[][50], int marks[][SUBJECTS], int n);

void showStatistics(int marks[][SUBJECTS], int n);

#endif
