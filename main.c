#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

void delay(i32 seconds) {
    i32 delayMilliseconds = seconds * 1000;
    i32 startTime = clock() * 1000 / CLOCKS_PER_SEC;
    while (clock() * 1000 / CLOCKS_PER_SEC < startTime + delayMilliseconds)
        ;
}

double getGradeAverage(i32 gradeSize, i32 grades[]) {
    double gradeValue = 0;
    for (i32 i = 0; i < gradeSize; i++) {
        gradeValue = gradeValue + grades[i];
    }
    double gradeAverage = gradeValue / gradeSize;
    return gradeAverage;
}

void swapArr(i32 *a, i32 *b) {
    i32 temp = *a;
    *a = *b;
    *b = temp;
}

void sortArr(i32 arr[], i32 size) {
    for (i32 i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (i32 j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapArr(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    i32 grades[10];
    i32 active = 1;
    i32 input;
    i32 result;
    i32 gradeSize = 0;
    char keyPress;
    char grade;

    while (active == 1) {
        system("cls");
        printf("%d/10 slots used\n\n", gradeSize);
        printf("Please select an option:\n1)Add a Grade\n2)View "
               "Grades\n3)Calculate Grades\n4)Calculate High/Low\n5)Quit\n\n>");
        result = scanf("%d", &input);
        system("cls");
        if (result != 0 && input > 0 && input < 6) {
            switch (input) {
            case 1:
                if (gradeSize < 10) {
                    printf("Please enter a grade (0-100): ");
                    result = scanf("%d", &input);
                    if (result != 0 && input >= 0 && input <= 100) {
                        grades[gradeSize] = input;
                        gradeSize++;
                        system("cls");
                        printf("Grade added\n");
                    } else {
                        system("cls");
                        printf("Invalid input\n");
                        while (getchar() != '\n')
                            ;
                    }
                } else {
                    printf("Grades full\n");
                }
                delay(1);
                break;
            case 2:
                if (gradeSize > 0) {
                    sortArr(grades, gradeSize);
                    for (i32 i = 0; i < gradeSize; i++) {
                        printf("%d. %d%%\n", i + 1, grades[i]);
                    }
                    printf("\n\n1. Delete\n2. Exit\n\n>");
                    result = scanf("%d", &input);
                    if (result != 0 && input > 0 && input < 3) {
                        switch (input) {
                        case 1:
                            printf("\nWhat grade would you like to remove: ");
                            result = scanf("%d", &input);
                            if (result != 0 && input <= gradeSize &&
                                input > 0) {
                                for (i32 i = input - 1; i < gradeSize - 1; i++) {
                                    grades[i] = grades[i + 1];
                                }
                                gradeSize--;
                                system("cls");
                                printf("Grade removed\n");
                            } else {
                                system("cls");
                                printf("Invalid input\n");
                                while (getchar() != '\n')
                                    ;
                            }
                            delay(1);
                            break;
                        case 2:
                            break;
                        }
                    } else {
                        system("cls");
                        printf("Invalid input\n");
                        while (getchar() != '\n')
                            ;
                        delay(1);
                    }
                } else {
                    printf("No grades\n");
                    delay(1);
                }
                break;
            case 3:
                if (gradeSize > 0) {
                    double gradeAverage = getGradeAverage(gradeSize, grades);
                    if (gradeAverage >= 90) {
                        grade = 'A';
                    } else if (gradeAverage >= 80) {
                        grade = 'B';
                    } else if (gradeAverage >= 70) {
                        grade = 'C';
                    } else if (gradeAverage >= 60) {
                        grade = 'D';
                    } else {
                        grade = 'F';
                    }
                    printf("Grade: %c, %.2f%%\n", grade, gradeAverage);
                    printf("Press enter to continue...\n");
                    scanf("%c", &keyPress);
                    while (getchar() != '\n')
                        ;
                } else {
                    printf("No grades\n");
                    delay(1);
                }
                break;
            case 4:
                if (gradeSize > 0) {
                    i32 gradeMin = grades[0];
                    i32 gradeMax = grades[0];
                    for (i32 i = 0; i < gradeSize; i++) {
                        if (grades[i] < gradeMin) {
                            gradeMin = grades[i];
                        }
                        if (grades[i] > gradeMax) {
                            gradeMax = grades[i];
                        }
                    }
                    printf("Highest grade: %d%%\n", gradeMax);
                    printf("Lowest grade: %d%%\n", gradeMin);
                    printf("Press enter to continue...\n");
                    scanf("%c", &keyPress);
                    while (getchar() != '\n')
                        ;
                } else {
                    printf("No grades\n");
                    delay(1);
                }
                break;
            case 5:
                printf("Quitting...\n");
                delay(1);
                system("cls");
                return 0;
            }
        } else {
            printf("Invalid input\n");
            while (getchar() != '\n')
                ;
            delay(1);
        }
    }
    return 0;
}
