/*
 * week4_3_struct_database.c
 * Author: Mert Aga
 * Student ID: 241ADB159
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Use malloc to allocate space for n Student records,
 *   read each record from the user, print them as a table,
 *   and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Same definition as in Task 2
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // One block big enough for n records; sizeof(struct Student) keeps it portable
    students = malloc((size_t)n * sizeof(struct Student));

    // malloc returns NULL on failure, so check before touching the memory
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);
        // %49s leaves room for '\0' in name[50], preventing a buffer overflow
        if (scanf("%49s %d %f", students[i].name, &students[i].id,
                  &students[i].grade) != 3) {
            printf("Invalid input.\n");
            free(students);  // free before exiting so we don't leak memory
            return 1;
        }
    }

    // Empty line, then the header and one row per student in input order
    printf("\n");
    printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-11s %.1f\n", students[i].id, students[i].name,
               students[i].grade);
    }

    // Every successful malloc needs a matching free
    free(students);

    return 0;
}
