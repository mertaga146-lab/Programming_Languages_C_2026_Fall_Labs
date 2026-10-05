/*
 * week4_2_struct_student.c
 * Author: Mert Aga
 * Student ID: 241ADB159
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Define a 'Student' struct with name, id and grade, create two
 *   instances with the values from the instructions, and print them.
 *
 *   This program reads no input. Output must match the format in the
 *   Week 4 instructions exactly (it is checked by the autograder).
 */

#include <stdio.h>
#include <string.h>

// A Student groups related data (name, id, grade) into a single type
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    struct Student s1, s2;

    // Arrays cannot be assigned with '=', so strcpy copies the name text
    strcpy(s1.name, "Alice Johnson");
    s1.id = 1001;
    s1.grade = 9.1f;

    strcpy(s2.name, "Bob Smith");
    s2.id = 1002;
    s2.grade = 8.7f;

    // Fields are accessed with the dot operator; %.1f prints 1 decimal place
    printf("Student 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

    return 0;
}
